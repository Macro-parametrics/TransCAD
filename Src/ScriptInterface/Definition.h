#pragma once

#include <math.h>

#define MAX_CHAR_LIMIT	20
#define MAX_DIGITS		18
#define MAX_DEPTH		1000000
#define PI 3.14159265359
#define tolerance 0.0000001
#define infinity 100000000000000000


// CMD 색상 타입
enum {
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

// 명령어 타입
namespace CommandType
{
	enum FeatureType
	{
		Sketch_Type,
		ProExtrude_Type,
		CutExtrude_Type,
		Fillet_Type,
		ProSweep_Type,
		CutSweep_Type,
		Chamfer_Type,
		ProRevolve_Type,
		CutRevolve_Type,
		RevolveWithAxis_Type,
		DatumPlaneOffset_Type,
		DatumPlaneEquation_Type,
		PatternRectangular_Type,
		PatternCircular_Type,
		HoleCounterbored_Type,
		HoleCountersunk_Type,
		HoleSimple_Type,
		Shell_Type,
		Loft_Type,
		Draft_Type,
		Offset_Type,
		BrepSolid_Type,
		NoFeature,
	};
	
	enum ReferenceType
	{
		Plane_Type,
		Brep_Type,
		Breps_Type,
		FaceByAxis_Type,
		EdgeByPoint_Type,
		EdgeByPoints_Type,
		Feature_Type,
		Features_Type,
		NoReference,
	};

	enum SketchItemType
	{
		CSYS_Type,
		Line_Type,
		CenterLine_Type,
		Circle_Type,
		Arc_Type,
		PolyLine_Type,
		Rectangle_Type,
		Polygon_Type,
		FilletLines_Type,
		ChamferLines_Type,
		ExtendLines_Type,
		TranslateSketch_Type,
		RotateSketch_Type,
		NoSketchItem,
	};

	enum GeneralType
	{
		NewPartDoc_Type,
		Terminate_Type,
		Reset_Type,
		Clear_Type,
		Restore_Type,
		Modify_Type,
		Delete_Type,
		Undo_Type,
		Redo_Type,
		Import_Type,
		Export_Type,
		Ask_Type,
		Parent_Type,
		Children_Type,
		Highlight_Type,
		ConvertMesh_Type,
		CustomFeature_Type,
		Help_Type,
		NoCommand,
	};
}

// 모든 한글 및 영어 명령어 관리하는 클래스. 명령어 타입과 순서가 맞아야 함 (매우 중요!)
class CommandList {
public:

	CommandList()
	{
		// 특징형상 생성 명령어
		char * FeatureKor[] = {"스케치시작", "돌출", "돌출컷", "필렛", "스윕", "스윕컷",
								"챔퍼", "회전", "회전컷", "축회전", "새평면", "새평면2", "사각패턴", 
								"원형패턴", "카운터보어", "카운터싱크", "구멍", "쉘", "로프트",
								"구배", "오프셋", "경계표현입력"};
		char * FeatureEng[] = {"opensketch", "createproextrude", "createcutextrude", "createfillet", "createprosweep", "createcutsweep",
								"createchamfer", "createprorevolve", "createcutrevolve", "createrevolvewithaxis", "createdatumplaneoffset", "createdatumplaneequation", "createrectpattern",
								"createcircpattern", "createholecounterbored", "createholecountersunk", "createholesimple", "createshell", "createloft",
								"createdraft", "createoffset", "importbrep"};
		
		// 특징형상 생성 명령어 저장
		for (int i = 0; i < CommandType::NoFeature; ++i)
		{
			FeatureCommandList.push_back(make_pair((CommandType::FeatureType)i, FeatureKor[i]));
			FeatureCommandList.push_back(make_pair((CommandType::FeatureType)i, FeatureEng[i]));
		}
		
		// 레퍼런스 선택 명령어
		char * ReferenceKor[] = {"평면선택", "요소선택", "요소들선택", "면선택", "한점모서리선택", "세점모서리선택", "피쳐선택", "피쳐들선택"};
		char * ReferenceEng[] = {"selectplane", "selectbrep", "selectbreps", "selectfacebyaxis", "selectedgebypoint", "selectedgebypoints", "selectfeature", "selectfeatures"};
		
		// 레퍼런스 선택 명령어 저장
		for (int i = 0; i < CommandType::NoReference; ++i)
		{
			ReferenceCommandList.push_back(make_pair((CommandType::ReferenceType)i, ReferenceKor[i]));
			ReferenceCommandList.push_back(make_pair((CommandType::ReferenceType)i, ReferenceEng[i]));
		}

		// 스케치요소 생성 명령어
		char * SketchItemKor[] = {"좌표계", "선", "중심선", "원", "호", "연결선", "사각형", "다각형",
									"선필렛", "선챔퍼", "선연장", "스케치이동", "스케치회전"};
		char * SketchItemEng[] = {"setcoordinatesystem", "createline", "createcenterline", "createcircle", "createarc", "createpolyline", "createrectangle", "createpolygon",
									"filletlines", "chamferlines", "extendlines", "translatesketch", "rotatesketch"};
		
		// 스케치요소 생성 명령어 저장
		for (int i = 0; i < CommandType::NoSketchItem; ++i)
		{
			SketchItemCommandList.push_back(make_pair((CommandType::SketchItemType)i, SketchItemKor[i]));
			SketchItemCommandList.push_back(make_pair((CommandType::SketchItemType)i, SketchItemEng[i]));
		}

		// 기타 명령어
		char * GeneralKor[] = {"새문서", "모두종료", "리셋", "비우기", "복구", "수정", "제거", "뒤로", "앞으로",
								"불러오기", "내보내기", "정보", "부모", "자식", "강조", "매쉬변환","커스텀피쳐", "도움말"};
		char * GeneralEng[] = {"newpartdoc", "exitall", "reset", "clear", "restore", "modify", "delete", "undo", "redo",
								"import", "export", "ask", "parent", "children", "highlight", "convertmesh", "customfeature", "help"};
		
		// 기타 명령어 저장
		for (int i = 0; i < CommandType::NoCommand; ++i)
		{
			GeneralCommandList.push_back(make_pair((CommandType::GeneralType)i, GeneralKor[i]));
			GeneralCommandList.push_back(make_pair((CommandType::GeneralType)i, GeneralEng[i]));
		}
	}

	// string을 받아서 해당 FeatureType을 리턴
	CommandType::FeatureType GetFeatureType(string command) 
	{
		for (int i = 0; i < (int)FeatureCommandList.size(); ++i)
		{
			if (FeatureCommandList[i].second == command)
				return FeatureCommandList[i].first;
		}
		
		return CommandType::NoFeature;
	}
	
	// string을 받아서 해당 ReferenceType을 리턴
	CommandType::ReferenceType GetReferenceType(string command) 
	{
		for (int i = 0; i < (int)ReferenceCommandList.size(); ++i)
		{
			if (ReferenceCommandList[i].second == command)
				return ReferenceCommandList[i].first;
		}
		
		return CommandType::NoReference;
	}
	
	// string을 받아서 해당 SketchItemType을 리턴
	CommandType::SketchItemType GetSketchItemType(string command) 
	{
		for (int i = 0; i < (int)SketchItemCommandList.size(); ++i)
		{
			if (SketchItemCommandList[i].second == command)
				return SketchItemCommandList[i].first;
		}
		
		return CommandType::NoSketchItem;
	}
	
	// string을 받아서 해당 CommandType을 리턴
	CommandType::GeneralType GetCommandType(string command) 
	{
		for (int i = 0; i < (int)GeneralCommandList.size(); ++i)
		{
			if (GeneralCommandList[i].second == command)
				return GeneralCommandList[i].first;
		}
		
		return CommandType::NoCommand;
	}

private:
	vector<pair<CommandType::FeatureType, string>> FeatureCommandList;
	vector<pair<CommandType::ReferenceType, string>> ReferenceCommandList;
	vector<pair<CommandType::SketchItemType, string>> SketchItemCommandList;
	vector<pair<CommandType::GeneralType, string>> GeneralCommandList;
};