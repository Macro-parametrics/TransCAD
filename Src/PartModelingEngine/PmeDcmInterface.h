#pragma once

struct IPmeDcmGeometry
{
	virtual DCM_g_type DcmGetIdentify() = 0;
	virtual void DcmTransform(double [3][3]) = 0;
	virtual void DcmSetStatus(g_node_status status) = 0;
};

struct IPmeDcmPoint
	: public IPmeDcmGeometry
{
	virtual void DcmGetPosition(double pt[2]) = 0;
};

struct IPmeDcmLine
	: public IPmeDcmGeometry
{
	virtual void DcmGetPosition(double pt[2]) = 0;
	virtual void DcmGetDirection(double dir[2]) = 0;
};

struct IPmeDcmCircle
	: public IPmeDcmGeometry
{
	virtual void DcmGetCenter(double pt[2]) = 0;
	virtual double DcmGetRadius() = 0;
	virtual void DcmSetRadius(double radius) = 0;
};

struct IPmeDcmDimension
{
	virtual DCM_d_type DcmGetDimensionType() = 0;
	virtual double DcmGetDimensionValue() = 0;
	virtual void DcmSetStatus(d_node_status status) = 0;

	virtual DCM_directed_type DcmGetDirected(double dir[2], void ** gn) = 0;
};

class PmeDcmCoincident
	: public IPmeDcmDimension
{
public:
	// IPmeDcmDimension
	virtual DCM_d_type DcmGetDimensionType() {return DCM_COINCIDENT;}
	virtual double DcmGetDimensionValue() {return 0.0;}
	virtual void DcmSetStatus(d_node_status status) {}
	virtual DCM_directed_type DcmGetDirected(double dir[2], void ** gn) {return DCM_NOT_DIRECTED;}
};

class PmeDcmConcentric
	: public IPmeDcmDimension
{
public:
	// IPmeDcmDimension
	virtual DCM_d_type DcmGetDimensionType() {return DCM_CONCENTRIC;}
	virtual double DcmGetDimensionValue() {return 0.0;}
	virtual void DcmSetStatus(d_node_status status) {}
	virtual DCM_directed_type DcmGetDirected(double dir[2], void ** gn) {return DCM_NOT_DIRECTED;}
};

class PmeDcmPerpendicular
	: public IPmeDcmDimension
{
public:
	// IPmeDcmDimension
	virtual DCM_d_type DcmGetDimensionType() {return DCM_PERPENDICULAR;}
	virtual double DcmGetDimensionValue() {return 0.0;}
	virtual void DcmSetStatus(d_node_status status) {}
	virtual DCM_directed_type DcmGetDirected(double dir[2], void ** gn) {return DCM_NOT_DIRECTED;}
};

class PmeDcmParallel
	: public IPmeDcmDimension
{
public:
	// IPmeDcmDimension
	virtual DCM_d_type DcmGetDimensionType() {return DCM_PARALLEL;}
	virtual double DcmGetDimensionValue() {return 0.0;}
	virtual void DcmSetStatus(d_node_status status) {}
	virtual DCM_directed_type DcmGetDirected(double dir[2], void ** gn) {return DCM_NOT_DIRECTED;}
};
