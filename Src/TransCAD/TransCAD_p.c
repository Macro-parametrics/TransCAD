

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Oct 27 02:55:44 2018
 */
/* Compiler settings for TransCAD.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "TransCAD_i.h"

#define TYPE_FORMAT_STRING_SIZE   2093                              
#define PROC_FORMAT_STRING_SIZE   12325                             
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _TransCAD_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } TransCAD_MIDL_TYPE_FORMAT_STRING;

typedef struct _TransCAD_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } TransCAD_MIDL_PROC_FORMAT_STRING;

typedef struct _TransCAD_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } TransCAD_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const TransCAD_MIDL_TYPE_FORMAT_STRING TransCAD__MIDL_TypeFormatString;
extern const TransCAD_MIDL_PROC_FORMAT_STRING TransCAD__MIDL_ProcFormatString;
extern const TransCAD_MIDL_EXPR_FORMAT_STRING TransCAD__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IApplication_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IApplication_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDocs_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDocs_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDoc_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDoc_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPartDocument_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPartDocument_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPart_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPart_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFeatures_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFeatures_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdDefaultDatumPlaneFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdDefaultDatumPlaneFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidProtrusionExtrudeFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidProtrusionExtrudeFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidCutExtrudeFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidCutExtrudeFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidFilletConstantFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidFilletConstantFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchOrigin_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchOrigin_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchVDirection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchVDirection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchHDirection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchHDirection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchGeometries_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchGeometries_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchConstraints_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchConstraints_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchGeometry_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchGeometry_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchConstraint_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchConstraint_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchCircle_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchCircle_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchCircularArc_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchCircularArc_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchControlPoint_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchControlPoint_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchLine_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchLine_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IReferences_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IReferences_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IReference_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IReference_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IExplicitModelObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IExplicitModelObject_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISketch_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISketch_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISketchEditor_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISketchEditor_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidProtrusionSweepFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidProtrusionSweepFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidProtrusionRevolveFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidProtrusionRevolveFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchCenterline_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchCenterline_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidOperatePatternRectangularFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidOperatePatternRectangularFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidChamferFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidChamferFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidCutRevolveFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidCutRevolveFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidOperatePatternCircularFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidOperatePatternCircularFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidHoleCounterboredFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidHoleCounterboredFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidHoleCountersunkFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidHoleCountersunkFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchCoincidentSamePoints_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchCoincidentSamePoints_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchParallel_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchParallel_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchPerpendicular_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchPerpendicular_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchHorizontal_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchHorizontal_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSketchVertical_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSketchVertical_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdDatumPlaneOffsetFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdDatumPlaneOffsetFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidLoftFacesFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidLoftFacesFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidLoftSectionsFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidLoftSectionsFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidCutSweepFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidCutSweepFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidHoleSimpleFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidHoleSimpleFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidShellFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidShellFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidRevolveWithExternalAxisFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidRevolveWithExternalAxisFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidDraftFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidDraftFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidOffsetFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidOffsetFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdSolidImportedBrepFeature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdSolidImportedBrepFeature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISolid_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISolid_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFaces_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFaces_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEdges_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEdges_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFace_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFace_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEdge_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEdge_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IVertices_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IVertices_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IVertex_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IVertex_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPoint3D_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPoint3D_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAxis1_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAxis1_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAssemDocument_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAssemDocument_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IComp_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IComp_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAssem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAssem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdAssemConstraints_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraints_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdAssemConstraint_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraint_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdAssemConstraintCoaxial_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraintCoaxial_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdAssemConstraintIncidence_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraintIncidence_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdAssemConstraintDistance_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraintDistance_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStdAssemConstraintAngle_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraintAngle_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const TransCAD_MIDL_PROC_FORMAT_STRING TransCAD__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_Visible */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x22 ),	/* 34 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 24 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Visible */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x6 ),	/* 6 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 60 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Application */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 88 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 96 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Parent */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0xa ),	/* 10 */
/* 116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 132 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ActiveDocument */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0xb ),	/* 11 */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 168 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Documents */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0xc ),	/* 12 */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 194 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 196 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 204 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 208 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */

/* 216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0xd ),	/* 13 */
/* 224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 230 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 232 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 234 */	NdrFcShort( 0x1 ),	/* 1 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 240 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 244 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */


	/* Procedure Quit */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0xe ),	/* 14 */
/* 260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 268 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Application */


	/* Procedure get_Application */


	/* Procedure get_Application */

/* 282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x7 ),	/* 7 */
/* 290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 296 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 298 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 306 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 308 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 310 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 314 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Parent */


	/* Procedure get_Parent */


	/* Procedure get_Parent */

/* 318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 326 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 332 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 334 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 342 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 344 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 346 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */


	/* Procedure get_Count */


	/* Procedure get_Count */


	/* Procedure get_Count */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x9 ),	/* 9 */
/* 362 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x24 ),	/* 36 */
/* 368 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 370 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 378 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 380 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 386 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0xa ),	/* 10 */
/* 398 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 400 */	NdrFcShort( 0x8 ),	/* 8 */
/* 402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 404 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 406 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 414 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 416 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 420 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 422 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 424 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 428 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0xb ),	/* 11 */
/* 440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 446 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 448 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppUnk */

/* 456 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 458 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 460 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddPartDocument */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0xc ),	/* 12 */
/* 476 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 482 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 484 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 492 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 494 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 496 */	NdrFcShort( 0xa0 ),	/* Type Offset=160 */

	/* Return value */

/* 498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 500 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddAssemDocument */

/* 504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0xd ),	/* 13 */
/* 512 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 520 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 528 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 530 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 532 */	NdrFcShort( 0xb6 ),	/* Type Offset=182 */

	/* Return value */

/* 534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 536 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Open */

/* 540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0xf ),	/* 15 */
/* 548 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 554 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 556 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x1 ),	/* 1 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filename */

/* 564 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 566 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 568 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ppVal */

/* 570 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 572 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 574 */	NdrFcShort( 0xa0 ),	/* Type Offset=160 */

	/* Return value */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */


	/* Procedure get_ReferenceeName */


	/* Procedure get_Name */


	/* Procedure get_Name */


	/* Procedure get_Name */


	/* Procedure get_Name */


	/* Procedure get_FullName */

/* 582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x9 ),	/* 9 */
/* 590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 596 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 598 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 600 */	NdrFcShort( 0x1 ),	/* 1 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 606 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 610 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */


	/* Procedure get_ParentName */


	/* Procedure get_Name */


	/* Procedure get_Name */


	/* Procedure get_Name */


	/* Procedure get_Name */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0xa ),	/* 10 */
/* 626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 632 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 634 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 636 */	NdrFcShort( 0x1 ),	/* 1 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 642 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */


	/* Procedure get_Path */

/* 654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0xb ),	/* 11 */
/* 662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 668 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 670 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 672 */	NdrFcShort( 0x1 ),	/* 1 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 678 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 682 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */


	/* Return value */

/* 684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Saved */

/* 690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0xc ),	/* 12 */
/* 698 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x22 ),	/* 34 */
/* 704 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 706 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 714 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 718 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Activate */

/* 726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0xd ),	/* 13 */
/* 734 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 742 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0xe ),	/* 14 */
/* 764 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 766 */	NdrFcShort( 0x6 ),	/* 6 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 772 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x1 ),	/* 1 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter saveChanges */

/* 780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter filename */

/* 786 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0xf ),	/* 15 */
/* 806 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 814 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 824 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveAs */

/* 828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0x10 ),	/* 16 */
/* 836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 842 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 844 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x1 ),	/* 1 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filename */

/* 852 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 854 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 856 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Part */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x11 ),	/* 17 */
/* 872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 878 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 880 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 888 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 890 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 892 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Return value */

/* 894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 896 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Update */


	/* Procedure Update */

/* 900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x12 ),	/* 18 */
/* 908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 914 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 916 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Title */

/* 930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x13 ),	/* 19 */
/* 938 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 944 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 946 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 948 */	NdrFcShort( 0x1 ),	/* 1 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 954 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 956 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 958 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */

/* 960 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 962 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 964 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoMeshGeneration */

/* 966 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 968 */	NdrFcLong( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x14 ),	/* 20 */
/* 974 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 976 */	NdrFcShort( 0x20 ),	/* 32 */
/* 978 */	NdrFcShort( 0x8 ),	/* 8 */
/* 980 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 982 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter normalTolerance */

/* 990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 992 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 994 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter surfaceTolerance */

/* 996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1000 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 1002 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1004 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBBDiagonal */

/* 1008 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1016 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1022 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1024 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1034 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ImportFromCATIA */

/* 1038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1046 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1052 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1054 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 1062 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1064 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1066 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1070 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportToCATIA */

/* 1074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1082 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1088 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1090 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 1098 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1100 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1102 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1106 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteByName */


	/* Procedure ImportFromUG */

/* 1110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1118 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1124 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1126 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter filePath */

/* 1134 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1138 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */


	/* Return value */

/* 1140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportToUG */

/* 1146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1160 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1162 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 1170 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1174 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportToMesh */

/* 1182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1190 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1196 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1198 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1202 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 1206 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1208 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1210 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1214 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportToBrep */

/* 1218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1226 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1232 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1234 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1240 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 1242 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1244 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1246 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1250 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportToXML */

/* 1254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1268 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1270 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1274 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 1278 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1280 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1282 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1286 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ImportFromXML */

/* 1290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1298 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1304 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1306 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 1314 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1316 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1318 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1322 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunScriptInterface */

/* 1326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1332 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1334 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1338 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1340 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1342 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter command */

/* 1350 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1352 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1354 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1358 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ImportFromBrep */

/* 1362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1370 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1376 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1378 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1382 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filePath */

/* 1386 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1390 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1394 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ConvertMesh */

/* 1398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1406 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1412 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1414 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1418 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter sourcePath */

/* 1422 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1424 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1426 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter targetPath */

/* 1428 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1430 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1432 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1436 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Features */

/* 1440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0xa ),	/* 10 */
/* 1448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1454 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1456 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 1464 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1466 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1468 */	NdrFcShort( 0xf0 ),	/* Type Offset=240 */

	/* Return value */

/* 1470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1472 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateReferences */

/* 1476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0xb ),	/* 11 */
/* 1484 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1490 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1492 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 1500 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1504 */	NdrFcShort( 0x106 ),	/* Type Offset=262 */

	/* Return value */

/* 1506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectObjectByName */

/* 1512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0xc ),	/* 12 */
/* 1520 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1526 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1528 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1532 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1536 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1538 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1540 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ppVal */

/* 1542 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1544 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1546 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 1548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1550 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectBrepByName */

/* 1554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0xd ),	/* 13 */
/* 1562 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1568 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1570 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1574 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1578 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1582 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ppVal */

/* 1584 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1588 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 1590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1592 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectPlaneByAxis */

/* 1596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0xe ),	/* 14 */
/* 1604 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 1606 */	NdrFcShort( 0x90 ),	/* 144 */
/* 1608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1610 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0xb,		/* 11 */
/* 1612 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ox */

/* 1620 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1624 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 1626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1628 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1630 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 1632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1634 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1636 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xx */

/* 1638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1640 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1642 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 1644 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1646 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1648 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 1650 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1652 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1654 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yx */

/* 1656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1658 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1660 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */

/* 1662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1664 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 1666 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */

/* 1668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1670 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 1672 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 1674 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1676 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 1678 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 1680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1682 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 1684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectCurveBy3Points */

/* 1686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0xf ),	/* 15 */
/* 1694 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 1696 */	NdrFcShort( 0x90 ),	/* 144 */
/* 1698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1700 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0xb,		/* 11 */
/* 1702 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter startx */

/* 1710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1712 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1714 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter starty */

/* 1716 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1718 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1720 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startz */

/* 1722 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1724 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1726 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endx */

/* 1728 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1730 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1732 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endy */

/* 1734 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1736 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1738 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endz */

/* 1740 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1742 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1744 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter curvex */

/* 1746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1748 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1750 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter curvey */

/* 1752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1754 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 1756 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter curvez */

/* 1758 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1760 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 1762 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 1764 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1766 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 1768 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 1770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1772 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectFeatureByName */

/* 1776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1784 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1790 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1792 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1800 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1802 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1804 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ppVal */

/* 1806 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1808 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1810 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectCurveByPoint */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1826 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1828 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1832 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter curvex */

/* 1842 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter curvey */

/* 1848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1850 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1852 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter curvez */

/* 1854 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1856 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1858 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 1860 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1862 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1864 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 1866 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1868 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure set_Name */

/* 1872 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1874 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1878 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1880 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1886 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1888 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1892 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1894 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1896 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1898 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1900 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 1902 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1904 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteByName */


	/* Procedure set_ParentName */

/* 1908 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1914 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1916 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1922 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1924 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1928 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter pVal */

/* 1932 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1934 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1936 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */


	/* Return value */

/* 1938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1940 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ParentName */

/* 1944 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1952 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1958 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1960 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1962 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1968 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1970 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1972 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */

/* 1974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1976 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadFromFile */

/* 1980 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1988 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1994 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1996 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2000 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2002 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2004 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2006 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2008 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 2010 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2012 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsCut */


	/* Procedure IsBrepPart */

/* 2016 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2018 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2022 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2024 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2028 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2030 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2032 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2038 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 2040 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2042 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2044 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2046 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2048 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectSketchSegmentByName */

/* 2052 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2060 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2066 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2068 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2072 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2076 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2078 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2080 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ppVal */

/* 2082 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2084 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2086 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 2088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2090 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Solid */

/* 2094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2102 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2108 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2110 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 2118 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2120 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2122 */	NdrFcShort( 0x132 ),	/* Type Offset=306 */

	/* Return value */

/* 2124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2126 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlacement */

/* 2130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2136 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2138 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x14c ),	/* 332 */
/* 2144 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xa,		/* 10 */
/* 2146 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ox */

/* 2154 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2156 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2158 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 2160 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2164 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 2166 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2168 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2170 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xx */

/* 2172 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2174 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2176 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 2178 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2180 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2182 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 2184 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2186 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2188 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yx */

/* 2190 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2192 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2194 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */

/* 2196 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2198 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2200 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */

/* 2202 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2204 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2206 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2210 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Application */

/* 2214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2220 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2222 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2228 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2230 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 2238 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2240 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2242 */	NdrFcShort( 0x14c ),	/* Type Offset=332 */

	/* Return value */

/* 2244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2246 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Parent */

/* 2250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2258 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2264 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2266 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2272 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 2274 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2276 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2278 */	NdrFcShort( 0x162 ),	/* Type Offset=354 */

	/* Return value */

/* 2280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2282 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 2286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2292 */	NdrFcShort( 0xa ),	/* 10 */
/* 2294 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2300 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2302 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 2310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 2316 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2320 */	NdrFcShort( 0x178 ),	/* Type Offset=376 */

	/* Return value */

/* 2322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2324 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 2328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0xb ),	/* 11 */
/* 2336 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2342 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2344 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppUnk */

/* 2352 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2354 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2356 */	NdrFcShort( 0x18e ),	/* Type Offset=398 */

	/* Return value */

/* 2358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2360 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSketchFeature */

/* 2364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2370 */	NdrFcShort( 0xc ),	/* 12 */
/* 2372 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2378 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2380 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2384 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2388 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2390 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2392 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pSketchPlane */

/* 2394 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2396 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2398 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter ppVal */

/* 2400 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2402 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2404 */	NdrFcShort( 0x1b6 ),	/* Type Offset=438 */

	/* Return value */

/* 2406 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2408 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidProtrusionExtrudeFeature */

/* 2412 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2414 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2418 */	NdrFcShort( 0xd ),	/* 13 */
/* 2420 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2422 */	NdrFcShort( 0x32 ),	/* 50 */
/* 2424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2426 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2428 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2434 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2436 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2438 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2440 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pProfileSketch */

/* 2442 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2444 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2446 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter startDepth */

/* 2448 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2450 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2452 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startCondition */

/* 2454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2456 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2458 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter endDepth */

/* 2460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2462 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2464 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endCondition */

/* 2466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2468 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2470 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter isFlip */

/* 2472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2474 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2476 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 2478 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2480 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2482 */	NdrFcShort( 0x1cc ),	/* Type Offset=460 */

	/* Return value */

/* 2484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2486 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidCutExtrudeFeature */

/* 2490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0xe ),	/* 14 */
/* 2498 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2500 */	NdrFcShort( 0x32 ),	/* 50 */
/* 2502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2504 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2506 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2514 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2518 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pProfileSketch */

/* 2520 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2524 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter startDepth */

/* 2526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2528 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2530 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startCondition */

/* 2532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2534 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2536 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter endDepth */

/* 2538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2540 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2542 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endCondition */

/* 2544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2546 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2548 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter isFlip */

/* 2550 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2552 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2554 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 2556 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2558 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2560 */	NdrFcShort( 0x1e2 ),	/* Type Offset=482 */

	/* Return value */

/* 2562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2564 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidFilletConstantFeature */

/* 2568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0xf ),	/* 15 */
/* 2576 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2578 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2582 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2584 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2588 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2592 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2594 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2596 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pfilletEdges */

/* 2598 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2600 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2602 */	NdrFcShort( 0x1f8 ),	/* Type Offset=504 */

	/* Parameter radius */

/* 2604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2606 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2608 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter propagation */

/* 2610 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2612 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2614 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 2616 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2618 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2620 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Return value */

/* 2622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2624 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidChamferFeature */

/* 2628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2634 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2636 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2638 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2642 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2644 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2652 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2654 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2656 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pSelectedEdges */

/* 2658 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2660 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2662 */	NdrFcShort( 0x1f8 ),	/* Type Offset=504 */

	/* Parameter length */

/* 2664 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2666 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2668 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 2670 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2672 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2674 */	NdrFcShort( 0x220 ),	/* Type Offset=544 */

	/* Return value */

/* 2676 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2678 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidProtrusionSweepFeature */

/* 2682 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2690 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2694 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2696 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2698 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2702 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2706 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2708 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2710 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pProfileSketch */

/* 2712 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2714 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2716 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter pGuideCurve */

/* 2718 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2720 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2722 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter ppVal */

/* 2724 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2726 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2728 */	NdrFcShort( 0x236 ),	/* Type Offset=566 */

	/* Return value */

/* 2730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2732 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidProtrusionRevolveFeature */

/* 2736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2742 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2744 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2746 */	NdrFcShort( 0x32 ),	/* 50 */
/* 2748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2750 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2752 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2756 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2758 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2760 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2762 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2764 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pProfileSketch */

/* 2766 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2768 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2770 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter startAngle */

/* 2772 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2774 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2776 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startCondition */

/* 2778 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2780 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2782 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter endAngle */

/* 2784 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2786 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2788 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endCondition */

/* 2790 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2792 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2794 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter isFlip */

/* 2796 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2798 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2800 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 2802 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2804 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2806 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Return value */

/* 2808 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2810 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 2812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidCutRevolveFeature */

/* 2814 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2816 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2820 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2822 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2824 */	NdrFcShort( 0x32 ),	/* 50 */
/* 2826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2828 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2830 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2834 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2836 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2838 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2840 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2842 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pProfileSketch */

/* 2844 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2846 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2848 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter startAngle */

/* 2850 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2852 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2854 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startCondition */

/* 2856 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2858 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2860 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter endAngle */

/* 2862 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2864 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2866 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endCondition */

/* 2868 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2870 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2872 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter isFlip */

/* 2874 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2876 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2878 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 2880 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2882 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2884 */	NdrFcShort( 0x262 ),	/* Type Offset=610 */

	/* Return value */

/* 2886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2888 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidOperatePatternRectangularFeature */

/* 2892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2900 */	NdrFcShort( 0x5c ),	/* x86 Stack size/offset = 92 */
/* 2902 */	NdrFcShort( 0x90 ),	/* 144 */
/* 2904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2906 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xe,		/* 14 */
/* 2908 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2916 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2918 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2920 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTargetFeatures */

/* 2922 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2924 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2926 */	NdrFcShort( 0x10a ),	/* Type Offset=266 */

	/* Parameter columnSpacing */

/* 2928 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2930 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2932 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter colDirX */

/* 2934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2936 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2938 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter colDirY */

/* 2940 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2942 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2944 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter colDirZ */

/* 2946 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2948 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2950 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter columnNumber */

/* 2952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2954 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 2956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rowSpacing */

/* 2958 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2960 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2962 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter rowDirX */

/* 2964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2966 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 2968 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter rowDirY */

/* 2970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2972 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 2974 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter rowDirZ */

/* 2976 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2978 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 2980 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter rowNumber */

/* 2982 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2984 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 2988 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2990 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 2992 */	NdrFcShort( 0x278 ),	/* Type Offset=632 */

	/* Return value */

/* 2994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2996 */	NdrFcShort( 0x58 ),	/* x86 Stack size/offset = 88 */
/* 2998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidOperatePatternCircularFeature */

/* 3000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3006 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3008 */	NdrFcShort( 0x60 ),	/* x86 Stack size/offset = 96 */
/* 3010 */	NdrFcShort( 0x96 ),	/* 150 */
/* 3012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3014 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xf,		/* 15 */
/* 3016 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3020 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3024 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3026 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3028 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTargetFeatures */

/* 3030 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3032 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3034 */	NdrFcShort( 0x10a ),	/* Type Offset=266 */

	/* Parameter x1 */

/* 3036 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3038 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3040 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter y1 */

/* 3042 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3044 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3046 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter z1 */

/* 3048 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3050 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3052 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter x2 */

/* 3054 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3056 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3058 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter y2 */

/* 3060 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3062 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3064 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter z2 */

/* 3066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3068 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 3070 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter angleNumber */

/* 3072 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3074 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 3076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter angleIncrement */

/* 3078 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3080 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 3082 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter radialNumber */

/* 3084 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3086 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 3088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter radialSpacing */

/* 3090 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3092 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 3094 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter radialAlignment */

/* 3096 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3098 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 3100 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3102 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3104 */	NdrFcShort( 0x58 ),	/* x86 Stack size/offset = 88 */
/* 3106 */	NdrFcShort( 0x28e ),	/* Type Offset=654 */

	/* Return value */

/* 3108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3110 */	NdrFcShort( 0x5c ),	/* x86 Stack size/offset = 92 */
/* 3112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidHoleCounterboredFeature */

/* 3114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3120 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3122 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 3124 */	NdrFcShort( 0x80 ),	/* 128 */
/* 3126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3128 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xc,		/* 12 */
/* 3130 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3134 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3138 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3142 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTargetFace */

/* 3144 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3148 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter cx */

/* 3150 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3154 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cy */

/* 3156 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3158 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3160 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cz */

/* 3162 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3164 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3166 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startRadius */

/* 3168 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3170 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3172 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startDepth */

/* 3174 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3176 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3178 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endRadius */

/* 3180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3182 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 3184 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endDepth */

/* 3186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3188 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 3190 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter angle */

/* 3192 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3194 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 3196 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3198 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3200 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 3202 */	NdrFcShort( 0x2a4 ),	/* Type Offset=676 */

	/* Return value */

/* 3204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3206 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 3208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidHoleCountersunkFeature */

/* 3210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3218 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 3220 */	NdrFcShort( 0x80 ),	/* 128 */
/* 3222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3224 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xc,		/* 12 */
/* 3226 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3230 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3234 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3238 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTargetFace */

/* 3240 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3244 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter cx */

/* 3246 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3250 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cy */

/* 3252 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3254 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3256 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cz */

/* 3258 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3260 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3262 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter radius */

/* 3264 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3266 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3268 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter depth */

/* 3270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3272 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3274 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter sinkRadius */

/* 3276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3278 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 3280 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter sinkAngle */

/* 3282 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3284 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 3286 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter bottomAngle */

/* 3288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3290 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 3292 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3294 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3296 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 3298 */	NdrFcShort( 0x2ba ),	/* Type Offset=698 */

	/* Return value */

/* 3300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3302 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewDatumPlaneOffsetFeature */

/* 3306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3314 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3316 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3320 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3322 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3330 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3334 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pSelectedPlane */

/* 3336 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3340 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter distance */

/* 3342 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3346 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter isFlip */

/* 3348 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3350 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3352 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3354 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3356 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3358 */	NdrFcShort( 0x2d0 ),	/* Type Offset=720 */

	/* Return value */

/* 3360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3362 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewDatumPlaneOffsetFeature2 */

/* 3366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3372 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3374 */	NdrFcShort( 0x5c ),	/* x86 Stack size/offset = 92 */
/* 3376 */	NdrFcShort( 0x96 ),	/* 150 */
/* 3378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3380 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xd,		/* 13 */
/* 3382 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3386 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3390 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3394 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ox */

/* 3396 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3400 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 3402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3404 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3406 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 3408 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3410 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3412 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xx */

/* 3414 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3416 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3418 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 3420 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3422 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3424 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 3426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3428 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3430 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yx */

/* 3432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3434 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3436 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */

/* 3438 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3440 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 3442 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */

/* 3444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3446 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 3448 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter isFlip */

/* 3450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3452 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 3454 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3456 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3458 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 3460 */	NdrFcShort( 0x2d0 ),	/* Type Offset=720 */

	/* Return value */

/* 3462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3464 */	NdrFcShort( 0x58 ),	/* x86 Stack size/offset = 88 */
/* 3466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidLoftFacesFeature */

/* 3468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3474 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3476 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3478 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3482 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3484 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3488 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3492 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3494 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3496 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pFace1 */

/* 3498 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3500 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3502 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter param1 */

/* 3504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3506 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3508 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pFace2 */

/* 3510 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3512 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3514 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter param2 */

/* 3516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3518 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3520 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3522 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3524 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3526 */	NdrFcShort( 0x2e6 ),	/* Type Offset=742 */

	/* Return value */

/* 3528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3530 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidLoftSectionsFeature */

/* 3534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3540 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3542 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3544 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3548 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3550 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3554 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3558 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3560 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3562 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pLoftSections */

/* 3564 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3566 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3568 */	NdrFcShort( 0x1f8 ),	/* Type Offset=504 */

	/* Parameter isCut */

/* 3570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3572 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3574 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3576 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3578 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3580 */	NdrFcShort( 0x2fc ),	/* Type Offset=764 */

	/* Return value */

/* 3582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3584 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidCutSweepFeature */

/* 3588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3594 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3596 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3602 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3604 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3608 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3612 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3616 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pProfileSketch */

/* 3618 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3622 */	NdrFcShort( 0x312 ),	/* Type Offset=786 */

	/* Parameter pGuideCurve */

/* 3624 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3628 */	NdrFcShort( 0x312 ),	/* Type Offset=786 */

	/* Parameter ppVal */

/* 3630 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3632 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3634 */	NdrFcShort( 0x324 ),	/* Type Offset=804 */

	/* Return value */

/* 3636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3638 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidHoleSimpleFeature */

/* 3642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3648 */	NdrFcShort( 0x1d ),	/* 29 */
/* 3650 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 3652 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3656 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 3658 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3662 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3666 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3670 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTargetFace */

/* 3672 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3676 */	NdrFcShort( 0x312 ),	/* Type Offset=786 */

	/* Parameter cx */

/* 3678 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3680 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3682 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cy */

/* 3684 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3686 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3688 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cz */

/* 3690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3692 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3694 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter Radius */

/* 3696 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3698 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3700 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter Depth */

/* 3702 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3704 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3706 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3708 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3710 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 3712 */	NdrFcShort( 0x33a ),	/* Type Offset=826 */

	/* Return value */

/* 3714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3716 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidShellFeature */

/* 3720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3726 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3728 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3730 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3734 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3736 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3740 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3744 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3748 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTargetFaces */

/* 3750 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3754 */	NdrFcShort( 0x1f8 ),	/* Type Offset=504 */

	/* Parameter innerThickness */

/* 3756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3758 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3760 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter outerThickness */

/* 3762 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3764 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3766 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3768 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3770 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3772 */	NdrFcShort( 0x350 ),	/* Type Offset=848 */

	/* Return value */

/* 3774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3776 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidRevolveWithExternalAxisFeature */

/* 3780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3786 */	NdrFcShort( 0x1f ),	/* 31 */
/* 3788 */	NdrFcShort( 0x64 ),	/* x86 Stack size/offset = 100 */
/* 3790 */	NdrFcShort( 0x98 ),	/* 152 */
/* 3792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3794 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x10,		/* 16 */
/* 3796 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3800 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3804 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3808 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pProfileSketch */

/* 3810 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3812 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3814 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Parameter startAngle */

/* 3816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3818 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3820 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startCondition */

/* 3822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3824 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3826 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter endAngle */

/* 3828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3830 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3832 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endCondition */

/* 3834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3836 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3838 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter orgX */

/* 3840 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3842 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3844 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgY */

/* 3846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3848 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3850 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgZ */

/* 3852 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3854 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 3856 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirX */

/* 3858 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3860 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 3862 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirY */

/* 3864 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3866 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 3868 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirZ */

/* 3870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3872 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 3874 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter isCut */

/* 3876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3878 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 3880 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter isFlip */

/* 3882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3884 */	NdrFcShort( 0x58 ),	/* x86 Stack size/offset = 88 */
/* 3886 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 3888 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3890 */	NdrFcShort( 0x5c ),	/* x86 Stack size/offset = 92 */
/* 3892 */	NdrFcShort( 0x366 ),	/* Type Offset=870 */

	/* Return value */

/* 3894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3896 */	NdrFcShort( 0x60 ),	/* x86 Stack size/offset = 96 */
/* 3898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */

/* 3900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3906 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3908 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3914 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3916 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 3924 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3930 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3932 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteByName */

/* 3936 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3942 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3944 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3950 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3952 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3956 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3958 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3960 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3962 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3964 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 3966 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3968 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidDraftFeature */

/* 3972 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3974 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3978 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3980 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 3982 */	NdrFcShort( 0x70 ),	/* 112 */
/* 3984 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3986 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 3988 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3992 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3994 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3996 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3998 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4000 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTargetFaces */

/* 4002 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4004 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4006 */	NdrFcShort( 0x10a ),	/* Type Offset=266 */

	/* Parameter orgX */

/* 4008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4010 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4012 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgY */

/* 4014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4016 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4018 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgZ */

/* 4020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4022 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4024 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirX */

/* 4026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4028 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 4030 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirY */

/* 4032 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4034 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 4036 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirZ */

/* 4038 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4040 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 4042 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter draftAngle */

/* 4044 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4046 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 4048 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 4050 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4052 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 4054 */	NdrFcShort( 0x37c ),	/* Type Offset=892 */

	/* Return value */

/* 4056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4058 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 4060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidOffsetFeature */

/* 4062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4068 */	NdrFcShort( 0x23 ),	/* 35 */
/* 4070 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4072 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4076 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4078 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4082 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 4086 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4090 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTargetFaces */

/* 4092 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4096 */	NdrFcShort( 0x10a ),	/* Type Offset=266 */

	/* Parameter offsetThickness */

/* 4098 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4100 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4102 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 4104 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4106 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4108 */	NdrFcShort( 0x392 ),	/* Type Offset=914 */

	/* Return value */

/* 4110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4112 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewSolidImportedBrepFeature */

/* 4116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4122 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4124 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4130 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4132 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4136 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 4140 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4144 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter filePath */

/* 4146 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4150 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ppVal */

/* 4152 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4156 */	NdrFcShort( 0x3a8 ),	/* Type Offset=936 */

	/* Return value */

/* 4158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4160 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Application */

/* 4164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4170 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4172 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4178 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4180 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4188 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4192 */	NdrFcShort( 0x3be ),	/* Type Offset=958 */

	/* Return value */

/* 4194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Parent */

/* 4200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4214 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4216 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4224 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4226 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4228 */	NdrFcShort( 0x3d4 ),	/* Type Offset=980 */

	/* Return value */

/* 4230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4232 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Type */


	/* Procedure get_Type */


	/* Procedure get_Type */


	/* Procedure get_Type */


	/* Procedure get_Type */

/* 4236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4242 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4244 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4248 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4250 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4252 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 4260 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 4262 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4264 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 4266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4268 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */


	/* Procedure SetName */

/* 4272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4278 */	NdrFcShort( 0xb ),	/* 11 */
/* 4280 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4286 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4288 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4292 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4294 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 4296 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4298 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4300 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */


	/* Return value */

/* 4302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4304 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Origin */

/* 4308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4314 */	NdrFcShort( 0xc ),	/* 12 */
/* 4316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4322 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4324 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4330 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4332 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4334 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4336 */	NdrFcShort( 0x3ee ),	/* Type Offset=1006 */

	/* Return value */

/* 4338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4340 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_HDirection */

/* 4344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4350 */	NdrFcShort( 0xd ),	/* 13 */
/* 4352 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4358 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4360 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4368 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4372 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 4374 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_VDirection */

/* 4380 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4386 */	NdrFcShort( 0xe ),	/* 14 */
/* 4388 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4392 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4394 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4396 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4404 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4406 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4408 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 4410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4412 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Geometries */

/* 4416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4422 */	NdrFcShort( 0xf ),	/* 15 */
/* 4424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4430 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4432 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4438 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4440 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4442 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4444 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 4446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4448 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Constraints */

/* 4452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4458 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4460 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4466 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4468 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4476 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4478 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4480 */	NdrFcShort( 0x446 ),	/* Type Offset=1094 */

	/* Return value */

/* 4482 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Sketch */

/* 4488 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4490 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4494 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4496 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4502 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4504 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4510 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4512 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4514 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4516 */	NdrFcShort( 0x45c ),	/* Type Offset=1116 */

	/* Return value */

/* 4518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4520 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SketchPlane */

/* 4524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4530 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4532 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4538 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4540 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4548 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4552 */	NdrFcShort( 0x472 ),	/* Type Offset=1138 */

	/* Return value */

/* 4554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsInversed */

/* 4560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4566 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4568 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4572 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4574 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4576 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 4584 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4586 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4588 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4592 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenEditor */

/* 4596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4602 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4610 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4612 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 4620 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4624 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */

	/* Return value */

/* 4626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenEditorEx */

/* 4632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4638 */	NdrFcShort( 0x15 ),	/* 21 */
/* 4640 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4642 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4646 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 4648 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter activateDcm */

/* 4656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4658 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4660 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 4662 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4666 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */

	/* Return value */

/* 4668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4670 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCoordinateSystem */

/* 4674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4680 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4682 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 4684 */	NdrFcShort( 0x90 ),	/* 144 */
/* 4686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4688 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xa,		/* 10 */
/* 4690 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ox */

/* 4698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4700 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4702 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 4704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4706 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4708 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 4710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4712 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4714 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xx */

/* 4716 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4718 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4720 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 4722 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4724 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 4726 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 4728 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4730 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 4732 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yx */

/* 4734 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4736 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 4738 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */

/* 4740 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4742 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 4744 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */

/* 4746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4748 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 4750 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 4752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4754 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 4756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCoordinateSystem */

/* 4758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4764 */	NdrFcShort( 0x17 ),	/* 23 */
/* 4766 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 4768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4770 */	NdrFcShort( 0x14c ),	/* 332 */
/* 4772 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xa,		/* 10 */
/* 4774 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4780 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ox */

/* 4782 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4784 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4786 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 4788 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4790 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4792 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 4794 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4796 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4798 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xx */

/* 4800 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4802 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4804 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 4806 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4808 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4810 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 4812 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4814 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4816 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yx */

/* 4818 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4820 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4822 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */

/* 4824 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4826 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4828 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */

/* 4830 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4832 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 4834 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 4836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4838 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ProfileSketch */


	/* Procedure get_ProfileSketch */

/* 4842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4848 */	NdrFcShort( 0xc ),	/* 12 */
/* 4850 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4856 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4858 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */

/* 4866 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4868 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4870 */	NdrFcShort( 0x472 ),	/* Type Offset=1138 */

	/* Return value */


	/* Return value */

/* 4872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4874 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ProfileSketch */


	/* Procedure put_ProfileSketch */

/* 4878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4884 */	NdrFcShort( 0xd ),	/* 13 */
/* 4886 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4892 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4894 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */

/* 4902 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4904 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4906 */	NdrFcShort( 0x312 ),	/* Type Offset=786 */

	/* Return value */


	/* Return value */

/* 4908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4910 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsFlip */


	/* Procedure get_IsFlip */


	/* Procedure get_IsFlip */


	/* Procedure get_IsFlip */


	/* Procedure get_IsFlip */

/* 4914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4920 */	NdrFcShort( 0xe ),	/* 14 */
/* 4922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4926 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4928 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4930 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4936 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 4938 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4940 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4942 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 4944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4946 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IsFlip */


	/* Procedure put_IsFlip */


	/* Procedure put_IsFlip */


	/* Procedure put_IsFlip */


	/* Procedure put_IsFlip */

/* 4950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4956 */	NdrFcShort( 0xf ),	/* 15 */
/* 4958 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4960 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4964 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4966 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 4974 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4976 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4978 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 4980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4982 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartCondition */


	/* Procedure get_StartCondition */


	/* Procedure get_StartCondition */


	/* Procedure get_Propagation */


	/* Procedure get_StartCondition */


	/* Procedure get_StartCondition */

/* 4986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4992 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4994 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4998 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5000 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5002 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5010 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 5012 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5014 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5016 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Propagation */


	/* Procedure put_StartCondition */


	/* Procedure put_StartCondition */

/* 5022 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5028 */	NdrFcShort( 0x11 ),	/* 17 */
/* 5030 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5032 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5036 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5038 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5044 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5046 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5048 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5050 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 5052 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5054 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */


	/* Procedure get_StartPosX */


	/* Procedure get_StartDepth */


	/* Procedure get_StartDepth */

/* 5058 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5060 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5064 */	NdrFcShort( 0x12 ),	/* 18 */
/* 5066 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5070 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5072 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5074 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5082 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5084 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5086 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5090 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_StartDepth */


	/* Procedure put_StartDepth */

/* 5094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5100 */	NdrFcShort( 0x13 ),	/* 19 */
/* 5102 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5104 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5108 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5110 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5118 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5120 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5122 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndCondition */


	/* Procedure get_EndCondition */

/* 5130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5136 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5138 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5142 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5144 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5146 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5154 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 5156 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5158 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */


	/* Return value */

/* 5160 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_EndCondition */


	/* Procedure put_EndCondition */

/* 5166 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5168 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5172 */	NdrFcShort( 0x15 ),	/* 21 */
/* 5174 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5176 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5178 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5180 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5182 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5190 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5192 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5194 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5198 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPosX */


	/* Procedure get_EndPosY */


	/* Procedure get_EndDepth */


	/* Procedure get_EndDepth */

/* 5202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5208 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5210 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5214 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5216 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5218 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5226 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5230 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_EndDepth */


	/* Procedure put_EndDepth */

/* 5238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5244 */	NdrFcShort( 0x17 ),	/* 23 */
/* 5246 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5248 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5252 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5254 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5264 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5266 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5270 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FilletEdges */

/* 5274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5280 */	NdrFcShort( 0xc ),	/* 12 */
/* 5282 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5288 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5290 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 5298 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5300 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5302 */	NdrFcShort( 0x48c ),	/* Type Offset=1164 */

	/* Return value */

/* 5304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5306 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FilletEdges */

/* 5310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5316 */	NdrFcShort( 0xd ),	/* 13 */
/* 5318 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5324 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5326 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5332 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 5334 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5336 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5338 */	NdrFcShort( 0x490 ),	/* Type Offset=1168 */

	/* Return value */

/* 5340 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5342 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OffsetThickness */


	/* Procedure get_DraftAngle */


	/* Procedure get_StartAngle */


	/* Procedure get_InnerThickness */


	/* Procedure get_ColumnSpacing */


	/* Procedure get_Radius */

/* 5346 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5352 */	NdrFcShort( 0xe ),	/* 14 */
/* 5354 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5358 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5360 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5362 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5368 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5370 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5372 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5374 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5378 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OffsetThickness */


	/* Procedure put_DraftAngle */


	/* Procedure put_StartAngle */


	/* Procedure put_InnerThickness */


	/* Procedure put_ColumnSpacing */


	/* Procedure put_Radius */

/* 5382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5388 */	NdrFcShort( 0xf ),	/* 15 */
/* 5390 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5392 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5394 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5396 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5398 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5410 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5414 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SinkRadius */


	/* Procedure get_EndRadius */


	/* Procedure get_StartPosX */


	/* Procedure get_RowSpacing */


	/* Procedure get_StartPosY */

/* 5418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5424 */	NdrFcShort( 0x13 ),	/* 19 */
/* 5426 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5430 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5432 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5434 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5442 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5446 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5450 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndAngle */


	/* Procedure get_StartPosY */


	/* Procedure get_EndAngle */


	/* Procedure get_StartPosZ */

/* 5454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5460 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5462 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5466 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5468 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5470 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5476 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5478 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5480 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5482 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5486 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SinkAngle */


	/* Procedure get_EndDepth */


	/* Procedure get_RadialSpacing */


	/* Procedure get_StartPosZ */


	/* Procedure get_EndPosX */

/* 5490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5496 */	NdrFcShort( 0x15 ),	/* 21 */
/* 5498 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5502 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5504 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5506 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5514 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5518 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_BottomAngle */


	/* Procedure get_Angle */


	/* Procedure get_EndPosY */


	/* Procedure get_EndPosZ */

/* 5526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5532 */	NdrFcShort( 0x17 ),	/* 23 */
/* 5534 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5538 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5540 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5542 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 5550 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5552 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5554 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5556 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5558 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartPosXAt */

/* 5562 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5564 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5568 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5570 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5574 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5576 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5578 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 5586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5588 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 5592 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5594 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5596 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 5598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5600 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartPosXAt */


	/* Procedure get_StartPosYAt */

/* 5604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5610 */	NdrFcShort( 0x19 ),	/* 25 */
/* 5612 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5616 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5618 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5620 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */


	/* Parameter index */

/* 5628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5634 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5638 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5642 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartPosYAt */


	/* Procedure get_StartPosZAt */

/* 5646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5652 */	NdrFcShort( 0x1a ),	/* 26 */
/* 5654 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5658 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5660 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5662 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */


	/* Parameter index */

/* 5670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5672 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5676 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5678 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5680 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartPosZAt */


	/* Procedure get_EndPosXAt */

/* 5688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5694 */	NdrFcShort( 0x1b ),	/* 27 */
/* 5696 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5700 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5702 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5704 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */


	/* Parameter index */

/* 5712 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5714 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5718 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5720 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5722 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5726 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPosXAt */


	/* Procedure get_EndPosYAt */

/* 5730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5736 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5738 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5742 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5744 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5746 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */


	/* Parameter index */

/* 5754 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5760 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5762 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5764 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5768 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPosYAt */


	/* Procedure get_EndPosZAt */

/* 5772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5778 */	NdrFcShort( 0x1d ),	/* 29 */
/* 5780 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5782 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5784 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5786 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5788 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5794 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */


	/* Parameter index */

/* 5796 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5798 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 5802 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5804 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5806 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5808 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5810 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Application */


	/* Procedure get_Application */


	/* Procedure get_Application */


	/* Procedure get_Application */

/* 5814 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5816 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5820 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5822 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5828 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5830 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5836 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 5838 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5840 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5842 */	NdrFcShort( 0x4a2 ),	/* Type Offset=1186 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5844 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5846 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Parent */


	/* Procedure get_Parent */


	/* Procedure get_Parent */


	/* Procedure get_Parent */

/* 5850 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5858 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5864 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5866 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 5874 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5876 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5878 */	NdrFcShort( 0x4b8 ),	/* Type Offset=1208 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5882 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SketchFeature */


	/* Procedure get_SketchFeature */


	/* Procedure get_SketchFeature */

/* 5886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5892 */	NdrFcShort( 0xa ),	/* 10 */
/* 5894 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5900 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5902 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 5910 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5912 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5914 */	NdrFcShort( 0x4ce ),	/* Type Offset=1230 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 5916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5918 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 5922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5928 */	NdrFcShort( 0xa ),	/* 10 */
/* 5930 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5932 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5936 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5938 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5944 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 5946 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5948 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 5952 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5954 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5956 */	NdrFcShort( 0x4e4 ),	/* Type Offset=1252 */

	/* Return value */

/* 5958 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5960 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 5964 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5970 */	NdrFcShort( 0xb ),	/* 11 */
/* 5972 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5978 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5980 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5986 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppUnk */

/* 5988 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5990 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5992 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 5994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5996 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FindByName */

/* 6000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6006 */	NdrFcShort( 0xc ),	/* 12 */
/* 6008 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6014 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6016 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 6024 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6026 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6028 */	NdrFcShort( 0x4e4 ),	/* Type Offset=1252 */

	/* Return value */

/* 6030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6032 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Application */


	/* Procedure get_Application */


	/* Procedure get_Application */


	/* Procedure get_Application */


	/* Procedure get_Application */

/* 6036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6042 */	NdrFcShort( 0x7 ),	/* 7 */
/* 6044 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6050 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6052 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 6060 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6062 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6064 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 6066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6068 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Parent */


	/* Procedure get_Parent */


	/* Procedure get_Parent */


	/* Procedure get_Parent */


	/* Procedure get_Parent */

/* 6072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6080 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6086 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6088 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 6096 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6098 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6100 */	NdrFcShort( 0x526 ),	/* Type Offset=1318 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 6102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 6108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6114 */	NdrFcShort( 0xa ),	/* 10 */
/* 6116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6122 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 6124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 6132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 6138 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6142 */	NdrFcShort( 0x53c ),	/* Type Offset=1340 */

	/* Return value */

/* 6144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 6150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6156 */	NdrFcShort( 0xb ),	/* 11 */
/* 6158 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6164 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6166 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppUnk */

/* 6174 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6178 */	NdrFcShort( 0x552 ),	/* Type Offset=1362 */

	/* Return value */

/* 6180 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FindByName */

/* 6186 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6192 */	NdrFcShort( 0xc ),	/* 12 */
/* 6194 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6200 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6202 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6208 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 6210 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6212 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6214 */	NdrFcShort( 0x53c ),	/* Type Offset=1340 */

	/* Return value */

/* 6216 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6218 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SketchFeature */


	/* Procedure get_SketchFeature */

/* 6222 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6224 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6228 */	NdrFcShort( 0xb ),	/* 11 */
/* 6230 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6236 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6238 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6244 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */

/* 6246 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6248 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6250 */	NdrFcShort( 0x568 ),	/* Type Offset=1384 */

	/* Return value */


	/* Return value */

/* 6252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6254 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartPoint */


	/* Procedure get_CenterPoint */


	/* Procedure get_CenterPoint */

/* 6258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6264 */	NdrFcShort( 0xc ),	/* 12 */
/* 6266 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6272 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6274 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 6282 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6286 */	NdrFcShort( 0x57e ),	/* Type Offset=1406 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 6288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6290 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Param1 */


	/* Procedure get_Y */


	/* Procedure get_Radius */

/* 6294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6300 */	NdrFcShort( 0xd ),	/* 13 */
/* 6302 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6306 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6308 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 6318 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6322 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 6324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPoint */


	/* Procedure get_StartPoint */

/* 6330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6336 */	NdrFcShort( 0xd ),	/* 13 */
/* 6338 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6344 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6346 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */

/* 6354 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6358 */	NdrFcShort( 0x57e ),	/* Type Offset=1406 */

	/* Return value */


	/* Return value */

/* 6360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPoint */

/* 6366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6372 */	NdrFcShort( 0xe ),	/* 14 */
/* 6374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6380 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6382 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 6390 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6394 */	NdrFcShort( 0x57e ),	/* Type Offset=1406 */

	/* Return value */

/* 6396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Area */


	/* Procedure get_Radius */


	/* Procedure get_Param2 */


	/* Procedure get_Radius */


	/* Procedure get_StartRadius */


	/* Procedure get_Radius */

/* 6402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6408 */	NdrFcShort( 0xf ),	/* 15 */
/* 6410 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6414 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6416 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6418 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 6426 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6428 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6430 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 6432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OuterThickness */


	/* Procedure get_Distance */


	/* Procedure get_Length */


	/* Procedure get_StartAngle */

/* 6438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6444 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6446 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6450 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6452 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6454 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 6462 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6464 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6466 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 6468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6470 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndAngle */


	/* Procedure get_Depth */


	/* Procedure get_Depth */


	/* Procedure get_StartDepth */


	/* Procedure get_AngleIncrement */


	/* Procedure get_StartAngle */


	/* Procedure get_StartAngle */


	/* Procedure get_EndAngle */

/* 6474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6480 */	NdrFcShort( 0x11 ),	/* 17 */
/* 6482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6486 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6488 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6490 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 6498 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6502 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 6504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6506 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_X */

/* 6510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6516 */	NdrFcShort( 0xc ),	/* 12 */
/* 6518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6522 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6524 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6526 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 6534 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6536 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6538 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 6540 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6542 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */


	/* Procedure get_Count */


	/* Procedure get_Count */


	/* Procedure get_Count */


	/* Procedure get_Count */

/* 6546 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6552 */	NdrFcShort( 0x7 ),	/* 7 */
/* 6554 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6558 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6560 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6562 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 6570 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6572 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 6576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6578 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 6582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6590 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6592 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6596 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 6598 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 6606 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 6612 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6616 */	NdrFcShort( 0x594 ),	/* Type Offset=1428 */

	/* Return value */

/* 6618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6620 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 6624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6630 */	NdrFcShort( 0x9 ),	/* 9 */
/* 6632 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6638 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6640 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppUnk */

/* 6648 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6650 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6652 */	NdrFcShort( 0x4fa ),	/* Type Offset=1274 */

	/* Return value */

/* 6654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6656 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 6660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6666 */	NdrFcShort( 0xa ),	/* 10 */
/* 6668 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6674 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6676 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 6684 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6686 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6688 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Return value */

/* 6690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Type */


	/* Procedure get_Type */


	/* Procedure get_Type */

/* 6696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6702 */	NdrFcShort( 0x7 ),	/* 7 */
/* 6704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6708 */	NdrFcShort( 0x22 ),	/* 34 */
/* 6710 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6712 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 6720 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 6722 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6724 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 6726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6728 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */


	/* Procedure get_Name */


	/* Procedure get_Name */

/* 6732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6740 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6746 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6748 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6750 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 6756 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 6758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6760 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 6762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Creator */

/* 6768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6774 */	NdrFcShort( 0xa ),	/* 10 */
/* 6776 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6782 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6784 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6790 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 6792 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6794 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6796 */	NdrFcShort( 0x5aa ),	/* Type Offset=1450 */

	/* Return value */

/* 6798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6800 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */

/* 6804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6810 */	NdrFcShort( 0x7 ),	/* 7 */
/* 6812 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6818 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6820 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create2DLine2Points */

/* 6834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6842 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 6844 */	NdrFcShort( 0x40 ),	/* 64 */
/* 6846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6848 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 6850 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6854 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 6858 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6862 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter startX */

/* 6864 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6868 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startY */

/* 6870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6872 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6874 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endX */

/* 6876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6878 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6880 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endY */

/* 6882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6884 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6886 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 6888 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6890 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6892 */	NdrFcShort( 0x5c0 ),	/* Type Offset=1472 */

	/* Return value */

/* 6894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6896 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 6898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create2DCircleCenterPoint */

/* 6900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6906 */	NdrFcShort( 0x9 ),	/* 9 */
/* 6908 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6910 */	NdrFcShort( 0x30 ),	/* 48 */
/* 6912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6914 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 6916 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6920 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 6924 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6928 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter centerX */

/* 6930 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6932 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6934 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter centerY */

/* 6936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6938 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6940 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter radius */

/* 6942 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6944 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6946 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 6948 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6950 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6952 */	NdrFcShort( 0x5d6 ),	/* Type Offset=1494 */

	/* Return value */

/* 6954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6956 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 6958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create2DArc */

/* 6960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6966 */	NdrFcShort( 0xa ),	/* 10 */
/* 6968 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 6970 */	NdrFcShort( 0x50 ),	/* 80 */
/* 6972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6974 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 6976 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6980 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 6984 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6988 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter centerX */

/* 6990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6994 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter centerY */

/* 6996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6998 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7000 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter radius */

/* 7002 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7004 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7006 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startAngle */

/* 7008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7010 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7012 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endAngle */

/* 7014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7016 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7018 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 7020 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7022 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 7024 */	NdrFcShort( 0x5ec ),	/* Type Offset=1516 */

	/* Return value */

/* 7026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7028 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 7030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create2DArcCenterStartEnd */

/* 7032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7038 */	NdrFcShort( 0xb ),	/* 11 */
/* 7040 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 7042 */	NdrFcShort( 0x60 ),	/* 96 */
/* 7044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7046 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 7048 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7052 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7056 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7058 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7060 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter centerX */

/* 7062 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7064 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7066 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter centerY */

/* 7068 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7070 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7072 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startX */

/* 7074 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7076 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7078 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startY */

/* 7080 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7082 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7084 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endX */

/* 7086 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7088 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7090 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endY */

/* 7092 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7094 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 7096 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 7098 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7100 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 7102 */	NdrFcShort( 0x5ec ),	/* Type Offset=1516 */

	/* Return value */

/* 7104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7106 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 7108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create2DArc3Points */

/* 7110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7116 */	NdrFcShort( 0xc ),	/* 12 */
/* 7118 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 7120 */	NdrFcShort( 0x60 ),	/* 96 */
/* 7122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7124 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 7126 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7130 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7134 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7138 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter startX */

/* 7140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7144 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startY */

/* 7146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7148 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7150 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter intermediateX */

/* 7152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7154 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7156 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter intermediateY */

/* 7158 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7160 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7162 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endX */

/* 7164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7166 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7168 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endY */

/* 7170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7172 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 7174 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 7176 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7178 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 7180 */	NdrFcShort( 0x5ec ),	/* Type Offset=1516 */

	/* Return value */

/* 7182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7184 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 7186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create2DCenterline2Points */

/* 7188 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7194 */	NdrFcShort( 0xd ),	/* 13 */
/* 7196 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 7198 */	NdrFcShort( 0x40 ),	/* 64 */
/* 7200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7202 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 7204 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7208 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7210 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7212 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7214 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7216 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter startX */

/* 7218 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7220 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7222 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter startY */

/* 7224 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7226 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7228 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endX */

/* 7230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7232 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7234 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter endY */

/* 7236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7238 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7240 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 7242 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7244 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7246 */	NdrFcShort( 0x5c0 ),	/* Type Offset=1472 */

	/* Return value */

/* 7248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7250 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 7252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateCoincidentSamePoints */

/* 7254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7260 */	NdrFcShort( 0xe ),	/* 14 */
/* 7262 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7264 */	NdrFcShort( 0xc ),	/* 12 */
/* 7266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7268 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 7270 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7274 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7278 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7280 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7282 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pFirstObject */

/* 7284 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7286 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7288 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Parameter firstType */

/* 7290 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7294 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pSecondObject */

/* 7296 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7298 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7300 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Parameter secondType */

/* 7302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7304 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7306 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 7308 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7310 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7312 */	NdrFcShort( 0x614 ),	/* Type Offset=1556 */

	/* Return value */

/* 7314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7316 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 7318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreatePerpendicular */

/* 7320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7326 */	NdrFcShort( 0xf ),	/* 15 */
/* 7328 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7334 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 7336 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7340 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7344 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7348 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pReferenceEdit */

/* 7350 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7354 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Parameter pTarget */

/* 7356 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7360 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Parameter ppVal */

/* 7362 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7364 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7366 */	NdrFcShort( 0x62a ),	/* Type Offset=1578 */

	/* Return value */

/* 7368 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7370 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateParallel */

/* 7374 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7376 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7380 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7382 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7388 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 7390 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7394 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7396 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7398 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7400 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7402 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pReferenceEdit */

/* 7404 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7406 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7408 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Parameter pTarget */

/* 7410 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7412 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7414 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Parameter ppVal */

/* 7416 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7418 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7420 */	NdrFcShort( 0x640 ),	/* Type Offset=1600 */

	/* Return value */

/* 7422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7424 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateHorizontal */

/* 7428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7434 */	NdrFcShort( 0x11 ),	/* 17 */
/* 7436 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7442 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 7444 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7448 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7452 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7454 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7456 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTarget */

/* 7458 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7460 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7462 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Parameter ppVal */

/* 7464 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7468 */	NdrFcShort( 0x656 ),	/* Type Offset=1622 */

	/* Return value */

/* 7470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7472 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateVertical */

/* 7476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7482 */	NdrFcShort( 0x12 ),	/* 18 */
/* 7484 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7490 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 7492 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7496 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7500 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7504 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pTarget */

/* 7506 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7510 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Parameter ppVal */

/* 7512 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7514 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7516 */	NdrFcShort( 0x66c ),	/* Type Offset=1644 */

	/* Return value */

/* 7518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7520 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ProfileSketch */


	/* Procedure get_TargetFace */


	/* Procedure get_ProfileSketch */


	/* Procedure get_Face1 */


	/* Procedure get_SelectedPlane */


	/* Procedure get_Target */


	/* Procedure get_Target */


	/* Procedure get_ReferenceEdit */


	/* Procedure get_ReferenceEdit */


	/* Procedure get_FirstObject */


	/* Procedure get_TargetFace */


	/* Procedure get_TargetFace */


	/* Procedure get_ProfileSketch */


	/* Procedure get_ProfileSketch */


	/* Procedure get_ProfileSketch */

/* 7524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7530 */	NdrFcShort( 0xc ),	/* 12 */
/* 7532 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7538 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7540 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 7548 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7552 */	NdrFcShort( 0x682 ),	/* Type Offset=1666 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 7554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ProfileSketch */


	/* Procedure put_TargetFace */


	/* Procedure put_ProfileSketch */


	/* Procedure put_SelectedPlane */


	/* Procedure put_TargetFace */


	/* Procedure put_TargetFace */


	/* Procedure put_ProfileSketch */


	/* Procedure put_ProfileSketch */


	/* Procedure put_ProfileSketch */

/* 7560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7566 */	NdrFcShort( 0xd ),	/* 13 */
/* 7568 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7574 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7576 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 7584 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7586 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7588 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 7590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7592 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_GuideCurve */


	/* Procedure get_Face2 */


	/* Procedure get_SecondObject */


	/* Procedure get_GuideCurve */

/* 7596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7602 */	NdrFcShort( 0xe ),	/* 14 */
/* 7604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7610 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7612 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 7620 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7624 */	NdrFcShort( 0x682 ),	/* Type Offset=1666 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 7626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_GuideCurve */


	/* Procedure put_GuideCurve */

/* 7632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7638 */	NdrFcShort( 0xf ),	/* 15 */
/* 7640 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7646 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7648 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */

/* 7656 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7658 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7660 */	NdrFcShort( 0x602 ),	/* Type Offset=1538 */

	/* Return value */


	/* Return value */

/* 7662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_EndAngle */


	/* Procedure put_Depth */


	/* Procedure put_Depth */


	/* Procedure put_StartDepth */


	/* Procedure put_AngleIncrement */


	/* Procedure put_StartAngle */


	/* Procedure put_StartAngle */

/* 7668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7674 */	NdrFcShort( 0x12 ),	/* 18 */
/* 7676 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7678 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7682 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7684 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 7692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7694 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7696 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 7698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7700 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndCondition */


	/* Procedure get_EndCondition */


	/* Procedure get_EndCondition */

/* 7704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7710 */	NdrFcShort( 0x13 ),	/* 19 */
/* 7712 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7716 */	NdrFcShort( 0x22 ),	/* 34 */
/* 7718 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7720 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 7728 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 7730 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7732 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 7734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7736 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_EndAngle */


	/* Procedure put_EndAngle */

/* 7740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7746 */	NdrFcShort( 0x15 ),	/* 21 */
/* 7748 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7750 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7754 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7756 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 7764 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7768 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 7770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7772 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartPoint */

/* 7776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7782 */	NdrFcShort( 0xc ),	/* 12 */
/* 7784 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7790 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7792 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 7800 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7802 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7804 */	NdrFcShort( 0x686 ),	/* Type Offset=1670 */

	/* Return value */

/* 7806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7808 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPoint */

/* 7812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7818 */	NdrFcShort( 0xd ),	/* 13 */
/* 7820 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7826 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7828 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 7836 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7838 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7840 */	NdrFcShort( 0x686 ),	/* Type Offset=1670 */

	/* Return value */

/* 7842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7844 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TargetFaces */


	/* Procedure get_TargetFaces */


	/* Procedure get_TargetFaces */


	/* Procedure get_References */


	/* Procedure get_TargetFeatures */


	/* Procedure get_TargetFeatures */

/* 7848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7854 */	NdrFcShort( 0xc ),	/* 12 */
/* 7856 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7862 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7864 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7870 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 7872 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7874 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7876 */	NdrFcShort( 0x69c ),	/* Type Offset=1692 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 7878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7880 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TargetFaces */


	/* Procedure put_TargetFaces */


	/* Procedure put_TargetFaces */


	/* Procedure put_TargetFeatures */


	/* Procedure put_TargetFeatures */

/* 7884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7890 */	NdrFcShort( 0xd ),	/* 13 */
/* 7892 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7898 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7900 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 7908 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7912 */	NdrFcShort( 0x6a0 ),	/* Type Offset=1696 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 7914 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ColumnDirection */

/* 7920 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7926 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7928 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7932 */	NdrFcShort( 0x74 ),	/* 116 */
/* 7934 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 7936 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7942 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 7944 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7946 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7948 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter y */

/* 7950 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7952 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7954 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter z */

/* 7956 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7958 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7960 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7964 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSize */


	/* Procedure get_ColumnNumber */

/* 7968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7974 */	NdrFcShort( 0x11 ),	/* 17 */
/* 7976 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7980 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7982 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7984 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7990 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 7992 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7994 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 7998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ColumnNumber */

/* 8004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8010 */	NdrFcShort( 0x12 ),	/* 18 */
/* 8012 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8018 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8020 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8028 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8030 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8036 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SinkRadius */


	/* Procedure put_EndRadius */


	/* Procedure put_RowSpacing */

/* 8040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8046 */	NdrFcShort( 0x14 ),	/* 20 */
/* 8048 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8050 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8052 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8054 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8056 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 8064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8066 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8068 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 8070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8072 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_YDirection */


	/* Procedure get_RowDirection */

/* 8076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8082 */	NdrFcShort( 0x15 ),	/* 21 */
/* 8084 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8088 */	NdrFcShort( 0x74 ),	/* 116 */
/* 8090 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 8092 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter yx */


	/* Parameter x */

/* 8100 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8104 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */


	/* Parameter y */

/* 8106 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8110 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */


	/* Parameter z */

/* 8112 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8116 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 8118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8120 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RowNumber */

/* 8124 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8130 */	NdrFcShort( 0x16 ),	/* 22 */
/* 8132 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8136 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8138 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8140 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8146 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8148 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8150 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8154 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8156 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RowNumber */

/* 8160 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8166 */	NdrFcShort( 0x17 ),	/* 23 */
/* 8168 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8172 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8174 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8176 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8184 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8186 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8192 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutYDirection */


	/* Procedure PutColumnDirection */

/* 8196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8202 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8204 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 8206 */	NdrFcShort( 0x30 ),	/* 48 */
/* 8208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8210 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 8212 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter yx */


	/* Parameter x */

/* 8220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8224 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */


	/* Parameter y */

/* 8226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8228 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8230 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */


	/* Parameter z */

/* 8232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8234 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8236 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 8238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8240 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 8242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutCenterPoint */


	/* Procedure PutCenterPoint */


	/* Procedure PutRowDirection */

/* 8244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8250 */	NdrFcShort( 0x19 ),	/* 25 */
/* 8252 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 8254 */	NdrFcShort( 0x30 ),	/* 48 */
/* 8256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8258 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 8260 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cx */


	/* Parameter cx */


	/* Parameter x */

/* 8268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8272 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cy */


	/* Parameter cy */


	/* Parameter y */

/* 8274 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8276 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8278 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cz */


	/* Parameter cz */


	/* Parameter z */

/* 8280 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8282 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8284 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 8286 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8288 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 8290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ChamferType */

/* 8292 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8294 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8298 */	NdrFcShort( 0xc ),	/* 12 */
/* 8300 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8304 */	NdrFcShort( 0x22 ),	/* 34 */
/* 8306 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8308 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8314 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8316 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 8318 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8320 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */

/* 8322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8324 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SelectedEdges */

/* 8328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8334 */	NdrFcShort( 0xd ),	/* 13 */
/* 8336 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8342 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8344 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 8352 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8354 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8356 */	NdrFcShort( 0x69c ),	/* Type Offset=1692 */

	/* Return value */

/* 8358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8360 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SelectedEdges */

/* 8364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8370 */	NdrFcShort( 0xe ),	/* 14 */
/* 8372 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8378 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 8380 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 8388 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 8390 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8392 */	NdrFcShort( 0x6a0 ),	/* Type Offset=1696 */

	/* Return value */

/* 8394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8396 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReferenceGeometry */


	/* Procedure get_ReferenceGeometry */


	/* Procedure get_ReferenceGeometry */


	/* Procedure get_ReferenceGeometry */


	/* Procedure get_SelectedFace */

/* 8400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8406 */	NdrFcShort( 0xf ),	/* 15 */
/* 8408 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8414 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8416 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 8424 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8426 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8428 */	NdrFcShort( 0x682 ),	/* Type Offset=1666 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 8430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OuterThickness */


	/* Procedure put_Distance */


	/* Procedure put_Length */

/* 8436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8442 */	NdrFcShort( 0x11 ),	/* 17 */
/* 8444 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8446 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8450 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8452 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 8460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8462 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8464 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 8466 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8468 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPosZ */

/* 8472 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8478 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8480 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8484 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8486 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8488 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8494 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8496 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8498 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8500 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 8502 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8504 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPosZAt */

/* 8508 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8514 */	NdrFcShort( 0x1e ),	/* 30 */
/* 8516 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8520 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8522 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8524 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 8532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8534 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 8538 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8540 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8542 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 8544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8546 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CenterAxis */

/* 8550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8556 */	NdrFcShort( 0xe ),	/* 14 */
/* 8558 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 8560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8562 */	NdrFcShort( 0xe0 ),	/* 224 */
/* 8564 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 8566 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x1 */

/* 8574 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8576 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8578 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter y1 */

/* 8580 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8582 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8584 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter z1 */

/* 8586 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8588 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8590 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter x2 */

/* 8592 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8594 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8596 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter y2 */

/* 8598 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8600 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8602 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter z2 */

/* 8604 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8606 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8608 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 8610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8612 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 8614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_AngleNumber */

/* 8616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8622 */	NdrFcShort( 0xf ),	/* 15 */
/* 8624 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8628 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8630 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8632 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8638 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8640 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8642 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8646 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8648 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_AngleNumber */

/* 8652 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8654 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8658 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8660 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8662 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8666 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8668 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8674 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8676 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8678 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8684 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RadialNumber */

/* 8688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8694 */	NdrFcShort( 0x13 ),	/* 19 */
/* 8696 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8700 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8702 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8704 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8712 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8714 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8720 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RadialNumber */

/* 8724 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8730 */	NdrFcShort( 0x14 ),	/* 20 */
/* 8732 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8738 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8740 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8750 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8756 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SinkAngle */


	/* Procedure put_EndDepth */


	/* Procedure put_RadialSpacing */

/* 8760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8766 */	NdrFcShort( 0x16 ),	/* 22 */
/* 8768 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8770 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8774 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8776 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8782 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 8784 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8786 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8788 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 8790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8792 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsRadialAnignment */

/* 8796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8802 */	NdrFcShort( 0x17 ),	/* 23 */
/* 8804 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8808 */	NdrFcShort( 0x22 ),	/* 34 */
/* 8810 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8812 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8818 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8820 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8822 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8824 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8828 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IsRadialAnignment */

/* 8832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8838 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8840 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8842 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8846 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8848 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 8856 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8858 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8860 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8864 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutRevolveAxis */


	/* Procedure PutCenterAxis */

/* 8868 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8874 */	NdrFcShort( 0x19 ),	/* 25 */
/* 8876 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 8878 */	NdrFcShort( 0x60 ),	/* 96 */
/* 8880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8882 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 8884 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter orgX */


	/* Parameter x1 */

/* 8892 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8894 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8896 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgY */


	/* Parameter y1 */

/* 8898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8902 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgZ */


	/* Parameter z1 */

/* 8904 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8906 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8908 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirX */


	/* Parameter x2 */

/* 8910 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8912 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 8914 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirY */


	/* Parameter y2 */

/* 8916 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8918 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 8920 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirZ */


	/* Parameter z2 */

/* 8922 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8924 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 8926 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 8928 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8930 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 8932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ZDirection */


	/* Procedure get_CenterPoint */


	/* Procedure get_CenterPoint */


	/* Procedure get_CenterPoint */

/* 8934 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8936 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8940 */	NdrFcShort( 0xe ),	/* 14 */
/* 8942 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8946 */	NdrFcShort( 0x74 ),	/* 116 */
/* 8948 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 8950 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8956 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter zx */


	/* Parameter cx */


	/* Parameter cx */


	/* Parameter cx */

/* 8958 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8960 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8962 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter zy */


	/* Parameter cy */


	/* Parameter cy */


	/* Parameter cy */

/* 8964 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8966 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8968 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter zz */


	/* Parameter cz */


	/* Parameter cz */


	/* Parameter cz */

/* 8970 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8972 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8974 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 8976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8978 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Radius */


	/* Procedure put_Radius */


	/* Procedure put_StartRadius */

/* 8982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8988 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8990 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8992 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8996 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8998 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9004 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 9006 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9008 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9010 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 9012 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9014 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_BottomAngle */


	/* Procedure put_Angle */

/* 9018 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9020 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9024 */	NdrFcShort( 0x18 ),	/* 24 */
/* 9026 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9028 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9032 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9034 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9040 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 9042 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9044 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9046 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 9048 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9050 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9052 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FirstType */

/* 9054 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9056 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9060 */	NdrFcShort( 0xd ),	/* 13 */
/* 9062 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9066 */	NdrFcShort( 0x22 ),	/* 34 */
/* 9068 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9070 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9076 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 9078 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 9080 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9082 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */

/* 9084 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9086 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SecondType */

/* 9090 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9092 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9096 */	NdrFcShort( 0xf ),	/* 15 */
/* 9098 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9102 */	NdrFcShort( 0x22 ),	/* 34 */
/* 9104 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9106 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 9114 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 9116 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9118 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */

/* 9120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9122 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ConstrainedGeometry */


	/* Procedure get_ConstrainedGeometry */


	/* Procedure get_ConstrainedGeometry */


	/* Procedure get_ConstrainedGeometry */


	/* Procedure get_Target */


	/* Procedure get_Target */

/* 9126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9132 */	NdrFcShort( 0xd ),	/* 13 */
/* 9134 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9140 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 9142 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9148 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 9150 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9152 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9154 */	NdrFcShort( 0x682 ),	/* Type Offset=1666 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 9156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9158 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsFree */

/* 9162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9168 */	NdrFcShort( 0x12 ),	/* 18 */
/* 9170 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9174 */	NdrFcShort( 0x22 ),	/* 34 */
/* 9176 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9178 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 9186 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9190 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 9192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Origin */

/* 9198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9204 */	NdrFcShort( 0x13 ),	/* 19 */
/* 9206 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9210 */	NdrFcShort( 0x74 ),	/* 116 */
/* 9212 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9214 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ox */

/* 9222 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9226 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 9228 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9230 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9232 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 9234 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9238 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 9240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9242 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_XDirection */

/* 9246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9252 */	NdrFcShort( 0x14 ),	/* 20 */
/* 9254 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9258 */	NdrFcShort( 0x74 ),	/* 116 */
/* 9260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9262 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9268 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xx */

/* 9270 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9274 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 9276 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9278 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9280 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 9282 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9284 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9286 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 9288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9290 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutOrigin */

/* 9294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9300 */	NdrFcShort( 0x16 ),	/* 22 */
/* 9302 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 9304 */	NdrFcShort( 0x30 ),	/* 48 */
/* 9306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9308 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ox */

/* 9318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9322 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 9324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9326 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9328 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 9330 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9332 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9334 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 9336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9338 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 9340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutXDirection */

/* 9342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9348 */	NdrFcShort( 0x17 ),	/* 23 */
/* 9350 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 9352 */	NdrFcShort( 0x30 ),	/* 48 */
/* 9354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9356 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9358 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xx */

/* 9366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9370 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 9372 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9376 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 9378 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9380 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9382 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 9384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9386 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 9388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsCut */

/* 9390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9396 */	NdrFcShort( 0xd ),	/* 13 */
/* 9398 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9402 */	NdrFcShort( 0x22 ),	/* 34 */
/* 9404 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9406 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 9414 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9416 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9418 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 9420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9422 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutCenterPoint */

/* 9426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9432 */	NdrFcShort( 0x13 ),	/* 19 */
/* 9434 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 9436 */	NdrFcShort( 0x30 ),	/* 48 */
/* 9438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9440 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9442 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cx */

/* 9450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9452 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9454 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cy */

/* 9456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9458 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9460 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cz */

/* 9462 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9464 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9466 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 9468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9470 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 9472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsFlip */

/* 9474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9480 */	NdrFcShort( 0x14 ),	/* 20 */
/* 9482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9486 */	NdrFcShort( 0x22 ),	/* 34 */
/* 9488 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9490 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 9498 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9502 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 9504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9506 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IsFlip */

/* 9510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9516 */	NdrFcShort( 0x15 ),	/* 21 */
/* 9518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9520 */	NdrFcShort( 0x6 ),	/* 6 */
/* 9522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9524 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9526 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 9534 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9536 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9538 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 9540 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9542 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IsCut */

/* 9546 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9552 */	NdrFcShort( 0x17 ),	/* 23 */
/* 9554 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9556 */	NdrFcShort( 0x6 ),	/* 6 */
/* 9558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9560 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9562 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 9570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9572 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9574 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 9576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9578 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RevolveAxis */

/* 9582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9588 */	NdrFcShort( 0x18 ),	/* 24 */
/* 9590 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 9592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9594 */	NdrFcShort( 0xe0 ),	/* 224 */
/* 9596 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 9598 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter orgX */

/* 9606 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9610 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgY */

/* 9612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9616 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgZ */

/* 9618 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9620 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9622 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirX */

/* 9624 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9626 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9628 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirY */

/* 9630 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9632 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9634 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirZ */

/* 9636 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9638 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9640 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 9642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9644 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 9646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_PullingDirection */

/* 9648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9654 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9656 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 9658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9660 */	NdrFcShort( 0xe0 ),	/* 224 */
/* 9662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 9664 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter orgX */

/* 9672 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9674 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9676 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgY */

/* 9678 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9680 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9682 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgZ */

/* 9684 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9686 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9688 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirX */

/* 9690 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9692 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9694 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirY */

/* 9696 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9698 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9700 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirZ */

/* 9702 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9704 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9706 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 9708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9710 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 9712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PutPullingDirection */

/* 9714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9720 */	NdrFcShort( 0x11 ),	/* 17 */
/* 9722 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 9724 */	NdrFcShort( 0x60 ),	/* 96 */
/* 9726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9728 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 9730 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter orgX */

/* 9738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9742 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgY */

/* 9744 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9746 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9748 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter orgZ */

/* 9750 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9752 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9754 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirX */

/* 9756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9758 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 9760 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirY */

/* 9762 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9764 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 9766 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dirZ */

/* 9768 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9770 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 9772 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 9774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9776 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 9778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */


	/* Procedure get_FilePath */

/* 9780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9786 */	NdrFcShort( 0xc ),	/* 12 */
/* 9788 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9794 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 9796 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 9798 */	NdrFcShort( 0x1 ),	/* 1 */
/* 9800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 9804 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 9806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9808 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */


	/* Return value */

/* 9810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9812 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Faces */

/* 9816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9822 */	NdrFcShort( 0x7 ),	/* 7 */
/* 9824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9830 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 9832 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9838 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 9840 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9842 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9844 */	NdrFcShort( 0x6b2 ),	/* Type Offset=1714 */

	/* Return value */

/* 9846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9848 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Edges */

/* 9852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9860 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9866 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 9868 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 9876 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9880 */	NdrFcShort( 0x6c8 ),	/* Type Offset=1736 */

	/* Return value */

/* 9882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9884 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Vertices */

/* 9888 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9894 */	NdrFcShort( 0x9 ),	/* 9 */
/* 9896 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9902 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 9904 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 9912 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9914 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9916 */	NdrFcShort( 0x6de ),	/* Type Offset=1758 */

	/* Return value */

/* 9918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9920 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 9924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9932 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9938 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 9940 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 9948 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9950 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 9954 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9956 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9958 */	NdrFcShort( 0x6f4 ),	/* Type Offset=1780 */

	/* Return value */

/* 9960 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9962 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9964 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */


	/* Procedure get__NewEnum */


	/* Procedure get__NewEnum */

/* 9966 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9968 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9972 */	NdrFcShort( 0x9 ),	/* 9 */
/* 9974 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9978 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9980 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 9982 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppUnk */


	/* Parameter ppUnk */


	/* Parameter ppUnk */

/* 9990 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9992 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9994 */	NdrFcShort( 0x552 ),	/* Type Offset=1362 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 9996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9998 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 10002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10010 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10016 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 10018 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 10026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 10028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 10032 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10036 */	NdrFcShort( 0x70a ),	/* Type Offset=1802 */

	/* Return value */

/* 10038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10040 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Edges */

/* 10044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10050 */	NdrFcShort( 0x9 ),	/* 9 */
/* 10052 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10058 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 10060 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 10068 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10070 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10072 */	NdrFcShort( 0x6c8 ),	/* Type Offset=1736 */

	/* Return value */

/* 10074 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Vertices */

/* 10080 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10082 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10086 */	NdrFcShort( 0xa ),	/* 10 */
/* 10088 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10092 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10094 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 10096 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 10104 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10106 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10108 */	NdrFcShort( 0x6de ),	/* Type Offset=1758 */

	/* Return value */

/* 10110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10112 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Centroid */

/* 10116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10122 */	NdrFcShort( 0xb ),	/* 11 */
/* 10124 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 10126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10128 */	NdrFcShort( 0x74 ),	/* 116 */
/* 10130 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 10132 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cx */

/* 10140 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10144 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cy */

/* 10146 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10150 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter cz */

/* 10152 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10156 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10160 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_XDirection */

/* 10164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10170 */	NdrFcShort( 0xc ),	/* 12 */
/* 10172 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 10174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10176 */	NdrFcShort( 0x74 ),	/* 116 */
/* 10178 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 10180 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xx */

/* 10188 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10192 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 10194 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10198 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 10200 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10202 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10204 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10206 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10208 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_YDirection */

/* 10212 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10214 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10218 */	NdrFcShort( 0xd ),	/* 13 */
/* 10220 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 10222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10224 */	NdrFcShort( 0x74 ),	/* 116 */
/* 10226 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 10228 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter yx */

/* 10236 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10238 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10240 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */

/* 10242 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10244 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10246 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */

/* 10248 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10250 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10252 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10256 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StartPoint */

/* 10260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10266 */	NdrFcShort( 0x9 ),	/* 9 */
/* 10268 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10274 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 10276 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10282 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 10284 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10286 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10288 */	NdrFcShort( 0x720 ),	/* Type Offset=1824 */

	/* Return value */

/* 10290 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10292 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EndPoint */

/* 10296 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10298 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10302 */	NdrFcShort( 0xa ),	/* 10 */
/* 10304 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10308 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10310 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 10312 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10318 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 10320 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10322 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10324 */	NdrFcShort( 0x720 ),	/* Type Offset=1824 */

	/* Return value */

/* 10326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10328 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 10332 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10338 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10340 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10346 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 10348 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10354 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 10356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 10358 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 10362 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10366 */	NdrFcShort( 0x720 ),	/* Type Offset=1824 */

	/* Return value */

/* 10368 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10370 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */

/* 10374 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10376 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10380 */	NdrFcShort( 0x7 ),	/* 7 */
/* 10382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10388 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 10390 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 10392 */	NdrFcShort( 0x1 ),	/* 1 */
/* 10394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10396 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10398 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 10400 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10402 */	NdrFcShort( 0x7c ),	/* Type Offset=124 */

	/* Return value */

/* 10404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10406 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Coordinates */

/* 10410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10418 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 10420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10422 */	NdrFcShort( 0x74 ),	/* 116 */
/* 10424 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 10426 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10432 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 10434 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10436 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10438 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter y */

/* 10440 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10442 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10444 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter z */

/* 10446 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10450 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10454 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Y */


	/* Procedure get_X */

/* 10458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10464 */	NdrFcShort( 0x9 ),	/* 9 */
/* 10466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10470 */	NdrFcShort( 0x2c ),	/* 44 */
/* 10472 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10474 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter x */

/* 10482 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10484 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10486 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 10488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10490 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Y */

/* 10494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10500 */	NdrFcShort( 0xa ),	/* 10 */
/* 10502 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10506 */	NdrFcShort( 0x2c ),	/* 44 */
/* 10508 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10510 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter y */

/* 10518 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10520 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10522 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10526 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Z */


	/* Procedure get_Z */

/* 10530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10536 */	NdrFcShort( 0xb ),	/* 11 */
/* 10538 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10542 */	NdrFcShort( 0x2c ),	/* 44 */
/* 10544 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10546 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter z */

/* 10554 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10556 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10558 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 10560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10562 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_X */

/* 10566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10572 */	NdrFcShort( 0x7 ),	/* 7 */
/* 10574 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10578 */	NdrFcShort( 0x2c ),	/* 44 */
/* 10580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10582 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10590 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10594 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_X */

/* 10602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10610 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10612 */	NdrFcShort( 0x10 ),	/* 16 */
/* 10614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10616 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10618 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10624 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 10628 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10630 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10634 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Y */

/* 10638 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10644 */	NdrFcShort( 0xa ),	/* 10 */
/* 10646 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10648 */	NdrFcShort( 0x10 ),	/* 16 */
/* 10650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10652 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10654 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 10664 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10666 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10670 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Z */

/* 10674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10680 */	NdrFcShort( 0xc ),	/* 12 */
/* 10682 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10684 */	NdrFcShort( 0x10 ),	/* 16 */
/* 10686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10688 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10690 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 10700 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10702 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 10704 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10706 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Location */

/* 10710 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10716 */	NdrFcShort( 0x7 ),	/* 7 */
/* 10718 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10724 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 10726 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10734 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10736 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10738 */	NdrFcShort( 0x736 ),	/* Type Offset=1846 */

	/* Return value */

/* 10740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10742 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Location */

/* 10746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10754 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10758 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10760 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 10762 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10770 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 10772 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10774 */	NdrFcShort( 0x73a ),	/* Type Offset=1850 */

	/* Return value */

/* 10776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10778 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Direction */

/* 10782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10788 */	NdrFcShort( 0x9 ),	/* 9 */
/* 10790 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10796 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 10798 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10806 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10808 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10810 */	NdrFcShort( 0x736 ),	/* Type Offset=1846 */

	/* Return value */

/* 10812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Direction */

/* 10818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10824 */	NdrFcShort( 0xa ),	/* 10 */
/* 10826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10832 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 10834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10842 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 10844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10846 */	NdrFcShort( 0x73a ),	/* Type Offset=1850 */

	/* Return value */

/* 10848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Assem */

/* 10854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10860 */	NdrFcShort( 0x11 ),	/* 17 */
/* 10862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10868 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 10870 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10878 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 10880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10882 */	NdrFcShort( 0x74c ),	/* Type Offset=1868 */

	/* Return value */

/* 10884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure test */

/* 10890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10896 */	NdrFcShort( 0x13 ),	/* 19 */
/* 10898 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10904 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 10906 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 10914 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure set_Name */

/* 10920 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10926 */	NdrFcShort( 0x7 ),	/* 7 */
/* 10928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10932 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10934 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 10936 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 10938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10940 */	NdrFcShort( 0x1 ),	/* 1 */
/* 10942 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10944 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 10946 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10948 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 10950 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10952 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure set_ParentName */

/* 10956 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10958 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10964 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10970 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 10972 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 10974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10976 */	NdrFcShort( 0x1 ),	/* 1 */
/* 10978 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 10980 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 10982 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 10984 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 10986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10988 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPart */

/* 10992 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10998 */	NdrFcShort( 0xb ),	/* 11 */
/* 11000 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11006 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 11008 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11014 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter i */

/* 11016 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11018 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 11022 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11024 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11026 */	NdrFcShort( 0x762 ),	/* Type Offset=1890 */

	/* Return value */

/* 11028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11030 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetComponent */

/* 11034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11040 */	NdrFcShort( 0xc ),	/* 12 */
/* 11042 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11048 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 11050 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter i */

/* 11058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11060 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 11064 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11066 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11068 */	NdrFcShort( 0x778 ),	/* Type Offset=1912 */

	/* Return value */

/* 11070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11072 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsComponent */

/* 11076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11082 */	NdrFcShort( 0xd ),	/* 13 */
/* 11084 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11086 */	NdrFcShort( 0x22 ),	/* 34 */
/* 11088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11090 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 11092 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter i */

/* 11100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 11106 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 11108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11110 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 11112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsPart */

/* 11118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11124 */	NdrFcShort( 0xe ),	/* 14 */
/* 11126 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11128 */	NdrFcShort( 0x22 ),	/* 34 */
/* 11130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11132 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 11134 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter i */

/* 11142 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 11148 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 11150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11152 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 11154 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11156 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddPart */

/* 11160 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11166 */	NdrFcShort( 0xf ),	/* 15 */
/* 11168 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11172 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11174 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 11176 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 11184 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11186 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11188 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Return value */

/* 11190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11192 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddComponent */

/* 11196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11202 */	NdrFcShort( 0x10 ),	/* 16 */
/* 11204 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11210 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 11212 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 11220 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11224 */	NdrFcShort( 0x77c ),	/* Type Offset=1916 */

	/* Return value */

/* 11226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlacement */

/* 11232 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11238 */	NdrFcShort( 0x12 ),	/* 18 */
/* 11240 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 11242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11244 */	NdrFcShort( 0x14c ),	/* 332 */
/* 11246 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xa,		/* 10 */
/* 11248 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11254 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ox */

/* 11256 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11258 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11260 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 11262 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11264 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11266 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 11268 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11270 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11272 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xx */

/* 11274 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11276 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11278 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 11280 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11282 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 11284 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 11286 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11288 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 11290 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yx */

/* 11292 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11294 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 11296 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yy */

/* 11298 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11300 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 11302 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter yz */

/* 11304 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11306 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 11308 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 11310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11312 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 11314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPlacement */

/* 11316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11322 */	NdrFcShort( 0x13 ),	/* 19 */
/* 11324 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 11326 */	NdrFcShort( 0x90 ),	/* 144 */
/* 11328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11330 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xa,		/* 10 */
/* 11332 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ox */

/* 11340 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11342 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11344 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 11346 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11348 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11350 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 11352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11354 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 11356 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter zx */

/* 11358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11360 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 11362 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter zy */

/* 11364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11366 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 11368 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter zz */

/* 11370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11372 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 11374 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xx */

/* 11376 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11378 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 11380 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 11382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11384 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 11386 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 11388 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11390 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 11392 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 11394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11396 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 11398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveAsMesh */

/* 11400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11406 */	NdrFcShort( 0x14 ),	/* 20 */
/* 11408 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11414 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 11416 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 11418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11420 */	NdrFcShort( 0x1 ),	/* 1 */
/* 11422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter i */

/* 11424 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11426 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter name */

/* 11430 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 11432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11434 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Return value */

/* 11436 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11438 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreatePart */

/* 11442 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11448 */	NdrFcShort( 0x15 ),	/* 21 */
/* 11450 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11456 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 11458 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 11460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11462 */	NdrFcShort( 0x1 ),	/* 1 */
/* 11464 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 11466 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 11468 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11470 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ppVal */

/* 11472 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11474 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11476 */	NdrFcShort( 0x762 ),	/* Type Offset=1890 */

	/* Return value */

/* 11478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11480 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ImportPartFromXML */

/* 11484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11490 */	NdrFcShort( 0x16 ),	/* 22 */
/* 11492 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 11494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11498 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 11500 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 11502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11504 */	NdrFcShort( 0x1 ),	/* 1 */
/* 11506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 11508 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 11510 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11512 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pVal */

/* 11514 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11516 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11518 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter ppVal */

/* 11520 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11522 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11524 */	NdrFcShort( 0x762 ),	/* Type Offset=1890 */

	/* Return value */

/* 11526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11528 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPartPlacement */

/* 11532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11538 */	NdrFcShort( 0x17 ),	/* 23 */
/* 11540 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 11542 */	NdrFcShort( 0x90 ),	/* 144 */
/* 11544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11546 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 11548 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 11556 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11560 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter ox */

/* 11562 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11566 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oy */

/* 11568 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11570 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11572 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter oz */

/* 11574 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11576 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 11578 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter zx */

/* 11580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11582 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 11584 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter zy */

/* 11586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11588 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 11590 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter zz */

/* 11592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11594 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 11596 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xx */

/* 11598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11600 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 11602 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xy */

/* 11604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11606 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 11608 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter xz */

/* 11610 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11612 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 11614 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 11616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11618 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 11620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreatePart */

/* 11622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11628 */	NdrFcShort( 0x7 ),	/* 7 */
/* 11630 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11636 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 11638 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 11646 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11648 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11650 */	NdrFcShort( 0x762 ),	/* Type Offset=1890 */

	/* Return value */

/* 11652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11654 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateComponent */

/* 11658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11666 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11672 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 11674 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11680 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 11682 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11684 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11686 */	NdrFcShort( 0x778 ),	/* Type Offset=1912 */

	/* Return value */

/* 11688 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11690 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddComponent */

/* 11694 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11700 */	NdrFcShort( 0x9 ),	/* 9 */
/* 11702 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11708 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 11710 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 11718 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11720 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11722 */	NdrFcShort( 0x77c ),	/* Type Offset=1916 */

	/* Return value */

/* 11724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11726 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetComponent */

/* 11730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11736 */	NdrFcShort( 0xa ),	/* 10 */
/* 11738 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11744 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 11746 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 11754 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 11760 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11762 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11764 */	NdrFcShort( 0x778 ),	/* Type Offset=1912 */

	/* Return value */

/* 11766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11768 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSize */

/* 11772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11778 */	NdrFcShort( 0xb ),	/* 11 */
/* 11780 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11784 */	NdrFcShort( 0x24 ),	/* 36 */
/* 11786 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 11788 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11794 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 11796 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 11798 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 11802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11804 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Constraints */

/* 11808 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11814 */	NdrFcShort( 0xd ),	/* 13 */
/* 11816 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11822 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 11824 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 11832 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11834 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11836 */	NdrFcShort( 0x792 ),	/* Type Offset=1938 */

	/* Return value */

/* 11838 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11840 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Constraint */

/* 11844 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11846 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11852 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11858 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 11860 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 11862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11866 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 11868 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 11870 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 11874 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11876 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11878 */	NdrFcShort( 0x7a8 ),	/* Type Offset=1960 */

	/* Return value */

/* 11880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11882 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectConstraintByName */

/* 11886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11892 */	NdrFcShort( 0x9 ),	/* 9 */
/* 11894 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11900 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 11902 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 11904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11906 */	NdrFcShort( 0x1 ),	/* 1 */
/* 11908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 11910 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 11912 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11914 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter ppVal */

/* 11916 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11918 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11920 */	NdrFcShort( 0x7a8 ),	/* Type Offset=1960 */

	/* Return value */

/* 11922 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11924 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11926 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewAssemblyCoaxialConstraint */

/* 11928 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 11934 */	NdrFcShort( 0xa ),	/* 10 */
/* 11936 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 11938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 11942 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 11944 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 11946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 11948 */	NdrFcShort( 0x1 ),	/* 1 */
/* 11950 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 11952 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 11954 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 11956 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pConstrainedPart */

/* 11958 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11960 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 11962 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter pConstrainedGeometry */

/* 11964 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11966 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 11968 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Parameter pReferencePart */

/* 11970 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11972 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 11974 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter pReferenceGeometry */

/* 11976 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 11978 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 11980 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Parameter ppVal */

/* 11982 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 11984 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 11986 */	NdrFcShort( 0x7be ),	/* Type Offset=1982 */

	/* Return value */

/* 11988 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 11990 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 11992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewAssemblyIncidenceConstraint */

/* 11994 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 11996 */	NdrFcLong( 0x0 ),	/* 0 */
/* 12000 */	NdrFcShort( 0xb ),	/* 11 */
/* 12002 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 12004 */	NdrFcShort( 0x6 ),	/* 6 */
/* 12006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12008 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 12010 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 12012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 12016 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 12018 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 12020 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 12022 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pConstrainedPart */

/* 12024 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12026 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 12028 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter pConstrainedGeometry */

/* 12030 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12032 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 12034 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Parameter pReferencePart */

/* 12036 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12038 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 12040 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter pReferenceGeometry */

/* 12042 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12044 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 12046 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Parameter incidenceType */

/* 12048 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 12050 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 12052 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 12054 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 12056 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 12058 */	NdrFcShort( 0x7d4 ),	/* Type Offset=2004 */

	/* Return value */

/* 12060 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 12062 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 12064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewAssemblyDistance */

/* 12066 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 12068 */	NdrFcLong( 0x0 ),	/* 0 */
/* 12072 */	NdrFcShort( 0xc ),	/* 12 */
/* 12074 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 12076 */	NdrFcShort( 0x16 ),	/* 22 */
/* 12078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12080 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 12082 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 12084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12086 */	NdrFcShort( 0x1 ),	/* 1 */
/* 12088 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 12090 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 12092 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 12094 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pConstrainedPart */

/* 12096 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12098 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 12100 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter pConstrainedGeometry */

/* 12102 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12104 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 12106 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Parameter pReferencePart */

/* 12108 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12110 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 12112 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter pReferenceGeometry */

/* 12114 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12116 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 12118 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Parameter distance */

/* 12120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 12122 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 12124 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter incidenceType */

/* 12126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 12128 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 12130 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 12132 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 12134 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 12136 */	NdrFcShort( 0x7ea ),	/* Type Offset=2026 */

	/* Return value */

/* 12138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 12140 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 12142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNewAssemblyAngle */

/* 12144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 12146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 12150 */	NdrFcShort( 0xd ),	/* 13 */
/* 12152 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 12154 */	NdrFcShort( 0x10 ),	/* 16 */
/* 12156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12158 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 12160 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 12162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12164 */	NdrFcShort( 0x1 ),	/* 1 */
/* 12166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 12168 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 12170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 12172 */	NdrFcShort( 0xd0 ),	/* Type Offset=208 */

	/* Parameter pConstrainedPart */

/* 12174 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 12178 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter pConstrainedGeometry */

/* 12180 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12182 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 12184 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Parameter pReferencePart */

/* 12186 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12188 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 12190 */	NdrFcShort( 0x766 ),	/* Type Offset=1894 */

	/* Parameter pReferenceGeometry */

/* 12192 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 12194 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 12196 */	NdrFcShort( 0x598 ),	/* Type Offset=1432 */

	/* Parameter angle */

/* 12198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 12200 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 12202 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ppVal */

/* 12204 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 12206 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 12208 */	NdrFcShort( 0x800 ),	/* Type Offset=2048 */

	/* Return value */

/* 12210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 12212 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 12214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ConstrainedPart */

/* 12216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 12218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 12222 */	NdrFcShort( 0xc ),	/* 12 */
/* 12224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 12226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12230 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 12232 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 12234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */

/* 12240 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 12242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 12244 */	NdrFcShort( 0x762 ),	/* Type Offset=1890 */

	/* Return value */

/* 12246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 12248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 12250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ReferencePart */


	/* Procedure get_ReferencePart */


	/* Procedure get_ReferencePart */


	/* Procedure get_ReferencePart */

/* 12252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 12254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 12258 */	NdrFcShort( 0xe ),	/* 14 */
/* 12260 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 12262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12266 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 12268 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 12270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 12276 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 12278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 12280 */	NdrFcShort( 0x816 ),	/* Type Offset=2070 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 12282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 12284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 12286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ConstrainedPart */


	/* Procedure get_ConstrainedPart */


	/* Procedure get_ConstrainedPart */

/* 12288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 12290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 12294 */	NdrFcShort( 0xc ),	/* 12 */
/* 12296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 12298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12302 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 12304 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 12306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVal */


	/* Parameter ppVal */


	/* Parameter ppVal */

/* 12312 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 12314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 12316 */	NdrFcShort( 0x816 ),	/* Type Offset=2070 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 12318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 12320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 12322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const TransCAD_MIDL_TYPE_FORMAT_STRING TransCAD__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 12 */	NdrFcLong( 0x19487fb9 ),	/* 424181689 */
/* 16 */	NdrFcShort( 0x54f2 ),	/* 21746 */
/* 18 */	NdrFcShort( 0x49a6 ),	/* 18854 */
/* 20 */	0x9d,		/* 157 */
			0xae,		/* 174 */
/* 22 */	0xfd,		/* 253 */
			0x9a,		/* 154 */
/* 24 */	0xdd,		/* 221 */
			0xd1,		/* 209 */
/* 26 */	0x2a,		/* 42 */
			0x76,		/* 118 */
/* 28 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 30 */	NdrFcShort( 0x2 ),	/* Offset= 2 (32) */
/* 32 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 34 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 44 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 46 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 48 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 50 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 52 */	NdrFcShort( 0x2 ),	/* Offset= 2 (54) */
/* 54 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 56 */	NdrFcLong( 0xbc5f8ab3 ),	/* -1134589261 */
/* 60 */	NdrFcShort( 0x439 ),	/* 1081 */
/* 62 */	NdrFcShort( 0x4f12 ),	/* 20242 */
/* 64 */	0xaf,		/* 175 */
			0x8,		/* 8 */
/* 66 */	0x8f,		/* 143 */
			0x7d,		/* 125 */
/* 68 */	0x74,		/* 116 */
			0x92,		/* 146 */
/* 70 */	0x89,		/* 137 */
			0x40,		/* 64 */
/* 72 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 74 */	NdrFcShort( 0x2 ),	/* Offset= 2 (76) */
/* 76 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 78 */	NdrFcLong( 0xc12fb0da ),	/* -1053839142 */
/* 82 */	NdrFcShort( 0x8bb2 ),	/* -29774 */
/* 84 */	NdrFcShort( 0x4cf4 ),	/* 19700 */
/* 86 */	0xbc,		/* 188 */
			0x4f,		/* 79 */
/* 88 */	0x7d,		/* 125 */
			0x53,		/* 83 */
/* 90 */	0x8b,		/* 139 */
			0xa3,		/* 163 */
/* 92 */	0x67,		/* 103 */
			0x27,		/* 39 */
/* 94 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 96 */	NdrFcShort( 0x1c ),	/* Offset= 28 (124) */
/* 98 */	
			0x13, 0x0,	/* FC_OP */
/* 100 */	NdrFcShort( 0xe ),	/* Offset= 14 (114) */
/* 102 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 104 */	NdrFcShort( 0x2 ),	/* 2 */
/* 106 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 108 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 110 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 112 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 114 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 118 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (102) */
/* 120 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 122 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 124 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x4 ),	/* 4 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0xffde ),	/* Offset= -34 (98) */
/* 134 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 136 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 138 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 140 */	NdrFcShort( 0x2 ),	/* Offset= 2 (142) */
/* 142 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 154 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 156 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 158 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 160 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 162 */	NdrFcShort( 0x2 ),	/* Offset= 2 (164) */
/* 164 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 166 */	NdrFcLong( 0xc37f3bc0 ),	/* -1015071808 */
/* 170 */	NdrFcShort( 0x22dd ),	/* 8925 */
/* 172 */	NdrFcShort( 0x4e20 ),	/* 20000 */
/* 174 */	0xa2,		/* 162 */
			0x3,		/* 3 */
/* 176 */	0x28,		/* 40 */
			0x6a,		/* 106 */
/* 178 */	0xce,		/* 206 */
			0x86,		/* 134 */
/* 180 */	0x27,		/* 39 */
			0x58,		/* 88 */
/* 182 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 184 */	NdrFcShort( 0x2 ),	/* Offset= 2 (186) */
/* 186 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 188 */	NdrFcLong( 0x1ee2b408 ),	/* 518173704 */
/* 192 */	NdrFcShort( 0x2ce ),	/* 718 */
/* 194 */	NdrFcShort( 0x4e5f ),	/* 20063 */
/* 196 */	0xbf,		/* 191 */
			0xfc,		/* 252 */
/* 198 */	0xb7,		/* 183 */
			0x93,		/* 147 */
/* 200 */	0xba,		/* 186 */
			0xc3,		/* 195 */
/* 202 */	0x22,		/* 34 */
			0xc1,		/* 193 */
/* 204 */	
			0x12, 0x0,	/* FC_UP */
/* 206 */	NdrFcShort( 0xffa4 ),	/* Offset= -92 (114) */
/* 208 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x4 ),	/* 4 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (204) */
/* 218 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 220 */	NdrFcShort( 0x2 ),	/* Offset= 2 (222) */
/* 222 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 224 */	NdrFcLong( 0x37ebffcd ),	/* 938213325 */
/* 228 */	NdrFcShort( 0x77e ),	/* 1918 */
/* 230 */	NdrFcShort( 0x4323 ),	/* 17187 */
/* 232 */	0x83,		/* 131 */
			0xe0,		/* 224 */
/* 234 */	0x3a,		/* 58 */
			0x82,		/* 130 */
/* 236 */	0x55,		/* 85 */
			0xaf,		/* 175 */
/* 238 */	0xb8,		/* 184 */
			0x45,		/* 69 */
/* 240 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 242 */	NdrFcShort( 0x2 ),	/* Offset= 2 (244) */
/* 244 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 246 */	NdrFcLong( 0x8084c085 ),	/* -2138783611 */
/* 250 */	NdrFcShort( 0x5f3f ),	/* 24383 */
/* 252 */	NdrFcShort( 0x49f0 ),	/* 18928 */
/* 254 */	0xb8,		/* 184 */
			0x2c,		/* 44 */
/* 256 */	0x22,		/* 34 */
			0x76,		/* 118 */
/* 258 */	0xf1,		/* 241 */
			0x2c,		/* 44 */
/* 260 */	0x88,		/* 136 */
			0xab,		/* 171 */
/* 262 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 264 */	NdrFcShort( 0x2 ),	/* Offset= 2 (266) */
/* 266 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 268 */	NdrFcLong( 0x2a7e4fcc ),	/* 712921036 */
/* 272 */	NdrFcShort( 0x4df6 ),	/* 19958 */
/* 274 */	NdrFcShort( 0x4e4f ),	/* 20047 */
/* 276 */	0x81,		/* 129 */
			0xf8,		/* 248 */
/* 278 */	0x80,		/* 128 */
			0xc0,		/* 192 */
/* 280 */	0x48,		/* 72 */
			0x31,		/* 49 */
/* 282 */	0x61,		/* 97 */
			0x56,		/* 86 */
/* 284 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 286 */	NdrFcShort( 0x2 ),	/* Offset= 2 (288) */
/* 288 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 290 */	NdrFcLong( 0xa0cdfcd7 ),	/* -1597113129 */
/* 294 */	NdrFcShort( 0xc97b ),	/* -13957 */
/* 296 */	NdrFcShort( 0x426f ),	/* 17007 */
/* 298 */	0x85,		/* 133 */
			0x28,		/* 40 */
/* 300 */	0xa,		/* 10 */
			0xa0,		/* 160 */
/* 302 */	0x32,		/* 50 */
			0x1e,		/* 30 */
/* 304 */	0xa0,		/* 160 */
			0xfa,		/* 250 */
/* 306 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 308 */	NdrFcShort( 0x2 ),	/* Offset= 2 (310) */
/* 310 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 312 */	NdrFcLong( 0x280df2d0 ),	/* 672002768 */
/* 316 */	NdrFcShort( 0xbe2a ),	/* -16854 */
/* 318 */	NdrFcShort( 0x448c ),	/* 17548 */
/* 320 */	0xbb,		/* 187 */
			0xce,		/* 206 */
/* 322 */	0x11,		/* 17 */
			0x81,		/* 129 */
/* 324 */	0x46,		/* 70 */
			0x36,		/* 54 */
/* 326 */	0xc4,		/* 196 */
			0xc8,		/* 200 */
/* 328 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 330 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 332 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 334 */	NdrFcShort( 0x2 ),	/* Offset= 2 (336) */
/* 336 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 338 */	NdrFcLong( 0x19487fb9 ),	/* 424181689 */
/* 342 */	NdrFcShort( 0x54f2 ),	/* 21746 */
/* 344 */	NdrFcShort( 0x49a6 ),	/* 18854 */
/* 346 */	0x9d,		/* 157 */
			0xae,		/* 174 */
/* 348 */	0xfd,		/* 253 */
			0x9a,		/* 154 */
/* 350 */	0xdd,		/* 221 */
			0xd1,		/* 209 */
/* 352 */	0x2a,		/* 42 */
			0x76,		/* 118 */
/* 354 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 356 */	NdrFcShort( 0x2 ),	/* Offset= 2 (358) */
/* 358 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 360 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 370 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 372 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 374 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 376 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 378 */	NdrFcShort( 0x2 ),	/* Offset= 2 (380) */
/* 380 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 382 */	NdrFcLong( 0xf898093c ),	/* -124253892 */
/* 386 */	NdrFcShort( 0x1b98 ),	/* 7064 */
/* 388 */	NdrFcShort( 0x420d ),	/* 16909 */
/* 390 */	0xb0,		/* 176 */
			0x97,		/* 151 */
/* 392 */	0xc2,		/* 194 */
			0xf1,		/* 241 */
/* 394 */	0xe8,		/* 232 */
			0x8c,		/* 140 */
/* 396 */	0xa3,		/* 163 */
			0x45,		/* 69 */
/* 398 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 400 */	NdrFcShort( 0x2 ),	/* Offset= 2 (402) */
/* 402 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 414 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 416 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 418 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 420 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 422 */	NdrFcLong( 0xa0cdfcd7 ),	/* -1597113129 */
/* 426 */	NdrFcShort( 0xc97b ),	/* -13957 */
/* 428 */	NdrFcShort( 0x426f ),	/* 17007 */
/* 430 */	0x85,		/* 133 */
			0x28,		/* 40 */
/* 432 */	0xa,		/* 10 */
			0xa0,		/* 160 */
/* 434 */	0x32,		/* 50 */
			0x1e,		/* 30 */
/* 436 */	0xa0,		/* 160 */
			0xfa,		/* 250 */
/* 438 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 440 */	NdrFcShort( 0x2 ),	/* Offset= 2 (442) */
/* 442 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 444 */	NdrFcLong( 0x54a6f7f9 ),	/* 1420228601 */
/* 448 */	NdrFcShort( 0x5c98 ),	/* 23704 */
/* 450 */	NdrFcShort( 0x4c65 ),	/* 19557 */
/* 452 */	0x96,		/* 150 */
			0xd5,		/* 213 */
/* 454 */	0xbd,		/* 189 */
			0x43,		/* 67 */
/* 456 */	0xd2,		/* 210 */
			0x48,		/* 72 */
/* 458 */	0xb7,		/* 183 */
			0x88,		/* 136 */
/* 460 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 462 */	NdrFcShort( 0x2 ),	/* Offset= 2 (464) */
/* 464 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 466 */	NdrFcLong( 0x570069a3 ),	/* 1459644835 */
/* 470 */	NdrFcShort( 0xac18 ),	/* -21480 */
/* 472 */	NdrFcShort( 0x40e5 ),	/* 16613 */
/* 474 */	0x9c,		/* 156 */
			0xd4,		/* 212 */
/* 476 */	0xbe,		/* 190 */
			0x1e,		/* 30 */
/* 478 */	0xcf,		/* 207 */
			0x83,		/* 131 */
/* 480 */	0x18,		/* 24 */
			0xe2,		/* 226 */
/* 482 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 484 */	NdrFcShort( 0x2 ),	/* Offset= 2 (486) */
/* 486 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 488 */	NdrFcLong( 0x8645e5ad ),	/* -2042239571 */
/* 492 */	NdrFcShort( 0x94df ),	/* -27425 */
/* 494 */	NdrFcShort( 0x48a8 ),	/* 18600 */
/* 496 */	0xad,		/* 173 */
			0x8e,		/* 142 */
/* 498 */	0x9e,		/* 158 */
			0xd7,		/* 215 */
/* 500 */	0x17,		/* 23 */
			0xac,		/* 172 */
/* 502 */	0x46,		/* 70 */
			0x91,		/* 145 */
/* 504 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 506 */	NdrFcLong( 0x2a7e4fcc ),	/* 712921036 */
/* 510 */	NdrFcShort( 0x4df6 ),	/* 19958 */
/* 512 */	NdrFcShort( 0x4e4f ),	/* 20047 */
/* 514 */	0x81,		/* 129 */
			0xf8,		/* 248 */
/* 516 */	0x80,		/* 128 */
			0xc0,		/* 192 */
/* 518 */	0x48,		/* 72 */
			0x31,		/* 49 */
/* 520 */	0x61,		/* 97 */
			0x56,		/* 86 */
/* 522 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 524 */	NdrFcShort( 0x2 ),	/* Offset= 2 (526) */
/* 526 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 528 */	NdrFcLong( 0x7813d4f8 ),	/* 2014565624 */
/* 532 */	NdrFcShort( 0x1398 ),	/* 5016 */
/* 534 */	NdrFcShort( 0x4a75 ),	/* 19061 */
/* 536 */	0x8f,		/* 143 */
			0xea,		/* 234 */
/* 538 */	0xaf,		/* 175 */
			0x3a,		/* 58 */
/* 540 */	0x26,		/* 38 */
			0x2a,		/* 42 */
/* 542 */	0x98,		/* 152 */
			0x98,		/* 152 */
/* 544 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 546 */	NdrFcShort( 0x2 ),	/* Offset= 2 (548) */
/* 548 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 550 */	NdrFcLong( 0x7397f21a ),	/* 1939337754 */
/* 554 */	NdrFcShort( 0xe19f ),	/* -7777 */
/* 556 */	NdrFcShort( 0x4eda ),	/* 20186 */
/* 558 */	0xb8,		/* 184 */
			0x9f,		/* 159 */
/* 560 */	0xe1,		/* 225 */
			0x84,		/* 132 */
/* 562 */	0x5,		/* 5 */
			0xbd,		/* 189 */
/* 564 */	0x37,		/* 55 */
			0x60,		/* 96 */
/* 566 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 568 */	NdrFcShort( 0x2 ),	/* Offset= 2 (570) */
/* 570 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 572 */	NdrFcLong( 0x62f39890 ),	/* 1660131472 */
/* 576 */	NdrFcShort( 0x584 ),	/* 1412 */
/* 578 */	NdrFcShort( 0x4142 ),	/* 16706 */
/* 580 */	0xa8,		/* 168 */
			0xde,		/* 222 */
/* 582 */	0xe4,		/* 228 */
			0x19,		/* 25 */
/* 584 */	0xf9,		/* 249 */
			0xbf,		/* 191 */
/* 586 */	0x73,		/* 115 */
			0x1,		/* 1 */
/* 588 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 590 */	NdrFcShort( 0x2 ),	/* Offset= 2 (592) */
/* 592 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 594 */	NdrFcLong( 0xb8aac9d3 ),	/* -1196766765 */
/* 598 */	NdrFcShort( 0x8453 ),	/* -31661 */
/* 600 */	NdrFcShort( 0x48c9 ),	/* 18633 */
/* 602 */	0xac,		/* 172 */
			0x93,		/* 147 */
/* 604 */	0xa1,		/* 161 */
			0x16,		/* 22 */
/* 606 */	0xe8,		/* 232 */
			0x91,		/* 145 */
/* 608 */	0x10,		/* 16 */
			0x1e,		/* 30 */
/* 610 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 612 */	NdrFcShort( 0x2 ),	/* Offset= 2 (614) */
/* 614 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 616 */	NdrFcLong( 0x1b8e8e40 ),	/* 462327360 */
/* 620 */	NdrFcShort( 0x7d68 ),	/* 32104 */
/* 622 */	NdrFcShort( 0x4387 ),	/* 17287 */
/* 624 */	0xa1,		/* 161 */
			0x3f,		/* 63 */
/* 626 */	0xd8,		/* 216 */
			0xe2,		/* 226 */
/* 628 */	0x4,		/* 4 */
			0x21,		/* 33 */
/* 630 */	0x26,		/* 38 */
			0x7,		/* 7 */
/* 632 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 634 */	NdrFcShort( 0x2 ),	/* Offset= 2 (636) */
/* 636 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 638 */	NdrFcLong( 0x929007fb ),	/* -1836054533 */
/* 642 */	NdrFcShort( 0xff4 ),	/* 4084 */
/* 644 */	NdrFcShort( 0x477a ),	/* 18298 */
/* 646 */	0xbc,		/* 188 */
			0x6b,		/* 107 */
/* 648 */	0x9d,		/* 157 */
			0xb6,		/* 182 */
/* 650 */	0x3b,		/* 59 */
			0x4f,		/* 79 */
/* 652 */	0x64,		/* 100 */
			0x7,		/* 7 */
/* 654 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 656 */	NdrFcShort( 0x2 ),	/* Offset= 2 (658) */
/* 658 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 660 */	NdrFcLong( 0x1b44e76f ),	/* 457500527 */
/* 664 */	NdrFcShort( 0x21ad ),	/* 8621 */
/* 666 */	NdrFcShort( 0x482b ),	/* 18475 */
/* 668 */	0xa2,		/* 162 */
			0xd4,		/* 212 */
/* 670 */	0x95,		/* 149 */
			0x3,		/* 3 */
/* 672 */	0x75,		/* 117 */
			0xec,		/* 236 */
/* 674 */	0x2d,		/* 45 */
			0x61,		/* 97 */
/* 676 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 678 */	NdrFcShort( 0x2 ),	/* Offset= 2 (680) */
/* 680 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 682 */	NdrFcLong( 0x5089ae2e ),	/* 1351200302 */
/* 686 */	NdrFcShort( 0x41c5 ),	/* 16837 */
/* 688 */	NdrFcShort( 0x4dd3 ),	/* 19923 */
/* 690 */	0xbf,		/* 191 */
			0xfa,		/* 250 */
/* 692 */	0x6b,		/* 107 */
			0x5e,		/* 94 */
/* 694 */	0xcf,		/* 207 */
			0xf9,		/* 249 */
/* 696 */	0x91,		/* 145 */
			0x41,		/* 65 */
/* 698 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 700 */	NdrFcShort( 0x2 ),	/* Offset= 2 (702) */
/* 702 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 704 */	NdrFcLong( 0x9980b5be ),	/* -1719618114 */
/* 708 */	NdrFcShort( 0x2421 ),	/* 9249 */
/* 710 */	NdrFcShort( 0x46dc ),	/* 18140 */
/* 712 */	0x94,		/* 148 */
			0x25,		/* 37 */
/* 714 */	0x84,		/* 132 */
			0x58,		/* 88 */
/* 716 */	0x80,		/* 128 */
			0x82,		/* 130 */
/* 718 */	0xdd,		/* 221 */
			0x28,		/* 40 */
/* 720 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 722 */	NdrFcShort( 0x2 ),	/* Offset= 2 (724) */
/* 724 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 726 */	NdrFcLong( 0x5a9fb9f5 ),	/* 1520417269 */
/* 730 */	NdrFcShort( 0x92a5 ),	/* -27995 */
/* 732 */	NdrFcShort( 0x4e46 ),	/* 20038 */
/* 734 */	0xb5,		/* 181 */
			0xa5,		/* 165 */
/* 736 */	0xd9,		/* 217 */
			0xc1,		/* 193 */
/* 738 */	0x63,		/* 99 */
			0xa1,		/* 161 */
/* 740 */	0xfd,		/* 253 */
			0x8c,		/* 140 */
/* 742 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 744 */	NdrFcShort( 0x2 ),	/* Offset= 2 (746) */
/* 746 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 748 */	NdrFcLong( 0xb1a7fe7f ),	/* -1314390401 */
/* 752 */	NdrFcShort( 0x54bf ),	/* 21695 */
/* 754 */	NdrFcShort( 0x4ce5 ),	/* 19685 */
/* 756 */	0x89,		/* 137 */
			0x47,		/* 71 */
/* 758 */	0x83,		/* 131 */
			0x13,		/* 19 */
/* 760 */	0x58,		/* 88 */
			0xc3,		/* 195 */
/* 762 */	0x8d,		/* 141 */
			0x56,		/* 86 */
/* 764 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 766 */	NdrFcShort( 0x2 ),	/* Offset= 2 (768) */
/* 768 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 770 */	NdrFcLong( 0x9be8c17 ),	/* 163482647 */
/* 774 */	NdrFcShort( 0xdb20 ),	/* -9440 */
/* 776 */	NdrFcShort( 0x4474 ),	/* 17524 */
/* 778 */	0x8b,		/* 139 */
			0xe9,		/* 233 */
/* 780 */	0xf4,		/* 244 */
			0xd9,		/* 217 */
/* 782 */	0x4e,		/* 78 */
			0x27,		/* 39 */
/* 784 */	0x26,		/* 38 */
			0x1a,		/* 26 */
/* 786 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 788 */	NdrFcLong( 0xa0cdfcd7 ),	/* -1597113129 */
/* 792 */	NdrFcShort( 0xc97b ),	/* -13957 */
/* 794 */	NdrFcShort( 0x426f ),	/* 17007 */
/* 796 */	0x85,		/* 133 */
			0x28,		/* 40 */
/* 798 */	0xa,		/* 10 */
			0xa0,		/* 160 */
/* 800 */	0x32,		/* 50 */
			0x1e,		/* 30 */
/* 802 */	0xa0,		/* 160 */
			0xfa,		/* 250 */
/* 804 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 806 */	NdrFcShort( 0x2 ),	/* Offset= 2 (808) */
/* 808 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 810 */	NdrFcLong( 0xcf090569 ),	/* -821492375 */
/* 814 */	NdrFcShort( 0x5d8 ),	/* 1496 */
/* 816 */	NdrFcShort( 0x44a0 ),	/* 17568 */
/* 818 */	0x86,		/* 134 */
			0x56,		/* 86 */
/* 820 */	0x82,		/* 130 */
			0xbd,		/* 189 */
/* 822 */	0xfe,		/* 254 */
			0x1b,		/* 27 */
/* 824 */	0x79,		/* 121 */
			0xa6,		/* 166 */
/* 826 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 828 */	NdrFcShort( 0x2 ),	/* Offset= 2 (830) */
/* 830 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 832 */	NdrFcLong( 0xfccf7496 ),	/* -53513066 */
/* 836 */	NdrFcShort( 0x9645 ),	/* -27067 */
/* 838 */	NdrFcShort( 0x4b6d ),	/* 19309 */
/* 840 */	0x9c,		/* 156 */
			0x4d,		/* 77 */
/* 842 */	0x6,		/* 6 */
			0x7d,		/* 125 */
/* 844 */	0x3d,		/* 61 */
			0x1d,		/* 29 */
/* 846 */	0x60,		/* 96 */
			0xaf,		/* 175 */
/* 848 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 850 */	NdrFcShort( 0x2 ),	/* Offset= 2 (852) */
/* 852 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 854 */	NdrFcLong( 0x66548701 ),	/* 1716815617 */
/* 858 */	NdrFcShort( 0x6acc ),	/* 27340 */
/* 860 */	NdrFcShort( 0x4271 ),	/* 17009 */
/* 862 */	0x98,		/* 152 */
			0xa8,		/* 168 */
/* 864 */	0xd7,		/* 215 */
			0x66,		/* 102 */
/* 866 */	0x69,		/* 105 */
			0x30,		/* 48 */
/* 868 */	0xff,		/* 255 */
			0x5,		/* 5 */
/* 870 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 872 */	NdrFcShort( 0x2 ),	/* Offset= 2 (874) */
/* 874 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 876 */	NdrFcLong( 0xea1585e2 ),	/* -367688222 */
/* 880 */	NdrFcShort( 0x4e46 ),	/* 20038 */
/* 882 */	NdrFcShort( 0x44e1 ),	/* 17633 */
/* 884 */	0x80,		/* 128 */
			0x8b,		/* 139 */
/* 886 */	0x44,		/* 68 */
			0x32,		/* 50 */
/* 888 */	0xb9,		/* 185 */
			0x89,		/* 137 */
/* 890 */	0x6e,		/* 110 */
			0x2d,		/* 45 */
/* 892 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 894 */	NdrFcShort( 0x2 ),	/* Offset= 2 (896) */
/* 896 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 898 */	NdrFcLong( 0x2ac4b8da ),	/* 717535450 */
/* 902 */	NdrFcShort( 0xf372 ),	/* -3214 */
/* 904 */	NdrFcShort( 0x4214 ),	/* 16916 */
/* 906 */	0x89,		/* 137 */
			0xf7,		/* 247 */
/* 908 */	0xab,		/* 171 */
			0x62,		/* 98 */
/* 910 */	0x31,		/* 49 */
			0xe9,		/* 233 */
/* 912 */	0x46,		/* 70 */
			0x91,		/* 145 */
/* 914 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 916 */	NdrFcShort( 0x2 ),	/* Offset= 2 (918) */
/* 918 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 920 */	NdrFcLong( 0xb7a36313 ),	/* -1214029037 */
/* 924 */	NdrFcShort( 0xca66 ),	/* -13722 */
/* 926 */	NdrFcShort( 0x4a4b ),	/* 19019 */
/* 928 */	0x83,		/* 131 */
			0xbe,		/* 190 */
/* 930 */	0xb7,		/* 183 */
			0x97,		/* 151 */
/* 932 */	0xfb,		/* 251 */
			0xd,		/* 13 */
/* 934 */	0xe8,		/* 232 */
			0xa,		/* 10 */
/* 936 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 938 */	NdrFcShort( 0x2 ),	/* Offset= 2 (940) */
/* 940 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 942 */	NdrFcLong( 0x378eba37 ),	/* 932100663 */
/* 946 */	NdrFcShort( 0x1568 ),	/* 5480 */
/* 948 */	NdrFcShort( 0x40e9 ),	/* 16617 */
/* 950 */	0xbd,		/* 189 */
			0x72,		/* 114 */
/* 952 */	0xea,		/* 234 */
			0x48,		/* 72 */
/* 954 */	0xed,		/* 237 */
			0x47,		/* 71 */
/* 956 */	0x1e,		/* 30 */
			0xdc,		/* 220 */
/* 958 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 960 */	NdrFcShort( 0x2 ),	/* Offset= 2 (962) */
/* 962 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 964 */	NdrFcLong( 0x19487fb9 ),	/* 424181689 */
/* 968 */	NdrFcShort( 0x54f2 ),	/* 21746 */
/* 970 */	NdrFcShort( 0x49a6 ),	/* 18854 */
/* 972 */	0x9d,		/* 157 */
			0xae,		/* 174 */
/* 974 */	0xfd,		/* 253 */
			0x9a,		/* 154 */
/* 976 */	0xdd,		/* 221 */
			0xd1,		/* 209 */
/* 978 */	0x2a,		/* 42 */
			0x76,		/* 118 */
/* 980 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 982 */	NdrFcShort( 0x2 ),	/* Offset= 2 (984) */
/* 984 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 986 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 996 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 998 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1000 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1002 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1004 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 1006 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1008 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1010) */
/* 1010 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1012 */	NdrFcLong( 0x1804c402 ),	/* 402965506 */
/* 1016 */	NdrFcShort( 0xfbaf ),	/* -1105 */
/* 1018 */	NdrFcShort( 0x438f ),	/* 17295 */
/* 1020 */	0xb8,		/* 184 */
			0x49,		/* 73 */
/* 1022 */	0xab,		/* 171 */
			0x69,		/* 105 */
/* 1024 */	0x40,		/* 64 */
			0x60,		/* 96 */
/* 1026 */	0x6e,		/* 110 */
			0x6d,		/* 109 */
/* 1028 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1030 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1032) */
/* 1032 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1034 */	NdrFcLong( 0x5a732443 ),	/* 1517495363 */
/* 1038 */	NdrFcShort( 0x2a35 ),	/* 10805 */
/* 1040 */	NdrFcShort( 0x4519 ),	/* 17689 */
/* 1042 */	0x9c,		/* 156 */
			0x1a,		/* 26 */
/* 1044 */	0x5c,		/* 92 */
			0x9e,		/* 158 */
/* 1046 */	0x25,		/* 37 */
			0x34,		/* 52 */
/* 1048 */	0x2d,		/* 45 */
			0x22,		/* 34 */
/* 1050 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1052 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1054) */
/* 1054 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1056 */	NdrFcLong( 0x1c5fdd6c ),	/* 476044652 */
/* 1060 */	NdrFcShort( 0x3075 ),	/* 12405 */
/* 1062 */	NdrFcShort( 0x4a54 ),	/* 19028 */
/* 1064 */	0x9e,		/* 158 */
			0x8,		/* 8 */
/* 1066 */	0xd9,		/* 217 */
			0x59,		/* 89 */
/* 1068 */	0x76,		/* 118 */
			0x9c,		/* 156 */
/* 1070 */	0x24,		/* 36 */
			0xc6,		/* 198 */
/* 1072 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1074 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1076) */
/* 1076 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1078 */	NdrFcLong( 0x7ffe9084 ),	/* 2147389572 */
/* 1082 */	NdrFcShort( 0x7c7b ),	/* 31867 */
/* 1084 */	NdrFcShort( 0x4e75 ),	/* 20085 */
/* 1086 */	0xab,		/* 171 */
			0xf6,		/* 246 */
/* 1088 */	0xc2,		/* 194 */
			0x1a,		/* 26 */
/* 1090 */	0x12,		/* 18 */
			0x81,		/* 129 */
/* 1092 */	0xe2,		/* 226 */
			0x79,		/* 121 */
/* 1094 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1096 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1098) */
/* 1098 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1100 */	NdrFcLong( 0x82dd5568 ),	/* -2099423896 */
/* 1104 */	NdrFcShort( 0xc7f7 ),	/* -14345 */
/* 1106 */	NdrFcShort( 0x4647 ),	/* 17991 */
/* 1108 */	0xb8,		/* 184 */
			0x15,		/* 21 */
/* 1110 */	0x66,		/* 102 */
			0xd4,		/* 212 */
/* 1112 */	0xe7,		/* 231 */
			0x2d,		/* 45 */
/* 1114 */	0x57,		/* 87 */
			0x38,		/* 56 */
/* 1116 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1118 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1120) */
/* 1120 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1122 */	NdrFcLong( 0x235d6ab ),	/* 37082795 */
/* 1126 */	NdrFcShort( 0xe6f9 ),	/* -6407 */
/* 1128 */	NdrFcShort( 0x4665 ),	/* 18021 */
/* 1130 */	0x98,		/* 152 */
			0xaf,		/* 175 */
/* 1132 */	0x75,		/* 117 */
			0xb7,		/* 183 */
/* 1134 */	0xd5,		/* 213 */
			0x6a,		/* 106 */
/* 1136 */	0x1,		/* 1 */
			0x29,		/* 41 */
/* 1138 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1140 */	NdrFcShort( 0xfe9e ),	/* Offset= -354 (786) */
/* 1142 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1144 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1146) */
/* 1146 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1148 */	NdrFcLong( 0x57fae9e3 ),	/* 1476061667 */
/* 1152 */	NdrFcShort( 0xf8d4 ),	/* -1836 */
/* 1154 */	NdrFcShort( 0x49b2 ),	/* 18866 */
/* 1156 */	0xab,		/* 171 */
			0xa,		/* 10 */
/* 1158 */	0xb8,		/* 184 */
			0x8f,		/* 143 */
/* 1160 */	0x64,		/* 100 */
			0xb,		/* 11 */
/* 1162 */	0x7c,		/* 124 */
			0xf2,		/* 242 */
/* 1164 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1166 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1168) */
/* 1168 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1170 */	NdrFcLong( 0x2a7e4fcc ),	/* 712921036 */
/* 1174 */	NdrFcShort( 0x4df6 ),	/* 19958 */
/* 1176 */	NdrFcShort( 0x4e4f ),	/* 20047 */
/* 1178 */	0x81,		/* 129 */
			0xf8,		/* 248 */
/* 1180 */	0x80,		/* 128 */
			0xc0,		/* 192 */
/* 1182 */	0x48,		/* 72 */
			0x31,		/* 49 */
/* 1184 */	0x61,		/* 97 */
			0x56,		/* 86 */
/* 1186 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1188 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1190) */
/* 1190 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1192 */	NdrFcLong( 0x19487fb9 ),	/* 424181689 */
/* 1196 */	NdrFcShort( 0x54f2 ),	/* 21746 */
/* 1198 */	NdrFcShort( 0x49a6 ),	/* 18854 */
/* 1200 */	0x9d,		/* 157 */
			0xae,		/* 174 */
/* 1202 */	0xfd,		/* 253 */
			0x9a,		/* 154 */
/* 1204 */	0xdd,		/* 221 */
			0xd1,		/* 209 */
/* 1206 */	0x2a,		/* 42 */
			0x76,		/* 118 */
/* 1208 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1210 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1212) */
/* 1212 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1214 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 1218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1222 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1224 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1226 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1228 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1230 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1232 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1234) */
/* 1234 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1236 */	NdrFcLong( 0x54a6f7f9 ),	/* 1420228601 */
/* 1240 */	NdrFcShort( 0x5c98 ),	/* 23704 */
/* 1242 */	NdrFcShort( 0x4c65 ),	/* 19557 */
/* 1244 */	0x96,		/* 150 */
			0xd5,		/* 213 */
/* 1246 */	0xbd,		/* 189 */
			0x43,		/* 67 */
/* 1248 */	0xd2,		/* 210 */
			0x48,		/* 72 */
/* 1250 */	0xb7,		/* 183 */
			0x88,		/* 136 */
/* 1252 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1254 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1256) */
/* 1256 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1258 */	NdrFcLong( 0x882df9bc ),	/* -2010252868 */
/* 1262 */	NdrFcShort( 0xff59 ),	/* -167 */
/* 1264 */	NdrFcShort( 0x4e65 ),	/* 20069 */
/* 1266 */	0x8e,		/* 142 */
			0x7b,		/* 123 */
/* 1268 */	0xb,		/* 11 */
			0xca,		/* 202 */
/* 1270 */	0xd3,		/* 211 */
			0xd4,		/* 212 */
/* 1272 */	0x15,		/* 21 */
			0xf,		/* 15 */
/* 1274 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1276 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1278) */
/* 1278 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1288 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1290 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1292 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1294 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1296 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1298 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1300) */
/* 1300 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1302 */	NdrFcLong( 0x19487fb9 ),	/* 424181689 */
/* 1306 */	NdrFcShort( 0x54f2 ),	/* 21746 */
/* 1308 */	NdrFcShort( 0x49a6 ),	/* 18854 */
/* 1310 */	0x9d,		/* 157 */
			0xae,		/* 174 */
/* 1312 */	0xfd,		/* 253 */
			0x9a,		/* 154 */
/* 1314 */	0xdd,		/* 221 */
			0xd1,		/* 209 */
/* 1316 */	0x2a,		/* 42 */
			0x76,		/* 118 */
/* 1318 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1320 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1322) */
/* 1322 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1324 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 1328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1332 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1334 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1336 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1338 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1340 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1342 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1344) */
/* 1344 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1346 */	NdrFcLong( 0x23057881 ),	/* 587561089 */
/* 1350 */	NdrFcShort( 0x19b6 ),	/* 6582 */
/* 1352 */	NdrFcShort( 0x4395 ),	/* 17301 */
/* 1354 */	0x9d,		/* 157 */
			0x39,		/* 57 */
/* 1356 */	0xb5,		/* 181 */
			0xb6,		/* 182 */
/* 1358 */	0x2f,		/* 47 */
			0x75,		/* 117 */
/* 1360 */	0xb5,		/* 181 */
			0xef,		/* 239 */
/* 1362 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1364 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1366) */
/* 1366 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1378 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1380 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1382 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1384 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1386 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1388) */
/* 1388 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1390 */	NdrFcLong( 0x54a6f7f9 ),	/* 1420228601 */
/* 1394 */	NdrFcShort( 0x5c98 ),	/* 23704 */
/* 1396 */	NdrFcShort( 0x4c65 ),	/* 19557 */
/* 1398 */	0x96,		/* 150 */
			0xd5,		/* 213 */
/* 1400 */	0xbd,		/* 189 */
			0x43,		/* 67 */
/* 1402 */	0xd2,		/* 210 */
			0x48,		/* 72 */
/* 1404 */	0xb7,		/* 183 */
			0x88,		/* 136 */
/* 1406 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1408 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1410) */
/* 1410 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1412 */	NdrFcLong( 0x3966e6f5 ),	/* 963045109 */
/* 1416 */	NdrFcShort( 0xec21 ),	/* -5087 */
/* 1418 */	NdrFcShort( 0x413e ),	/* 16702 */
/* 1420 */	0xb0,		/* 176 */
			0xea,		/* 234 */
/* 1422 */	0xaf,		/* 175 */
			0x50,		/* 80 */
/* 1424 */	0x77,		/* 119 */
			0x20,		/* 32 */
/* 1426 */	0x59,		/* 89 */
			0x67,		/* 103 */
/* 1428 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1430 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1432) */
/* 1432 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1434 */	NdrFcLong( 0xa0cdfcd7 ),	/* -1597113129 */
/* 1438 */	NdrFcShort( 0xc97b ),	/* -13957 */
/* 1440 */	NdrFcShort( 0x426f ),	/* 17007 */
/* 1442 */	0x85,		/* 133 */
			0x28,		/* 40 */
/* 1444 */	0xa,		/* 10 */
			0xa0,		/* 160 */
/* 1446 */	0x32,		/* 50 */
			0x1e,		/* 30 */
/* 1448 */	0xa0,		/* 160 */
			0xfa,		/* 250 */
/* 1450 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1452 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1454) */
/* 1454 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1456 */	NdrFcLong( 0xf898093c ),	/* -124253892 */
/* 1460 */	NdrFcShort( 0x1b98 ),	/* 7064 */
/* 1462 */	NdrFcShort( 0x420d ),	/* 16909 */
/* 1464 */	0xb0,		/* 176 */
			0x97,		/* 151 */
/* 1466 */	0xc2,		/* 194 */
			0xf1,		/* 241 */
/* 1468 */	0xe8,		/* 232 */
			0x8c,		/* 140 */
/* 1470 */	0xa3,		/* 163 */
			0x45,		/* 69 */
/* 1472 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1474 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1476) */
/* 1476 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1478 */	NdrFcLong( 0xee1eb2ea ),	/* -299978006 */
/* 1482 */	NdrFcShort( 0xdfa3 ),	/* -8285 */
/* 1484 */	NdrFcShort( 0x42a5 ),	/* 17061 */
/* 1486 */	0xa9,		/* 169 */
			0xcb,		/* 203 */
/* 1488 */	0x32,		/* 50 */
			0x1f,		/* 31 */
/* 1490 */	0xc4,		/* 196 */
			0xb,		/* 11 */
/* 1492 */	0x4,		/* 4 */
			0xdc,		/* 220 */
/* 1494 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1496 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1498) */
/* 1498 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1500 */	NdrFcLong( 0xc10c6fdd ),	/* -1056149539 */
/* 1504 */	NdrFcShort( 0x8b99 ),	/* -29799 */
/* 1506 */	NdrFcShort( 0x4449 ),	/* 17481 */
/* 1508 */	0x82,		/* 130 */
			0xf1,		/* 241 */
/* 1510 */	0xea,		/* 234 */
			0xe6,		/* 230 */
/* 1512 */	0x74,		/* 116 */
			0x7,		/* 7 */
/* 1514 */	0xce,		/* 206 */
			0x67,		/* 103 */
/* 1516 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1518 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1520) */
/* 1520 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1522 */	NdrFcLong( 0xef6bf49c ),	/* -278137700 */
/* 1526 */	NdrFcShort( 0x742c ),	/* 29740 */
/* 1528 */	NdrFcShort( 0x4c57 ),	/* 19543 */
/* 1530 */	0x8a,		/* 138 */
			0x37,		/* 55 */
/* 1532 */	0xce,		/* 206 */
			0xcf,		/* 207 */
/* 1534 */	0xe2,		/* 226 */
			0x79,		/* 121 */
/* 1536 */	0xdb,		/* 219 */
			0x97,		/* 151 */
/* 1538 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1540 */	NdrFcLong( 0xa0cdfcd7 ),	/* -1597113129 */
/* 1544 */	NdrFcShort( 0xc97b ),	/* -13957 */
/* 1546 */	NdrFcShort( 0x426f ),	/* 17007 */
/* 1548 */	0x85,		/* 133 */
			0x28,		/* 40 */
/* 1550 */	0xa,		/* 10 */
			0xa0,		/* 160 */
/* 1552 */	0x32,		/* 50 */
			0x1e,		/* 30 */
/* 1554 */	0xa0,		/* 160 */
			0xfa,		/* 250 */
/* 1556 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1558 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1560) */
/* 1560 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1562 */	NdrFcLong( 0x16103c6e ),	/* 370162798 */
/* 1566 */	NdrFcShort( 0xb6d1 ),	/* -18735 */
/* 1568 */	NdrFcShort( 0x4f7c ),	/* 20348 */
/* 1570 */	0xbd,		/* 189 */
			0xa8,		/* 168 */
/* 1572 */	0xe6,		/* 230 */
			0xcf,		/* 207 */
/* 1574 */	0x51,		/* 81 */
			0x12,		/* 18 */
/* 1576 */	0xac,		/* 172 */
			0xcd,		/* 205 */
/* 1578 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1580 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1582) */
/* 1582 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1584 */	NdrFcLong( 0xff3a0bdd ),	/* -12973091 */
/* 1588 */	NdrFcShort( 0x1aa5 ),	/* 6821 */
/* 1590 */	NdrFcShort( 0x48fa ),	/* 18682 */
/* 1592 */	0x9f,		/* 159 */
			0x40,		/* 64 */
/* 1594 */	0x22,		/* 34 */
			0x8a,		/* 138 */
/* 1596 */	0x0,		/* 0 */
			0xc6,		/* 198 */
/* 1598 */	0x4a,		/* 74 */
			0x47,		/* 71 */
/* 1600 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1602 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1604) */
/* 1604 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1606 */	NdrFcLong( 0xaba27711 ),	/* -1415416047 */
/* 1610 */	NdrFcShort( 0x124a ),	/* 4682 */
/* 1612 */	NdrFcShort( 0x47c3 ),	/* 18371 */
/* 1614 */	0xbb,		/* 187 */
			0x88,		/* 136 */
/* 1616 */	0x3d,		/* 61 */
			0x27,		/* 39 */
/* 1618 */	0x3,		/* 3 */
			0xf8,		/* 248 */
/* 1620 */	0x79,		/* 121 */
			0x84,		/* 132 */
/* 1622 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1624 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1626) */
/* 1626 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1628 */	NdrFcLong( 0x3c500269 ),	/* 1011876457 */
/* 1632 */	NdrFcShort( 0x634e ),	/* 25422 */
/* 1634 */	NdrFcShort( 0x4018 ),	/* 16408 */
/* 1636 */	0x95,		/* 149 */
			0x98,		/* 152 */
/* 1638 */	0x91,		/* 145 */
			0x6c,		/* 108 */
/* 1640 */	0x70,		/* 112 */
			0x35,		/* 53 */
/* 1642 */	0xcc,		/* 204 */
			0xaa,		/* 170 */
/* 1644 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1646 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1648) */
/* 1648 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1650 */	NdrFcLong( 0x7f4ba82 ),	/* 133479042 */
/* 1654 */	NdrFcShort( 0xaa63 ),	/* -21917 */
/* 1656 */	NdrFcShort( 0x4c00 ),	/* 19456 */
/* 1658 */	0xb6,		/* 182 */
			0x40,		/* 64 */
/* 1660 */	0xd,		/* 13 */
			0x0,		/* 0 */
/* 1662 */	0x4,		/* 4 */
			0x4f,		/* 79 */
/* 1664 */	0xb2,		/* 178 */
			0xdc,		/* 220 */
/* 1666 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1668 */	NdrFcShort( 0xff7e ),	/* Offset= -130 (1538) */
/* 1670 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1672 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1674) */
/* 1674 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1676 */	NdrFcLong( 0x3966e6f5 ),	/* 963045109 */
/* 1680 */	NdrFcShort( 0xec21 ),	/* -5087 */
/* 1682 */	NdrFcShort( 0x413e ),	/* 16702 */
/* 1684 */	0xb0,		/* 176 */
			0xea,		/* 234 */
/* 1686 */	0xaf,		/* 175 */
			0x50,		/* 80 */
/* 1688 */	0x77,		/* 119 */
			0x20,		/* 32 */
/* 1690 */	0x59,		/* 89 */
			0x67,		/* 103 */
/* 1692 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1694 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1696) */
/* 1696 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1698 */	NdrFcLong( 0x2a7e4fcc ),	/* 712921036 */
/* 1702 */	NdrFcShort( 0x4df6 ),	/* 19958 */
/* 1704 */	NdrFcShort( 0x4e4f ),	/* 20047 */
/* 1706 */	0x81,		/* 129 */
			0xf8,		/* 248 */
/* 1708 */	0x80,		/* 128 */
			0xc0,		/* 192 */
/* 1710 */	0x48,		/* 72 */
			0x31,		/* 49 */
/* 1712 */	0x61,		/* 97 */
			0x56,		/* 86 */
/* 1714 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1716 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1718) */
/* 1718 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1720 */	NdrFcLong( 0x3c5c1ab1 ),	/* 1012669105 */
/* 1724 */	NdrFcShort( 0xafe7 ),	/* -20505 */
/* 1726 */	NdrFcShort( 0x43b3 ),	/* 17331 */
/* 1728 */	0x87,		/* 135 */
			0x4b,		/* 75 */
/* 1730 */	0xd7,		/* 215 */
			0x6d,		/* 109 */
/* 1732 */	0x77,		/* 119 */
			0x90,		/* 144 */
/* 1734 */	0x90,		/* 144 */
			0x18,		/* 24 */
/* 1736 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1738 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1740) */
/* 1740 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1742 */	NdrFcLong( 0x9e0256d6 ),	/* -1644013866 */
/* 1746 */	NdrFcShort( 0x3731 ),	/* 14129 */
/* 1748 */	NdrFcShort( 0x41c9 ),	/* 16841 */
/* 1750 */	0x99,		/* 153 */
			0x7b,		/* 123 */
/* 1752 */	0x24,		/* 36 */
			0x5f,		/* 95 */
/* 1754 */	0xf5,		/* 245 */
			0x62,		/* 98 */
/* 1756 */	0xe8,		/* 232 */
			0x29,		/* 41 */
/* 1758 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1760 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1762) */
/* 1762 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1764 */	NdrFcLong( 0xac5c4dc7 ),	/* -1403236921 */
/* 1768 */	NdrFcShort( 0xe3a7 ),	/* -7257 */
/* 1770 */	NdrFcShort( 0x4978 ),	/* 18808 */
/* 1772 */	0x97,		/* 151 */
			0xe0,		/* 224 */
/* 1774 */	0xe4,		/* 228 */
			0xf2,		/* 242 */
/* 1776 */	0xdb,		/* 219 */
			0x12,		/* 18 */
/* 1778 */	0x26,		/* 38 */
			0xef,		/* 239 */
/* 1780 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1782 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1784) */
/* 1784 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1786 */	NdrFcLong( 0x2439d908 ),	/* 607770888 */
/* 1790 */	NdrFcShort( 0xc5b ),	/* 3163 */
/* 1792 */	NdrFcShort( 0x47e0 ),	/* 18400 */
/* 1794 */	0x89,		/* 137 */
			0xe,		/* 14 */
/* 1796 */	0x46,		/* 70 */
			0xc2,		/* 194 */
/* 1798 */	0xb,		/* 11 */
			0x9f,		/* 159 */
/* 1800 */	0x18,		/* 24 */
			0x97,		/* 151 */
/* 1802 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1804 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1806) */
/* 1806 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1808 */	NdrFcLong( 0xd54bd7b3 ),	/* -716449869 */
/* 1812 */	NdrFcShort( 0x4ae1 ),	/* 19169 */
/* 1814 */	NdrFcShort( 0x4b8e ),	/* 19342 */
/* 1816 */	0x89,		/* 137 */
			0x25,		/* 37 */
/* 1818 */	0xa9,		/* 169 */
			0x2a,		/* 42 */
/* 1820 */	0x22,		/* 34 */
			0x3e,		/* 62 */
/* 1822 */	0xf6,		/* 246 */
			0x14,		/* 20 */
/* 1824 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1826 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1828) */
/* 1828 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1830 */	NdrFcLong( 0xea073cc ),	/* 245396428 */
/* 1834 */	NdrFcShort( 0x3c4a ),	/* 15434 */
/* 1836 */	NdrFcShort( 0x48ea ),	/* 18666 */
/* 1838 */	0x97,		/* 151 */
			0x99,		/* 153 */
/* 1840 */	0x3c,		/* 60 */
			0x81,		/* 129 */
/* 1842 */	0x8d,		/* 141 */
			0x81,		/* 129 */
/* 1844 */	0x7,		/* 7 */
			0xa6,		/* 166 */
/* 1846 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1848 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1850) */
/* 1850 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1852 */	NdrFcLong( 0x381b3303 ),	/* 941306627 */
/* 1856 */	NdrFcShort( 0x9eea ),	/* -24854 */
/* 1858 */	NdrFcShort( 0x482a ),	/* 18474 */
/* 1860 */	0xa1,		/* 161 */
			0x84,		/* 132 */
/* 1862 */	0xf4,		/* 244 */
			0x4,		/* 4 */
/* 1864 */	0xc8,		/* 200 */
			0x5a,		/* 90 */
/* 1866 */	0xb8,		/* 184 */
			0x7d,		/* 125 */
/* 1868 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1870 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1872) */
/* 1872 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1874 */	NdrFcLong( 0xad55f898 ),	/* -1386874728 */
/* 1878 */	NdrFcShort( 0x5cf6 ),	/* 23798 */
/* 1880 */	NdrFcShort( 0x4d13 ),	/* 19731 */
/* 1882 */	0x97,		/* 151 */
			0xdb,		/* 219 */
/* 1884 */	0xfe,		/* 254 */
			0xab,		/* 171 */
/* 1886 */	0x11,		/* 17 */
			0x56,		/* 86 */
/* 1888 */	0x62,		/* 98 */
			0x6f,		/* 111 */
/* 1890 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1892 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1894) */
/* 1894 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1896 */	NdrFcLong( 0x37ebffcd ),	/* 938213325 */
/* 1900 */	NdrFcShort( 0x77e ),	/* 1918 */
/* 1902 */	NdrFcShort( 0x4323 ),	/* 17187 */
/* 1904 */	0x83,		/* 131 */
			0xe0,		/* 224 */
/* 1906 */	0x3a,		/* 58 */
			0x82,		/* 130 */
/* 1908 */	0x55,		/* 85 */
			0xaf,		/* 175 */
/* 1910 */	0xb8,		/* 184 */
			0x45,		/* 69 */
/* 1912 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1914 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1916) */
/* 1916 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1918 */	NdrFcLong( 0x47b8d6ab ),	/* 1203295915 */
/* 1922 */	NdrFcShort( 0x475c ),	/* 18268 */
/* 1924 */	NdrFcShort( 0x4102 ),	/* 16642 */
/* 1926 */	0xaf,		/* 175 */
			0x1a,		/* 26 */
/* 1928 */	0x69,		/* 105 */
			0x62,		/* 98 */
/* 1930 */	0xa7,		/* 167 */
			0x79,		/* 121 */
/* 1932 */	0x6c,		/* 108 */
			0x3a,		/* 58 */
/* 1934 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1936 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1938 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1940 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1942) */
/* 1942 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1944 */	NdrFcLong( 0x4ab8ed74 ),	/* 1253633396 */
/* 1948 */	NdrFcShort( 0x3b2f ),	/* 15151 */
/* 1950 */	NdrFcShort( 0x47ab ),	/* 18347 */
/* 1952 */	0xb0,		/* 176 */
			0x81,		/* 129 */
/* 1954 */	0xd6,		/* 214 */
			0x76,		/* 118 */
/* 1956 */	0xc2,		/* 194 */
			0xc4,		/* 196 */
/* 1958 */	0x5a,		/* 90 */
			0xe8,		/* 232 */
/* 1960 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1962 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1964) */
/* 1964 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1966 */	NdrFcLong( 0x861dbf0 ),	/* 140631024 */
/* 1970 */	NdrFcShort( 0x310a ),	/* 12554 */
/* 1972 */	NdrFcShort( 0x4f63 ),	/* 20323 */
/* 1974 */	0xbb,		/* 187 */
			0x23,		/* 35 */
/* 1976 */	0xdc,		/* 220 */
			0x9c,		/* 156 */
/* 1978 */	0x37,		/* 55 */
			0x34,		/* 52 */
/* 1980 */	0x11,		/* 17 */
			0x55,		/* 85 */
/* 1982 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1984 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1986) */
/* 1986 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1988 */	NdrFcLong( 0xf5074ba1 ),	/* -184071263 */
/* 1992 */	NdrFcShort( 0x513a ),	/* 20794 */
/* 1994 */	NdrFcShort( 0x4f33 ),	/* 20275 */
/* 1996 */	0x90,		/* 144 */
			0x91,		/* 145 */
/* 1998 */	0xcc,		/* 204 */
			0x8c,		/* 140 */
/* 2000 */	0xf5,		/* 245 */
			0x6d,		/* 109 */
/* 2002 */	0xaa,		/* 170 */
			0xb1,		/* 177 */
/* 2004 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2006 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2008) */
/* 2008 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2010 */	NdrFcLong( 0x449f2c9c ),	/* 1151282332 */
/* 2014 */	NdrFcShort( 0xfa8e ),	/* -1394 */
/* 2016 */	NdrFcShort( 0x43a1 ),	/* 17313 */
/* 2018 */	0xb3,		/* 179 */
			0x32,		/* 50 */
/* 2020 */	0xaf,		/* 175 */
			0xad,		/* 173 */
/* 2022 */	0x30,		/* 48 */
			0x36,		/* 54 */
/* 2024 */	0xc,		/* 12 */
			0x60,		/* 96 */
/* 2026 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2028 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2030) */
/* 2030 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2032 */	NdrFcLong( 0x2eedc914 ),	/* 787335444 */
/* 2036 */	NdrFcShort( 0xdab8 ),	/* -9544 */
/* 2038 */	NdrFcShort( 0x467b ),	/* 18043 */
/* 2040 */	0x89,		/* 137 */
			0x9f,		/* 159 */
/* 2042 */	0xed,		/* 237 */
			0xcc,		/* 204 */
/* 2044 */	0x4c,		/* 76 */
			0x2b,		/* 43 */
/* 2046 */	0x5d,		/* 93 */
			0xb,		/* 11 */
/* 2048 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2050 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2052) */
/* 2052 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2054 */	NdrFcLong( 0x27423066 ),	/* 658649190 */
/* 2058 */	NdrFcShort( 0x332f ),	/* 13103 */
/* 2060 */	NdrFcShort( 0x4719 ),	/* 18201 */
/* 2062 */	0xb6,		/* 182 */
			0x4b,		/* 75 */
/* 2064 */	0xba,		/* 186 */
			0x65,		/* 101 */
/* 2066 */	0x5c,		/* 92 */
			0x36,		/* 54 */
/* 2068 */	0xce,		/* 206 */
			0x47,		/* 71 */
/* 2070 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2072 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2074) */
/* 2074 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2076 */	NdrFcLong( 0x37ebffcd ),	/* 938213325 */
/* 2080 */	NdrFcShort( 0x77e ),	/* 1918 */
/* 2082 */	NdrFcShort( 0x4323 ),	/* 17187 */
/* 2084 */	0x83,		/* 131 */
			0xe0,		/* 224 */
/* 2086 */	0x3a,		/* 58 */
			0x82,		/* 130 */
/* 2088 */	0x55,		/* 85 */
			0xaf,		/* 175 */
/* 2090 */	0xb8,		/* 184 */
			0x45,		/* 69 */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Standard interface: __MIDL_itf_TransCAD_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IApplication, ver. 0.0,
   GUID={0x19487FB9,0x54F2,0x49A6,{0x9D,0xAE,0xFD,0x9A,0xDD,0xD1,0x2A,0x76}} */

#pragma code_seg(".orpc")
static const unsigned short IApplication_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    108,
    144,
    180,
    216,
    252
    };

static const MIDL_STUBLESS_PROXY_INFO IApplication_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IApplication_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IApplication_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IApplication_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IApplicationProxyVtbl = 
{
    &IApplication_ProxyInfo,
    &IID_IApplication,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IApplication::get_Visible */ ,
    (void *) (INT_PTR) -1 /* IApplication::put_Visible */ ,
    (void *) (INT_PTR) -1 /* IApplication::get_Application */ ,
    (void *) (INT_PTR) -1 /* IApplication::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IApplication::get_ActiveDocument */ ,
    (void *) (INT_PTR) -1 /* IApplication::get_Documents */ ,
    (void *) (INT_PTR) -1 /* IApplication::get_Name */ ,
    (void *) (INT_PTR) -1 /* IApplication::Quit */
};


static const PRPC_STUB_FUNCTION IApplication_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IApplicationStubVtbl =
{
    &IID_IApplication,
    &IApplication_ServerInfo,
    15,
    &IApplication_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDocs, ver. 0.0,
   GUID={0xC12FB0DA,0x8BB2,0x4CF4,{0xBC,0x4F,0x7D,0x53,0x8B,0xA3,0x67,0x27}} */

#pragma code_seg(".orpc")
static const unsigned short IDocs_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    282,
    318,
    354,
    390,
    432,
    468,
    504,
    252,
    540
    };

static const MIDL_STUBLESS_PROXY_INFO IDocs_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IDocs_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDocs_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IDocs_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IDocsProxyVtbl = 
{
    &IDocs_ProxyInfo,
    &IID_IDocs,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDocs::get_Application */ ,
    (void *) (INT_PTR) -1 /* IDocs::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IDocs::get_Count */ ,
    (void *) (INT_PTR) -1 /* IDocs::get_Item */ ,
    (void *) (INT_PTR) -1 /* IDocs::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IDocs::AddPartDocument */ ,
    (void *) (INT_PTR) -1 /* IDocs::AddAssemDocument */ ,
    (void *) (INT_PTR) -1 /* IDocs::Close */ ,
    (void *) (INT_PTR) -1 /* IDocs::Open */
};


static const PRPC_STUB_FUNCTION IDocs_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDocsStubVtbl =
{
    &IID_IDocs,
    &IDocs_ServerInfo,
    16,
    &IDocs_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDoc, ver. 0.0,
   GUID={0xBC5F8AB3,0x0439,0x4F12,{0xAF,0x08,0x8F,0x7D,0x74,0x92,0x89,0x40}} */

#pragma code_seg(".orpc")
static const unsigned short IDoc_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    282,
    318,
    582,
    618,
    654,
    690,
    726,
    756,
    798,
    828
    };

static const MIDL_STUBLESS_PROXY_INFO IDoc_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IDoc_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDoc_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IDoc_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IDocProxyVtbl = 
{
    &IDoc_ProxyInfo,
    &IID_IDoc,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Application */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_FullName */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Name */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Path */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Saved */ ,
    (void *) (INT_PTR) -1 /* IDoc::Activate */ ,
    (void *) (INT_PTR) -1 /* IDoc::Close */ ,
    (void *) (INT_PTR) -1 /* IDoc::Save */ ,
    (void *) (INT_PTR) -1 /* IDoc::SaveAs */
};


static const PRPC_STUB_FUNCTION IDoc_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDocStubVtbl =
{
    &IID_IDoc,
    &IDoc_ServerInfo,
    17,
    &IDoc_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IPartDocument, ver. 0.0,
   GUID={0xC37F3BC0,0x22DD,0x4E20,{0xA2,0x03,0x28,0x6A,0xCE,0x86,0x27,0x58}} */

#pragma code_seg(".orpc")
static const unsigned short IPartDocument_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    282,
    318,
    582,
    618,
    654,
    690,
    726,
    756,
    798,
    828,
    864,
    900,
    930,
    966,
    1008,
    1038,
    1074,
    1110,
    1146,
    1182,
    1218,
    1254,
    1290,
    1326,
    1362,
    1398
    };

static const MIDL_STUBLESS_PROXY_INFO IPartDocument_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IPartDocument_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPartDocument_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IPartDocument_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(33) _IPartDocumentProxyVtbl = 
{
    &IPartDocument_ProxyInfo,
    &IID_IPartDocument,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Application */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_FullName */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Name */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Path */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Saved */ ,
    (void *) (INT_PTR) -1 /* IDoc::Activate */ ,
    (void *) (INT_PTR) -1 /* IDoc::Close */ ,
    (void *) (INT_PTR) -1 /* IDoc::Save */ ,
    (void *) (INT_PTR) -1 /* IDoc::SaveAs */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::get_Part */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::Update */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::get_Title */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::DoMeshGeneration */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::GetBBDiagonal */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ImportFromCATIA */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ExportToCATIA */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ImportFromUG */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ExportToUG */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ExportToMesh */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ExportToBrep */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ExportToXML */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ImportFromXML */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::RunScriptInterface */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ImportFromBrep */ ,
    (void *) (INT_PTR) -1 /* IPartDocument::ConvertMesh */
};


static const PRPC_STUB_FUNCTION IPartDocument_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IPartDocumentStubVtbl =
{
    &IID_IPartDocument,
    &IPartDocument_ServerInfo,
    33,
    &IPartDocument_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IPart, ver. 0.0,
   GUID={0x37EBFFCD,0x077E,0x4323,{0x83,0xE0,0x3A,0x82,0x55,0xAF,0xB8,0x45}} */

#pragma code_seg(".orpc")
static const unsigned short IPart_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    282,
    318,
    582,
    1440,
    1476,
    1512,
    1554,
    1596,
    1686,
    1776,
    1818,
    1872,
    1908,
    1944,
    1980,
    2016,
    2052,
    2094,
    2130
    };

static const MIDL_STUBLESS_PROXY_INFO IPart_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IPart_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPart_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IPart_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IPartProxyVtbl = 
{
    &IPart_ProxyInfo,
    &IID_IPart,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IPart::get_Application */ ,
    (void *) (INT_PTR) -1 /* IPart::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IPart::get_Name */ ,
    (void *) (INT_PTR) -1 /* IPart::get_Features */ ,
    (void *) (INT_PTR) -1 /* IPart::CreateReferences */ ,
    (void *) (INT_PTR) -1 /* IPart::SelectObjectByName */ ,
    (void *) (INT_PTR) -1 /* IPart::SelectBrepByName */ ,
    (void *) (INT_PTR) -1 /* IPart::SelectPlaneByAxis */ ,
    (void *) (INT_PTR) -1 /* IPart::SelectCurveBy3Points */ ,
    (void *) (INT_PTR) -1 /* IPart::SelectFeatureByName */ ,
    (void *) (INT_PTR) -1 /* IPart::SelectCurveByPoint */ ,
    (void *) (INT_PTR) -1 /* IPart::set_Name */ ,
    (void *) (INT_PTR) -1 /* IPart::set_ParentName */ ,
    (void *) (INT_PTR) -1 /* IPart::get_ParentName */ ,
    (void *) (INT_PTR) -1 /* IPart::LoadFromFile */ ,
    (void *) (INT_PTR) -1 /* IPart::IsBrepPart */ ,
    (void *) (INT_PTR) -1 /* IPart::SelectSketchSegmentByName */ ,
    (void *) (INT_PTR) -1 /* IPart::get_Solid */ ,
    (void *) (INT_PTR) -1 /* IPart::GetPlacement */
};


static const PRPC_STUB_FUNCTION IPart_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IPartStubVtbl =
{
    &IID_IPart,
    &IPart_ServerInfo,
    26,
    &IPart_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFeatures, ver. 0.0,
   GUID={0x8084C085,0x5F3F,0x49F0,{0xB8,0x2C,0x22,0x76,0xF1,0x2C,0x88,0xAB}} */

#pragma code_seg(".orpc")
static const unsigned short IFeatures_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2214,
    2250,
    354,
    2286,
    2328,
    2364,
    2412,
    2490,
    2568,
    2628,
    2682,
    2736,
    2814,
    2892,
    3000,
    3114,
    3210,
    3306,
    3366,
    3468,
    3534,
    3588,
    3642,
    3720,
    3780,
    3900,
    3936,
    3972,
    4062,
    4116
    };

static const MIDL_STUBLESS_PROXY_INFO IFeatures_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IFeatures_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFeatures_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IFeatures_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(37) _IFeaturesProxyVtbl = 
{
    &IFeatures_ProxyInfo,
    &IID_IFeatures,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeatures::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeatures::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeatures::get_Count */ ,
    (void *) (INT_PTR) -1 /* IFeatures::get_Item */ ,
    (void *) (INT_PTR) -1 /* IFeatures::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSketchFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidProtrusionExtrudeFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidCutExtrudeFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidFilletConstantFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidChamferFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidProtrusionSweepFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidProtrusionRevolveFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidCutRevolveFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidOperatePatternRectangularFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidOperatePatternCircularFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidHoleCounterboredFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidHoleCountersunkFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewDatumPlaneOffsetFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewDatumPlaneOffsetFeature2 */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidLoftFacesFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidLoftSectionsFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidCutSweepFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidHoleSimpleFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidShellFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidRevolveWithExternalAxisFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::Delete */ ,
    (void *) (INT_PTR) -1 /* IFeatures::DeleteByName */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidDraftFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidOffsetFeature */ ,
    (void *) (INT_PTR) -1 /* IFeatures::AddNewSolidImportedBrepFeature */
};


static const PRPC_STUB_FUNCTION IFeatures_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFeaturesStubVtbl =
{
    &IID_IFeatures,
    &IFeatures_ServerInfo,
    37,
    &IFeatures_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFeature, ver. 0.0,
   GUID={0xF898093C,0x1B98,0x420d,{0xB0,0x97,0xC2,0xF1,0xE8,0x8C,0xA3,0x45}} */

#pragma code_seg(".orpc")
static const unsigned short IFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272
    };

static const MIDL_STUBLESS_PROXY_INFO IFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IFeatureProxyVtbl = 
{
    &IFeature_ProxyInfo,
    &IID_IFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */
};


static const PRPC_STUB_FUNCTION IFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFeatureStubVtbl =
{
    &IID_IFeature,
    &IFeature_ServerInfo,
    12,
    &IFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdDefaultDatumPlaneFeature, ver. 0.0,
   GUID={0xF91A93A8,0x65A9,0x48DC,{0xA4,0x4F,0xBD,0xD0,0x1C,0xBE,0xF5,0x88}} */

#pragma code_seg(".orpc")
static const unsigned short IStdDefaultDatumPlaneFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IStdDefaultDatumPlaneFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdDefaultDatumPlaneFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdDefaultDatumPlaneFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdDefaultDatumPlaneFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IStdDefaultDatumPlaneFeatureProxyVtbl = 
{
    0,
    &IID_IStdDefaultDatumPlaneFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    0 /* forced delegation IFeature::get_Application */ ,
    0 /* forced delegation IFeature::get_Parent */ ,
    0 /* forced delegation IFeature::get_Type */ ,
    0 /* forced delegation IFeature::get_Name */ ,
    0 /* forced delegation IFeature::SetName */
};


static const PRPC_STUB_FUNCTION IStdDefaultDatumPlaneFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdDefaultDatumPlaneFeatureStubVtbl =
{
    &IID_IStdDefaultDatumPlaneFeature,
    &IStdDefaultDatumPlaneFeature_ServerInfo,
    12,
    &IStdDefaultDatumPlaneFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchFeature, ver. 0.0,
   GUID={0x54A6F7F9,0x5C98,0x4C65,{0x96,0xD5,0xBD,0x43,0xD2,0x48,0xB7,0x88}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    4308,
    4344,
    4380,
    4416,
    4452,
    4488,
    4524,
    4560,
    4596,
    4632,
    4674,
    4758,
    1110
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IStdSketchFeatureProxyVtbl = 
{
    &IStdSketchFeature_ProxyInfo,
    &IID_IStdSketchFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::get_Origin */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::get_HDirection */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::get_VDirection */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::get_Geometries */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::get_Constraints */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::get_Sketch */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::get_SketchPlane */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::get_IsInversed */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::OpenEditor */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::OpenEditorEx */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::SetCoordinateSystem */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::GetCoordinateSystem */ ,
    (void *) (INT_PTR) -1 /* IStdSketchFeature::DeleteByName */
};


static const PRPC_STUB_FUNCTION IStdSketchFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchFeatureStubVtbl =
{
    &IID_IStdSketchFeature,
    &IStdSketchFeature_ServerInfo,
    25,
    &IStdSketchFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidProtrusionExtrudeFeature, ver. 0.0,
   GUID={0x570069A3,0xAC18,0x40E5,{0x9C,0xD4,0xBE,0x1E,0xCF,0x83,0x18,0xE2}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidProtrusionExtrudeFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    4842,
    4878,
    4914,
    4950,
    4986,
    5022,
    5058,
    5094,
    5130,
    5166,
    5202,
    5238
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidProtrusionExtrudeFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidProtrusionExtrudeFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidProtrusionExtrudeFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidProtrusionExtrudeFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IStdSolidProtrusionExtrudeFeatureProxyVtbl = 
{
    &IStdSolidProtrusionExtrudeFeature_ProxyInfo,
    &IID_IStdSolidProtrusionExtrudeFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::get_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::put_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::get_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::put_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::get_StartCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::put_StartCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::get_StartDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::put_StartDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::get_EndCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::put_EndCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::get_EndDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionExtrudeFeature::put_EndDepth */
};


static const PRPC_STUB_FUNCTION IStdSolidProtrusionExtrudeFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidProtrusionExtrudeFeatureStubVtbl =
{
    &IID_IStdSolidProtrusionExtrudeFeature,
    &IStdSolidProtrusionExtrudeFeature_ServerInfo,
    24,
    &IStdSolidProtrusionExtrudeFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidCutExtrudeFeature, ver. 0.0,
   GUID={0x8645E5AD,0x94DF,0x48A8,{0xAD,0x8E,0x9E,0xD7,0x17,0xAC,0x46,0x91}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidCutExtrudeFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    4842,
    4878,
    4914,
    4950,
    4986,
    5022,
    5058,
    5094,
    5130,
    5166,
    5202,
    5238
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidCutExtrudeFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidCutExtrudeFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidCutExtrudeFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidCutExtrudeFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IStdSolidCutExtrudeFeatureProxyVtbl = 
{
    &IStdSolidCutExtrudeFeature_ProxyInfo,
    &IID_IStdSolidCutExtrudeFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::get_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::put_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::get_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::put_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::get_StartCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::put_StartCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::get_StartDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::put_StartDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::get_EndCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::put_EndCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::get_EndDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutExtrudeFeature::put_EndDepth */
};


static const PRPC_STUB_FUNCTION IStdSolidCutExtrudeFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidCutExtrudeFeatureStubVtbl =
{
    &IID_IStdSolidCutExtrudeFeature,
    &IStdSolidCutExtrudeFeature_ServerInfo,
    24,
    &IStdSolidCutExtrudeFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidFilletConstantFeature, ver. 0.0,
   GUID={0x7813D4F8,0x1398,0x4A75,{0x8F,0xEA,0xAF,0x3A,0x26,0x2A,0x98,0x98}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidFilletConstantFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    5274,
    5310,
    5346,
    5382,
    4986,
    5022,
    5058,
    5418,
    5454,
    5490,
    5202,
    5526,
    5562,
    5604,
    5646,
    5688,
    5730,
    5772
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidFilletConstantFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidFilletConstantFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidFilletConstantFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidFilletConstantFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(30) _IStdSolidFilletConstantFeatureProxyVtbl = 
{
    &IStdSolidFilletConstantFeature_ProxyInfo,
    &IID_IStdSolidFilletConstantFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_FilletEdges */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::put_FilletEdges */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_Radius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::put_Radius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_Propagation */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::put_Propagation */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_StartPosX */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_StartPosY */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_StartPosZ */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_EndPosX */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_EndPosY */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_EndPosZ */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_StartPosXAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_StartPosYAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_StartPosZAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_EndPosXAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_EndPosYAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidFilletConstantFeature::get_EndPosZAt */
};


static const PRPC_STUB_FUNCTION IStdSolidFilletConstantFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidFilletConstantFeatureStubVtbl =
{
    &IID_IStdSolidFilletConstantFeature,
    &IStdSolidFilletConstantFeature_ServerInfo,
    30,
    &IStdSolidFilletConstantFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchOrigin, ver. 0.0,
   GUID={0x1804C402,0xFBAF,0x438F,{0xB8,0x49,0xAB,0x69,0x40,0x60,0x6E,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchOrigin_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5814,
    5850,
    582,
    5886
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchOrigin_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchOrigin_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchOrigin_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchOrigin_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IStdSketchOriginProxyVtbl = 
{
    &IStdSketchOrigin_ProxyInfo,
    &IID_IStdSketchOrigin,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchOrigin::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchOrigin::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchOrigin::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchOrigin::get_SketchFeature */
};


static const PRPC_STUB_FUNCTION IStdSketchOrigin_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchOriginStubVtbl =
{
    &IID_IStdSketchOrigin,
    &IStdSketchOrigin_ServerInfo,
    11,
    &IStdSketchOrigin_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchVDirection, ver. 0.0,
   GUID={0x1C5FDD6C,0x3075,0x4A54,{0x9E,0x08,0xD9,0x59,0x76,0x9C,0x24,0xC6}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchVDirection_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5814,
    5850,
    582,
    5886
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchVDirection_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchVDirection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchVDirection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchVDirection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IStdSketchVDirectionProxyVtbl = 
{
    &IStdSketchVDirection_ProxyInfo,
    &IID_IStdSketchVDirection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchVDirection::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchVDirection::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchVDirection::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchVDirection::get_SketchFeature */
};


static const PRPC_STUB_FUNCTION IStdSketchVDirection_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchVDirectionStubVtbl =
{
    &IID_IStdSketchVDirection,
    &IStdSketchVDirection_ServerInfo,
    11,
    &IStdSketchVDirection_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchHDirection, ver. 0.0,
   GUID={0x5A732443,0x2A35,0x4519,{0x9C,0x1A,0x5C,0x9E,0x25,0x34,0x2D,0x22}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchHDirection_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5814,
    5850,
    582,
    5886
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchHDirection_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchHDirection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchHDirection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchHDirection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IStdSketchHDirectionProxyVtbl = 
{
    &IStdSketchHDirection_ProxyInfo,
    &IID_IStdSketchHDirection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchHDirection::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchHDirection::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchHDirection::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchHDirection::get_SketchFeature */
};


static const PRPC_STUB_FUNCTION IStdSketchHDirection_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchHDirectionStubVtbl =
{
    &IID_IStdSketchHDirection,
    &IStdSketchHDirection_ServerInfo,
    11,
    &IStdSketchHDirection_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchGeometries, ver. 0.0,
   GUID={0x7FFE9084,0x7C7B,0x4E75,{0xAB,0xF6,0xC2,0x1A,0x12,0x81,0xE2,0x79}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchGeometries_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5814,
    5850,
    354,
    5922,
    5964,
    6000
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchGeometries_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchGeometries_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchGeometries_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchGeometries_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IStdSketchGeometriesProxyVtbl = 
{
    &IStdSketchGeometries_ProxyInfo,
    &IID_IStdSketchGeometries,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometries::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometries::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometries::get_Count */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometries::get_Item */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometries::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometries::get_FindByName */
};


static const PRPC_STUB_FUNCTION IStdSketchGeometries_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchGeometriesStubVtbl =
{
    &IID_IStdSketchGeometries,
    &IStdSketchGeometries_ServerInfo,
    13,
    &IStdSketchGeometries_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchConstraints, ver. 0.0,
   GUID={0x82DD5568,0xC7F7,0x4647,{0xB8,0x15,0x66,0xD4,0xE7,0x2D,0x57,0x38}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchConstraints_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    354,
    6108,
    6150,
    6186
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchConstraints_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchConstraints_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchConstraints_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchConstraints_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IStdSketchConstraintsProxyVtbl = 
{
    &IStdSketchConstraints_ProxyInfo,
    &IID_IStdSketchConstraints,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraints::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraints::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraints::get_Count */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraints::get_Item */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraints::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraints::get_FindByName */
};


static const PRPC_STUB_FUNCTION IStdSketchConstraints_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchConstraintsStubVtbl =
{
    &IID_IStdSketchConstraints,
    &IStdSketchConstraints_ServerInfo,
    13,
    &IStdSketchConstraints_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchGeometry, ver. 0.0,
   GUID={0x882DF9BC,0xFF59,0x4E65,{0x8E,0x7B,0x0B,0xCA,0xD3,0xD4,0x15,0x0F}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchGeometry_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchGeometry_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchGeometry_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchGeometry_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchGeometry_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IStdSketchGeometryProxyVtbl = 
{
    &IStdSketchGeometry_ProxyInfo,
    &IID_IStdSketchGeometry,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_SketchFeature */
};


static const PRPC_STUB_FUNCTION IStdSketchGeometry_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchGeometryStubVtbl =
{
    &IID_IStdSketchGeometry,
    &IStdSketchGeometry_ServerInfo,
    12,
    &IStdSketchGeometry_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchConstraint, ver. 0.0,
   GUID={0x23057881,0x19B6,0x4395,{0x9D,0x39,0xB5,0xB6,0x2F,0x75,0xB5,0xEF}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchConstraint_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchConstraint_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchConstraint_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchConstraint_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchConstraint_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IStdSketchConstraintProxyVtbl = 
{
    &IStdSketchConstraint_ProxyInfo,
    &IID_IStdSketchConstraint,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_SketchFeature */
};


static const PRPC_STUB_FUNCTION IStdSketchConstraint_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchConstraintStubVtbl =
{
    &IID_IStdSketchConstraint,
    &IStdSketchConstraint_ServerInfo,
    12,
    &IStdSketchConstraint_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchCircle, ver. 0.0,
   GUID={0xC10C6FDD,0x8B99,0x4449,{0x82,0xF1,0xEA,0xE6,0x74,0x07,0xCE,0x67}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchCircle_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    6258,
    6294
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchCircle_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchCircle_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchCircle_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchCircle_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStdSketchCircleProxyVtbl = 
{
    &IStdSketchCircle_ProxyInfo,
    &IID_IStdSketchCircle,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCircle::get_CenterPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCircle::get_Radius */
};


static const PRPC_STUB_FUNCTION IStdSketchCircle_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchCircleStubVtbl =
{
    &IID_IStdSketchCircle,
    &IStdSketchCircle_ServerInfo,
    14,
    &IStdSketchCircle_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchCircularArc, ver. 0.0,
   GUID={0xEF6BF49C,0x742C,0x4C57,{0x8A,0x37,0xCE,0xCF,0xE2,0x79,0xDB,0x97}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchCircularArc_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    6258,
    6330,
    6366,
    6402,
    6438,
    6474
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchCircularArc_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchCircularArc_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchCircularArc_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchCircularArc_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IStdSketchCircularArcProxyVtbl = 
{
    &IStdSketchCircularArc_ProxyInfo,
    &IID_IStdSketchCircularArc,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCircularArc::get_CenterPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCircularArc::get_StartPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCircularArc::get_EndPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCircularArc::get_Radius */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCircularArc::get_StartAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCircularArc::get_EndAngle */
};


static const PRPC_STUB_FUNCTION IStdSketchCircularArc_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchCircularArcStubVtbl =
{
    &IID_IStdSketchCircularArc,
    &IStdSketchCircularArc_ServerInfo,
    18,
    &IStdSketchCircularArc_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchControlPoint, ver. 0.0,
   GUID={0x3966E6F5,0xEC21,0x413E,{0xB0,0xEA,0xAF,0x50,0x77,0x20,0x59,0x67}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchControlPoint_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    6510,
    6294
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchControlPoint_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchControlPoint_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchControlPoint_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchControlPoint_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStdSketchControlPointProxyVtbl = 
{
    &IStdSketchControlPoint_ProxyInfo,
    &IID_IStdSketchControlPoint,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchControlPoint::get_X */ ,
    (void *) (INT_PTR) -1 /* IStdSketchControlPoint::get_Y */
};


static const PRPC_STUB_FUNCTION IStdSketchControlPoint_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchControlPointStubVtbl =
{
    &IID_IStdSketchControlPoint,
    &IStdSketchControlPoint_ServerInfo,
    14,
    &IStdSketchControlPoint_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchLine, ver. 0.0,
   GUID={0xEE1EB2EA,0xDFA3,0x42A5,{0xA9,0xCB,0x32,0x1F,0xC4,0x0B,0x04,0xDC}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchLine_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    6258,
    6330
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchLine_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchLine_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchLine_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchLine_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStdSketchLineProxyVtbl = 
{
    &IStdSketchLine_ProxyInfo,
    &IID_IStdSketchLine,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchLine::get_StartPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSketchLine::get_EndPoint */
};


static const PRPC_STUB_FUNCTION IStdSketchLine_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchLineStubVtbl =
{
    &IID_IStdSketchLine,
    &IStdSketchLine_ServerInfo,
    14,
    &IStdSketchLine_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IReferences, ver. 0.0,
   GUID={0x2A7E4FCC,0x4DF6,0x4E4F,{0x81,0xF8,0x80,0xC0,0x48,0x31,0x61,0x56}} */

#pragma code_seg(".orpc")
static const unsigned short IReferences_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6546,
    6582,
    6624,
    6660
    };

static const MIDL_STUBLESS_PROXY_INFO IReferences_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IReferences_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IReferences_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IReferences_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IReferencesProxyVtbl = 
{
    &IReferences_ProxyInfo,
    &IID_IReferences,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IReferences::get_Count */ ,
    (void *) (INT_PTR) -1 /* IReferences::get_Item */ ,
    (void *) (INT_PTR) -1 /* IReferences::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IReferences::Add */
};


static const PRPC_STUB_FUNCTION IReferences_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IReferencesStubVtbl =
{
    &IID_IReferences,
    &IReferences_ServerInfo,
    11,
    &IReferences_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IReference, ver. 0.0,
   GUID={0xA0CDFCD7,0xC97B,0x426F,{0x85,0x28,0x0A,0xA0,0x32,0x1E,0xA0,0xFA}} */

#pragma code_seg(".orpc")
static const unsigned short IReference_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6696,
    6732,
    582
    };

static const MIDL_STUBLESS_PROXY_INFO IReference_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IReference_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IReference_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IReference_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IReferenceProxyVtbl = 
{
    &IReference_ProxyInfo,
    &IID_IReference,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IReference::get_Type */ ,
    (void *) (INT_PTR) -1 /* IReference::get_Name */ ,
    (void *) (INT_PTR) -1 /* IReference::get_ReferenceeName */
};


static const PRPC_STUB_FUNCTION IReference_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IReferenceStubVtbl =
{
    &IID_IReference,
    &IReference_ServerInfo,
    10,
    &IReference_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IExplicitModelObject, ver. 0.0,
   GUID={0x86E4FF07,0x1F31,0x42AD,{0xA9,0x22,0x31,0x5C,0x8D,0xD5,0x79,0x43}} */

#pragma code_seg(".orpc")
static const unsigned short IExplicitModelObject_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    6768,
    654
    };

static const MIDL_STUBLESS_PROXY_INFO IExplicitModelObject_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IExplicitModelObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IExplicitModelObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IExplicitModelObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IExplicitModelObjectProxyVtbl = 
{
    &IExplicitModelObject_ProxyInfo,
    &IID_IExplicitModelObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IExplicitModelObject::get_Application */ ,
    (void *) (INT_PTR) -1 /* IExplicitModelObject::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IExplicitModelObject::get_Type */ ,
    (void *) (INT_PTR) -1 /* IExplicitModelObject::get_Creator */ ,
    (void *) (INT_PTR) -1 /* IExplicitModelObject::get_Name */
};


static const PRPC_STUB_FUNCTION IExplicitModelObject_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IExplicitModelObjectStubVtbl =
{
    &IID_IExplicitModelObject,
    &IExplicitModelObject_ServerInfo,
    12,
    &IExplicitModelObject_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ISketch, ver. 0.0,
   GUID={0x0235D6AB,0xE6F9,0x4665,{0x98,0xAF,0x75,0xB7,0xD5,0x6A,0x01,0x29}} */

#pragma code_seg(".orpc")
static const unsigned short ISketch_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    6768,
    654,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISketch_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &ISketch_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISketch_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &ISketch_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _ISketchProxyVtbl = 
{
    0,
    &IID_ISketch,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    0 /* forced delegation IExplicitModelObject::get_Application */ ,
    0 /* forced delegation IExplicitModelObject::get_Parent */ ,
    0 /* forced delegation IExplicitModelObject::get_Type */ ,
    0 /* forced delegation IExplicitModelObject::get_Creator */ ,
    0 /* forced delegation IExplicitModelObject::get_Name */
};


static const PRPC_STUB_FUNCTION ISketch_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISketchStubVtbl =
{
    &IID_ISketch,
    &ISketch_ServerInfo,
    12,
    &ISketch_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ISketchEditor, ver. 0.0,
   GUID={0x57FAE9E3,0xF8D4,0x49B2,{0xAB,0x0A,0xB8,0x8F,0x64,0x0B,0x7C,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short ISketchEditor_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6804,
    6834,
    6900,
    6960,
    7032,
    7110,
    7188,
    7254,
    7320,
    7374,
    7428,
    7476,
    1908
    };

static const MIDL_STUBLESS_PROXY_INFO ISketchEditor_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &ISketchEditor_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISketchEditor_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &ISketchEditor_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(20) _ISketchEditorProxyVtbl = 
{
    &ISketchEditor_ProxyInfo,
    &IID_ISketchEditor,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::Close */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::Create2DLine2Points */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::Create2DCircleCenterPoint */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::Create2DArc */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::Create2DArcCenterStartEnd */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::Create2DArc3Points */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::Create2DCenterline2Points */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::CreateCoincidentSamePoints */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::CreatePerpendicular */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::CreateParallel */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::CreateHorizontal */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::CreateVertical */ ,
    (void *) (INT_PTR) -1 /* ISketchEditor::DeleteByName */
};


static const PRPC_STUB_FUNCTION ISketchEditor_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISketchEditorStubVtbl =
{
    &IID_ISketchEditor,
    &ISketchEditor_ServerInfo,
    20,
    &ISketchEditor_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidProtrusionSweepFeature, ver. 0.0,
   GUID={0x62F39890,0x0584,0x4142,{0xA8,0xDE,0xE4,0x19,0xF9,0xBF,0x73,0x01}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidProtrusionSweepFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    7596,
    7632
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidProtrusionSweepFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidProtrusionSweepFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidProtrusionSweepFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidProtrusionSweepFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdSolidProtrusionSweepFeatureProxyVtbl = 
{
    &IStdSolidProtrusionSweepFeature_ProxyInfo,
    &IID_IStdSolidProtrusionSweepFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionSweepFeature::get_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionSweepFeature::put_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionSweepFeature::get_GuideCurve */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionSweepFeature::put_GuideCurve */
};


static const PRPC_STUB_FUNCTION IStdSolidProtrusionSweepFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidProtrusionSweepFeatureStubVtbl =
{
    &IID_IStdSolidProtrusionSweepFeature,
    &IStdSolidProtrusionSweepFeature_ServerInfo,
    16,
    &IStdSolidProtrusionSweepFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidProtrusionRevolveFeature, ver. 0.0,
   GUID={0xB8AAC9D3,0x8453,0x48C9,{0xAC,0x93,0xA1,0x16,0xE8,0x91,0x10,0x1E}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidProtrusionRevolveFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    4914,
    4950,
    4986,
    6474,
    7668,
    7704,
    5454,
    7740
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidProtrusionRevolveFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidProtrusionRevolveFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidProtrusionRevolveFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidProtrusionRevolveFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(22) _IStdSolidProtrusionRevolveFeatureProxyVtbl = 
{
    &IStdSolidProtrusionRevolveFeature_ProxyInfo,
    &IID_IStdSolidProtrusionRevolveFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::get_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::put_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::get_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::put_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::get_StartCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::get_StartAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::put_StartAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::get_EndCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::get_EndAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidProtrusionRevolveFeature::put_EndAngle */
};


static const PRPC_STUB_FUNCTION IStdSolidProtrusionRevolveFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidProtrusionRevolveFeatureStubVtbl =
{
    &IID_IStdSolidProtrusionRevolveFeature,
    &IStdSolidProtrusionRevolveFeature_ServerInfo,
    22,
    &IStdSolidProtrusionRevolveFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchCenterline, ver. 0.0,
   GUID={0x2600ED0F,0x883F,0x478A,{0xAF,0xDA,0xA7,0x74,0x3A,0x1A,0xDF,0x3A}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchCenterline_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    7776,
    7812
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchCenterline_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchCenterline_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchCenterline_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchCenterline_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStdSketchCenterlineProxyVtbl = 
{
    &IStdSketchCenterline_ProxyInfo,
    &IID_IStdSketchCenterline,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchGeometry::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCenterline::get_StartPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCenterline::get_EndPoint */
};


static const PRPC_STUB_FUNCTION IStdSketchCenterline_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchCenterlineStubVtbl =
{
    &IID_IStdSketchCenterline,
    &IStdSketchCenterline_ServerInfo,
    14,
    &IStdSketchCenterline_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidOperatePatternRectangularFeature, ver. 0.0,
   GUID={0x929007FB,0x0FF4,0x477A,{0xBC,0x6B,0x9D,0xB6,0x3B,0x4F,0x64,0x07}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidOperatePatternRectangularFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7848,
    7884,
    5346,
    5382,
    7920,
    7968,
    8004,
    5418,
    8040,
    8076,
    8124,
    8160,
    8196,
    8244
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidOperatePatternRectangularFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidOperatePatternRectangularFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidOperatePatternRectangularFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidOperatePatternRectangularFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IStdSolidOperatePatternRectangularFeatureProxyVtbl = 
{
    &IStdSolidOperatePatternRectangularFeature_ProxyInfo,
    &IID_IStdSolidOperatePatternRectangularFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::get_TargetFeatures */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::put_TargetFeatures */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::get_ColumnSpacing */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::put_ColumnSpacing */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::get_ColumnDirection */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::get_ColumnNumber */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::put_ColumnNumber */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::get_RowSpacing */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::put_RowSpacing */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::get_RowDirection */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::get_RowNumber */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::put_RowNumber */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::PutColumnDirection */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternRectangularFeature::PutRowDirection */
};


static const PRPC_STUB_FUNCTION IStdSolidOperatePatternRectangularFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidOperatePatternRectangularFeatureStubVtbl =
{
    &IID_IStdSolidOperatePatternRectangularFeature,
    &IStdSolidOperatePatternRectangularFeature_ServerInfo,
    26,
    &IStdSolidOperatePatternRectangularFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidChamferFeature, ver. 0.0,
   GUID={0x7397F21A,0xE19F,0x4EDA,{0xB8,0x9F,0xE1,0x84,0x05,0xBD,0x37,0x60}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidChamferFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    8292,
    8328,
    8364,
    8400,
    6438,
    8436,
    5058,
    5418,
    5454,
    5490,
    5202,
    5526,
    8472,
    5604,
    5646,
    5688,
    5730,
    5772,
    8508
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidChamferFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidChamferFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidChamferFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidChamferFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(31) _IStdSolidChamferFeatureProxyVtbl = 
{
    &IStdSolidChamferFeature_ProxyInfo,
    &IID_IStdSolidChamferFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_ChamferType */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_SelectedEdges */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::put_SelectedEdges */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_SelectedFace */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_Length */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::put_Length */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_Value */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_StartPosX */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_StartPosY */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_StartPosZ */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_EndPosX */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_EndPosY */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_EndPosZ */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_StartPosXAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_StartPosYAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_StartPosZAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_EndPosXAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_EndPosYAt */ ,
    (void *) (INT_PTR) -1 /* IStdSolidChamferFeature::get_EndPosZAt */
};


static const PRPC_STUB_FUNCTION IStdSolidChamferFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidChamferFeatureStubVtbl =
{
    &IID_IStdSolidChamferFeature,
    &IStdSolidChamferFeature_ServerInfo,
    31,
    &IStdSolidChamferFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidCutRevolveFeature, ver. 0.0,
   GUID={0x1B8E8E40,0x7D68,0x4387,{0xA1,0x3F,0xD8,0xE2,0x04,0x21,0x26,0x07}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidCutRevolveFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    4914,
    4950,
    4986,
    6474,
    7668,
    7704,
    5454,
    7740
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidCutRevolveFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidCutRevolveFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidCutRevolveFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidCutRevolveFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(22) _IStdSolidCutRevolveFeatureProxyVtbl = 
{
    &IStdSolidCutRevolveFeature_ProxyInfo,
    &IID_IStdSolidCutRevolveFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::get_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::put_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::get_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::put_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::get_StartCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::get_StartAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::put_StartAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::get_EndCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::get_EndAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutRevolveFeature::put_EndAngle */
};


static const PRPC_STUB_FUNCTION IStdSolidCutRevolveFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidCutRevolveFeatureStubVtbl =
{
    &IID_IStdSolidCutRevolveFeature,
    &IStdSolidCutRevolveFeature_ServerInfo,
    22,
    &IStdSolidCutRevolveFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidOperatePatternCircularFeature, ver. 0.0,
   GUID={0x1B44E76F,0x21AD,0x482B,{0xA2,0xD4,0x95,0x03,0x75,0xEC,0x2D,0x61}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidOperatePatternCircularFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7848,
    7884,
    8550,
    8616,
    8652,
    6474,
    7668,
    8688,
    8724,
    5490,
    8760,
    8796,
    8832,
    8868
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidOperatePatternCircularFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidOperatePatternCircularFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidOperatePatternCircularFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidOperatePatternCircularFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IStdSolidOperatePatternCircularFeatureProxyVtbl = 
{
    &IStdSolidOperatePatternCircularFeature_ProxyInfo,
    &IID_IStdSolidOperatePatternCircularFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::get_TargetFeatures */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::put_TargetFeatures */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::get_CenterAxis */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::get_AngleNumber */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::put_AngleNumber */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::get_AngleIncrement */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::put_AngleIncrement */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::get_RadialNumber */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::put_RadialNumber */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::get_RadialSpacing */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::put_RadialSpacing */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::get_IsRadialAnignment */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::put_IsRadialAnignment */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOperatePatternCircularFeature::PutCenterAxis */
};


static const PRPC_STUB_FUNCTION IStdSolidOperatePatternCircularFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidOperatePatternCircularFeatureStubVtbl =
{
    &IID_IStdSolidOperatePatternCircularFeature,
    &IStdSolidOperatePatternCircularFeature_ServerInfo,
    26,
    &IStdSolidOperatePatternCircularFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidHoleCounterboredFeature, ver. 0.0,
   GUID={0x5089AE2E,0x41C5,0x4DD3,{0xBF,0xFA,0x6B,0x5E,0xCF,0xF9,0x91,0x41}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidHoleCounterboredFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    8934,
    6402,
    8982,
    6474,
    7668,
    5418,
    8040,
    5490,
    8760,
    5526,
    9018,
    8244
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidHoleCounterboredFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidHoleCounterboredFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidHoleCounterboredFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidHoleCounterboredFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IStdSolidHoleCounterboredFeatureProxyVtbl = 
{
    &IStdSolidHoleCounterboredFeature_ProxyInfo,
    &IID_IStdSolidHoleCounterboredFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::get_TargetFace */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::put_TargetFace */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::get_CenterPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::get_StartRadius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::put_StartRadius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::get_StartDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::put_StartDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::get_EndRadius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::put_EndRadius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::get_EndDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::put_EndDepth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::get_Angle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::put_Angle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCounterboredFeature::PutCenterPoint */
};


static const PRPC_STUB_FUNCTION IStdSolidHoleCounterboredFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidHoleCounterboredFeatureStubVtbl =
{
    &IID_IStdSolidHoleCounterboredFeature,
    &IStdSolidHoleCounterboredFeature_ServerInfo,
    26,
    &IStdSolidHoleCounterboredFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidHoleCountersunkFeature, ver. 0.0,
   GUID={0x9980B5BE,0x2421,0x46DC,{0x94,0x25,0x84,0x58,0x80,0x82,0xDD,0x28}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidHoleCountersunkFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    8934,
    6402,
    8982,
    6474,
    7668,
    5418,
    8040,
    5490,
    8760,
    5526,
    9018,
    8244
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidHoleCountersunkFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidHoleCountersunkFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidHoleCountersunkFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidHoleCountersunkFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IStdSolidHoleCountersunkFeatureProxyVtbl = 
{
    &IStdSolidHoleCountersunkFeature_ProxyInfo,
    &IID_IStdSolidHoleCountersunkFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::get_TargetFace */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::put_TargetFace */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::get_CenterPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::get_Radius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::put_Radius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::get_Depth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::put_Depth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::get_SinkRadius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::put_SinkRadius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::get_SinkAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::put_SinkAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::get_BottomAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::put_BottomAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleCountersunkFeature::PutCenterPoint */
};


static const PRPC_STUB_FUNCTION IStdSolidHoleCountersunkFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidHoleCountersunkFeatureStubVtbl =
{
    &IID_IStdSolidHoleCountersunkFeature,
    &IStdSolidHoleCountersunkFeature_ServerInfo,
    26,
    &IStdSolidHoleCountersunkFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchCoincidentSamePoints, ver. 0.0,
   GUID={0x16103C6E,0xB6D1,0x4F7C,{0xBD,0xA8,0xE6,0xCF,0x51,0x12,0xAC,0xCD}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchCoincidentSamePoints_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    7524,
    9054,
    7596,
    9090
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchCoincidentSamePoints_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchCoincidentSamePoints_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchCoincidentSamePoints_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchCoincidentSamePoints_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdSketchCoincidentSamePointsProxyVtbl = 
{
    &IStdSketchCoincidentSamePoints_ProxyInfo,
    &IID_IStdSketchCoincidentSamePoints,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCoincidentSamePoints::get_FirstObject */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCoincidentSamePoints::get_FirstType */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCoincidentSamePoints::get_SecondObject */ ,
    (void *) (INT_PTR) -1 /* IStdSketchCoincidentSamePoints::get_SecondType */
};


static const PRPC_STUB_FUNCTION IStdSketchCoincidentSamePoints_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchCoincidentSamePointsStubVtbl =
{
    &IID_IStdSketchCoincidentSamePoints,
    &IStdSketchCoincidentSamePoints_ServerInfo,
    16,
    &IStdSketchCoincidentSamePoints_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchParallel, ver. 0.0,
   GUID={0xABA27711,0x124A,0x47C3,{0xBB,0x88,0x3D,0x27,0x03,0xF8,0x79,0x84}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchParallel_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    7524,
    9126
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchParallel_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchParallel_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchParallel_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchParallel_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStdSketchParallelProxyVtbl = 
{
    &IStdSketchParallel_ProxyInfo,
    &IID_IStdSketchParallel,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchParallel::get_ReferenceEdit */ ,
    (void *) (INT_PTR) -1 /* IStdSketchParallel::get_Target */
};


static const PRPC_STUB_FUNCTION IStdSketchParallel_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchParallelStubVtbl =
{
    &IID_IStdSketchParallel,
    &IStdSketchParallel_ServerInfo,
    14,
    &IStdSketchParallel_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchPerpendicular, ver. 0.0,
   GUID={0xFF3A0BDD,0x1AA5,0x48FA,{0x9F,0x40,0x22,0x8A,0x00,0xC6,0x4A,0x47}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchPerpendicular_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    7524,
    9126
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchPerpendicular_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchPerpendicular_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchPerpendicular_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchPerpendicular_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStdSketchPerpendicularProxyVtbl = 
{
    &IStdSketchPerpendicular_ProxyInfo,
    &IID_IStdSketchPerpendicular,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchPerpendicular::get_ReferenceEdit */ ,
    (void *) (INT_PTR) -1 /* IStdSketchPerpendicular::get_Target */
};


static const PRPC_STUB_FUNCTION IStdSketchPerpendicular_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchPerpendicularStubVtbl =
{
    &IID_IStdSketchPerpendicular,
    &IStdSketchPerpendicular_ServerInfo,
    14,
    &IStdSketchPerpendicular_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchHorizontal, ver. 0.0,
   GUID={0x3C500269,0x634E,0x4018,{0x95,0x98,0x91,0x6C,0x70,0x35,0xCC,0xAA}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchHorizontal_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    7524
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchHorizontal_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchHorizontal_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchHorizontal_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchHorizontal_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IStdSketchHorizontalProxyVtbl = 
{
    &IStdSketchHorizontal_ProxyInfo,
    &IID_IStdSketchHorizontal,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchHorizontal::get_Target */
};


static const PRPC_STUB_FUNCTION IStdSketchHorizontal_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchHorizontalStubVtbl =
{
    &IID_IStdSketchHorizontal,
    &IStdSketchHorizontal_ServerInfo,
    13,
    &IStdSketchHorizontal_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSketchVertical, ver. 0.0,
   GUID={0x07F4BA82,0xAA63,0x4C00,{0xB6,0x40,0x0D,0x00,0x04,0x4F,0xB2,0xDC}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSketchVertical_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    6222,
    7524
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSketchVertical_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchVertical_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSketchVertical_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSketchVertical_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IStdSketchVerticalProxyVtbl = 
{
    &IStdSketchVertical_ProxyInfo,
    &IID_IStdSketchVertical,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdSketchConstraint::get_SketchFeature */ ,
    (void *) (INT_PTR) -1 /* IStdSketchVertical::get_Target */
};


static const PRPC_STUB_FUNCTION IStdSketchVertical_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSketchVerticalStubVtbl =
{
    &IID_IStdSketchVertical,
    &IStdSketchVertical_ServerInfo,
    13,
    &IStdSketchVertical_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdDatumPlaneOffsetFeature, ver. 0.0,
   GUID={0x5A9FB9F5,0x92A5,0x4E46,{0xB5,0xA5,0xD9,0xC1,0x63,0xA1,0xFD,0x8C}} */

#pragma code_seg(".orpc")
static const unsigned short IStdDatumPlaneOffsetFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    4914,
    4950,
    6438,
    8436,
    9162,
    9198,
    9246,
    8076,
    9294,
    9342,
    8196
    };

static const MIDL_STUBLESS_PROXY_INFO IStdDatumPlaneOffsetFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdDatumPlaneOffsetFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdDatumPlaneOffsetFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdDatumPlaneOffsetFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IStdDatumPlaneOffsetFeatureProxyVtbl = 
{
    &IStdDatumPlaneOffsetFeature_ProxyInfo,
    &IID_IStdDatumPlaneOffsetFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::get_SelectedPlane */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::put_SelectedPlane */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::get_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::put_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::get_Distance */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::put_Distance */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::get_IsFree */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::get_Origin */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::get_XDirection */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::get_YDirection */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::PutOrigin */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::PutXDirection */ ,
    (void *) (INT_PTR) -1 /* IStdDatumPlaneOffsetFeature::PutYDirection */
};


static const PRPC_STUB_FUNCTION IStdDatumPlaneOffsetFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdDatumPlaneOffsetFeatureStubVtbl =
{
    &IID_IStdDatumPlaneOffsetFeature,
    &IStdDatumPlaneOffsetFeature_ServerInfo,
    25,
    &IStdDatumPlaneOffsetFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidLoftFacesFeature, ver. 0.0,
   GUID={0xB1A7FE7F,0x54BF,0x4CE5,{0x89,0x47,0x83,0x13,0x58,0xC3,0x8D,0x56}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidLoftFacesFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    6294,
    7596,
    6402
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidLoftFacesFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidLoftFacesFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidLoftFacesFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidLoftFacesFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdSolidLoftFacesFeatureProxyVtbl = 
{
    &IStdSolidLoftFacesFeature_ProxyInfo,
    &IID_IStdSolidLoftFacesFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidLoftFacesFeature::get_Face1 */ ,
    (void *) (INT_PTR) -1 /* IStdSolidLoftFacesFeature::get_Param1 */ ,
    (void *) (INT_PTR) -1 /* IStdSolidLoftFacesFeature::get_Face2 */ ,
    (void *) (INT_PTR) -1 /* IStdSolidLoftFacesFeature::get_Param2 */
};


static const PRPC_STUB_FUNCTION IStdSolidLoftFacesFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidLoftFacesFeatureStubVtbl =
{
    &IID_IStdSolidLoftFacesFeature,
    &IStdSolidLoftFacesFeature_ServerInfo,
    16,
    &IStdSolidLoftFacesFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidLoftSectionsFeature, ver. 0.0,
   GUID={0x09BE8C17,0xDB20,0x4474,{0x8B,0xE9,0xF4,0xD9,0x4E,0x27,0x26,0x1A}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidLoftSectionsFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7848,
    9390
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidLoftSectionsFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidLoftSectionsFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidLoftSectionsFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidLoftSectionsFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStdSolidLoftSectionsFeatureProxyVtbl = 
{
    &IStdSolidLoftSectionsFeature_ProxyInfo,
    &IID_IStdSolidLoftSectionsFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidLoftSectionsFeature::get_References */ ,
    (void *) (INT_PTR) -1 /* IStdSolidLoftSectionsFeature::get_IsCut */
};


static const PRPC_STUB_FUNCTION IStdSolidLoftSectionsFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidLoftSectionsFeatureStubVtbl =
{
    &IID_IStdSolidLoftSectionsFeature,
    &IStdSolidLoftSectionsFeature_ServerInfo,
    14,
    &IStdSolidLoftSectionsFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidCutSweepFeature, ver. 0.0,
   GUID={0xCF090569,0x05D8,0x44A0,{0x86,0x56,0x82,0xBD,0xFE,0x1B,0x79,0xA6}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidCutSweepFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    7596,
    7632
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidCutSweepFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidCutSweepFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidCutSweepFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidCutSweepFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdSolidCutSweepFeatureProxyVtbl = 
{
    &IStdSolidCutSweepFeature_ProxyInfo,
    &IID_IStdSolidCutSweepFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutSweepFeature::get_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutSweepFeature::put_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutSweepFeature::get_GuideCurve */ ,
    (void *) (INT_PTR) -1 /* IStdSolidCutSweepFeature::put_GuideCurve */
};


static const PRPC_STUB_FUNCTION IStdSolidCutSweepFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidCutSweepFeatureStubVtbl =
{
    &IID_IStdSolidCutSweepFeature,
    &IStdSolidCutSweepFeature_ServerInfo,
    16,
    &IStdSolidCutSweepFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidHoleSimpleFeature, ver. 0.0,
   GUID={0xFCCF7496,0x9645,0x4B6D,{0x9C,0x4D,0x06,0x7D,0x3D,0x1D,0x60,0xAF}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidHoleSimpleFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    8934,
    6402,
    8982,
    6474,
    7668,
    9426
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidHoleSimpleFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidHoleSimpleFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidHoleSimpleFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidHoleSimpleFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(20) _IStdSolidHoleSimpleFeatureProxyVtbl = 
{
    &IStdSolidHoleSimpleFeature_ProxyInfo,
    &IID_IStdSolidHoleSimpleFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleSimpleFeature::get_TargetFace */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleSimpleFeature::put_TargetFace */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleSimpleFeature::get_CenterPoint */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleSimpleFeature::get_Radius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleSimpleFeature::put_Radius */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleSimpleFeature::get_Depth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleSimpleFeature::put_Depth */ ,
    (void *) (INT_PTR) -1 /* IStdSolidHoleSimpleFeature::PutCenterPoint */
};


static const PRPC_STUB_FUNCTION IStdSolidHoleSimpleFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidHoleSimpleFeatureStubVtbl =
{
    &IID_IStdSolidHoleSimpleFeature,
    &IStdSolidHoleSimpleFeature_ServerInfo,
    20,
    &IStdSolidHoleSimpleFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidShellFeature, ver. 0.0,
   GUID={0x66548701,0x6ACC,0x4271,{0x98,0xA8,0xD7,0x66,0x69,0x30,0xFF,0x05}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidShellFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7848,
    7884,
    5346,
    5382,
    6438,
    8436
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidShellFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidShellFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidShellFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidShellFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IStdSolidShellFeatureProxyVtbl = 
{
    &IStdSolidShellFeature_ProxyInfo,
    &IID_IStdSolidShellFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidShellFeature::get_TargetFaces */ ,
    (void *) (INT_PTR) -1 /* IStdSolidShellFeature::put_TargetFaces */ ,
    (void *) (INT_PTR) -1 /* IStdSolidShellFeature::get_InnerThickness */ ,
    (void *) (INT_PTR) -1 /* IStdSolidShellFeature::put_InnerThickness */ ,
    (void *) (INT_PTR) -1 /* IStdSolidShellFeature::get_OuterThickness */ ,
    (void *) (INT_PTR) -1 /* IStdSolidShellFeature::put_OuterThickness */
};


static const PRPC_STUB_FUNCTION IStdSolidShellFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidShellFeatureStubVtbl =
{
    &IID_IStdSolidShellFeature,
    &IStdSolidShellFeature_ServerInfo,
    18,
    &IStdSolidShellFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidRevolveWithExternalAxisFeature, ver. 0.0,
   GUID={0xEA1585E2,0x4E46,0x44E1,{0x80,0x8B,0x44,0x32,0xB9,0x89,0x6E,0x2D}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidRevolveWithExternalAxisFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7524,
    7560,
    5346,
    5382,
    4986,
    6474,
    7668,
    7704,
    9474,
    9510,
    2016,
    9546,
    9582,
    8868
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidRevolveWithExternalAxisFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidRevolveWithExternalAxisFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidRevolveWithExternalAxisFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidRevolveWithExternalAxisFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IStdSolidRevolveWithExternalAxisFeatureProxyVtbl = 
{
    &IStdSolidRevolveWithExternalAxisFeature_ProxyInfo,
    &IID_IStdSolidRevolveWithExternalAxisFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::get_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::put_ProfileSketch */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::get_StartAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::put_StartAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::get_StartCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::get_EndAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::put_EndAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::get_EndCondition */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::get_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::put_IsFlip */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::get_IsCut */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::put_IsCut */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::get_RevolveAxis */ ,
    (void *) (INT_PTR) -1 /* IStdSolidRevolveWithExternalAxisFeature::PutRevolveAxis */
};


static const PRPC_STUB_FUNCTION IStdSolidRevolveWithExternalAxisFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidRevolveWithExternalAxisFeatureStubVtbl =
{
    &IID_IStdSolidRevolveWithExternalAxisFeature,
    &IStdSolidRevolveWithExternalAxisFeature_ServerInfo,
    26,
    &IStdSolidRevolveWithExternalAxisFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidDraftFeature, ver. 0.0,
   GUID={0x2AC4B8DA,0xF372,0x4214,{0x89,0xF7,0xAB,0x62,0x31,0xE9,0x46,0x91}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidDraftFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7848,
    7884,
    5346,
    5382,
    9648,
    9714
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidDraftFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidDraftFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidDraftFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidDraftFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IStdSolidDraftFeatureProxyVtbl = 
{
    &IStdSolidDraftFeature_ProxyInfo,
    &IID_IStdSolidDraftFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidDraftFeature::get_TargetFaces */ ,
    (void *) (INT_PTR) -1 /* IStdSolidDraftFeature::put_TargetFaces */ ,
    (void *) (INT_PTR) -1 /* IStdSolidDraftFeature::get_DraftAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidDraftFeature::put_DraftAngle */ ,
    (void *) (INT_PTR) -1 /* IStdSolidDraftFeature::get_PullingDirection */ ,
    (void *) (INT_PTR) -1 /* IStdSolidDraftFeature::PutPullingDirection */
};


static const PRPC_STUB_FUNCTION IStdSolidDraftFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidDraftFeatureStubVtbl =
{
    &IID_IStdSolidDraftFeature,
    &IStdSolidDraftFeature_ServerInfo,
    18,
    &IStdSolidDraftFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidOffsetFeature, ver. 0.0,
   GUID={0xB7A36313,0xCA66,0x4A4B,{0x83,0xBE,0xB7,0x97,0xFB,0x0D,0xE8,0x0A}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidOffsetFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    7848,
    7884,
    5346,
    5382
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidOffsetFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidOffsetFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidOffsetFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidOffsetFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdSolidOffsetFeatureProxyVtbl = 
{
    &IStdSolidOffsetFeature_ProxyInfo,
    &IID_IStdSolidOffsetFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOffsetFeature::get_TargetFaces */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOffsetFeature::put_TargetFaces */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOffsetFeature::get_OffsetThickness */ ,
    (void *) (INT_PTR) -1 /* IStdSolidOffsetFeature::put_OffsetThickness */
};


static const PRPC_STUB_FUNCTION IStdSolidOffsetFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidOffsetFeatureStubVtbl =
{
    &IID_IStdSolidOffsetFeature,
    &IStdSolidOffsetFeature_ServerInfo,
    16,
    &IStdSolidOffsetFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdSolidImportedBrepFeature, ver. 0.0,
   GUID={0x378EBA37,0x1568,0x40E9,{0xBD,0x72,0xEA,0x48,0xED,0x47,0x1E,0xDC}} */

#pragma code_seg(".orpc")
static const unsigned short IStdSolidImportedBrepFeature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4164,
    4200,
    4236,
    618,
    4272,
    9780
    };

static const MIDL_STUBLESS_PROXY_INFO IStdSolidImportedBrepFeature_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidImportedBrepFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdSolidImportedBrepFeature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdSolidImportedBrepFeature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IStdSolidImportedBrepFeatureProxyVtbl = 
{
    &IStdSolidImportedBrepFeature_ProxyInfo,
    &IID_IStdSolidImportedBrepFeature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Application */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFeature::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFeature::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdSolidImportedBrepFeature::get_FilePath */
};


static const PRPC_STUB_FUNCTION IStdSolidImportedBrepFeature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdSolidImportedBrepFeatureStubVtbl =
{
    &IID_IStdSolidImportedBrepFeature,
    &IStdSolidImportedBrepFeature_ServerInfo,
    13,
    &IStdSolidImportedBrepFeature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ISolid, ver. 0.0,
   GUID={0x280DF2D0,0xBE2A,0x448C,{0xBB,0xCE,0x11,0x81,0x46,0x36,0xC4,0xC8}} */

#pragma code_seg(".orpc")
static const unsigned short ISolid_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    9816,
    9852,
    9888
    };

static const MIDL_STUBLESS_PROXY_INFO ISolid_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &ISolid_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISolid_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &ISolid_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _ISolidProxyVtbl = 
{
    &ISolid_ProxyInfo,
    &IID_ISolid,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ISolid::get_Faces */ ,
    (void *) (INT_PTR) -1 /* ISolid::get_Edges */ ,
    (void *) (INT_PTR) -1 /* ISolid::get_Vertices */
};


static const PRPC_STUB_FUNCTION ISolid_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISolidStubVtbl =
{
    &IID_ISolid,
    &ISolid_ServerInfo,
    10,
    &ISolid_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFaces, ver. 0.0,
   GUID={0x3C5C1AB1,0xAFE7,0x43B3,{0x87,0x4B,0xD7,0x6D,0x77,0x90,0x90,0x18}} */

#pragma code_seg(".orpc")
static const unsigned short IFaces_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6546,
    9924,
    9966
    };

static const MIDL_STUBLESS_PROXY_INFO IFaces_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IFaces_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFaces_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IFaces_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IFacesProxyVtbl = 
{
    &IFaces_ProxyInfo,
    &IID_IFaces,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFaces::get_Count */ ,
    (void *) (INT_PTR) -1 /* IFaces::get_Item */ ,
    (void *) (INT_PTR) -1 /* IFaces::get__NewEnum */
};


static const PRPC_STUB_FUNCTION IFaces_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFacesStubVtbl =
{
    &IID_IFaces,
    &IFaces_ServerInfo,
    10,
    &IFaces_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IEdges, ver. 0.0,
   GUID={0x9E0256D6,0x3731,0x41C9,{0x99,0x7B,0x24,0x5F,0xF5,0x62,0xE8,0x29}} */

#pragma code_seg(".orpc")
static const unsigned short IEdges_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6546,
    10002,
    9966
    };

static const MIDL_STUBLESS_PROXY_INFO IEdges_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IEdges_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IEdges_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IEdges_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IEdgesProxyVtbl = 
{
    &IEdges_ProxyInfo,
    &IID_IEdges,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IEdges::get_Count */ ,
    (void *) (INT_PTR) -1 /* IEdges::get_Item */ ,
    (void *) (INT_PTR) -1 /* IEdges::get__NewEnum */
};


static const PRPC_STUB_FUNCTION IEdges_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IEdgesStubVtbl =
{
    &IID_IEdges,
    &IEdges_ServerInfo,
    10,
    &IEdges_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFace, ver. 0.0,
   GUID={0x2439D908,0x0C5B,0x47E0,{0x89,0x0E,0x46,0xC2,0x0B,0x9F,0x18,0x97}} */

#pragma code_seg(".orpc")
static const unsigned short IFace_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6696,
    6732,
    10044,
    10080,
    10116,
    10164,
    10212,
    8934,
    6402
    };

static const MIDL_STUBLESS_PROXY_INFO IFace_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IFace_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFace_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IFace_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IFaceProxyVtbl = 
{
    &IFace_ProxyInfo,
    &IID_IFace,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFace::get_Type */ ,
    (void *) (INT_PTR) -1 /* IFace::get_Name */ ,
    (void *) (INT_PTR) -1 /* IFace::get_Edges */ ,
    (void *) (INT_PTR) -1 /* IFace::get_Vertices */ ,
    (void *) (INT_PTR) -1 /* IFace::get_Centroid */ ,
    (void *) (INT_PTR) -1 /* IFace::get_XDirection */ ,
    (void *) (INT_PTR) -1 /* IFace::get_YDirection */ ,
    (void *) (INT_PTR) -1 /* IFace::get_ZDirection */ ,
    (void *) (INT_PTR) -1 /* IFace::get_Area */
};


static const PRPC_STUB_FUNCTION IFace_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFaceStubVtbl =
{
    &IID_IFace,
    &IFace_ServerInfo,
    16,
    &IFace_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IEdge, ver. 0.0,
   GUID={0xD54BD7B3,0x4AE1,0x4B8E,{0x89,0x25,0xA9,0x2A,0x22,0x3E,0xF6,0x14}} */

#pragma code_seg(".orpc")
static const unsigned short IEdge_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6696,
    6732,
    10260,
    10296
    };

static const MIDL_STUBLESS_PROXY_INFO IEdge_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IEdge_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IEdge_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IEdge_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IEdgeProxyVtbl = 
{
    &IEdge_ProxyInfo,
    &IID_IEdge,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IEdge::get_Type */ ,
    (void *) (INT_PTR) -1 /* IEdge::get_Name */ ,
    (void *) (INT_PTR) -1 /* IEdge::get_StartPoint */ ,
    (void *) (INT_PTR) -1 /* IEdge::get_EndPoint */
};


static const PRPC_STUB_FUNCTION IEdge_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IEdgeStubVtbl =
{
    &IID_IEdge,
    &IEdge_ServerInfo,
    11,
    &IEdge_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IVertices, ver. 0.0,
   GUID={0xAC5C4DC7,0xE3A7,0x4978,{0x97,0xE0,0xE4,0xF2,0xDB,0x12,0x26,0xEF}} */

#pragma code_seg(".orpc")
static const unsigned short IVertices_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6546,
    10332,
    9966
    };

static const MIDL_STUBLESS_PROXY_INFO IVertices_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IVertices_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IVertices_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IVertices_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IVerticesProxyVtbl = 
{
    &IVertices_ProxyInfo,
    &IID_IVertices,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IVertices::get_Count */ ,
    (void *) (INT_PTR) -1 /* IVertices::get_Item */ ,
    (void *) (INT_PTR) -1 /* IVertices::get__NewEnum */
};


static const PRPC_STUB_FUNCTION IVertices_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IVerticesStubVtbl =
{
    &IID_IVertices,
    &IVertices_ServerInfo,
    10,
    &IVertices_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IVertex, ver. 0.0,
   GUID={0x0EA073CC,0x3C4A,0x48EA,{0x97,0x99,0x3C,0x81,0x8D,0x81,0x07,0xA6}} */

#pragma code_seg(".orpc")
static const unsigned short IVertex_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    10374,
    10410,
    10458,
    10494,
    10530
    };

static const MIDL_STUBLESS_PROXY_INFO IVertex_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IVertex_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IVertex_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IVertex_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IVertexProxyVtbl = 
{
    &IVertex_ProxyInfo,
    &IID_IVertex,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IVertex::get_Name */ ,
    (void *) (INT_PTR) -1 /* IVertex::get_Coordinates */ ,
    (void *) (INT_PTR) -1 /* IVertex::get_X */ ,
    (void *) (INT_PTR) -1 /* IVertex::get_Y */ ,
    (void *) (INT_PTR) -1 /* IVertex::get_Z */
};


static const PRPC_STUB_FUNCTION IVertex_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IVertexStubVtbl =
{
    &IID_IVertex,
    &IVertex_ServerInfo,
    12,
    &IVertex_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IPoint3D, ver. 0.0,
   GUID={0x381B3303,0x9EEA,0x482A,{0xA1,0x84,0xF4,0x04,0xC8,0x5A,0xB8,0x7D}} */

#pragma code_seg(".orpc")
static const unsigned short IPoint3D_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    10566,
    10602,
    10458,
    10638,
    10530,
    10674
    };

static const MIDL_STUBLESS_PROXY_INFO IPoint3D_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IPoint3D_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPoint3D_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IPoint3D_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IPoint3DProxyVtbl = 
{
    &IPoint3D_ProxyInfo,
    &IID_IPoint3D,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IPoint3D::get_X */ ,
    (void *) (INT_PTR) -1 /* IPoint3D::put_X */ ,
    (void *) (INT_PTR) -1 /* IPoint3D::get_Y */ ,
    (void *) (INT_PTR) -1 /* IPoint3D::put_Y */ ,
    (void *) (INT_PTR) -1 /* IPoint3D::get_Z */ ,
    (void *) (INT_PTR) -1 /* IPoint3D::put_Z */
};


static const PRPC_STUB_FUNCTION IPoint3D_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IPoint3DStubVtbl =
{
    &IID_IPoint3D,
    &IPoint3D_ServerInfo,
    13,
    &IPoint3D_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAxis1, ver. 0.0,
   GUID={0xF30AD8B9,0x836E,0x4869,{0xB5,0xA2,0xCD,0x76,0x82,0x55,0x57,0x19}} */

#pragma code_seg(".orpc")
static const unsigned short IAxis1_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    10710,
    10746,
    10782,
    10818
    };

static const MIDL_STUBLESS_PROXY_INFO IAxis1_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IAxis1_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAxis1_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IAxis1_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IAxis1ProxyVtbl = 
{
    &IAxis1_ProxyInfo,
    &IID_IAxis1,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IAxis1::get_Location */ ,
    (void *) (INT_PTR) -1 /* IAxis1::put_Location */ ,
    (void *) (INT_PTR) -1 /* IAxis1::get_Direction */ ,
    (void *) (INT_PTR) -1 /* IAxis1::put_Direction */
};


static const PRPC_STUB_FUNCTION IAxis1_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IAxis1StubVtbl =
{
    &IID_IAxis1,
    &IAxis1_ServerInfo,
    11,
    &IAxis1_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAssemDocument, ver. 0.0,
   GUID={0x1EE2B408,0x02CE,0x4E5F,{0xBF,0xFC,0xB7,0x93,0xBA,0xC3,0x22,0xC1}} */

#pragma code_seg(".orpc")
static const unsigned short IAssemDocument_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    282,
    318,
    582,
    618,
    654,
    690,
    726,
    756,
    798,
    828,
    10854,
    900,
    10890
    };

static const MIDL_STUBLESS_PROXY_INFO IAssemDocument_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IAssemDocument_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAssemDocument_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IAssemDocument_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(20) _IAssemDocumentProxyVtbl = 
{
    &IAssemDocument_ProxyInfo,
    &IID_IAssemDocument,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Application */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_FullName */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Name */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Path */ ,
    (void *) (INT_PTR) -1 /* IDoc::get_Saved */ ,
    (void *) (INT_PTR) -1 /* IDoc::Activate */ ,
    (void *) (INT_PTR) -1 /* IDoc::Close */ ,
    (void *) (INT_PTR) -1 /* IDoc::Save */ ,
    (void *) (INT_PTR) -1 /* IDoc::SaveAs */ ,
    (void *) (INT_PTR) -1 /* IAssemDocument::get_Assem */ ,
    (void *) (INT_PTR) -1 /* IAssemDocument::Update */ ,
    (void *) (INT_PTR) -1 /* IAssemDocument::test */
};


static const PRPC_STUB_FUNCTION IAssemDocument_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IAssemDocumentStubVtbl =
{
    &IID_IAssemDocument,
    &IAssemDocument_ServerInfo,
    20,
    &IAssemDocument_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IComp, ver. 0.0,
   GUID={0x47B8D6AB,0x475C,0x4102,{0xAF,0x1A,0x69,0x62,0xA7,0x79,0x6C,0x3A}} */

#pragma code_seg(".orpc")
static const unsigned short IComp_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    10920,
    10956,
    582,
    618,
    10992,
    11034,
    11076,
    11118,
    11160,
    11196,
    7968,
    11232,
    11316,
    11400,
    11442,
    11484,
    11532
    };

static const MIDL_STUBLESS_PROXY_INFO IComp_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IComp_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IComp_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IComp_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _ICompProxyVtbl = 
{
    &IComp_ProxyInfo,
    &IID_IComp,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IComp::set_Name */ ,
    (void *) (INT_PTR) -1 /* IComp::set_ParentName */ ,
    (void *) (INT_PTR) -1 /* IComp::get_Name */ ,
    (void *) (INT_PTR) -1 /* IComp::get_ParentName */ ,
    (void *) (INT_PTR) -1 /* IComp::GetPart */ ,
    (void *) (INT_PTR) -1 /* IComp::GetComponent */ ,
    (void *) (INT_PTR) -1 /* IComp::IsComponent */ ,
    (void *) (INT_PTR) -1 /* IComp::IsPart */ ,
    (void *) (INT_PTR) -1 /* IComp::AddPart */ ,
    (void *) (INT_PTR) -1 /* IComp::AddComponent */ ,
    (void *) (INT_PTR) -1 /* IComp::GetSize */ ,
    (void *) (INT_PTR) -1 /* IComp::GetPlacement */ ,
    (void *) (INT_PTR) -1 /* IComp::SetPlacement */ ,
    (void *) (INT_PTR) -1 /* IComp::SaveAsMesh */ ,
    (void *) (INT_PTR) -1 /* IComp::CreatePart */ ,
    (void *) (INT_PTR) -1 /* IComp::ImportPartFromXML */ ,
    (void *) (INT_PTR) -1 /* IComp::SetPartPlacement */
};


static const PRPC_STUB_FUNCTION IComp_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ICompStubVtbl =
{
    &IID_IComp,
    &IComp_ServerInfo,
    24,
    &IComp_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAssem, ver. 0.0,
   GUID={0xAD55F898,0x5CF6,0x4D13,{0x97,0xDB,0xFE,0xAB,0x11,0x56,0x62,0x6F}} */

#pragma code_seg(".orpc")
static const unsigned short IAssem_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    11622,
    11658,
    11694,
    11730,
    11772,
    9780,
    11808
    };

static const MIDL_STUBLESS_PROXY_INFO IAssem_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IAssem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAssem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IAssem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IAssemProxyVtbl = 
{
    &IAssem_ProxyInfo,
    &IID_IAssem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IAssem::CreatePart */ ,
    (void *) (INT_PTR) -1 /* IAssem::CreateComponent */ ,
    (void *) (INT_PTR) -1 /* IAssem::AddComponent */ ,
    (void *) (INT_PTR) -1 /* IAssem::GetComponent */ ,
    (void *) (INT_PTR) -1 /* IAssem::GetSize */ ,
    (void *) (INT_PTR) -1 /* IAssem::get_Name */ ,
    (void *) (INT_PTR) -1 /* IAssem::get_Constraints */
};


static const PRPC_STUB_FUNCTION IAssem_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IAssemStubVtbl =
{
    &IID_IAssem,
    &IAssem_ServerInfo,
    14,
    &IAssem_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdAssemConstraints, ver. 0.0,
   GUID={0x4AB8ED74,0x3B2F,0x47AB,{0xB0,0x81,0xD6,0x76,0xC2,0xC4,0x5A,0xE8}} */

#pragma code_seg(".orpc")
static const unsigned short IStdAssemConstraints_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6546,
    11844,
    11886,
    11928,
    11994,
    12066,
    12144
    };

static const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraints_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraints_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdAssemConstraints_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraints_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStdAssemConstraintsProxyVtbl = 
{
    &IStdAssemConstraints_ProxyInfo,
    &IID_IStdAssemConstraints,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraints::get_Count */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraints::get_Constraint */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraints::SelectConstraintByName */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraints::AddNewAssemblyCoaxialConstraint */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraints::AddNewAssemblyIncidenceConstraint */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraints::AddNewAssemblyDistance */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraints::AddNewAssemblyAngle */
};


static const PRPC_STUB_FUNCTION IStdAssemConstraints_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdAssemConstraintsStubVtbl =
{
    &IID_IStdAssemConstraints,
    &IStdAssemConstraints_ServerInfo,
    14,
    &IStdAssemConstraints_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdAssemConstraint, ver. 0.0,
   GUID={0x0861DBF0,0x310A,0x4F63,{0xBB,0x23,0xDC,0x9C,0x37,0x34,0x11,0x55}} */

#pragma code_seg(".orpc")
static const unsigned short IStdAssemConstraint_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    4272
    };

static const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraint_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraint_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdAssemConstraint_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraint_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IStdAssemConstraintProxyVtbl = 
{
    &IStdAssemConstraint_ProxyInfo,
    &IID_IStdAssemConstraint,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::SetName */
};


static const PRPC_STUB_FUNCTION IStdAssemConstraint_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdAssemConstraintStubVtbl =
{
    &IID_IStdAssemConstraint,
    &IStdAssemConstraint_ServerInfo,
    12,
    &IStdAssemConstraint_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdAssemConstraintCoaxial, ver. 0.0,
   GUID={0xF5074BA1,0x513A,0x4F33,{0x90,0x91,0xCC,0x8C,0xF5,0x6D,0xAA,0xB1}} */

#pragma code_seg(".orpc")
static const unsigned short IStdAssemConstraintCoaxial_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    4272,
    12216,
    9126,
    12252,
    8400
    };

static const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraintCoaxial_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraintCoaxial_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdAssemConstraintCoaxial_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraintCoaxial_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdAssemConstraintCoaxialProxyVtbl = 
{
    &IStdAssemConstraintCoaxial_ProxyInfo,
    &IID_IStdAssemConstraintCoaxial,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintCoaxial::get_ConstrainedPart */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintCoaxial::get_ConstrainedGeometry */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintCoaxial::get_ReferencePart */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintCoaxial::get_ReferenceGeometry */
};


static const PRPC_STUB_FUNCTION IStdAssemConstraintCoaxial_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdAssemConstraintCoaxialStubVtbl =
{
    &IID_IStdAssemConstraintCoaxial,
    &IStdAssemConstraintCoaxial_ServerInfo,
    16,
    &IStdAssemConstraintCoaxial_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdAssemConstraintIncidence, ver. 0.0,
   GUID={0x449F2C9C,0xFA8E,0x43A1,{0xB3,0x32,0xAF,0xAD,0x30,0x36,0x0C,0x60}} */

#pragma code_seg(".orpc")
static const unsigned short IStdAssemConstraintIncidence_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    4272,
    12288,
    9126,
    12252,
    8400
    };

static const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraintIncidence_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraintIncidence_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdAssemConstraintIncidence_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraintIncidence_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdAssemConstraintIncidenceProxyVtbl = 
{
    &IStdAssemConstraintIncidence_ProxyInfo,
    &IID_IStdAssemConstraintIncidence,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintIncidence::get_ConstrainedPart */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintIncidence::get_ConstrainedGeometry */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintIncidence::get_ReferencePart */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintIncidence::get_ReferenceGeometry */
};


static const PRPC_STUB_FUNCTION IStdAssemConstraintIncidence_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdAssemConstraintIncidenceStubVtbl =
{
    &IID_IStdAssemConstraintIncidence,
    &IStdAssemConstraintIncidence_ServerInfo,
    16,
    &IStdAssemConstraintIncidence_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdAssemConstraintDistance, ver. 0.0,
   GUID={0x2EEDC914,0xDAB8,0x467B,{0x89,0x9F,0xED,0xCC,0x4C,0x2B,0x5D,0x0B}} */

#pragma code_seg(".orpc")
static const unsigned short IStdAssemConstraintDistance_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    4272,
    12288,
    9126,
    12252,
    8400
    };

static const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraintDistance_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraintDistance_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdAssemConstraintDistance_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraintDistance_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdAssemConstraintDistanceProxyVtbl = 
{
    &IStdAssemConstraintDistance_ProxyInfo,
    &IID_IStdAssemConstraintDistance,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintDistance::get_ConstrainedPart */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintDistance::get_ConstrainedGeometry */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintDistance::get_ReferencePart */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintDistance::get_ReferenceGeometry */
};


static const PRPC_STUB_FUNCTION IStdAssemConstraintDistance_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdAssemConstraintDistanceStubVtbl =
{
    &IID_IStdAssemConstraintDistance,
    &IStdAssemConstraintDistance_ServerInfo,
    16,
    &IStdAssemConstraintDistance_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IStdAssemConstraintAngle, ver. 0.0,
   GUID={0x27423066,0x332F,0x4719,{0xB6,0x4B,0xBA,0x65,0x5C,0x36,0xCE,0x47}} */

#pragma code_seg(".orpc")
static const unsigned short IStdAssemConstraintAngle_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6036,
    6072,
    4236,
    618,
    4272,
    12288,
    9126,
    12252,
    8400
    };

static const MIDL_STUBLESS_PROXY_INFO IStdAssemConstraintAngle_ProxyInfo =
    {
    &Object_StubDesc,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraintAngle_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStdAssemConstraintAngle_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    TransCAD__MIDL_ProcFormatString.Format,
    &IStdAssemConstraintAngle_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IStdAssemConstraintAngleProxyVtbl = 
{
    &IStdAssemConstraintAngle_ProxyInfo,
    &IID_IStdAssemConstraintAngle,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Application */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Parent */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Type */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::get_Name */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraint::SetName */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintAngle::get_ConstrainedPart */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintAngle::get_ConstrainedGeometry */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintAngle::get_ReferencePart */ ,
    (void *) (INT_PTR) -1 /* IStdAssemConstraintAngle::get_ReferenceGeometry */
};


static const PRPC_STUB_FUNCTION IStdAssemConstraintAngle_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IStdAssemConstraintAngleStubVtbl =
{
    &IID_IStdAssemConstraintAngle,
    &IStdAssemConstraintAngle_ServerInfo,
    16,
    &IStdAssemConstraintAngle_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    TransCAD__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _TransCAD_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IStdSolidShellFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchOriginProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPoint3DProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IExplicitModelObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAssemDocumentProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFaceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchCenterlineProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchParallelProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidOffsetFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdAssemConstraintDistanceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidLoftSectionsFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidChamferFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidHoleCounterboredFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidImportedBrepFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidCutRevolveFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchHDirectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdAssemConstraintAngleProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchConstraintsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchHorizontalProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidCutSweepFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchVDirectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchCoincidentSamePointsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidOperatePatternCircularFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdAssemConstraintsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidLoftFacesFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchConstraintProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchVerticalProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchGeometriesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFeaturesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidProtrusionSweepFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidHoleSimpleFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAssemProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdAssemConstraintIncidenceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchCircularArcProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdAssemConstraintCoaxialProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidProtrusionExtrudeFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdDefaultDatumPlaneFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISketchProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICompProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidCutExtrudeFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFacesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDocProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEdgeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IApplicationProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAxis1ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchGeometryProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidHoleCountersunkFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPartDocumentProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IVerticesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IReferencesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IVertexProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPartProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISolidProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidProtrusionRevolveFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEdgesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IReferenceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDocsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidDraftFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchPerpendicularProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchCircleProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidRevolveWithExternalAxisFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISketchEditorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchLineProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdAssemConstraintProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdDatumPlaneOffsetFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchControlPointProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidFilletConstantFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSketchFeatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStdSolidOperatePatternRectangularFeatureProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _TransCAD_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IStdSolidShellFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchOriginStubVtbl,
    ( CInterfaceStubVtbl *) &_IPoint3DStubVtbl,
    ( CInterfaceStubVtbl *) &_IExplicitModelObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IAssemDocumentStubVtbl,
    ( CInterfaceStubVtbl *) &_IFaceStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchCenterlineStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchParallelStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidOffsetFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdAssemConstraintDistanceStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidLoftSectionsFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidChamferFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidHoleCounterboredFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidImportedBrepFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidCutRevolveFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchHDirectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdAssemConstraintAngleStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchConstraintsStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchHorizontalStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidCutSweepFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchVDirectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchCoincidentSamePointsStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidOperatePatternCircularFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdAssemConstraintsStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidLoftFacesFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchConstraintStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchVerticalStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchGeometriesStubVtbl,
    ( CInterfaceStubVtbl *) &_IFeaturesStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidProtrusionSweepFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidHoleSimpleFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IAssemStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdAssemConstraintIncidenceStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchCircularArcStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdAssemConstraintCoaxialStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidProtrusionExtrudeFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdDefaultDatumPlaneFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_ISketchStubVtbl,
    ( CInterfaceStubVtbl *) &_ICompStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidCutExtrudeFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IFacesStubVtbl,
    ( CInterfaceStubVtbl *) &_IDocStubVtbl,
    ( CInterfaceStubVtbl *) &_IEdgeStubVtbl,
    ( CInterfaceStubVtbl *) &_IApplicationStubVtbl,
    ( CInterfaceStubVtbl *) &_IAxis1StubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchGeometryStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidHoleCountersunkFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IPartDocumentStubVtbl,
    ( CInterfaceStubVtbl *) &_IVerticesStubVtbl,
    ( CInterfaceStubVtbl *) &_IReferencesStubVtbl,
    ( CInterfaceStubVtbl *) &_IVertexStubVtbl,
    ( CInterfaceStubVtbl *) &_IPartStubVtbl,
    ( CInterfaceStubVtbl *) &_ISolidStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidProtrusionRevolveFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IEdgesStubVtbl,
    ( CInterfaceStubVtbl *) &_IReferenceStubVtbl,
    ( CInterfaceStubVtbl *) &_IDocsStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidDraftFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchPerpendicularStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchCircleStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidRevolveWithExternalAxisFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_ISketchEditorStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchLineStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdAssemConstraintStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdDatumPlaneOffsetFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchControlPointStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidFilletConstantFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSketchFeatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IStdSolidOperatePatternRectangularFeatureStubVtbl,
    0
};

PCInterfaceName const _TransCAD_InterfaceNamesList[] = 
{
    "IStdSolidShellFeature",
    "IStdSketchOrigin",
    "IPoint3D",
    "IExplicitModelObject",
    "IAssemDocument",
    "IFace",
    "IStdSketchCenterline",
    "IStdSketchParallel",
    "IStdSolidOffsetFeature",
    "IStdAssemConstraintDistance",
    "IStdSolidLoftSectionsFeature",
    "IStdSolidChamferFeature",
    "IStdSolidHoleCounterboredFeature",
    "IStdSolidImportedBrepFeature",
    "IFeature",
    "IStdSolidCutRevolveFeature",
    "IStdSketchHDirection",
    "IStdAssemConstraintAngle",
    "IStdSketchConstraints",
    "IStdSketchHorizontal",
    "IStdSolidCutSweepFeature",
    "IStdSketchVDirection",
    "IStdSketchCoincidentSamePoints",
    "IStdSolidOperatePatternCircularFeature",
    "IStdAssemConstraints",
    "IStdSolidLoftFacesFeature",
    "IStdSketchConstraint",
    "IStdSketchVertical",
    "IStdSketchGeometries",
    "IFeatures",
    "IStdSolidProtrusionSweepFeature",
    "IStdSolidHoleSimpleFeature",
    "IAssem",
    "IStdAssemConstraintIncidence",
    "IStdSketchCircularArc",
    "IStdAssemConstraintCoaxial",
    "IStdSolidProtrusionExtrudeFeature",
    "IStdDefaultDatumPlaneFeature",
    "ISketch",
    "IComp",
    "IStdSolidCutExtrudeFeature",
    "IFaces",
    "IDoc",
    "IEdge",
    "IApplication",
    "IAxis1",
    "IStdSketchGeometry",
    "IStdSolidHoleCountersunkFeature",
    "IPartDocument",
    "IVertices",
    "IReferences",
    "IVertex",
    "IPart",
    "ISolid",
    "IStdSolidProtrusionRevolveFeature",
    "IEdges",
    "IReference",
    "IDocs",
    "IStdSolidDraftFeature",
    "IStdSketchPerpendicular",
    "IStdSketchCircle",
    "IStdSolidRevolveWithExternalAxisFeature",
    "ISketchEditor",
    "IStdSketchLine",
    "IStdAssemConstraint",
    "IStdDatumPlaneOffsetFeature",
    "IStdSketchControlPoint",
    "IStdSolidFilletConstantFeature",
    "IStdSketchFeature",
    "IStdSolidOperatePatternRectangularFeature",
    0
};

const IID *  const _TransCAD_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _TransCAD_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _TransCAD, pIID, n)

int __stdcall _TransCAD_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _TransCAD, 70, 64 )
    IID_BS_LOOKUP_NEXT_TEST( _TransCAD, 32 )
    IID_BS_LOOKUP_NEXT_TEST( _TransCAD, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _TransCAD, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _TransCAD, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _TransCAD, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _TransCAD, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _TransCAD, 70, *pIndex )
    
}

const ExtendedProxyFileInfo TransCAD_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _TransCAD_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _TransCAD_StubVtblList,
    (const PCInterfaceName * ) & _TransCAD_InterfaceNamesList,
    (const IID ** ) & _TransCAD_BaseIIDList,
    & _TransCAD_IID_Lookup, 
    70,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

