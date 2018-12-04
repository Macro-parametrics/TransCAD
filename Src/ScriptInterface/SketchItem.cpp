#include "stdafx.h"
#include "SketchItem.h"

SketchItem::SketchItem(FeatureSketch * pSketch, int sketchItemType)
	:Object(sketchItemType)
{
	SetSketch(pSketch);
	m_isCreated = false;
}

SketchItem::~SketchItem(void)
{
}

// 입력 된 이름의 스케치 요소 존재 여부 판별
bool SketchItem::CheckExistence(string name)
{
	if (GetSketch()->GetSketchItemByName(name))
		return false;
	else
		return true;
}

bool SketchItem::IsDifferentPoint(Point2D p1, Point2D p2)
{
	if (abs(p1.X() - p2.X()) < tolerance
		&& abs(p1.Y() - p2.Y()) < tolerance)
	{
		cout << GetName() <<" has two same points!" << endl;
		return false;
	}
	else
		return true;
}

void SketchItem::GetLineEquation(Point2D firstPoint, Point2D secondPoint, double & a, double & b)
{
	a = (firstPoint.Y() - secondPoint.Y())/(firstPoint.X() - secondPoint.X());
	b = firstPoint.Y() - firstPoint.X()*a;

	if (firstPoint.X() == secondPoint.X()) // 라인이 y축과 평행할 때. 즉, 기울기가 무한대
	{
		a = infinity;
		b = -firstPoint.X();
	}
}

bool SketchItem::GetIntersectingPoint(double a[2], double b[2], Point2D & intPoint)
{
	if (a[0] == a[1]) // 두 라인이 서로 평행할 때
	{
		cout << "Two lines should not be in parrallel!" << endl;
		return false;
	}
	else if (a[0] == infinity)
	{
		intPoint.X(-b[0]);
		intPoint.Y(a[1]*intPoint.X() + b[1]);
	}
	else if (a[1] == infinity)
	{
		intPoint.X(-b[1]);
		intPoint.Y(a[0]*intPoint.X() + b[0]);
	}
	else
	{
		intPoint.X((b[1] - b[0])/(a[0] - a[1]));
		intPoint.Y(a[0]*intPoint.X() + b[0]);
	}
	
	return true;
}

void SketchItem::GetDistantPoint(Point2D org, Point2D p1, Point2D p2, Point2D & dP)
{
	if (org.GetDistance(p1) > org.GetDistance(p2))
		dP.SetXY(p1);
	else
		dP.SetXY(p2);
}