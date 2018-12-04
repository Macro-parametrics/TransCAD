#include "stdafx.h"
#include "Part.h"

#include "Feature.h"
#include "FeatureSketch.h"
#include "FeatureExtrude.h"
#include "FeatureSweep.h"
#include "FeatureRevolve.h"
#include "FeatureFillet.h"
#include "FeatureChamfer.h"
#include "FeatureDatumPlaneOffset.h"
#include "FeatureDatumPlaneEquation.h"
#include "FeaturePatternRectangular.h"
#include "FeaturePatternCircular.h"
#include "FeatureHole.h"
#include "FeatureLoft.h"
#include "FeatureShell.h"
#include "FeatureDraft.h"
#include "FeatureOffset.h"
#include "FeatureBrep.h"

#include "Reference.h"
#include "ReferenceBrep.h"
#include "ReferenceExplicitModelObject.h"
#include "ReferenceFeature.h"

#include "SketchItem.h"
#include "SketchItemCircle.h"
#include "SketchItemArc.h"
#include "SketchItemLine.h"
#include "SketchItemCenterLine.h"
#include "SketchItemPolyLine.h"
#include "SketchItemRectangle.h"
#include "SketchItemFillet.h"
#include "SketchItemChamfer.h"
#include "SketchItemExtendLines.h"
#include "SketchItemPolygon.h"
#include "SketchItemTranslate.h"
#include "SketchItemRotate.h"

#include "Manipulation.h"

#include "CustomFeature.h"

Part::Part(void)
{
	SetDocsPtr(m_spApplication->GetDocuments());

	// 활성 문서가 있는 경우 대입. 아닌 경우 새로 생성
	if (m_spApplication->GetActiveDocument())
		SetPartDocumentPtr(m_spApplication->GetActiveDocument());
	else
		SetPartDocumentPtr(GetDocsPtr()->AddPartDocument());
	
	SetPartPtr(GetPartDocumentPtr()->GetPart());			// Set TransCAD PartPtr
	SetFeaturesPtr(GetPartPtr()->GetFeatures());			// Set TransCAD FeaturesPtr
	m_initialTitle = _bstr_t(GetPartDocumentPtr()->GetTitle());		// 문서의 타이틀 저장
	
	//ReadCustomFeatures();

	System::Reset(this);
	SetCurrentSketch(NULL);
	SetCurrentReference(NULL);
	SetCurrentFeature(NULL);
}

Part::~Part(void)
{
	CMD::SetTitle(TEXT("Good bye!"), 0);
	
	// Clear features
	m_currentState = 0;
	Clear();

	System::UninitTransCAD(this);
}

// 현재 특징형상 목록 및 전체 특징형상 이력 제거
void Part::Clear(void)
{
	// 현재 특징형상 목록 제거
	ClearList(m_featureList);
	
	// 전체 특징형상 이력 제거
	if (GetCurrentState() == 0)
		ClearList(m_allFeatureList);
}

// 특징형상 생성, 수정, 제거 시 호출되는 함수. 각 상태에서 Undo와 Redo를 체크하기 위해 활용
void Part::CheckCurrentState(void)
{
	// 현재 상태 갱신
	m_currentState = GetHistoryFeatureListSize() - m_undoCount + m_redoCount;
	
	// Undo, Redo를 거쳐 가장 최근보다 이전 상태에서 특징형상의 생성, 수정, 삭제가 이루어지는 경우 이 후의 이력을 모두 제거
	// 새로운 특징형상을 목록에 추가 하기 전에 호출되어야 함
	if ((m_updateCount != 0)
		&& (m_currentState < GetHistoryFeatureListSize()))
	{
		m_undoCount = 0;
		m_redoCount = 0;
		
		// Initial 상태 이후의 이력을 모두 삭제
		for (int i = GetHistoryFeatureListSize() - 1; i > m_currentState - 1; --i)
		{
			EraseHistoryFeature(i);
			m_updateCount--;
		}
	}

	m_updateCount++;
}


// 모든 명령어를 수행하는 함수
void Part::RunCommands(char * command)
{
	try
	{
		TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "No command!");

		System::Renew(this); // 매 입력마다 최신 TransCAD 정보로 갱신

		CMD::SetColor(D_BLUE, YELLOW);

		if ((fType = Commands.GetFeatureType(token)) != NoFeature)			// 특징형상을 생성하는 부분
			RunFeatureCommand(fType, command);
		else if ((rType = Commands.GetReferenceType(token)) != NoReference)	// 레퍼런스를 생성(선택)하는 부분
			RunReferenceCommand(rType, command);
		else if ((gType = Commands.GetCommandType(token)) != NoCommand)		// 기타 명령어를 수행하는 부분
			RunGeneralCommand(gType, command);
		else if (GetCustomFeatureByName(token))								// 커스텀 피쳐를 수행하는 부분
			GetCustomFeatureByName(token)->Run(command);
		else if (token != "exit" && token != "종료")
			cout << "Invalid command!" << endl;
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
	}
}

// 특징형상 생성 명령어 수행
void Part::RunFeatureCommand(FeatureType type, char * command)
{
	Feature * pFeature = 0;
	
	switch(type)
	{
		case Sketch_Type:
			pFeature = new FeatureSketch(this, 0);
			break;
		case ProExtrude_Type:
			pFeature = new FeatureExtrude(this, 1);
			break;
		case CutExtrude_Type:
			pFeature = new FeatureExtrude(this, 2);
			break;
		case Fillet_Type:
			pFeature = new FeatureFillet(this, 3);
			break;
		case ProSweep_Type:
			pFeature = new FeatureSweep(this, 4);
			break;
		case CutSweep_Type:
			pFeature = new FeatureSweep(this, 5);
			break;
		case Chamfer_Type:
			pFeature = new FeatureChamfer(this, 6);
			break;
		case ProRevolve_Type:
			pFeature = new FeatureRevolve(this, 7);
			break;
		case CutRevolve_Type:
			pFeature = new FeatureRevolve(this, 8);
			break;
		case RevolveWithAxis_Type:
			pFeature = new FeatureRevolve(this, 9);
			break;
		case DatumPlaneOffset_Type:
			pFeature = new FeatureDatumPlaneOffset(this, 10);
			break;
		case PatternRectangular_Type:
			pFeature = new FeaturePatternRectangular(this, 11);
			break;
		case PatternCircular_Type:
			pFeature = new FeaturePatternCircular(this, 12);
			break;
		case HoleCounterbored_Type:
			pFeature = new FeatureHole(this, 13);
			break;
		case HoleCountersunk_Type:
			pFeature = new FeatureHole(this, 14);
			break;
		case HoleSimple_Type:
			pFeature = new FeatureHole(this, 15);
			break;
		case Shell_Type:
			pFeature = new FeatureShell(this, 16);
			break;
		case Loft_Type:
			pFeature = new FeatureLoft(this, 17);
			break;
		case Draft_Type:
			pFeature = new FeatureDraft(this, 18);
			break;
		case Offset_Type:
			pFeature = new FeatureOffset(this, 19);
			break;
		case BrepSolid_Type:
			pFeature = new FeatureBrep(this, 20);
			break;
		case DatumPlaneEquation_Type:
			pFeature = new FeatureDatumPlaneEquation(this, 21);
			break;
	}

	if (pFeature)
	{
		try
		{
			pFeature->GetInfo(command);
			pFeature->SetOrder(GetFeatureListSize());
			SetFeature(pFeature);
			
			CheckCurrentState();

			if(!GetCurrentSketch())
				SetHistoryFeature(CopyFeature(pFeature));
		}
		catch (TSIArgumentException & e)
		{
			cout << e.GetMessageW() << endl;
			delete pFeature;
		}
	}
}

// 레퍼런스 선택 명령어 수행. CurrentReference(s)에 저장 됨
void Part::RunReferenceCommand(ReferenceType type, char * command)
{
	Reference * pReference = 0;
	Feature * pFeature = new Feature(this, 0); // 임시 특징형상

	switch(type)
	{
		case Plane_Type:
			pReference = new ReferenceExplicitModelObject(pFeature, 0);
			break;
		case Brep_Type:
			pReference = new ReferenceBrep(pFeature, 1);
			break;
		case Breps_Type:
			pReference = new ReferenceBrep(pFeature, 2);
			break;
		case FaceByAxis_Type:
			pReference = new ReferenceBrep(pFeature, 3);
			break;
		case EdgeByPoint_Type:
			pReference = new ReferenceBrep(pFeature, 4);
			break;
		case EdgeByPoints_Type:
			pReference = new ReferenceBrep(pFeature, 5);
			break;
		case Feature_Type:
			pReference = new ReferenceFeature(pFeature, 6);
			break;
		case Features_Type:
			pReference = new ReferenceFeature(pFeature, 7);
			break;
	}

	if (pReference)
	{
		try
		{
			pReference->GetInfo(command);
		}
		catch (TSIArgumentException & e)
		{
			cout << e.GetMessageW() << endl;
		}
	}

	if (!GetCurrentReference() && !GetCurrentFeature())
	{
		delete pReference;
		delete pFeature;
	}
}

// 기타 명령어를 수행
void Part::RunGeneralCommand(GeneralType type, char * command)
{
	switch(type)
	{
		case NewPartDoc_Type:
			System::InitTransCAD(this);
			break;
		case Terminate_Type:
			System::TerminateTransCAD(this);
			break;
		case Restore_Type:
			System::RestoreSession(this);
			break;
		case Reset_Type:
			System::Reset(this);
			break;
		case Clear_Type:
			CMD::Clear();
			break;
		case Modify_Type:
			Manipulation::Modify(command, this);
			break;
		case Delete_Type:
			Manipulation::Delete(command, this);
			break;
		case Undo_Type:
			Manipulation::UndoFeature(this);
			break;
		case Redo_Type:
			Manipulation::RedoFeature(this);
			break;
		case Import_Type:
			File::Import(command, this);
			break;
		case Export_Type:
			File::Export(command, this);
			break;
		case ConvertMesh_Type:
			File::ConvertMesh(command, this);
			break;
		case Ask_Type:
			Information::Ask(command, this);
			break;
		case Parent_Type:
			Information::Parent(command, this);
			break;
		case Children_Type:
			Information::Children(command, this);
			break;
		case Highlight_Type:
			Information::Highlight(command, this);
			break;
		case Help_Type:
			Help(command);
			break;
		case CustomFeature_Type:
			CreateCustomFeature(command);
			break;
	}
}


// 스케치가 생성 중일 때, 스케치 요소 생성/수정/제거 등 명령어 수행
void Part::OnCreatingSketch(char * command)
{
	token = command;
	
	// 스케치 명령어 수행
	GetCurrentSketch()->RunCommands(command);
	
	try
	{
		if (token == "closesketch" || token == "스케치종료")
		{
			CMD::SetColor(D_BLUE, YELLOW);
			
			// 스케치 Closeness 체크
			GetCurrentSketch()->CheckCloseness();

			if (GetCurrentSketch()->GetCloseness() == 0)
				cout << "WARNING: " << GetCurrentSketch()->GetName() << " is neither connected nor closed." << endl;

			// 스케치 요소가 0개인 경우
			if (GetCurrentSketch()->GetSketchItemListSize() == 0)
			{
				GetFeaturesPtr()->DeleteByName(GetCurrentSketch()->GetName().c_str());
				GetPartDocumentPtr()->Update();
			}

			// Operation을 한 번도 수행하지 않았거나, 스케치 요소가 0개일 때 예외
			TSIThrowExceptionIf<TSIArgumentException>(GetCurrentSketch()->GetUpdateCount() == 0, "No operation has been done!");
			
			// 스케치 저장
			SetHistoryFeature(CopyFeature(GetCurrentSketch()));
			
			TSIThrowExceptionIf<TSIArgumentException>(GetCurrentSketch()->GetSketchItemListSize() == 0, "Sketch is empty!");

			// 스케치를 수정한 경우 재생성
			if(GetCurrentSketch()->IsModified())
				Manipulation::RegenerateFeature(GetCurrentSketch()->GetOriginalOrder(), m_currentState, 0, this);

			SetCurrentSketch(NULL);
		}
	}
	catch (TSIArgumentException & e) // 스케치가 비었거나 아무 작업도 일어나지 않았을 때 진입
	{
		CMD::SetColor(D_BLUE, YELLOW);
		cout << e.GetMessageW() << endl;
		
		// 아무 작업도 일어나지 않았을 때
		if (GetCurrentSketch()->GetUpdateCount() == 0)
			m_updateCount--;
		
		Manipulation::RegenerateFeature(GetCurrentSketch()->GetOriginalOrder(), m_currentState - 1, 0, this);

		SetCurrentSketch(NULL);
	}
}

// 다 수의 레퍼런스를 선택 중일 때, 레퍼런스 선택 명령어 수행
void Part::OnSelectingReferences(char * command)
{
	token = command;

	// 레퍼런스 선택 명령어 수행
	GetCurrentReference()->RunCommands(command);
	
	try
	{
		if (token == "취소" || token == "cancel")
		{
			CMD::SetColor(D_BLUE, YELLOW);
			SetCurrentReferencesPtr(NULL);
		
			SetCurrentReference(NULL);
			TSIThrowExceptionIf<TSIArgumentException>(token == "취소" || token == "cancel", "Nothing is selected!");
		}
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
	}
}

// 다 수의 특징형상을 선택 중일 때, 특징형상 선택 명령어 수행
void Part::OnSelectingFeatures(char * command)
{
	token = command;

	// 레퍼런스 선택 명령어 수행
	GetCurrentFeature()->RunCommands(command);
	
	try
	{
		if (token == "취소" || token == "cancel")
		{
			CMD::SetColor(D_BLUE, YELLOW);
			SetCurrentReferencesPtr(NULL);
		
			SetCurrentFeature(NULL);
			TSIThrowExceptionIf<TSIArgumentException>(token == "취소" || token == "cancel", "Nothing is selected!");
		}
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
	}
}


// TransCAD 모델 정보를 추출하여 저장하는 함수. Reset 함수에서 호출
void Part::AddInfo(void)
{
	if (m_updateCount != 0)
		return;
	
	Clear();

	// 최신 TransCAD 정보 추가
	for (int i = 1; i <= GetFeaturesPtr()->GetCount(); ++i)
	{
		CMD::SetTitle(TEXT("Loading current features"), i);
		
		AddFeature(GetFeaturesPtr()->GetItem(i));
	}

	// Operation(생성, 수정, 삭제)이 발생하기 직전까지의 특징형상 목록을 저장/갱신
	// Operation이 발생하는 순간, 이전에 저장된 목록이 초기 목록이 된다.
	for (int i = 0; i < GetFeatureListSize(); ++i)
	{
		CMD::SetTitle(TEXT("Loading current features"), i);
		
		Feature * pFeature = CopyFeature(GetFeature(i));
		SetHistoryFeature(pFeature);
	}

	m_initialState = GetHistoryFeatureListSize(); // 초기 상태 저장
	m_currentState = m_initialState;

	CMD::SetTitle(TEXT("TransCAD Script Interface 1.0"), 0);
}

// 특징형상 추가
void Part::AddFeature(TransCAD::IFeaturePtr spFeature)
{
	Feature * pFeature = 0;
	
	switch(spFeature->Type)
	{
		case TransCAD::StdSketchFeature:
			pFeature = new FeatureSketch(this, 0);
			break;
		case TransCAD::StdSolidProtrusionExtrudeFeature:
			pFeature = new FeatureExtrude(this, 1);
			break;
		case TransCAD::StdSolidCutExtrudeFeature:
			pFeature = new FeatureExtrude(this, 2);
			break;
		case TransCAD::StdSolidFilletConstantFeature:
			pFeature = new FeatureFillet(this, 3);
			break;
		case TransCAD::StdSolidProtrusionSweepFeature:
			pFeature = new FeatureSweep(this, 4);
			break;
		case TransCAD::StdSolidCutSweepFeature:
			pFeature = new FeatureSweep(this, 5);
			break;
		case TransCAD::StdSolidChamferFeature:
			pFeature = new FeatureChamfer(this, 6);
			break;
		case TransCAD::StdSolidProtrusionRevolveFeature:
			pFeature = new FeatureRevolve(this, 7);
			break;
		case TransCAD::StdSolidCutRevolveFeature:
			pFeature = new FeatureRevolve(this, 8);
			break;
		case TransCAD::StdSolidRevolveWithExternalAxisFeature:
			pFeature = new FeatureRevolve(this, 9);
			break;
		case TransCAD::StdDatumPlaneOffsetFeature:
			if (((TransCAD::IStdDatumPlaneOffsetFeaturePtr)spFeature)->GetIsFree() == VARIANT_FALSE) pFeature = new FeatureDatumPlaneOffset(this, 10);
			else pFeature = new FeatureDatumPlaneEquation(this, 21);
			break;
		case TransCAD::StdSolidOperatePatternRectangularFeature:
			pFeature = new FeaturePatternRectangular(this, 11);
			break;
		case TransCAD::StdSolidOperatePatternCircularFeature:
			pFeature = new FeaturePatternCircular(this, 12);
			break;
		case TransCAD::StdSolidHoleCounterboredFeature:
			pFeature = new FeatureHole(this, 13);
			break;
		case TransCAD::StdSolidHoleCountersunkFeature:
			pFeature = new FeatureHole(this, 14);
			break;
		case TransCAD::StdSolidHoleSimpleFeature:
			pFeature = new FeatureHole(this, 15);
			break;
		case TransCAD::StdSolidShellFeature:
			pFeature = new FeatureShell(this, 16);
			break;
		case TransCAD::StdSolidLoftSectionsFeature:
			pFeature = new FeatureLoft(this, 17);
			break;
		case TransCAD::StdSolidDraftFeature:
			pFeature = new FeatureDraft(this, 18);
			break;
		case TransCAD::StdSolidOffsetFeature:
			pFeature = new FeatureOffset(this, 19);
			break;
		case TransCAD::StdSolidImportedBrepFeature:
			pFeature = new FeatureBrep(this, 20);
			break;
	}

	if (pFeature)
	{
		pFeature->AddInfo(spFeature);
		pFeature->SetOrder(GetFeatureListSize());
		SetFeature(pFeature);
	}
}

// 특징형상의 이름으로부터 현재 존재하는 Feature 객체 리턴
Feature * Part::GetFeatureByName(string name)
{
	Feature * pFeature = 0;
	
	for (int i = 0; i < GetFeatureListSize(); ++i)
	{
		if (GetFeature(i)->GetName() == name)
		{
			pFeature = GetFeature(i);
			break;
		}
	}
	
	return pFeature;
}

// 특징형상의 이름으로부터 히스토리에 존재하는 첫 Feature 객체 리턴
Feature * Part::GetHistoryFeatureByName(string name)
{
	Feature * pFeature = 0;
	
	for (int i = 0; i < GetHistoryFeatureListSize(); ++i)
	{
		if (GetHistoryFeature(i)->GetName() == name)
		{
			pFeature = GetHistoryFeature(i);
			break;
		}
	}
	
	return pFeature;
}

// Feature 포인터를 복사하는 함수. 깊은 복사를 위함
Feature * Part::CopyFeature(Feature * pFeature)
{
	Feature * pCopiedFeature = 0;
	
	if (pFeature->GetType() == 0)
		pCopiedFeature = new FeatureSketch(*(FeatureSketch*)pFeature);
	else if (pFeature->GetType() == 1 || pFeature->GetType() == 2)
		pCopiedFeature = new FeatureExtrude(*(FeatureExtrude*)pFeature);
	else if (pFeature->GetType() == 3)
		pCopiedFeature = new FeatureFillet(*(FeatureFillet*)pFeature);
	else if (pFeature->GetType() == 4 || pFeature->GetType() == 5)
		pCopiedFeature = new FeatureSweep(*(FeatureSweep*)pFeature);
	else if (pFeature->GetType() == 6)
		pCopiedFeature = new FeatureChamfer(*(FeatureChamfer*)pFeature);
	else if (pFeature->GetType() == 7 || pFeature->GetType() == 8 || pFeature->GetType() == 9)
		pCopiedFeature = new FeatureRevolve(*(FeatureRevolve*)pFeature);
	else if (pFeature->GetType() == 10)
		pCopiedFeature = new FeatureDatumPlaneOffset(*(FeatureDatumPlaneOffset*)pFeature);
	else if (pFeature->GetType() == 11)
		pCopiedFeature = new FeaturePatternRectangular(*(FeaturePatternRectangular*)pFeature);
	else if (pFeature->GetType() == 12)
		pCopiedFeature = new FeaturePatternCircular(*(FeaturePatternCircular*)pFeature);
	else if (pFeature->GetType() == 13 || pFeature->GetType() == 14 || pFeature->GetType() == 15)
		pCopiedFeature = new FeatureHole(*(FeatureHole*)pFeature);
	else if (pFeature->GetType() == 16)
		pCopiedFeature = new FeatureShell(*(FeatureShell*)pFeature);
	else if (pFeature->GetType() == 17)
		pCopiedFeature = new FeatureLoft(*(FeatureLoft*)pFeature);
	else if (pFeature->GetType() == 18)
		pCopiedFeature = new FeatureDraft(*(FeatureDraft*)pFeature);
	else if (pFeature->GetType() == 19)
		pCopiedFeature = new FeatureOffset(*(FeatureOffset*)pFeature);
	else if (pFeature->GetType() == 20)
		pCopiedFeature = new FeatureBrep(*(FeatureBrep*)pFeature);
	else if (pFeature->GetType() == 21)
		pCopiedFeature = new FeatureDatumPlaneEquation(*(FeatureDatumPlaneEquation*)pFeature);

	return pCopiedFeature;
}


// 명령어에 대한 도움말을 출력하는 함수
void Part::Help(char * command)
{
	CMD::SetColor(D_BLUE, SKYBLUE); // cmd 색상 변경(배경:파랑, 글자:밝은 스카이블루)

	string name;
	
	if ((name = StringToken::GetString( NULL, seps_blank, command )) == "FAIL")
		name = "all";

	if (name == "all")
	{
		cout << "[TransCAD Script Interface Function List]" << endl;
		cout << " Please enter 'help FunctionName (도움말 함수명)' to see the details for each function" << endl;
		cout << "	- Functions for Selection" << endl;
		cout << "		selectplane (평면선택)" << endl;
		cout << "		selectbrep (요소선택)" << endl;
		cout << "		selectbreps (요소들선택)" << endl;
		cout << "		selectfeature (피쳐선택)" << endl;
		cout << "		selectfeatures (피쳐들선택)" << endl;
		cout << "		selectfacebyaxis (면선택)" << endl;
		cout << "		selectedgebypoint (한점모서리선택)" << endl;
		cout << "		selectedgebypoints (세점모서리선택)" << endl;
		cout << "	- Functions for Creating a Feature" << endl;
		cout << "		opensketch (스케치시작)" << endl;
		cout << "		closesketch (스케치종료)" << endl;
		cout << "		createproextrude (돌출)" << endl;
		cout << "		createcutextrude (돌출컷)" << endl;
		cout << "		createprorevolve (회전)" << endl;
		cout << "		createcutrevolve (회전컷)" << endl;
		cout << "		createrevolvewithaxis (축회전)" << endl;
		cout << "		createprosweep (스윕)" << endl;
		cout << "		createcutsweep (스윕컷)" << endl;
		cout << "		createloft (로프트)" << endl;
		cout << "		createfillet (필렛)" << endl;
		cout << "		createchamfer (챔퍼)" << endl;
		cout << "		createshell (쉘)" << endl;
		cout << "		createdraft (구배)" << endl;
		cout << "		createoffset (오프셋)" << endl;
		cout << "		createrectpattern (사각패턴)" << endl;
		cout << "		createcircpattern (원형패턴)" << endl;
		cout << "		createholecounterbored (카운터보어)" << endl;
		cout << "		createholecountersunk (카운터싱크)" << endl;
		cout << "		createholesimple (구멍)" << endl;
		cout << "		createdatumplaneoffset (새평면)" << endl;
		cout << "		createdatumplaneequation (새평면2)" << endl;
		cout << "		importbrep (경계표현입력)" << endl;
		cout << "	- Functions for Creating a Sketch" << endl;
		cout << "		createline (선)" << endl;
		cout << "		createcenterline (중심선)" << endl;
		cout << "		createcircle (원)" << endl;
		cout << "		createarc (호)" << endl;
		cout << "		createpolyline (연결선)" << endl;
		cout << "		createrectangle (사각형)" << endl;
		cout << "		createpolygon (다각형)" << endl;
		cout << "		filletlines (선필렛)" << endl;
		cout << "		chamferlines (선챔퍼)" << endl;
		cout << "		extendlines (선연장)" << endl;
		cout << "		translatesketch (스케치이동)" << endl;
		cout << "		rotatesketch (스케치회전)" << endl;
		cout << "		setcoordinatesystem (좌표계)" << endl;
		cout << "	- Functions for Manipulation" << endl;
		cout << "		modify (수정)" << endl;
		cout << "		delete (제거)" << endl;
		cout << "		undo (뒤로)" << endl;
		cout << "		redo (앞으로)" << endl;
		cout << "	- Functions for Getting Information" << endl;
		cout << "		ask (정보)" << endl;
		cout << "		parent (부모)" << endl;
		cout << "		children (자식)" << endl;
		cout << "		highlight (강조)" << endl;
		cout << "	- Functions for Making Customized Features" << endl;
		cout << "		customfeature (커스텀피쳐)" << endl;
		cout << "		parameter (파라메터)" << endl;
		cout << "	- Other Functions" << endl;
		cout << "		newpartdoc (새문서)" << endl;
		cout << "		reset (리셋)" << endl;
		cout << "		clear (비우기)" << endl;
		cout << "		import (불러오기)" << endl;
		cout << "		export (내보내기)" << endl;
		cout << "		convertmesh (매쉬변환)" << endl;
		cout << "		restore (복구)" << endl;
		cout << "		exit (종료)" << endl;
		cout << "		exitall (모두종료)" << endl;
		cout << "	- Custom Features" << endl;
		
		// 현재 정의된 커스텀 피쳐의 목록을 출력한다
		if (GetCustomFeatureListSize() == 0)
			cout << "		No custom feature is defined in the current session" << endl;
		else
		{
			for (int i = 0; i < GetCustomFeatureListSize(); ++i)
				cout << "		" << GetCustomFeature(i)->GetName() << endl;
		}
	}
	else if (GetCustomFeatureByName(name)) // 커스텀 피쳐 도움말
	{
		GetCustomFeatureByName(name)->Help();
	}
	else if ((fType = Commands.GetFeatureType(name)) != NoFeature)	// 특징형상 도움말
	{
		Feature * pFeature = 0;
		
		switch(fType)
		{
			case Sketch_Type:
				pFeature = new FeatureSketch(NULL, 0);
				break;
			case ProExtrude_Type:
				pFeature = new FeatureExtrude(NULL, 1);
				break;
			case CutExtrude_Type:
				pFeature = new FeatureExtrude(NULL, 2);
				break;
			case Fillet_Type:
				pFeature = new FeatureFillet(NULL, 3);
				break;
			case ProSweep_Type:
				pFeature = new FeatureSweep(NULL, 4);
				break;
			case CutSweep_Type:
				pFeature = new FeatureSweep(NULL, 5);
				break;
			case Chamfer_Type:
				pFeature = new FeatureChamfer(NULL, 6);
				break;
			case ProRevolve_Type:
				pFeature = new FeatureRevolve(NULL, 7);
				break;
			case CutRevolve_Type:
				pFeature = new FeatureRevolve(NULL, 8);
				break;
			case RevolveWithAxis_Type:
				pFeature = new FeatureRevolve(NULL, 9);
				break;
			case DatumPlaneOffset_Type:
				pFeature = new FeatureDatumPlaneOffset(NULL, 10);
				break;
			case PatternRectangular_Type:
				pFeature = new FeaturePatternRectangular(NULL, 11);
				break;
			case PatternCircular_Type:
				pFeature = new FeaturePatternCircular(NULL, 12);
				break;
			case HoleCounterbored_Type:
				pFeature = new FeatureHole(NULL, 13);
				break;
			case HoleCountersunk_Type:
				pFeature = new FeatureHole(NULL, 14);
				break;
			case HoleSimple_Type:
				pFeature = new FeatureHole(NULL, 15);
				break;
			case Shell_Type:
				pFeature = new FeatureShell(NULL, 16);
				break;
			case Loft_Type:
				pFeature = new FeatureLoft(NULL, 17);
				break;
			case Draft_Type:
				pFeature = new FeatureDraft(NULL, 18);
				break;
			case Offset_Type:
				pFeature = new FeatureOffset(NULL, 19);
				break;
			case BrepSolid_Type:
				pFeature = new FeatureBrep(NULL, 20);
				break;
			case DatumPlaneEquation_Type:
			pFeature = new FeatureDatumPlaneEquation(this, 21);
				break;
		}

		if (pFeature)
		{
			pFeature->Help();
			delete pFeature;
		}
	}
	else if ((rType = Commands.GetReferenceType(name)) != NoReference)	// 레퍼런스 도움말
	{
		Reference * pReference = 0;

		switch(rType)
		{
			case Plane_Type:
				pReference = new ReferenceExplicitModelObject(NULL, 0);
				break;
			case Brep_Type:
				pReference = new ReferenceBrep(NULL, 1);
				break;
			case Breps_Type:
				pReference = new ReferenceBrep(NULL, 2);
				break;
			case FaceByAxis_Type:
				pReference = new ReferenceBrep(NULL, 3);
				break;
			case EdgeByPoint_Type:
				pReference = new ReferenceBrep(NULL, 4);
				break;
			case EdgeByPoints_Type:
				pReference = new ReferenceBrep(NULL, 5);
				break;
			case Feature_Type:
				pReference = new ReferenceFeature(NULL, 6);
				break;
			case Features_Type:
				pReference = new ReferenceFeature(NULL, 7);
				break;
		}

		if (pReference)
		{
			pReference->Help();
			delete pReference;
		}
	}
	else if ((sType = Commands.GetSketchItemType(name)) != NoSketchItem)	// SketchItem 도움말
	{
		SketchItem * pSketchItem = 0;
	
		switch(sType)
		{
			case Line_Type:
				pSketchItem = new SketchItemLine(NULL, 0);
				break;
			case CenterLine_Type:
				pSketchItem = new SketchItemCenterLine(NULL, 1);
				break;
			case Circle_Type:
				pSketchItem = new SketchItemCircle(NULL, 2);
				break;
			case Arc_Type:
				pSketchItem = new SketchItemArc(NULL, 3);
				break;
			case PolyLine_Type:
				pSketchItem = new SketchItemPolyLine(NULL, 4);
				break;
			case Rectangle_Type:
				pSketchItem = new SketchItemRectangle(NULL, 5);
				break;
			case FilletLines_Type:
				pSketchItem = new SketchItemFillet(NULL, 6);
				break;
			case ChamferLines_Type:
				pSketchItem = new SketchItemChamfer(NULL, 7);
				break;
			case ExtendLines_Type:
				pSketchItem = new SketchItemExtendLines(NULL, 8);
				break;
			case Polygon_Type:
				pSketchItem = new SketchItemPolygon(NULL, 9);
				break;
			case TranslateSketch_Type:
				pSketchItem = new SketchItemTranslate(NULL, 10);
				break;
			case RotateSketch_Type:
				pSketchItem = new SketchItemRotate(NULL, 11);
				break;
		}

		if (pSketchItem)
		{
			pSketchItem->Help();
			delete pSketchItem;
		}
	}
	else if (name == "closesketch" || name == "스케치종료")
	{
		cout << " [closesketch]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "closesketch" << endl;
		cout << " [NOTE] " << "This function must be called after 'opensketch' function" << endl;
	}
	else if (name == "setcoordinatesystem" || name == "좌표계")
	{
		cout << " [setcoordinatesystem p1 p2 p3 p4 p5 p6 p7 p8 p9]" << endl;
		cout << " -p1 : " << "Origin (X)" << endl;
		cout << " -p2 : " << "Origin (Y)" << endl;
		cout << " -p3 : " << "Origin (Z)" << endl;
		cout << " -p4 : " << "X Direction (X)" << endl;
		cout << " -p5 : " << "X Direction (Y)" << endl;
		cout << " -p6 : " << "X Direction (Z)" << endl;
		cout << " -p7 : " << "Y Direction (X)" << endl;
		cout << " -p8 : " << "Y Direction (Y)" << endl;
		cout << " -p9 : " << "Y Direction (Z)" << endl;
		cout << " [EXAMPLE] " << "setcoordinatesystem 0 0 100 0 1 0 0 0 1" << endl;
		cout << " [NOTE] " << "This function must be called after 'opensketch' function" << endl;
	}
	else if (name == "modify" || name == "수정")
	{
		cout << " [modify p1 p2 ... pn]" << endl;
		cout << " -p1 : " << "Feature Name" << endl;
		cout << " -p2 ... pn : Total Number of Parameters Varies" << endl;
		cout << "  # Sketch-based features" << endl;
		cout << "   [EXAMPLE 1] " << "modify Extrude1 100 0 0 0 0" << endl;
		cout << "   [EXAMPLE 2] " << "modify Revolve1 270 0 0 0 0" << endl;
		cout << "   [NOTE] " << "All the parameters except the sketch name are required" << endl;
		cout << "  # Other features" << endl;
		cout << "   [EXAMPLE 1] " << "modify RectPattern1 1 0 0 0 1 0 4 50 3 30" << endl;
		cout << "   [EXAMPLE 2] " << "modify CircPattern1 0 0 0 0 0 1 8 45 2 30 1" << endl;
		cout << "   [EXAMPLE 3] " << "modify Fillet1 10 0" << endl;
		cout << "   [EXAMPLE 4] " << "modify Chamfer1 10" << endl;
		cout << "   [EXAMPLE 5] " << "modify Plane1 50 0" << endl;
		cout << "   [NOTE] " << "Required parameters are the same" << endl;
		cout << "  # Sketches" << endl;
		cout << "   [EXAMPLE]" << "	modify Sketch1" << endl;
		cout << "		createline Line1 0 0 100 0" << endl;
		cout << "		undo" << endl;
		cout << "		redo" << endl;
		cout << "		delete Line1" << endl;
		cout << "		createcircle Circle1 0 0 50" << endl;
		cout << "		modify Circle1 0 0 30" << endl;
		cout << "		closesketch" << endl;
		cout << "   [NOTE 1] " << "'modify', 'delete', 'undo', and 'redo' can be used during sketch" << endl;
		cout << "   [NOTE 2] " << "While modifying a sketch, features created after the sketch will be temporarily hidden until the sketch is closed" << endl;
		cout << "   [NOTE 3] " << "'closesketch' must be called after the modification" << endl;
	}
	else if (name == "delete" || name == "제거")
	{
		cout << " [delete p1]" << endl;
		cout << " -p1 : " << "Feature (Sketch Item) Name" << endl;
		cout << " [EXAMPLE 1] " << "delete Fillet1" << endl;
		cout << " [EXAMPLE 2] " << "delete Line1" << endl;
		cout << " [NOTE 1] " << "Child features will be deleted too" << endl;
		cout << " [NOTE 2] " << "Deleting a sketch item can be done during sketch" << endl;
	}
	else if (name == "undo" || name == "뒤로")
	{
		cout << " [undo]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "undo" << endl;
		cout << " [NOTE] " << "Before undoing, more than one operation have to be finished before" << endl;
	}
	else if (name == "redo" || name == "앞으로")
	{
		cout << " [redo]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "redo" << endl;
		cout << " [NOTE] " << "Before redoing, 'undo' should be called before" << endl;
	}
	else if (name == "reset" || name == "리셋")
	{
		cout << " [reset]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "reset" << endl;
		cout << " [NOTE] " << "You must enter this function if you change the model (e.g. K1 → K3) without re-open the part document" << endl;
	}
	else if (name == "ask" || name == "정보")
	{
		cout << " [ask p1]" << endl;
		cout << " -p1 : " << "Feature Name or 'all' or 'history'" << endl;
		cout << " [EXAMPLE 1] " << "ask all" << endl;
		cout << " [EXAMPLE 2] " << "ask history" << endl;
		cout << " [EXAMPLE 3] " << "ask Extrude1" << endl;
		cout << " [NOTE 1] " << "'ask all': This is for getting information of current features" << endl;
		cout << " [NOTE 2] " << "'ask history': This is for getting information of history" << endl;
		cout << " [NOTE 3] " << "'ask FeatureName': This is for getting information of a feature" << endl;
	}
	else if (name == "clear" || name == "비우기")
	{
		cout << " [clear]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "clear" << endl;
		cout << " [NOTE] " << "This function is for clearing the window" << endl;
	}
	else if (name == "newpartdoc" || name == "새문서")
	{
		cout << " [newpartdoc]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "newpartdoc" << endl;
		cout << " [NOTE] " << "This function is for creating a new part document" << endl;
	}
	else if (name == "import" || name == "불러오기")
	{
		cout << " [import p1]" << endl;
		cout << " - p1 : " << "File Path" << endl;
		cout << " [EXAMPLE 1] " << "import C:\\K1.xml" << endl;
		cout << " [EXAMPLE 2] " << "import C:\\K1.CATScript" << endl;
		cout << " [EXAMPLE 3] " << "import C:\\K1.prt" << endl;
		cout << " [NOTE] " << "Supporting Formats: .xml, .CATScript, .prt, .stp, .sat, .igs" << endl;
	}
	else if (name == "export" || name == "내보내기")
	{
		cout << " [export p1]" << endl;
		cout << " - p1 : " << "File Path" << endl;
		cout << " [EXAMPLE 1] " << "export C:\\K1.xml" << endl;
		cout << " [EXAMPLE 2] " << "export C:\\K1.CATScript" << endl;
		cout << " [EXAMPLE 3] " << "export C:\\K1.prt" << endl;
		cout << " [EXAMPLE 4] " << "export C:\\K1.x3d" << endl;
		cout << " [EXAMPLE 5] " << "export C:\\K1.stp" << endl;
		cout << " [NOTE] " << "Supporting Formats: .xml, .CATScript, .prt, .stp, .sat, .igs, .x3d, .obj, .stl, .ply, .wrl, .pdf" << endl;
	}
	else if (name == "convertmesh" || name == "매쉬변환")
	{
		cout << " [convertmesh p1 p2]" << endl;
		cout << " - p1 : " << "Source File Path" << endl;
		cout << " - p2 : " << "Target File Path" << endl;
		cout << " [EXAMPLE 1] " << "convertmesh C:\\K1.obj C:\\K1.stl" << endl;
		cout << " [EXAMPLE 2] " << "convertmesh C:\\K1.stl C:\\K1.ply" << endl;
		cout << " [EXAMPLE 3] " << "convertmesh C:\\K1.ply C:\\K1.x3d" << endl;
		cout << " [NOTE 1] " << "Supporting Input Formats: .x3d, .obj, .stl, .ply, .wrl" << endl;
		cout << " [NOTE 2] " << "Supporting Output Formats: .x3d, .obj, .stl, .ply, .wrl" << endl;
	}
	else if (name == "exit" || name == "종료")
	{
		cout << " [exit]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "exit" << endl;
		cout << " [NOTE] " << "This function is for exiting from the script interface" << endl;
	}
	else if (name == "exitall" || name == "모두종료")
	{
		cout << " [exitall]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "exitall" << endl;
		cout << " [NOTE] " << "This function is for terminating both script interface and TransCAD" << endl;
	}
	else if (name == "restore" || name == "복구")
	{
		cout << " [restore]" << endl;
		cout << " - No parameter needed" << endl;
		cout << " [EXAMPLE] " << "restore" << endl;
		cout << " [NOTE] " << "This function can be only used when TransCAD has unexpectedly shut down or closed" << endl;
	}
	else if (name == "parent" || name == "부모")
	{
		cout << " [parent p1]" << endl;
		cout << " - p1 : " << "Feature Name" << endl;
		cout << " [EXAMPLE 1] " << "parent Extrude1" << endl;
		cout << " [EXAMPLE 2] " << "parent Sketch2" << endl;
		cout << " [NOTE] " << "This function is for getting parent feature name" << endl;
	}
	else if (name == "children" || name == "자식")
	{
		cout << " [children p1]" << endl;
		cout << " - p1 : " << "Feature Name" << endl;
		cout << " [EXAMPLE 1] " << "children XYPlane" << endl;
		cout << " [EXAMPLE 2] " << "children Extrude1" << endl;
		cout << " [NOTE] " << "This function is for getting all children feature name" << endl;
	}
	else if (name == "highlight" || name == "강조")
	{
		cout << " [highlight p1]" << endl;
		cout << " - p1 : " << "Feature Name" << endl;
		cout << " [EXAMPLE 1] " << "highlight Extrude1" << endl;
		cout << " [EXAMPLE 2] " << "highlight Fillet1" << endl;
		cout << " [EXAMPLE 3] " << "highlight Line1" << endl;
		cout << " [NOTE 1] " << "This function is for highlighting the selected feature by blinking it" << endl;
		cout << " [NOTE 2] " << "You can also use this function for sketch items during sketch" << endl;
	}
	else if (name == "customfeature" || name == "커스텀피쳐")
	{
		cout << " [customfeature p1 p2 ... pn]" << endl;
		cout << " -p1 : " << "Custom Feature Name" << endl;
		cout << " -p2 ... pn : Total Number of Parameters Varies" << endl;
		cout << " [EXAMPLE 1] " << "	customfeature pe 'a' 'b' 'c'" << endl;
		cout << "		createproextrude Extrude'a' Sketch'b' 'c' 0 0 0 0" << endl;
		cout << "		endcustom" << endl;
		cout << "		pe 1 1 50" << endl;
		cout << " [EXAMPLE 2] " << "	customfeature cylinder 'a' 'b' 'c' 'd' 'e' 'f'" << endl;
		cout << "		selectplane 'a'" << endl;
		cout << "		opensketch Sketch'b'" << endl;
		cout << "		createcircle Circle1 'c' 'd' 'e'" << endl;
		cout << "		closesketch" << endl;
		cout << "		createproextrude Extrude'b' Sketch'b' 'f' 0 0 0 0" << endl;
		cout << "		endcustom" << endl;
		cout << "		cylinder xy 1 0 0 20 100" << endl;
		cout << "		cylinder xy 2 50 50 20 100" << endl;
		cout << " [EXAMPLE 3] " << "	customfeature sphere 'a' 'b' 'c' 'd' 'e'" << endl;
		cout << "		parameter 'f'='c'+'e'" << endl;
		cout << "		parameter 'g'='c'-'e'" << endl;
		cout << "		selectplane 'a'" << endl;
		cout << "		opensketch Sketch'b'" << endl;
		cout << "		createarc Arc1 'c' 'd' 'f' 'd' 'g' 'd'" << endl;
		cout << "		createline Line1 'f' 'd' 'g' 'd'" << endl;
		cout << "		createcenterline CenterLine1 'f' 'd' 'g' 'd'" << endl;
		cout << "		closesketch" << endl;
		cout << "		createprorevolve Revolve'b' Sketch'b' 360 0 0 0 0" << endl;
		cout << "		endcustom" << endl;
		cout << "		sphere xy 1 0 0 20" << endl;
		cout << "		sphere xy 2 50 50 20" << endl;
		cout << " [NOTE 1] " << "This function is for making a customized feature" << endl;
		cout << " [NOTE 2] " << "It is recommended to use quotation marks ('a' or \"a\") for parameters" << endl;
		cout << " [NOTE 3] " << "Define your own custom features at 'D:\\CustomFeatures.txt' beforehand" << endl;
		cout << " [NOTE 4] " << "'endcustom' function must be called to stop defining custom feature" << endl;
	}
	else if (name == "parameter" || name == "파라메터")
	{
		cout << " [parameter equation]" << endl;
		cout << " -equation : " << "Equation for Defining a Parameter" << endl;
		cout << " [EXAMPLE 1] " << "parameter 'c'='a'+'b'" << endl;
		cout << " [EXAMPLE 2] " << "parameter 'c'=('a'+'b')/2" << endl;
		cout << " [NOTE 1] " << "This function is for defining a parameter in a customized feature" << endl;
		cout << " [NOTE 2] " << "New parameter name must be on the left side of the equation" << endl;
		cout << " [NOTE 3] " << "No blank is allowd in the equation" << endl;
		cout << " [NOTE 4] " << "Minus sign cannot be located at the very first on the right side \n (ex. 'c'=-1*('a'+'b') (X) → 'c'=(-1)*('a'+'b') (O))" << endl;
		cout << " [NOTE 5] " << "This function should be called after 'customfeature' function" << endl;
	}

	CMD::SetColor(D_BLUE, YELLOW);
}


// 스크립트 인터페이스를 시작할 때, D:\ 경로에 저장되어 있는 커스텀 피쳐를 불러와서 저장하는 함수
void Part::ReadCustomFeatures(void)
{
	ifstream fin;
	char buffer[1000];
	char * context = NULL;

	string filePath = "D:\\CustomFeatures.txt";	// 커스텀 피쳐를 미리 정의해 놓은 경로

	fin.open(filePath, ios::in);

	if (!fin)
		return;

	while(!fin.eof()) // CATIA 매크로 파일의 끝까지 라인 읽기 수행
	{	
		try
		{
			fin.getline(buffer, 1000);   //한 라인을 읽는다.

			token = StringToken::GetString( buffer, seps_blank, context );

			if (token.find("customfeature") == 0 || token.find("커스텀피쳐") == 0)
			{
				TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, context )) == "FAIL", "Insufficient input parameters!");
				TSIThrowExceptionIf<TSIArgumentException>(GetCustomFeatureByName(token) != NULL, "Enter another name!");
				TSIThrowExceptionIf<TSIArgumentException>(Commands.GetFeatureType(token) != NoFeature, "Enter another name!");
				TSIThrowExceptionIf<TSIArgumentException>(Commands.GetReferenceType(token) != NoReference, "Enter another name!");
				TSIThrowExceptionIf<TSIArgumentException>(Commands.GetCommandType(token) != NoCommand, "Enter another name!");
				TSIThrowExceptionIf<TSIArgumentException>(Commands.GetSketchItemType(token) != NoSketchItem, "Enter another name!");

				CustomFeature * pCusFeature = new CustomFeature(this);
				
				// 커스텀 피쳐 이름 설정
				pCusFeature->SetName(token);
				
				// 파라메터 저장 (ex. 'a', 'b', 'c' 등)
				while (token != "FAIL")
				{
					token = StringToken::GetString( NULL, seps_blank, context );
		
					if (token != "FAIL")
						pCusFeature->SetParameters(token);
				}

				// 모든 명령어 저장
				while (token != "endcustom" && token != "커스텀종료")
				{
					fin.getline(buffer, 1000);

					token = buffer;
		
					if(token != "endcustom" && token != "커스텀종료")
						pCusFeature->SetCommands(token);
				}

				// 커스텀피쳐 순서 저장
				pCusFeature->SetOrder(GetCustomFeatureListSize());
				pCusFeature->Initialize();

				// 커스텀 피쳐 저장
				SetCustomFeature(pCusFeature);
			}
		}
		catch (TSIArgumentException & e)
		{
			cout << e.GetMessageW() << endl;
		}
		context = NULL;
	}

	fin.close();
}

// 커스텀 피쳐를 생성하는 함수
void Part::CreateCustomFeature(char * command)
{
	TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "Insufficient input parameters!");
		
	// 기존의 커멘드와 이름 중첩 검사
	TSIThrowExceptionIf<TSIArgumentException>(GetCustomFeatureByName(token) != NULL, "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(Commands.GetFeatureType(token) != NoFeature, "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(Commands.GetReferenceType(token) != NoReference, "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(Commands.GetCommandType(token) != NoCommand, "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(Commands.GetSketchItemType(token) != NoSketchItem, "Enter another name!");
	
	CustomFeature * pCusFeature = new CustomFeature(this);
	
	pCusFeature->SetName(token);		// 커스텀 피쳐 이름 설정
	pCusFeature->Create(command);	// 커스텀 피쳐 생성

	SetCustomFeature(pCusFeature);	// 커스텀 피쳐 저장
}

// 커스텀 피쳐 이름으로 검색하는 함수
CustomFeature * Part::GetCustomFeatureByName(string name)
{
	CustomFeature * pCusFeature = 0;
	
	for (int i = 0; i < GetCustomFeatureListSize(); ++i)
	{
		if (GetCustomFeature(i)->GetName() == name)
		{
			pCusFeature = GetCustomFeature(i);
			break;
		}
	}
	
	return pCusFeature;
}