#include "StdAfx.h"
#include "PmMeshManager.h"

#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include ".\PmePersistentNameAPI.h"
#include "stlmmg.hxx"
#include "fct_utl.hxx"
#include "facet_options.hxx"

PmMeshManager::PmMeshManager(void)
: m_isEmpty(true)
, m_surfaceTolerance(-1)
, m_normalTolerance(1)
, m_gridAspectRatio(0.0)
, m_maxEdgeLength(0.0)
, m_maxGridLines(512)
, m_gridMode(AF_GRID_INTERIOR)
, m_triangMode(AF_TRIANG_ALL)
, m_adjustMode(AF_ADJUST_ALL)
, m_pts(0)
, m_facelist(0)
, m_BBDiagonal (0)
, m_facetArea (0)
, m_surfArea (0)
{
}

PmMeshManager::PmMeshManager(
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
, m_BBDiagonal (0)
, m_facetArea (0)
, m_surfArea (0)
{
}

PmMeshManager::~PmMeshManager(void)
{
	if(m_facelist)
		delete m_facelist;
	m_facelist = 0;

	if(m_pts)
		delete m_pts;
	m_pts = 0;
}



void PmMeshManager::Remove(void)
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

void PmMeshManager::RegisterEventListener(IPmMeshManagerEventListener * pListener)
{
	m_listeners.push_back(pListener);
}

void PmMeshManager::UnregisterEventListener(IPmMeshManagerEventListener * pListener)
{
	ListenerList::iterator i = std::find(m_listeners.begin(), m_listeners.end(), pListener);
	m_listeners.erase(i);
}

void PmMeshManager::FireMeshGeneratedEvent(void)
{
	ListenerList::iterator i = m_listeners.begin();

	while(i != m_listeners.end())
	{
		IPmMeshManagerEventListener * pListener = *i;
		pListener->OnMeshGenerated();

		i ++;
	}
}

void PmMeshManager::FireMeshRemovedEvent(void)
{
	ListenerList::iterator i = m_listeners.begin();

	while(i != m_listeners.end())
	{
		IPmMeshManagerEventListener * pListener = *i;
		pListener->OnMeshRemoved();

		i ++;
	}
}

// Mesh 생성 (16-11-25 권순조)
void PmMeshManager::Generate(BODY *& pBody, CString filename)
{
	SPAbox boundingBox = get_body_box(pBody);
	m_BBDiagonal = (boundingBox.high()-boundingBox.low()).len();
	
	if (filename.Find(_T(".stl")) != -1)
		WriteSTL(pBody, filename);
	else if (filename.Find(_T(".obj")) != -1 || filename.Find(_T(".x3d")) != -1 || filename.Find(_T(".ply")) != -1 || filename.Find(_T(".wrl")) != -1)
		GenerateMesh(pBody, filename);
	
	m_isEmpty = false;
}

void PmMeshManager::GenerateMesh(BODY *& pBody, CString filename)
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

	if(filename.Find(_T(".obj")) != -1)
		WriteOBJ(pBody, filename);
	else if(filename.Find(_T(".x3d")) != -1)
		WriteX3D(pBody, filename);
	else if(filename.Find(_T(".ply")) != -1)
		WritePLY(pBody, filename);
	else if(filename.Find(_T(".wrl")) != -1)
		WriteVRML(pBody, filename);

	pRefinement->lose();
	api_set_entity_refinement(pBody, NULL, FALSE);
	ACIS_DELETE pMeshManager;
}

// OBJ 생성 전용 (16-11-25 권순조)
void PmMeshManager::WriteOBJ(BODY *& pBody, CString filename)
{
	outcome result;
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

	//Error calculation
	m_facetArea = 0;
	m_surfArea = 0;

    // Compute area of surfaces.
    double target_tol = 0.001;
    double real_tol;
    result = api_ent_area(pBody, target_tol, m_surfArea, real_tol);
    check_outcome(result);

	int index = 1;

	for(faces.init(); pFace = (FACE *)(faces.next());)
	{
		MESH * pFaceMesh = NULL;

		af_query((ENTITY *)pFace, IDX_MESH_APP, IDX_MESH_ID, pFaceMesh);
		
		if(pFaceMesh == NULL)
			continue;

		SEQUENTIAL_MESH * pMesh = (SEQUENTIAL_MESH *)pFaceMesh;
		GetMesh(pMesh, xform, coordInfo, faceInfo);

		// For every facet (or polygon) compute the area.
		int polygon_count = pMesh->get_num_polygon();
		MESH_POLYGON mesh_polygon;
		pMesh->get_first_polygon(mesh_polygon);
		
		for (int polygon_index = 0; polygon_index < polygon_count; polygon_index++) 
		{
			int polynode_count = pMesh->get_num_polynode(mesh_polygon);
			double polygon_area = 0;

			// Consider the polygon as a fan of triangles, all sharing one node.
			// Each triangle is formed by one fixed node and two other consecutive nodes.
			// Compute area of each triangle (negative areas indicated concavity).

			// Use the first node as the fixed node.
			MESH_POLYNODE mesh_polynode;
			pMesh->get_first_polynode(mesh_polygon, mesh_polynode);
			const SPAposition & fixed_pos = pMesh->get_position(mesh_polynode);

			// Make the first edge of the first triangle using a vector.
			pMesh->get_next_polynode(mesh_polynode);
			SPAvector prev_edge(pMesh->get_position(mesh_polynode) - fixed_pos);
			prev_edge *= xform;

			// For every remaining node, create triangles and add up the areas.
			for (int polynode_index = 2; polynode_index < polynode_count; polynode_index++) 
			{
				// Make the other edge of the triangle.
				pMesh->get_next_polynode(mesh_polynode);
				SPAvector curr_edge(pMesh->get_position(mesh_polynode) - fixed_pos);
				curr_edge *= xform;

				// Compute the area of the parellelogram.
				SPAvector n(prev_edge * curr_edge);
				double mag = n.len();

				// Total the area (negative areas indicated concavity)
				polygon_area += mag;

				// Use this last edge as the first edge of the next triangle.
				prev_edge = curr_edge;
			}
			// Total the areas of all the facets.
			m_facetArea += polygon_area;

			// Get the next facet.
			pMesh->get_next_polygon(mesh_polygon);
		}
	}

	// Currently we have area of paralleograms. The triangles are half of the paralleograms.
	m_facetArea /= 2.0;
	

	// OBJ 파일 출력하는 부분
	FILE * fp;
	fp = fopen(filename, "wt");

	fprintf(fp,"####\n");
	fprintf(fp,"#\n");
	fprintf(fp,"# OBJ File Generated by TransCAD\n");
	fprintf(fp,"#\n");
	fprintf(fp,"####\n");
	fprintf(fp,"# %s\n",filename);
	fprintf(fp,"#\n");
	fprintf(fp,"# Vertices: %d\n",coordInfo.size() - 1);
	fprintf(fp,"# Faces: %d\n",faceInfo.size() - 1);
	fprintf(fp,"#\n");
	fprintf(fp,"####\n");
	
	for (int i = 1; i <= (int)coordInfo.size() - 1; i++)
		fprintf(fp,"v %lf %lf %lf\n", coordInfo[i].x, coordInfo[i].y, coordInfo[i].z);
	
	fprintf(fp,"# %d vertices, 0 vertices normals\n\n",coordInfo.size() - 1);

	for (int i = 1; i <= (int)faceInfo.size() - 1; i++)
		fprintf(fp,"f %d %d %d\n", faceInfo[i].node1, faceInfo[i].node2, faceInfo[i].node3);	
	
	fprintf(fp,"# %d faces, 0 coords texture\n\n",faceInfo.size() - 1);
	fprintf(fp,"# End of File");

	fclose(fp);
}

// PLY 생성 전용 (16-11-28 권순조)
void PmMeshManager::WritePLY(BODY *& pBody, CString filename)
{
	outcome result;
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

	//Error calculation
	m_facetArea = 0;
	m_surfArea = 0;

    // Compute area of surfaces.
    double target_tol = 0.001;
    double real_tol;
    result = api_ent_area(pBody, target_tol, m_surfArea, real_tol);
    check_outcome(result);

	int index = 1;

	for(faces.init(); pFace = (FACE *)(faces.next());)
	{
		MESH * pFaceMesh = NULL;

		af_query((ENTITY *)pFace, IDX_MESH_APP, IDX_MESH_ID, pFaceMesh);
		
		if(pFaceMesh == NULL)
			continue;

		SEQUENTIAL_MESH * pMesh = (SEQUENTIAL_MESH *)pFaceMesh;
		GetMesh(pMesh, xform, coordInfo, faceInfo);

		// For every facet (or polygon) compute the area.
		int polygon_count = pMesh->get_num_polygon();
		MESH_POLYGON mesh_polygon;
		pMesh->get_first_polygon(mesh_polygon);
		
		for (int polygon_index = 0; polygon_index < polygon_count; polygon_index++) 
		{
			int polynode_count = pMesh->get_num_polynode(mesh_polygon);
			double polygon_area = 0;

			// Consider the polygon as a fan of triangles, all sharing one node.
			// Each triangle is formed by one fixed node and two other consecutive nodes.
			// Compute area of each triangle (negative areas indicated concavity).

			// Use the first node as the fixed node.
			MESH_POLYNODE mesh_polynode;
			pMesh->get_first_polynode(mesh_polygon, mesh_polynode);
			const SPAposition & fixed_pos = pMesh->get_position(mesh_polynode);

			// Make the first edge of the first triangle using a vector.
			pMesh->get_next_polynode(mesh_polynode);
			SPAvector prev_edge(pMesh->get_position(mesh_polynode) - fixed_pos);
			prev_edge *= xform;

			// For every remaining node, create triangles and add up the areas.
			for (int polynode_index = 2; polynode_index < polynode_count; polynode_index++) 
			{
				// Make the other edge of the triangle.
				pMesh->get_next_polynode(mesh_polynode);
				SPAvector curr_edge(pMesh->get_position(mesh_polynode) - fixed_pos);
				curr_edge *= xform;

				// Compute the area of the parellelogram.
				SPAvector n(prev_edge * curr_edge);
				double mag = n.len();

				// Total the area (negative areas indicated concavity)
				polygon_area += mag;

				// Use this last edge as the first edge of the next triangle.
				prev_edge = curr_edge;
			}
			// Total the areas of all the facets.
			m_facetArea += polygon_area;

			// Get the next facet.
			pMesh->get_next_polygon(mesh_polygon);
		}
	}

	// Currently we have area of paralleograms. The triangles are half of the paralleograms.
	m_facetArea /= 2.0;
	
	// PLY 파일 출력하는 부분
	FILE * fp;
	fp = fopen(filename, "wt");

	fprintf(fp,"ply\n");
	fprintf(fp,"format ascii 1.0\n");
	fprintf(fp,"comment TransCAD generated\n");
	fprintf(fp,"element vertex %d\n",coordInfo.size() - 1);
	fprintf(fp,"property float x\n");
	fprintf(fp,"property float y\n");
	fprintf(fp,"property float z\n");
	fprintf(fp,"element face %d\n",faceInfo.size() - 1);
	fprintf(fp,"property list uchar int vertex_indices\n");
	fprintf(fp,"end_header\n");
	
	for (int i = 1; i <= (int)coordInfo.size() - 1; i++)
		fprintf(fp,"%lf %lf %lf \n", coordInfo[i].x, coordInfo[i].y, coordInfo[i].z);

	for (int i = 1; i <= (int)faceInfo.size() - 1; i++)
		fprintf(fp,"3 %d %d %d \n", faceInfo[i].node1 - 1, faceInfo[i].node2 - 1, faceInfo[i].node3 - 1);	

	fclose(fp);
}

// X3D 생성 전용 (16-11-25 권순조)
void PmMeshManager::WriteX3D(BODY *& pBody, CString filename)
{
	outcome result;
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

	//Error calculation
	m_facetArea = 0;
	m_surfArea = 0;
    // Compute area of surfaces.
    double target_tol = 0.001;
    double real_tol;
    result = api_ent_area(pBody, target_tol, m_surfArea, real_tol);
    check_outcome(result);
	
	// X3D 파일 열기
	std::ofstream write_x3d;
	write_x3d.open(filename, std::ios::out);
	write_x3d << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	write_x3d << "<!DOCTYPE X3D PUBLIC \"ISO//Web3D//DTD X3D 3.1//EN\" \"http://www.web3d.org/specifications/x3d-3.1.dtd\">\n";
	write_x3d << "<X3D profile='Immersive' xmlns:xsd=\"http://www.w3.org/2001/XMLSchema-instance\" version=\"3.2\" xsd:noNamespaceSchemaLocation=\"http://www.web3d.org/specifications/x3d-3.1.xsd\">\n";	// 2016. 2. 23 Pixel size 수정
	write_x3d << "\t<head>\n";
	write_x3d << "\t\t<meta name=\"title\" content=\"";
	write_x3d << filename;
	write_x3d << "\"/>\n";
	write_x3d << "\t\t<meta name=\"description\" content=\"Generated from TransCAD\"/>\n";
	write_x3d << "\t\t<meta name=\"generator\" content=\"TransCAD\"/>\n";
	write_x3d << "\t</head>\n";
	write_x3d << "\t<Scene>\n";

	int index = 1;

	for(faces.init(); pFace = (FACE *)(faces.next());)
	{
		MESH * pFaceMesh = NULL;

		af_query((ENTITY *)pFace, IDX_MESH_APP, IDX_MESH_ID, pFaceMesh);
		if(pFaceMesh == NULL)
			continue;

		SEQUENTIAL_MESH * pMesh = (SEQUENTIAL_MESH *)pFaceMesh;
		GetMesh(pMesh, xform, coordInfo, faceInfo);

		// For every facet (or polygon) compute the area.
		int polygon_count = pMesh->get_num_polygon();
		MESH_POLYGON mesh_polygon;
		pMesh->get_first_polygon(mesh_polygon);

		for (int polygon_index = 0; polygon_index < polygon_count; polygon_index++) 
		{
			int polynode_count = pMesh->get_num_polynode(mesh_polygon);
			double polygon_area = 0;

			// Consider the polygon as a fan of triangles, all sharing one node.
			// Each triangle is formed by one fixed node and two other consecutive nodes.
			// Compute area of each triangle (negative areas indicated concavity).

			// Use the first node as the fixed node.
			MESH_POLYNODE mesh_polynode;
			pMesh->get_first_polynode(mesh_polygon, mesh_polynode);
			const SPAposition & fixed_pos = pMesh->get_position(mesh_polynode);

			// Make the first edge of the first triangle using a vector.
			pMesh->get_next_polynode(mesh_polynode);
			SPAvector prev_edge(pMesh->get_position(mesh_polynode) - fixed_pos);
			prev_edge *= xform;

			// For every remaining node, create triangles and add up the areas.
			for (int polynode_index = 2; polynode_index < polynode_count; polynode_index++) 
			{
				// Make the other edge of the triangle.
				pMesh->get_next_polynode(mesh_polynode);
				SPAvector curr_edge(pMesh->get_position(mesh_polynode) - fixed_pos);
				curr_edge *= xform;

				// Compute the area of the parellelogram.
				SPAvector n(prev_edge * curr_edge);
				double mag = n.len();

				// Total the area (negative areas indicated concavity)
				polygon_area += mag;

				// Use this last edge as the first edge of the next triangle.
				prev_edge = curr_edge;
			}
			// Total the areas of all the facets.
			m_facetArea += polygon_area;

			// Get the next facet.
			pMesh->get_next_polygon(mesh_polygon);
		}

		CoordInfo coordInfo1;
		FaceInfo faceInfo1;

		coordInfo1.push_back(tempCoord);
		faceInfo1.push_back(tempFace);
		GetMesh(pMesh, xform, coordInfo1, faceInfo1);

		// Face 별로 X3D Shape 노드를 구성하고,
		// 하위 Material 노드에 Persistent naming을 id로 붙임 (16-10-10 권순조)
		write_x3d << "\t\t<Shape>\n";
		write_x3d << "\t\t\t<Appearance>\n";
		write_x3d << "\t\t\t\t<Material id='";
		
		CString faceName;
		PmePersistentNameAPI::FindFaceName(pFace, faceName);

		write_x3d << faceName << "' diffuseColor = '0.75 0.75 0.75'> </Material>\n";
		write_x3d << "\t\t\t</Appearance>\n";

		/* ----- Write face index in X3DOM file ----- */
		write_x3d << "\t\t\t<IndexedFaceSet coordIndex = '";
		
		for (int i = 1; i <= (int)faceInfo1.size() - 1; ++i)
		{
			write_x3d << faceInfo1[i].node1 - 1<< " ";
			write_x3d << faceInfo1[i].node2 - 1<< " ";
			write_x3d << faceInfo1[i].node3 - 1<< " ";
			write_x3d << "-1 ";		// To generate face. X3D grammer
		}

		write_x3d << "' solid='false' colorVertex='false'>\n";	// 2016. 2. 23 creaseAngle 삭제 --> 가시화 품질 향상

		/* ----- Write vertex in X3DOM file ----- */
		write_x3d << "\t\t\t\t<Coordinate point = '";
	
		for (int i = 1; i <= (int)coordInfo1.size() - 1; ++i)
		{
			write_x3d << coordInfo1[i].x << " ";
			write_x3d << coordInfo1[i].y << " ";
			write_x3d << coordInfo1[i].z << " ";
		}

		write_x3d << "'/>\n";

		/* ----- Close tag ----- */
		write_x3d << "\t\t\t</IndexedFaceSet>\n";
		write_x3d << "\t\t</Shape>\n";
	}

	write_x3d << "\t</Scene>\n";
	write_x3d << "</X3D>\n";
}

// STL 생성 전용 (16-11-25 권순조)
void PmMeshManager::WriteSTL(BODY *& pBody, CString filename)
{
	STL_MESH_MANAGER * MyMeshManager = NULL;

	// Get the previous mesh manager.
	FILE* fp_stl;
	fp_stl = fopen((CStringA)filename, "wt");

	facet_options_precise * fop =new facet_options_precise;
	fop->set_surface_tolerance(-1);
	fop->set_normal_tolerance(1);
	
	// Tell the Faceter to use our STL_MESH_MANAGER.
	MyMeshManager = ACIS_NEW STL_MESH_MANAGER();
	outcome result = api_set_mesh_manager(MyMeshManager);
	MyMeshManager->set_output_file(fp_stl);
	check_outcome(result);

	result = api_facet_entity(pBody);
	check_outcome(result);

	delete MyMeshManager;

	fclose(fp_stl);
}

// VRML 생성 전용 (16-11-29 권순조)
void PmMeshManager::WriteVRML(BODY *& pBody, CString filename)
{
	outcome result;
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

	//Error calculation
	m_facetArea = 0;
	m_surfArea = 0;

    // Compute area of surfaces.
    double target_tol = 0.001;
    double real_tol;
    result = api_ent_area(pBody, target_tol, m_surfArea, real_tol);
    check_outcome(result);

	int index = 1;

	for(faces.init(); pFace = (FACE *)(faces.next());)
	{
		MESH * pFaceMesh = NULL;

		af_query((ENTITY *)pFace, IDX_MESH_APP, IDX_MESH_ID, pFaceMesh);
		
		if(pFaceMesh == NULL)
			continue;

		SEQUENTIAL_MESH * pMesh = (SEQUENTIAL_MESH *)pFaceMesh;
		GetMesh(pMesh, xform, coordInfo, faceInfo);

		// For every facet (or polygon) compute the area.
		int polygon_count = pMesh->get_num_polygon();
		MESH_POLYGON mesh_polygon;
		pMesh->get_first_polygon(mesh_polygon);
		
		for (int polygon_index = 0; polygon_index < polygon_count; polygon_index++) 
		{
			int polynode_count = pMesh->get_num_polynode(mesh_polygon);
			double polygon_area = 0;

			// Consider the polygon as a fan of triangles, all sharing one node.
			// Each triangle is formed by one fixed node and two other consecutive nodes.
			// Compute area of each triangle (negative areas indicated concavity).

			// Use the first node as the fixed node.
			MESH_POLYNODE mesh_polynode;
			pMesh->get_first_polynode(mesh_polygon, mesh_polynode);
			const SPAposition & fixed_pos = pMesh->get_position(mesh_polynode);

			// Make the first edge of the first triangle using a vector.
			pMesh->get_next_polynode(mesh_polynode);
			SPAvector prev_edge(pMesh->get_position(mesh_polynode) - fixed_pos);
			prev_edge *= xform;

			// For every remaining node, create triangles and add up the areas.
			for (int polynode_index = 2; polynode_index < polynode_count; polynode_index++) 
			{
				// Make the other edge of the triangle.
				pMesh->get_next_polynode(mesh_polynode);
				SPAvector curr_edge(pMesh->get_position(mesh_polynode) - fixed_pos);
				curr_edge *= xform;

				// Compute the area of the parellelogram.
				SPAvector n(prev_edge * curr_edge);
				double mag = n.len();

				// Total the area (negative areas indicated concavity)
				polygon_area += mag;

				// Use this last edge as the first edge of the next triangle.
				prev_edge = curr_edge;
			}
			// Total the areas of all the facets.
			m_facetArea += polygon_area;

			// Get the next facet.
			pMesh->get_next_polygon(mesh_polygon);
		}
	}

	// Currently we have area of paralleograms. The triangles are half of the paralleograms.
	m_facetArea /= 2.0;
	
	// VRML 파일 출력하는 부분
	FILE * fp;
	fp = fopen(filename, "wt");

	fprintf(fp,"#VRML V2.0 utf8\n");
	fprintf(fp,"\n");
	fprintf(fp,"# Generated by TransCAD, (C)Copyright 2004-2016, KAIST\n");
	fprintf(fp,"\n");
	fprintf(fp,"NavigationInfo {\n");
	fprintf(fp,"	type [ \"EXAMINE\", \"ANY\" ]\n");
	fprintf(fp,"}\n");
	fprintf(fp,"Transform {\n");
	fprintf(fp,"	scale 1 1 1\n");
	fprintf(fp,"	translation 0 0 0\n");
	fprintf(fp,"	children [\n");
	fprintf(fp,"Shape {\n");
	fprintf(fp,"geometry IndexedFaceSet {\n");
	fprintf(fp,"solid FALSE\n");
	fprintf(fp,"coord Coordinate {\n");
	fprintf(fp,"	point	[\n		");
	
	int coordCount = 0;
	for (int i = 1; i <= (int)coordInfo.size() - 1; i++)
	{
		coordCount++;
		
		if (i == (int)coordInfo.size() - 1)
			fprintf(fp," %lf %lf %lf,\n", coordInfo[i].x, coordInfo[i].y, coordInfo[i].z);
		else if (coordCount == 4)
		{
			fprintf(fp," %lf %lf %lf,\n		", coordInfo[i].x, coordInfo[i].y, coordInfo[i].z);
			coordCount = 0;
		}
		else if (coordCount < 4)
			fprintf(fp," %lf %lf %lf,", coordInfo[i].x, coordInfo[i].y, coordInfo[i].z);

	}

	fprintf(fp,"		]\n");
	fprintf(fp,"	}\n");
	fprintf(fp,"coordIndex [\n		");

	int faceCount = 0;
	for (int i = 1; i <= (int)faceInfo.size() - 1; i++)
	{
		faceCount++;
		
		if (i == (int)faceInfo.size() - 1)
			fprintf(fp," %d,%d,%d,-1\n", faceInfo[i].node1 - 1, faceInfo[i].node2 - 1, faceInfo[i].node3 - 1);
		else if (faceCount == 6)
		{
			fprintf(fp," %d,%d,%d,-1\n		", faceInfo[i].node1 - 1, faceInfo[i].node2 - 1, faceInfo[i].node3 - 1);
			faceCount = 0;
		}
		else if (faceCount < 6)
			fprintf(fp," %d,%d,%d,-1", faceInfo[i].node1 - 1, faceInfo[i].node2 - 1, faceInfo[i].node3 - 1);
	}

	fprintf(fp,"		]\n");
	fprintf(fp,"}\n");
	fprintf(fp,"appearance Appearance {\n");
	fprintf(fp,"	material Material {\n");
	fprintf(fp,"		diffuseColor 0.9 0.9 0.9\n");
	fprintf(fp,"	}\n");
	
	fprintf(fp,"}\n");
	fprintf(fp,"}\n");
	fprintf(fp,"	]\n");
	fprintf(fp,"}\n");

	fclose(fp);
}


void PmMeshManager::GetMesh(SEQUENTIAL_MESH * pMesh, SPAtransf xform, CoordInfo & coordInfo, FaceInfo & faceInfo)
{
	int nPolygon = pMesh->get_num_polygon();
    MESH_POLYGON meshPolygon;
    pMesh->get_first_polygon(meshPolygon);
	
	for(int i = 0; i < nPolygon; ++i)
	{	
		int nNode = pMesh->get_num_polynode(meshPolygon);
		
		MESH_POLYNODE node;
		pMesh->get_first_polynode(meshPolygon, node);

		Face face;

		int * pNode = &face.node1;

		for(int j = 0; j < nNode; ++j)
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

void PmMeshManager::GenerateRenderingData()
{
	char bufferstr[200];
	FILE * fp;
	/*fp = fopen("C:\\Part.2.obj", "rt");
	if (fp == NULL)*/
	fp = fopen("D:\\Part.1.obj", "rt");
		
	//get point and face counts
	m_ptsCount = 0;
	for (int i=1; i<=15; i++)
		fscanf(fp, "%s", bufferstr);
	fscanf(fp, "%d", &m_ptsCount);

	m_faceCount = 0;
	for (int i=1; i<=2; i++)
		fscanf(fp, "%s", bufferstr);
	fscanf(fp, "%d", &m_faceCount);

	for (int i=1; i<=2; i++)
		fscanf(fp, "%s", bufferstr);

	//read all points
	m_pts = new Point[m_ptsCount + 1];
	m_pts[0].x = 0.0;
	m_pts[0].y = 0.0;
	m_pts[0].z = 0.0;
	for(int i = 1; i <= m_ptsCount; i ++)
		fscanf(fp, "%s %f %f %f", bufferstr, &(m_pts[i].x), &(m_pts[i].y), &(m_pts[i].z));
	
	for (int i=1; i<=6; i++)
		fscanf(fp, "%s", bufferstr);

	//read all faces
	m_facelist = new int[m_faceCount*4];

	int * curFace = &m_facelist[0];
	int v1, v2, v3;
	for(int i = 0; i < m_faceCount; i ++)
	{
		fscanf(fp, "%s %d %d %d", bufferstr, &v1, &v2, &v3);
			
		*curFace = 3;
		curFace ++;
		*curFace = v1;
		curFace ++;
		*curFace = v2;
		curFace ++;
		*curFace = v3;
		curFace ++;
	}		

	fclose(fp);
}

void PmMeshManager::Render()
{
	GenerateRenderingData();
	HC_Open_Segment("Mesh");
		HC_Insert_Shell_By_Ref(m_ptsCount + 1, m_pts, m_faceCount * 4, m_facelist);
		HC_Set_Visibility("edges=(on, perimeters=on), faces=on");  
		HC_Set_Rendering_Options("no lighting interpolation");
	HC_Close_Segment();
}