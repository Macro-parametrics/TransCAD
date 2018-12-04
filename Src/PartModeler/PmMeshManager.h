#pragma once

#include <vector>
#include <string>
#include <box.hxx>
#include <getbox.hxx>

struct IPmMeshManagerEventListener
{
	virtual void OnMeshGenerated(void) = 0;
	virtual void OnMeshRemoved(void) = 0;
};

class PmMeshManager
{
private:
	typedef std::vector<IPmMeshManagerEventListener *> ListenerList;

	typedef struct
	{
		double x, y, z;
	} Coord;

	typedef struct
	{
		int node1;
		int node2;
		int node3;
	} Face;

	typedef struct
	{
		float x, y, z;
	} Point;

	typedef std::vector<Coord> CoordInfo;
	typedef std::vector<Face> FaceInfo;

public:
	PmMeshManager(void);
	PmMeshManager(
		double surfaceTolerance,
        double normalTolerance,
        double gridAspectRatio,
        double maxEdgeLength,
        int maxGridLines,
	    AF_GRID_MODE gridMode,
        AF_TRIANG_MODE triangMode,
        AF_ADJUST_MODE adjustMode);
	~PmMeshManager(void);

	void SetNormalTolerance(double NormalTolerance) {m_normalTolerance = NormalTolerance;}
	void SetSurfaceTolerance(double SurfaceTolerance) {m_surfaceTolerance = SurfaceTolerance;}
	
	void Generate(BODY *& pBody, CString filename);
	void Remove(void);
	
	bool IsEmpty(void) const {return m_isEmpty;}

	void Render();

	void RegisterEventListener(IPmMeshManagerEventListener * pListener);
	void UnregisterEventListener(IPmMeshManagerEventListener * pListener);

private:
	void GenerateMesh(BODY *& pBody, CString filename);
	void WriteOBJ(BODY *& pBody, CString filename);
	void WriteX3D(BODY *& pBody, CString filename);
	void WriteSTL(BODY *& pBody, CString filename);
	void WritePLY(BODY *& pBody, CString filename);
	void WriteVRML(BODY *& pBody, CString filename);

	void GetMesh(SEQUENTIAL_MESH * pMesh, SPAtransf xform, CoordInfo & coordInfo, FaceInfo & faceInfo);
	void GenerateRenderingData();
	
	void FireMeshGeneratedEvent(void);
	void FireMeshRemovedEvent(void);

private:	
	ListenerList m_listeners;
	bool m_isEmpty;
	
	double m_surfaceTolerance;
	double m_normalTolerance;
	double m_gridAspectRatio;
	double m_maxEdgeLength;
	int m_maxGridLines;
	AF_GRID_MODE m_gridMode;
	AF_TRIANG_MODE m_triangMode;
	AF_ADJUST_MODE m_adjustMode;

	int m_ptsCount;
	int m_faceCount;
	Point * m_pts;
	int * m_facelist;
	CString filename;

public:
	double m_BBDiagonal;
	double m_facetArea;
	double m_surfArea;
};
