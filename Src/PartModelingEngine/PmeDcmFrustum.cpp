#include "stdafx.h"

#include ".\PmeDcmFrustum.h"
#include ".\PmeDcmInterface.h"

void DCM_license_message(char* message, char* ref_str)
{
	MessageBox(NULL, message, ref_str, MB_OK);
}

// Basic geometry enquiry functions

DCM_g_type DCM_g_identify(void * ag)
{
	return ((IPmeDcmGeometry *)ag)->DcmGetIdentify();
}

void DCM_point_point(double pt[2], void * ag)
{
	IPmeDcmPoint * pPoint = (IPmeDcmPoint *)ag;
	pPoint->DcmGetPosition(pt);	
}

void DCM_line_point(double pt[2], void * ag)
{
	IPmeDcmLine * pLine = (IPmeDcmLine *)ag;
	pLine->DcmGetPosition(pt);
}

void DCM_line_direction(double dir[2], void * ag)
{
	IPmeDcmLine * pLine = (IPmeDcmLine *)ag;
	pLine->DcmGetDirection(dir);
}

void DCM_circle_center(double pt[2], void * ag)
{
	IPmeDcmCircle * pCircle = (IPmeDcmCircle *)ag;
	pCircle->DcmGetCenter(pt);
}

double DCM_circle_radius(void * ag)
{
	IPmeDcmCircle * pCircle = (IPmeDcmCircle *)ag;
	return pCircle->DcmGetRadius();
}

// Basic dimension functions

DCM_d_type DCM_dimension_type(void * ad)
{
	IPmeDcmDimension * pDim = (IPmeDcmDimension *)ad;	
	return pDim->DcmGetDimensionType();
}

double DCM_dimension_value(void * ad)
{
	IPmeDcmDimension * pDim = (IPmeDcmDimension *)ad;
	return pDim->DcmGetDimensionValue();	
}

DCM_logical DCM_dimension_point(double hpt[2], void * ad, void * ag)
{
	return DCM_FALSE;
}

DCM_directed_type DCM_directed_distance(void * ad, double dir[2], void ** gn)
{
	IPmeDcmDimension * pDim = (IPmeDcmDimension *)ad;
	return pDim->DcmGetDirected(dir, gn);
}

// Functions for outputting change information

void DCM_transform(double mat[3][3], void * ag)
{
	IPmeDcmGeometry * pGeometry = (IPmeDcmGeometry *)ag;
	pGeometry->DcmTransform(mat);
}

void DCM_set_radius(double rad, void * ag)
{
	IPmeDcmCircle * pCircle = (IPmeDcmCircle *)ag;
	pCircle->DcmSetRadius(rad);
}

void DCM_g_status(g_node_status os, g_node_status ns, void * ag)
{
	((IPmeDcmGeometry *)ag)->DcmSetStatus(ns);
}

void DCM_d_status(d_node_status, d_node_status ns, void * ag)
{
	((IPmeDcmDimension *)ag)->DcmSetStatus(ns);
}

void PmeDcmRegisterFrustum(dimension_system * pDcm)
{
	DCM_frustum_functions frust;
	pDcm->enquire_frustum_functions(&frust);

	// Basic geometry enquiry functions
	frust.g_identify = &DCM_g_identify;
	frust.point_point = &DCM_point_point;
	frust.line_point = &DCM_line_point;
	frust.line_direction = &DCM_line_direction;
	frust.circle_center = &DCM_circle_center;
	frust.circle_radius = &DCM_circle_radius;

	// Basic dimension functions
	frust.dimension_type = &DCM_dimension_type;
	frust.dimension_value = &DCM_dimension_value;
	frust.directed_distance = &DCM_directed_distance;
	frust.dimension_point = &DCM_dimension_point;

	// Functions for outputting change information
	frust.transform = &DCM_transform;
	frust.set_radius = &DCM_set_radius;
	
	frust.g_status = &DCM_g_status;	
	frust.d_status = &DCM_d_status;

	pDcm->register_frustum_functions(&frust);
}

/*

void register_frustum(dimension_system* dsp)
	{
	DCM_frustum_functions frust;
	dsp->enquire_frustum_functions(&frust);

	// Missing functions either
	//    1. Take default action.
	//    2. Are not called, and so are not required.
	// Registering DCM_debug_message ensures we will be informed
	// of missing cases.

	frust.g_identify = &DCM_g_identify;
	frust.point_point = &DCM_point_point;
	frust.line_point = &DCM_line_point;
	frust.line_direction = &DCM_line_direction;
	frust.circle_center = &DCM_circle_center;
	frust.circle_radius = &DCM_circle_radius;
	frust.set_radius = &DCM_set_radius;
	frust.ellipse_center = &DCM_ellipse_center;
	frust.ellipse_direction = &DCM_ellipse_direction;
	frust.ellipse_major_radius = &DCM_ellipse_major_radius;
	frust.ellipse_minor_radius = &DCM_ellipse_minor_radius;
	frust.set_major_radius = &DCM_set_major_radius;
	frust.set_minor_radius = &DCM_set_minor_radius;
	frust.transform = &DCM_transform;
	frust.dimension_type = &DCM_dimension_type;
	frust.dimension_value = &DCM_dimension_value;
	frust.directed_distance = &DCM_directed_distance;
	frust.dimension_point = &DCM_dimension_point;
	frust.dimension_point_update = &DCM_dimension_point_update;
	frust.pattern_multiplier = &DCM_pattern_multiplier;
	frust.parametric_limits = &DCM_parametric_limits;
	frust.parametric_period = &DCM_parametric_period;
	frust.parametric_evaluator = &DCM_parametric_evaluator;
	frust.parametric_direction = &DCM_parametric_direction;
	frust.parametric_regenerate = &DCM_parametric_regenerate;
	frust.dimension_parameter = &DCM_dimension_parameter;
	frust.dimension_parameter_update = &DCM_dimension_parameter_update;
	frust.offset_orientation = &DCM_offset_orientation;
	frust.offset_distance = &DCM_offset_distance;
	frust.update_offset_data = &DCM_update_offset_data;
	frust.variable_start_value = &DCM_variable_start_value;
	frust.variable_new_value = &DCM_variable_new_value;
	frust.variable_dist_start_sign = &DCM_variable_dist_start_sign;
	frust.equation_type = &DCM_equation_type;
	frust.equation_constant_value = &DCM_equation_constant_value;
	frust.equation_coefficient_value = &DCM_equation_coefficient_value;
	frust.equation_derivative_value = &DCM_equation_derivative_value;
	frust.equation_residual = &DCM_equation_residual;
	frust.inequality_minimum = &DCM_inequality_minimum;
	frust.inequality_maximum = &DCM_inequality_maximum;
	frust.g_status = &DCM_g_status;
	frust.v_status = &DCM_v_status;
	frust.d_status = &DCM_d_status;
	frust.e_status = &DCM_e_status;
	frust.p_status = &DCM_p_status;
	frust.autodim_weight = &DCM_autodim_weight;
	frust.autodim_dir_weight = &DCM_autodim_dir_weight;
	frust.automatic_dimension = &DCM_automatic_dimension;
	frust.automatic_dir_dimension = &DCM_automatic_dir_dimension;
	frust.automatic_class = &DCM_automatic_class;
	frust.automatic_constraint = &DCM_automatic_constraint;
	frust.automatic_constraint3 = &DCM_automatic_constraint3;
	frust.deduced_class = &DCM_deduced_class;
	frust.deduced_constraint = &DCM_deduced_constraint;
	frust.deduced_constraint4 = &DCM_deduced_constraint4;
	//DCM_erased_node is not registered by default
	//frust.erased_node = &DCM_erased_node;
	frust.spline_changed = &DCM_spline_changed;
	frust.spline_status = &DCM_spline_status;

	frust.debug_message = &DCM_debug_message;
	
	dsp->register_frustum_functions(&frust);
}

*/