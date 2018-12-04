#include "StdAfx.h"
#include ".\PmImUtility.h"
#include <math.h>

void PmImUtility::RegisterCallbacks()
{
	HImRegisterCallback("PmImUtility_DatumPlaneCallback", DatumPlaneCallback);
}

void PmImUtility::ScaleIndependentSegment(HIC_Rendition * nr, HIC_Segment_Info * si, float scale)
{
	HBaseView * pView = (HBaseView *)HIC_Show_User_Index(nr, H_HBASEVIEW_POINTER_MAGIC);
	HC_KEY hSegmentKey = HIC_Show_Segment_Key(si);
	HC_Open_Segment_By_Key(hSegmentKey);
		HPoint p1, p2;
		
		HC_KEY hKeys[MVO_BUFFER_SIZE];
		int kcount = HUtility::CalculateKeyPath(hSegmentKey, pView, hKeys, MVO_BUFFER_SIZE);
	 	
		HC_Compute_Coordinates_By_Path(kcount, hKeys, "local pixels", &HPoint(0, 0, 0), "world", &p1);
		HC_Compute_Coordinates_By_Path(kcount, hKeys, "local pixels", &HPoint(scale, 0, 0), "world", &p2);

		HPoint dt;
		dt.Set(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
		float vl = (float)HC_Compute_Vector_Length(&dt);

		float matrix1[16], matrix2[16], matrix3[16], matrixt[16], netmatrix[16];

		HC_Show_Net_Modelling_Matrix(netmatrix);
		float s2 = netmatrix[0] * netmatrix[0] + netmatrix[4] * netmatrix[4] + netmatrix[8] * netmatrix[8];
		float s = sqrt(s2);

		HC_Compute_Scale_Matrix(vl, vl, vl, matrix3);
		HC_Compute_Scale_Matrix(1.0 / s, 1.0 / s, 1.0 / s, matrix1);
		HC_Compute_Matrix_Product(netmatrix, matrix1, matrix2);
		HC_Compute_Matrix_Product(matrix2, matrix3, matrixt);
		
		HC_Set_Modelling_Matrix(matrixt);
		HIC_Draw_Segment(nr, si);
	HC_Close_Segment();
}

void PmImUtility::DatumPlaneCallback(HIC_Rendition * nr, HIC_Segment_Info * si)
{
	ScaleIndependentSegment(nr, si, 30.0);
}