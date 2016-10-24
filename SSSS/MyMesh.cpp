#include "MyMesh.h"
#include <iostream>

OpenMesh::EPropHandleT<double> MyMesh::edgeWeight;
OpenMesh::VPropHandleT<double> MyMesh::oneRingArea;

MyMesh::MyMesh()
{
	add_property(edgeWeight);
	add_property(oneRingArea);
	hasExtraction = false;
}

MyMesh::~MyMesh()
{

}

void MyMesh::Extraction(float s)
{
	if (!hasExtraction) {
		hasExtraction = true;
		UpdateEdgeWeight();
		double wl = sqrt(MeshArea() / n_faces()) * 0.001;
		std::cout << "MeshArea()" << wl << std::endl;
		a = Eigen::SparseMatrix<double>(n_vertices() * 2, n_vertices());
		b = Eigen::MatrixXd(n_vertices() * 2, 3);
		x = Eigen::MatrixXd(n_vertices(), 3);
		// fill matrix
		for (VertexIter v_it = vertices_begin(); v_it != vertices_end(); ++v_it) {
			property(oneRingArea, v_it) = one_ring_area(v_it);
			double w = 0;
			for (VertexOHalfedgeIter voh_it = voh_begin(v_it); voh_it != voh_end(v_it); ++voh_it) {
				a.insert(v_it->idx(), to_vertex_handle(voh_it).idx()) = -property(edgeWeight, edge_handle(voh_it));
				w += property(edgeWeight, edge_handle(voh_it));
			}
			a.insert(v_it->idx(), v_it->idx()) = w;
			a.insert(n_vertices() + v_it->idx(), v_it->idx()) = 1;
			b(n_vertices() + v_it->idx(), 0) = point(v_it)[0];
			b(n_vertices() + v_it->idx(), 1) = point(v_it)[1];
			b(n_vertices() + v_it->idx(), 2) = point(v_it)[2];
		}
		a.block(0, 0, n_vertices(), n_vertices()) *= wl;
		b.block(0, 0, n_vertices(), 3).setZero();
		// slove
		a.makeCompressed();
		linearSolver.compute(a.transpose() * a);
		x.col(0) = linearSolver.solve(a.transpose() * b.col(0));
		x.col(1) = linearSolver.solve(a.transpose() * b.col(1));
		x.col(2) = linearSolver.solve(a.transpose() * b.col(2));
	}
	else {
		for (VertexIter v_it = vertices_begin(); v_it != vertices_end(); ++v_it) {
			double ora = one_ring_area(v_it);
			a.coeffRef(n_vertices() + v_it->idx(), v_it->idx()) *= sqrt(property(oneRingArea, v_it) / ora);
			property(oneRingArea, v_it) = ora;
			b(n_vertices() + v_it->idx(), 0) = x(v_it->idx(), 0) * a.coeffRef(n_vertices() + v_it->idx(), v_it->idx());
			b(n_vertices() + v_it->idx(), 1) = x(v_it->idx(), 1) * a.coeffRef(n_vertices() + v_it->idx(), v_it->idx());
			b(n_vertices() + v_it->idx(), 2) = x(v_it->idx(), 2) * a.coeffRef(n_vertices() + v_it->idx(), v_it->idx());
		}
		a.block(0, 0, n_vertices(), n_vertices()) *= s;
		//b.block(n_vertices(), 0, n_vertices(), 3) = x;
		a.makeCompressed();
		linearSolver.compute(a.transpose() * a);
		x.col(0) = linearSolver.solve(a.transpose() * b.col(0));
		x.col(1) = linearSolver.solve(a.transpose() * b.col(1));
		x.col(2) = linearSolver.solve(a.transpose() * b.col(2));
	}
	// fill mesh
	for (VertexIter v_it = vertices_begin(); v_it != vertices_end(); ++v_it) {
		point(v_it)[0] = x(v_it->idx(), 0);
		point(v_it)[1] = x(v_it->idx(), 1);
		point(v_it)[2] = x(v_it->idx(), 2);
	}
#include <fstream>
	std::fstream fp;
	fp.open("a.mat.txt", std::ios::out);//開啟檔案
	fp << a << std::endl;
	fp.close();
	fp.open("b.mat.txt", std::ios::out);//開啟檔案
	fp << b << std::endl;
	fp.close();
	puts("Extraction");
}

void MyMesh::UpdateEdgeWeight()
{
	for (EdgeIter e_it = edges_begin(); e_it != edges_end(); ++e_it) {
		if (!is_boundary(e_it)) {
			HalfedgeHandle he = halfedge_handle(e_it, 0);
			Point vertex0 = point(from_vertex_handle(he));
			Point vertex1 = point(to_vertex_handle(he));
			Point vertex2 = point(opposite_vh(he));
			Point vertex3 = point(opposite_he_opposite_vh(he));
			Point vectorA1 = vertex0 - vertex2;
			Point vectorA2 = vertex1 - vertex2;
			Point vectorB1 = vertex0 - vertex3;
			Point vectorB2 = vertex1 - vertex3;
			double cotA = 1.0 / tan(acos(dot(vectorA1, vectorA2) / vectorA1.length() / vectorA2.length()));
			double cotB = 1.0 / tan(acos(dot(vectorB1, vectorB2) / vectorB1.length() / vectorB2.length()));
			property(edgeWeight, e_it.handle()) = cotA + cotB;
		}
		else {
			property(edgeWeight, e_it.handle()) = 0;
		}
		//std::cout << e_it->idx() << ":" << property(edgeWeight, e_it.handle()) << std::endl;
	}
}

double MyMesh::MeshArea()
{
	double area = 0;
	for (FaceIter f_it = faces_begin(); f_it != faces_end(); ++f_it) {
		area += face_area(f_it);
	}
	return area;
}

double MyMesh::face_area(FaceHandle fh)
{
	FaceVertexIter fv_it = fv_begin(fh);
	Point vertex0 = point(fv_it);
	++fv_it;
	Point vertex1 = point(fv_it);
	++fv_it;
	Point vertex2 = point(fv_it);
	double a = (vertex0 - vertex1).length();
	double b = (vertex1 - vertex2).length();
	double c = (vertex2 - vertex0).length();
	double s = (a + b + c) / 2;
	double r = sqrt(s * (s - a) * (s - b) * (s - c));
	//std::cout << r;
	return r;
}

double MyMesh::one_ring_area(VertexHandle vh)
{
	double area = 0;
	for (VertexFaceIter vf_it = vf_begin(vh); vf_it != vf_end(vh); ++vf_it) {
		area += face_area(vf_it);
	}
	return area;
}

