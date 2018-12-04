#include "StdAfx.h"
#include "AssemMeshManager.h"
#include "PmeAssembly.h"
#include "PmeComponentAPI.h"
#include "PmePartApi.h"
#include "PmeExplicitModelAPI.h"
#include "pmeSolidAPI.h"
//#include ".\..\PartModeler\PmMeshManager.h"
#include "PmeHandleMacro.h"
#include "PmMeshManager.h"
#include <algorithm>

//#include <vector>
/* */
AssemMeshManager::AssemMeshManager(void)
: m_isEmpty(true)
, m_surfaceTolerance(-1)
, m_normalTolerance(10)
, m_gridAspectRatio(0.0)
, m_maxEdgeLength(0.0)
, m_maxGridLines(250)
, m_gridMode(AF_GRID_NONE)
, m_triangMode(AF_TRIANG_ALL)
, m_adjustMode(AF_ADJUST_NONE)
, m_pts(0)
, m_facelist(0)
, m_maxVolume(10)
{
	  
}
/*
AssemMeshManager::AssemMeshManager(
							 double surfaceTolerance,
							 double normalTolerance,
							 double gridAspectRatio,
							 double maxEdgeLength,
							 int maxGridLines,
							 AF_GRID_MODE gridMode,
							 AF_TRIANG_MODE triangMode,
							 AF_ADJUST_MODE adjustMode)
							 : m_isEmpty(true)
							 , m_surfaceTolerance(surfaceTolerance)
							 , m_normalTolerance(normalTolerance)
							 , m_gridAspectRatio(gridAspectRatio)
							 , m_maxEdgeLength(maxEdgeLength)
							 , m_maxGridLines(maxGridLines)
							 , m_gridMode(gridMode)
							 , m_triangMode(triangMode)
							 , m_adjustMode(adjustMode)
							 , m_pts(0)
							 , m_facelist(0)
							 , m_maxVolume(10)
{
}
*/
AssemMeshManager::~AssemMeshManager(void)
{
	if(m_facelist)
		delete m_facelist;
	m_facelist = 0;

	if(m_pts)
		delete m_pts;
	m_pts = 0;
}

void AssemMeshManager::Generate(PmeHAssembly  hAssembly)
{ 
	/*
	CString filename = GenerateInputFile(pBody);
	RunMeshGenerator(filename);
	GenerateRenderingData(filename);

	m_isEmpty = false;

	FireMeshGeneratedEvent();
	*/

 // PmeAssembly  * assemb;
// assemb->GetComponentList();


 // PmeComponent * pComponent = assemb->ComponentList->begin(); 
 // pComponent->GetPart()->GetExplicitModel()->GetSolid();
  
//  std::vector<PmeComponent *>::iterator itor;
  

/*
  for (itor =hAssemb->GetComponentList().begin(); itor != assemb->GetComponentList().end(); itor++)
  {
	  BODY * pBody = 0;

	 PmeComponent * pcomp = *itor;
	//  pBody = pcomp->GetPart()->GetExplicitModel()->GetSolid()->GetSolid();
	//  pBody =pcomp->GetPart()->GetExplicitModel()->GetSolid()->GetSolid();
	  //PmMeshManager::Generate(pBody);
	 
	  PmMeshManager mesh;
	  mesh.Generate(pBody);

  }
 */
	BODY * pBody;
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);
	PmeHComponent hComponent;
	PmeHPart hPart;
	PmeHExplicitModel hExplicitModel;
	PmeHExplicitModelObject hExplicitModeObject;
	
	PmeAssemblyAPI::GetComponent(hAssembly, 0,hComponent);
	//PmeComponentAPI::GetPart(hComponent,hPart);
	PmePartAPI::GetExplicitModel(hPart,hExplicitModel);
	PmeExplicitModelAPI::GetSolid(hExplicitModel,hExplicitModeObject);
	PmeSolidAPI::GetSolid(hExplicitModeObject,pBody);

	CString path;
	PmMeshManager *mesh = new PmMeshManager();
	mesh->Generate(pBody,path);
	

  
	//  BODY* pBody = pAssembly->GetComponent(1)->GetPart())->GetExplicitModel()->GetSolid()->GetSolid();
 // PmeComponent * pComponent = pAssembly->GetComponent(1) ;

//  PmeHComponent * hComponent =PME_ASSEMBLY2HANDLE(pComponent);
  
//	PmMeshManager mesh;
//	  mesh.Generate(pBody);

}

void AssemMeshManager::Remove(void)
{
	if(m_facelist)
		delete m_facelist;
	m_facelist = 0;

	if(m_pts)
		delete m_pts;
	m_pts = 0;

	m_isEmpty = true;

	FireMeshRemovedEvent();
}

void AssemMeshManager::RegisterEventListener(IAssemMeshManagerEventListener * pListener)
{
	m_listeners.push_back(pListener);
}

void AssemMeshManager::UnregisterEventListener(IAssemMeshManagerEventListener * pListener)
{
	ListenerList::iterator i = std::find(m_listeners.begin(), m_listeners.end(), pListener);
	m_listeners.erase(i);
}

void AssemMeshManager::FireMeshGeneratedEvent(void)
{
	ListenerList::iterator i = m_listeners.begin();

	while(i != m_listeners.end())
	{
		IAssemMeshManagerEventListener * pListener = *i;
		pListener->OnMeshGenerated();

		i ++;
	}
}

void AssemMeshManager::FireMeshRemovedEvent(void)
{
	ListenerList::iterator i = m_listeners.begin();

	while(i != m_listeners.end())
	{
		IAssemMeshManagerEventListener * pListener = *i;
		pListener->OnMeshRemoved();

		i ++;
	}
}

void AssemMeshManager::GenerateMesh(BODY *& pBody, CString filename)
{
	outcome result;

	MESH_MANAGER * pMeshManager = ACIS_NEW LINKED_MESH_MANAGER;
	api_set_mesh_manager(pMeshManager);

	REFINEMENT * pRefinement = 0;
	api_create_refinement(pRefinement);

	pRefinement->set_surface_tol(m_surfaceTolerance);
	pRefinement->set_normal_tol(m_normalTolerance);
	pRefinement->set_grid_aspect_ratio(m_gridAspectRatio);
	pRefinement->set_max_edge_length(m_maxEdgeLength);
	pRefinement->set_max_grid_lines(m_maxGridLines);
	pRefinement->set_grid_mode(m_gridMode);
	pRefinement->set_triang_mode(m_triangMode);
	pRefinement->set_adjust_mode(m_adjustMode);
	pRefinement->set_surf_mode(AF_SURF_ALL);

	api_set_entity_refinement(pBody, pRefinement, FALSE);

	result = api_facet_entity(pBody);
	if(!result.ok())
	{
		TRACE(_T("Mesh generation error: %s\n"), result.get_error_info()->error_message());
		return;
	}

	WriteMesh(pBody, filename);

	pRefinement->lose();

	api_set_entity_refinement(pBody, NULL, FALSE);
	ACIS_DELETE pMeshManager;
}

CString AssemMeshManager::GenerateInputFile(BODY *& pBody)
{
	char tempPath[MAX_PATH];
	GetTempPath(MAX_PATH, tempPath);

	char tempFileName[MAX_PATH];
	GetTempFileName(tempPath, _T("pol"), 0, tempFileName);

	CString filename(tempFileName);
	filename.Append(_T(".poly"));

	GenerateMesh(pBody, filename);

	return filename;
}

void AssemMeshManager::WriteMesh(BODY *& pBody, CString filename)
{
	ENTITY_LIST faces;
	api_get_faces(pBody, faces);

	SPAtransf xform;
	ENTITY * owner;

	api_get_owner(pBody, owner);

	if(is_BODY(owner))
	{
		BODY * pTempBody;
		pTempBody = (BODY *)owner;

		if(pTempBody->transform())
			xform = pTempBody->transform()->transform();
	}

	FACE * pFace;
	ENTITY_LIST entities;

	CoordInfo coordInfo;
	FaceInfo faceInfo;

	// index start at 1.
	Coord tempCoord;
	coordInfo.push_back(tempCoord);
	Face tempFace;
	faceInfo.push_back(tempFace);

	for(faces.init(); pFace = (FACE *)(faces.next());)
	{
		MESH * pFaceMesh = NULL;

		af_query((ENTITY *)pFace, IDX_MESH_APP, IDX_MESH_ID, pFaceMesh);
		if(pFaceMesh == NULL)
			continue;

		SEQUENTIAL_MESH * pMesh = (SEQUENTIAL_MESH *)pFaceMesh;
		GetMesh(pMesh, xform, coordInfo, faceInfo);
	}

	FILE *fp;
	TRACE("Writing mesh input file into %s\n", filename);
	fp = fopen(filename, "wt");

	fprintf(fp,"#nodelist \n");
	fprintf(fp,"%d 3 0 0\n", coordInfo.size() - 1);

	for (int i=1; i <= (int)coordInfo.size() - 1; i ++)
	{
		fprintf(fp,"%d %lf %lf %lf \n", i, coordInfo[i].x, coordInfo[i].y, coordInfo[i].z);
	}

	fprintf(fp,"\n #facelist \n");
	fprintf(fp,"%d 1 \n", faceInfo.size() - 1);

	for (int i=1; i <= (int)faceInfo.size() - 1; i ++)
	{	
		fprintf(fp,"%d 0 1\n",i);
		fprintf(fp,"3 %d %d %d \n", faceInfo[i].node1, faceInfo[i].node2, faceInfo[i].node3);	
	}

	fprintf(fp,"# Part 3 - hole list\n");
	fprintf(fp,"0\n");
	fprintf(fp,"# Part 4 - region list\n");
	fprintf(fp,"0\n");

	fclose(fp);
}

void AssemMeshManager::GetMesh(SEQUENTIAL_MESH * pMesh, SPAtransf xform, CoordInfo & coordInfo, FaceInfo & faceInfo)
{
	int nPolygon = pMesh->get_num_polygon();
	MESH_POLYGON meshPolygon;
	pMesh->get_first_polygon(meshPolygon);

	for(int i = 0; i < nPolygon; ++ i)
	{	
		int nNode = pMesh->get_num_polynode(meshPolygon);

		MESH_POLYNODE node;
		pMesh->get_first_polynode(meshPolygon, node);

		Face face;

		int * pNode = &face.node1;

		for(int j = 0; j < nNode; ++ j)
		{
			const SPAposition & pos = pMesh->get_position(node);
			SPAposition newPos = pos * xform;

			int v = (int)coordInfo.size();

			*pNode = v;
			pNode ++;

			Coord coord;
			coord.x = newPos.x();
			coord.y = newPos.y();
			coord.z = newPos.z();

			coordInfo.push_back(coord);

			pMesh->get_next_polynode(node);
		}

		faceInfo.push_back(face);

		pMesh->get_next_polygon(meshPolygon);
	}
}

void AssemMeshManager::GenerateRenderingData(CString filename)
{
	CString path = filename.Left(filename.GetLength() - 4);
	CString faceFilename = path + "1.face";
	CString nodeFilename = path + "1.node";

	FILE * fp = fopen(nodeFilename, "rt");
	if(fp == NULL)
		return;

	m_ptsCount = 0;
	fscanf(fp, "%d", &m_ptsCount);

	m_pts = new Point[m_ptsCount + 1];

	int buf;
	fscanf(fp, "%d", &buf);
	fscanf(fp, "%d", &buf);
	fscanf(fp, "%d", &buf);

	m_pts[0].x = 0.0;
	m_pts[0].y = 0.0;
	m_pts[0].z = 0.0;

	for(int i = 1; i <= m_ptsCount; i ++)
	{
		fscanf(fp, "%d %f %f %f", &buf, &(m_pts[i].x), &(m_pts[i].y), &(m_pts[i].z));
	}	

	fclose(fp);

	FILE * ft;

	ft = fopen(faceFilename, "rt");
	if(ft == NULL)
		return;

	m_faceCount = 0;
	fscanf(ft, "%d", &m_faceCount);

	m_facelist = new int[m_faceCount*4];

	fscanf(fp, "%d", &buf);

	int * curFace = &m_facelist[0];

	int dummy1, dummy2;
	int v1, v2, v3;

	for(int i = 0; i < m_faceCount; i ++)
	{
		fscanf(ft, "%d %d %d %d %d", &dummy1, &v1, &v2, &v3, &dummy2);

		*curFace = 3;
		curFace ++;
		*curFace = v1;
		curFace ++;
		*curFace = v2;
		curFace ++;
		*curFace = v3;
		curFace ++;
	}		

	fclose(ft);
}

void AssemMeshManager::Render(void)
{
	HC_Open_Segment("Mesh");
	HC_Insert_Shell_By_Ref(m_ptsCount + 1, m_pts, m_faceCount * 4, m_facelist);

	HC_Set_Visibility("edges=(on, perimeters=on), faces=on");  
	HC_Set_Rendering_Options("no lighting interpolation");

	HC_Close_Segment();
}

void AssemMeshManager::RunMeshGenerator(CString filename)
{
// 	CString tetgenPath = getenv("TETGEN");
// 	CString option;
// 	option.Format("-pqa%f", GetMaxVolume());
// 
// 	CString cmdLine = tetgenPath + _T(" ") + option + _T(" ") + filename;
// 
// 	STARTUPINFO si;
// 	PROCESS_INFORMATION pi;
// 
// 	ZeroMemory(&si, sizeof(si));
// 	si.cb = sizeof(si);
// 	ZeroMemory(&pi, sizeof(pi));
// 
// 	// Start the child process. 
// 	if(!CreateProcess(NULL, (LPSTR)(LPCSTR)cmdLine, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) 
// 	{
// 		return;
// 	}
// 
// 	// Wait until child process exits.
// 	WaitForSingleObject(pi.hProcess, INFINITE);
// 
// 	DWORD exitCode;
// 	GetExitCodeProcess(pi.hProcess, &exitCode);
// 
// 	if(exitCode != 0)
// 		return;
// 
// 	// Close process and thread handles. 
// 	CloseHandle(pi.hProcess);
// 	CloseHandle(pi.hThread);
}

