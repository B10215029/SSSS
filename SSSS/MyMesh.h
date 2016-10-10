#pragma once
#undef min
#undef max
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

public class MyTraits : public OpenMesh::DefaultTraits
{
public:
	MyTraits()
	{

	}
	~MyTraits()
	{

	}

private:

};

public class MyMesh : public OpenMesh::TriMesh_ArrayKernelT<MyTraits>
{
public:
	MyMesh();
	~MyMesh();

private:

};