#include "stdafx.h"
#include "ReferenceBrep.h"

ReferenceBrep::ReferenceBrep(Feature * pFeature, int referenceType)
	:Reference(pFeature, referenceType)
{
}

ReferenceBrep::~ReferenceBrep(void)
{
}

void ReferenceBrep::GetInfo(char * command)
{
	if (GetType() == 1) // Brep 요소 1개 일 때 (네이밍으로 선택)
		SelectBrep(command);
	else if (GetType() == 2) // Brep 요소 여러 개 일 때 (네이밍으로 선택)
		SelectBreps(command);
	else if (GetType() == 3) // Axis로 Face를 선택할 때
		SelectFaceByAxis(command);
	else if (GetType() == 4) // 한 점으로 Edge를 선택할 때
		SelectEdgeByPoint(command);
	else if (GetType() == 5) // 세 점으로 Edge를 선택할 때
		SelectEdgeByPoints(command);
	
	if (GetReferencePtr())
	{
		GetFeature()->GetPart()->SetCurrentReferencePtr(GetReferencePtr());
		GetFeature()->GetPart()->SetCurrentReferencesPtr(NULL);
	}
	else if (GetReferencesPtr())
	{
		GetFeature()->GetPart()->SetCurrentReferencePtr(NULL);
		GetFeature()->GetPart()->SetCurrentReferencesPtr(GetReferencesPtr());
	}
}

void ReferenceBrep::AddInfo(TransCAD::IReferencePtr spReference)
{
	SetReferencePtr(spReference);

	SetName((string)GetReferencePtr()->GetReferenceeName());
	SetReferenceName((string)GetReferencePtr()->GetReferenceeName());

	GetTargetFeaturesFromBrepName(GetName());

	assert(GetTargetFeatureListSize() != 0);

	// Parent 저장
	for (int i = 0; i < GetTargetFeatureListSize(); ++i)
		GetFeature()->SetParentName(GetTargetFeature(i));
}

void ReferenceBrep::AddInfo(TransCAD::IReferencesPtr spReferences)
{
	SetReferencesPtr(spReferences);

	for (int i = 1; i <= GetReferencesPtr()->GetCount(); ++i)
	{
		string name = GetReferencesPtr()->GetItem(i)->GetReferenceeName();
		SetReferenceName(name);

		string brepName(name);

		GetTargetFeaturesFromBrepName(brepName);
	}
	
	assert(GetTargetFeatureListSize() != 0);

	// Parent 저장
	for (int i = 0; i < GetTargetFeatureListSize(); ++i)
		GetFeature()->SetParentName(GetTargetFeature(i));
}

void ReferenceBrep::AskInfo(void)
{
	char buffer[500];
	
	if (GetReferencePtr())			// Reference 포인터일 때
		cout << "selectbrep " + GetName() << endl;
	else if (GetReferencesPtr())	// References 포인터일 때
	{
		if ((int)GetReferencesPtr()->GetCount() == 1)
			cout << "selectbrep " + GetReferencesPtr()->GetItem(1)->GetReferenceeName() << endl;
		else
		{
			sprintf_s(buffer, "selectbreps %d", (int)GetReferencesPtr()->GetCount());
			cout << buffer << endl;

			for (int i = 1; i <= (int)GetReferencesPtr()->GetCount(); ++i)
			{
				token = GetReferencesPtr()->GetItem(i)->GetReferenceeName();
				cout << "selectbrep " << token << endl;
			}
		}
	}
}

void ReferenceBrep::Help(void)
{
	if (GetType() == 1)
	{
		cout << " [selectbrep p1]" << endl;
		cout << " -p1 : " << "Face or Edge Name" << endl;
		cout << " [EXAMPLE 1] " << "selectbrep Extrude1,Sketch1,Line3,0,0,0,ExtrudeFeature:0,0:0;0" << endl;
		cout << " [EXAMPLE 2] " << "selectbrep Extrude1,Sketch1,Line2,0,0,0,ExtrudeFeature:0,0:0;0#Extrude1,Sketch1,Line3,0,0,0,ExtrudeFeature:0,0:0;0" << endl;
		cout << " [NOTE 1] " << "Face or edge names must be in the form of TransCAD persistent naming" << endl;
		cout << " [NOTE 2] " << "You can see the face or edge name from 'View - Check feature name' in TransCAD" << endl;
	}
	else if (GetType() == 2)
	{
		cout << " [selectbreps p1]" << endl;
		cout << " -p1 : " << "Total Number of Faces or Edges" << endl;
		cout << " [EXAMPLE 1]" << "	selectbreps 4" << endl;
		cout << "		selectbrep Extrude1,Sketch1,Line4,0,0,0,ExtrudeFeature:0,0:0;0" << endl;
		cout << "		selectfacebyaxis 0 0 0 1 0 0 0 1 0" << endl;
		cout << "		selectedgebypoint 0 0 40" << endl;
		cout << "		selectedgebypoints 0 80 0 0 80 80 0 80 40" << endl;
		cout << " [EXAMPLE 2]" << "	selectbreps 2" << endl;
		cout << "		selectbrep Extrude1,Sketch1,Line4,0,0,0,ExtrudeFeature:0,0:0;0" << endl;
		cout << "		cancel" << endl;
		cout << " [NOTE 1] " << "Use other selecting functions during the selection" << endl;
		cout << " [NOTE 2] " << "You should select the correct face or edge exactly p1 times" << endl;
		cout << " [NOTE 3] " << "'cancel(취소)' will escape this function" << endl;
	}
	else if (GetType() == 3)
	{
		cout << " [selectfacebyaxis p1 p2 p3 p4 p5 p6 p7 p8 p9]" << endl;
		cout << " -p1 : " << "Origin (X)" << endl;
		cout << " -p2 : " << "Origin (Y)" << endl;
		cout << " -p3 : " << "Origin (Z)" << endl;
		cout << " -p4 : " << "X Direction (X)" << endl;
		cout << " -p5 : " << "X Direction (Y)" << endl;
		cout << " -p6 : " << "X Direction (Z)" << endl;
		cout << " -p7 : " << "Y Direction (X)" << endl;
		cout << " -p8 : " << "Y Direction (Y)" << endl;
		cout << " -p9 : " << "Y Direction (Z)" << endl;
		cout << " [EXAMPLE] " << "selectfacebyaxis 0 0 0 1 0 0 0 1 0" << endl;
	}
	else if (GetType() == 4)
	{
		cout << " [selectedgebypoint p1 p2 p3]" << endl;
		cout << " -p1 : " << "Point on Edge (X)" << endl;
		cout << " -p2 : " << "Point on Edge (Y)" << endl;
		cout << " -p3 : " << "Point on Edge (Z)" << endl;
		cout << " [EXAMPLE] " << "selectedgebypoint 100 50 80" << endl;
		cout << " [NOTE] " << "It is recommended to use a point that is not shared by two or more lines" << endl;
	}
	else if (GetType() == 5)
	{
		cout << " [selectedgebypoints p1 p2 p3 p4 p5 p6 p7 p8 p9]" << endl;
		cout << " -p1 : " << "Start Point of Edge (X)" << endl;
		cout << " -p2 : " << "Start Point of Edge (Y)" << endl;
		cout << " -p3 : " << "Start Point of Edge (Z)" << endl;
		cout << " -p4 : " << "End Point of Edge (X)" << endl;
		cout << " -p5 : " << "End Point of Edge (Y)" << endl;
		cout << " -p6 : " << "End Point of Edge (Z)" << endl;
		cout << " -p7 : " << "Middle Point of Edge (X)" << endl;
		cout << " -p8 : " << "Middle Point of Edge (Y)" << endl;
		cout << " -p9 : " << "Middle Point of Edge (Z)" << endl;
		cout << " [EXAMPLE] " << "selectedgebypoints 100 0 0 100 100 0 100 50 0" << endl;
	}
}

void ReferenceBrep::Restore(void)
{
	if (GetType() == 2)	// Brep 요소 여러 개 일 때
	{
		SetReferencesPtr(GetFeature()->GetPart()->GetPartPtr()->CreateReferences());

		for (int i = 0; i < (int)GetReferenceNameListSize(); ++i)
		{
			SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectBrepByName(GetReferenceName(i).c_str()));
			assert(GetReferencePtr());
			GetReferencesPtr()->Add(GetReferencePtr());
		}

		SetReferencePtr(NULL);
	}
	else				// Brep 요소 1개 일 때
	{
		SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectBrepByName(GetName().c_str()));
		assert(GetReferencePtr());
	}
}

void ReferenceBrep::RunCommands(char * command)
{
	try
	{
		TSIThrowExceptionIf<TSIArgumentException>((token = StringToken::GetString( NULL, seps_blank, command )) == "FAIL", "No command!");

		switch(Commands.GetReferenceType(token))
		{
			case Brep_Type:
				SelectBrep(command);
				break;
			case FaceByAxis_Type:
				SelectFaceByAxis(command);
				break;
			case EdgeByPoint_Type:
				SelectEdgeByPoint(command);
				break;
			case EdgeByPoints_Type:
				SelectEdgeByPoints(command);
				break;
			default:
				if (token != "취소" && token != "cancel") cout << "Invalid command!" << endl;
				else SetReferencesPtr(NULL);
				break;
		}

		// 레퍼런스가 선택된 경우
		if (GetReferencePtr())
		{
			GetReferencesPtr()->Add(GetReferencePtr());
			SetReferencePtr(NULL);

			m_selectCount++;
		}
		
		// 모든 레퍼런스가 선택된 경우
		if (m_totalCount == m_selectCount)
		{
			CMD::SetColor(D_BLUE, YELLOW);
			GetFeature()->GetPart()->SetCurrentReferencesPtr(GetReferencesPtr());
			GetFeature()->GetPart()->SetCurrentReference(NULL);
		}
	}
	catch (TSIArgumentException & e)
	{
		cout << e.GetMessageW() << endl;
	}
}


void ReferenceBrep::SelectBrep(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	
	SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectBrepByName(token.c_str()));

	TSIThrowExceptionIf<TSIArgumentException>(!GetReferencePtr(), "Nothing is selected!");
	
	SetName(token);
}

void ReferenceBrep::SelectBreps(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	
	m_totalCount = atoi(token.c_str());
	m_selectCount = 0;

	TSIThrowExceptionIf<TSIArgumentException>(m_totalCount < 2, "Enter a number greater than 1!");
	SetReferencesPtr(GetFeature()->GetPart()->GetPartPtr()->CreateReferences());

	GetFeature()->GetPart()->SetCurrentReference(this);
	CMD::SetColor(D_BLUE, WHITE);
}

void ReferenceBrep::SelectFaceByAxis(char * command)
{
	Point3D org, xdir, ydir;
		
	token = StringToken::GetString( NULL, seps_blank, command );
	org.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	org.Y(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	org.Z(atof(token.c_str()));
		
	token = StringToken::GetString( NULL, seps_blank, command );
	xdir.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	xdir.Y(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	xdir.Z(atof(token.c_str()));
		
	token = StringToken::GetString( NULL, seps_blank, command );
	ydir.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	ydir.Y(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	ydir.Z(atof(token.c_str()));
		
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(xdir == Point3D(0,0,0), "Invalid x direction!");
	TSIThrowExceptionIf<TSIArgumentException>(ydir == Point3D(0,0,0), "Invalid y direction!");
	TSIThrowExceptionIf<TSIArgumentException>(xdir == ydir, "Two directions should not be the same!");
	TSIThrowExceptionIf<TSIArgumentException>(xdir == ydir.operator*(-1), "Two directions should not be in the opposite!");
	
	SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectPlaneByAxis(org[0], org[1], org[2], xdir[0], xdir[1], xdir[2], ydir[0], ydir[1], ydir[2]));

	TSIThrowExceptionIf<TSIArgumentException>(!GetReferencePtr(), "Nothing is selected!");
	SetName((string)GetReferencePtr()->GetReferenceeName());
}

void ReferenceBrep::SelectEdgeByPoint(char * command)
{
	Point3D middle;
		
	token = StringToken::GetString( NULL, seps_blank, command );
	middle.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	middle.Y(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	middle.Z(atof(token.c_str()));

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");

	SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectCurveByPoint(middle[0], middle[1], middle[2]));

	TSIThrowExceptionIf<TSIArgumentException>(!GetReferencePtr(), "Nothing is selected!");
	SetName((string)GetReferencePtr()->GetReferenceeName());
}

void ReferenceBrep::SelectEdgeByPoints(char * command)
{
	Point3D start, end, middle;
	
	token = StringToken::GetString( NULL, seps_blank, command );
	start.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	start.Y(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	start.Z(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	end.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	end.Y(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	end.Z(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	middle.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	middle.Y(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	middle.Z(atof(token.c_str()));
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(start == end, "Start and end points should not be the same!");
	TSIThrowExceptionIf<TSIArgumentException>(!middle.IsBetween(start, end), "Midpoint should be in between start and end points!");
	
	SetReferencePtr(GetFeature()->GetPart()->GetPartPtr()->SelectCurveBy3Points(start[0], start[1], start[2], end[0], end[1], end[2], middle[0], middle[1], middle[2]));
	
	TSIThrowExceptionIf<TSIArgumentException>(!GetReferencePtr(), "Nothing is selected!");
	SetName((string)GetReferencePtr()->GetReferenceeName());
}


// Face 혹은 Edge 이름으로부터 해당 요소를 포함하는 특징형상 이름을 추출
void ReferenceBrep::GetTargetFeaturesFromBrepName(string brepName)
{
	char * _brepName = (char *)brepName.c_str();
	
	string faceName[2];
	
	for (int i = 0; i < 2; ++i)
	{
		faceName[i] = StringToken::GetString(NULL, "#", _brepName);
		
		if (faceName[i] != "FAIL") // Edge의 경우
			GetTargetFeaturesFromFaceName(faceName[i]);
	}
}

// Face 이름으로부터 해당 요소를 포함하는 특징형상 이름을 추출
void ReferenceBrep::GetTargetFeaturesFromFaceName(string faceName)
{
	char * _faceName = (char *)faceName.c_str();

	for (;;)
	{
		token = StringToken::GetString(NULL, ",", _faceName);

		if (token == "FAIL")
			break;
		else if (token != "0" && token != "0}") // Merge 된 면이 있는 경우에도 진입하여 해당 특징형상을 찾음
		{
			int count = 0;

			for (int i = 0; i < (int)GetTargetFeatureListSize(); ++i)
				if (token == GetTargetFeature(i))
					count ++;

			if (count == 0)
				SetTargetFeature(token);
		}

		token = StringToken::GetString(NULL, ";", _faceName);
	}
}