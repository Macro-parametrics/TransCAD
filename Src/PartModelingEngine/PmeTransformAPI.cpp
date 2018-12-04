#include "stdafx.h"
#include ".\PmeTransformAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeSolid.h"
#include ".\PmeExplicitModel.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"
#include ".\PmeAssemblyAPI.h"
#include ".\PmeComponentAPI.h"
#include ".\PmeComponent.h"

#include "math.h"

// void PmeTransformAPI::Rotate
// 	( 
// 		PmeHAssembly hPmeAssembly,
// 		PmeHComponent &hComponent, 
// 		float x, float y, float z, 
// 		float radianAngle 
// 	)
// {
// 	
// 	PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
// 
// 	PmeComponent * pComp = PME_HANDLE2COMPONENT(hComponent);
// 		
// 
// 	MrAxis2 placement = pComp->GetPlacement();
// 	MrPosition org = pComp->GetPlacement().Location();
// 
// 	MrTransformation preTransf = CalcModelingMatrix(hComponent);
// 
// 	MrPosition objPos = preTransf.Transform(MrPosition(x,y,z));
// 
// 	//placement = Rotate(preTransf, placement);
// 	
// 	
// // 	PmeComponent* parent = NULL; 
// // 
// // 	parent = (PmeComponent*)pComp->GetParent();
// // 	
// // 	MrVector preTranslateVec;
// // 	MrVector postTranslateVec;
// // 	if(parent)
// // 	{
// // 		preTranslateVec= MrVector (placement.Location(),parent->GetPlacement().Location());
// // 	}
// // 	else
// // 	{
// // 		preTranslateVec=  MrVector (placement.Location(),MrPosition(0,0,0));
// // 	}
// // 	MrTransformation preTranslate = MrTransformation::CreateTranslation(preTranslateVec);
// // 	placement = Translate(preTranslate, placement);
// 
// 	placement.SetLocation(MrPosition(0,0,0));
// 
// 	MrTransformation transf = MrTransformation::CreateRotation(MrAxis1(MrPosition(0,0,0),MrDirection(x,y,z)),radianAngle);
// 		
// 	placement = MrMath::Transform(placement,transf);
// 
// 	placement.SetLocation(org);
// // 	if(parent)
// // 	{
// // 		postTranslateVec = MrVector(parent->GetPlacement().Location(),org);
// // 	}
// // 	else
// // 	{
// // 		postTranslateVec = MrVector(MrPosition(0,0,0),org);
// // 
// // 	}
// // 
// // 	MrTransformation postTranslate = MrTransformation::CreateTranslation(postTranslateVec);
// 
// 	//newCoordSys = Translate(postTranslate, newCoordSys);
// 
// // 	MrTransformation postTransf = CalcModelingMatrix(hComponent,TRUE);
// // 
// // 	placement = Transform(postTransf, placement);
// 		
// 	pComp->SetPlacement(placement);
// 	
// 	PME_UPDATE_COMPONENT(hPmeAssembly, hComponent, PmeUpdateState_Update); 
// 
// }
// 
// void PmeTransformAPI::Rotate2
// 	( 
// 		PmeHAssembly hPmeAssembly,
// 		PmeHComponent &hComponent, 
// 		float x, float y, float z, 
// 		float radianAngle 
// 	)
// {
// 	
// 	PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
// 
// 	PmeComponent * pComp = PME_HANDLE2COMPONENT(hComponent);
// 		
// 
// 	MrAxis2 placement = pComp->GetPlacement();
// 	MrPosition org = pComp->GetPlacement().Location();
// 
// 	MrTransformation preTransf = CalcModelingMatrix(hComponent);
// 
// 	MrPosition p = preTransf.Transform(MrPosition(x,y,z));
// 
// 	placement.SetLocation(MrPosition(0,0,0));
// 
// 	MrTransformation transf = MrTransformation::CreateRotation(MrAxis1(MrPosition(0,0,0),MrDirection(p.X(),p.Y(),p.Z())),radianAngle);
// 		
// 	placement = MrMath::Transform(placement,transf);
// 
// 	placement.SetLocation(org);
// 
// // 	if(parent)
// // 	{
// // 		postTranslateVec = MrVector(parent->GetPlacement().Location(),org);
// // 	}
// // 	else
// // 	{
// // 		postTranslateVec = MrVector(MrPosition(0,0,0),org);
// // 
// // 	}
// // 
// // 	MrTransformation postTranslate = MrTransformation::CreateTranslation(postTranslateVec);
// 
// 	//newCoordSys = Translate(postTranslate, newCoordSys);
// 
// // 	MrTransformation postTransf = CalcModelingMatrix(hComponent,TRUE);
// // 
// // 	placement = Transform(postTransf, placement);
// 		
// 	pComp->SetPlacement(placement);
// 	
// 	PME_UPDATE_COMPONENT(hPmeAssembly, hComponent, PmeUpdateState_Update); 
// 
// }

void PmeTransformAPI::Rotate
	( 
		PmeHAssembly hPmeAssembly,
		PmeHComponent &hComponent, 
		double x, double y, double z, 
		float radianAngle 
	)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
	PmeComponent * pComp = PME_HANDLE2COMPONENT(hComponent);

	MrAxis2 placement = pComp->GetPlacement();
	MrDirection dir(x,y,z);

	MrTransformation rt1 = CalcModelingMatrix(hComponent,0);
	MrTransformation rt2 = MrMath::Inverse(rt1);

	TRACE("\nR axis  point : %f, %f, %f",dir.X(),dir.Y(),dir.Z());

	placement = MrMath::Transform(placement,rt2);

	MrTransformation transf = MrTransformation::CreateRotation(MrAxis1(MrPosition::O(),dir),radianAngle);

	placement = MrMath::Transform(placement,transf);	
	placement = MrMath::Transform(placement,rt1);

	pComp->SetPlacement(placement);


	PME_UPDATE_COMPONENT(hPmeAssembly, hComponent, PmeUpdateState_Update); 
}

void PmeTransformAPI::Translate
(
	 PmeHAssembly hPmeAssembly,
	 PmeHComponent& hComponent,
		float dx,
		float dy,
		float dz

 )
{
PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
	PmeComponent * pComp = PME_HANDLE2COMPONENT(hComponent);

	MrAxis2 placement = pComp->GetPlacement();
	MrDirection dir(dx,dy,dz);

	MrTransformation rt1 = CalcModelingMatrix(hComponent,0);
	MrTransformation rt2 = MrMath::Inverse(rt1);

	TRACE("\nR axis  point : %f, %f, %f",dir.X(),dir.Y(),dir.Z());

	//placement = MrMath::Transform(placement,rt2);


	dir = MrMath::Transform(dir,rt1);
		

	MrTransformation transf = MrTransformation::CreateTranslation(dir);

	transf.SetTranslation(MrVector(dir.X()*fabsf(dx+dy+dz),dir.Y()*fabsf(dx+dy+dz),dir.Z()*fabsf(dx+dy+dz)));


	placement = MrMath::Transform(placement,transf);	
	//placement = MrMath::Transform(placement,rt1);

	pComp->SetPlacement(placement);


	PME_UPDATE_COMPONENT(hPmeAssembly, hComponent, PmeUpdateState_Update); 
}

MrTransformation PmeTransformAPI::CalcModelingMatrix( PmeHComponent hComponent, BOOL UpToParent )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
	PmeComponent * pComp = PME_HANDLE2COMPONENT(hComponent);

	MrAxis2 placement = pComp->GetPlacement();

	PmeHComponent hParent;
	PmeComponentAPI::GetParentComp(hComponent, hParent);
		
	MrTransformation mrTrsf = MrTransformation::CreateCoordinateSystemTransformation(placement, MrAxis2::OXY());

	if(hParent && UpToParent)
	{
		MrTransformation pTransf = CalcModelingMatrix(hParent);
		mrTrsf = pTransf * mrTrsf;
	}
		
	return mrTrsf;
}

/*
MrTransformation PmeTransformAPI::CalcModelingMatrix2( PmeHPart hPart, BOOL UpToParent )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	MrAxis2 placement = pPart->GetPlacement();

	PmeHComponent hParent;
	PmeComponentAPI::GetParentComp(hComponent, hParent);
		
	MrTransformation mrTrsf = MrTransformation::CreateCoordinateSystemTransformation(placement, MrAxis2::OXY());

	if(hParent && UpToParent)
	{
		MrTransformation pTransf = CalcModelingMatrix(hParent);
		mrTrsf = pTransf * mrTrsf;
	}
		
	return mrTrsf;
}
*/