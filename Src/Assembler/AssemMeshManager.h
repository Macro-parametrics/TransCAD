#pragma once

#include "PmeAssembly.h"
#include <vector>

struct IAssemMeshManagerEventListener
{
	virtual void OnMeshGenerated(void) = 0;
	virtual void OnMeshRemoved(void) = 0;
};

class AssemMeshManager
{
private:
	typedef std::vector<IAssemMeshManagerEventListener *> ListenerList;

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
	AssemMeshManager(void);
	/*AssemMeshManager(
		double surfaceTolerance,
		double normalTolerance,
		double gridAspectRatio,
		double maxEdgeLength,
		int maxGridLines,
		AF_GRID_MODE gridMode,
		AF_TRIANG_MODE triangMode,
		AF_ADJUST_MODE adjustMode);
	*/
	~AssemMeshManager(void);

	void SetMaxVolume(double volume) {m_maxVolume = volume;}
	double GetMaxVolume(void) const {return m_maxVolume;}
//
	void Generate(PmeHAssembly hAssembly);
	void Remove(void);

	bool IsEmpty(void) const {return m_isEmpty;}

	void Render(void);

	void RegisterEventListener(IAssemMeshManagerEventListener * pListener);
	void UnregisterEventListener(IAssemMeshManagerEventListener * pListener);

private:
	
	void GenerateMesh(BODY *& pBody, CString filename);
	CString GenerateInputFile(BODY *& pBody);
	void WriteMesh(BODY *& pBody, CString filename);
	void GetMesh(SEQUENTIAL_MESH * pMesh, SPAtransf xform, CoordInfo & coordInfo, FaceInfo & faceInfo);
	void GenerateRenderingData(CString filename);
	void RunMeshGenerator(CString filename);

	void FireMeshGeneratedEvent(void);
	void FireMeshRemovedEvent(void);
/**/ 
private:
	/**/ 
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

	double m_maxVolume;
	
};
