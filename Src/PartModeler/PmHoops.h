#pragma once

#ifdef _DEBUG
#pragma comment(lib, "hoopsd.lib")
#pragma comment(lib, "hoops_streamd.lib")
#pragma comment(lib, "hoops_mvod.lib")
//#pragma comment(lib, "hoops_utilsstatd_md.lib")
#pragma comment(lib, "hoops_mfcud.lib")

#else
#pragma comment(lib, "hoops.lib")
#pragma comment(lib, "hoops_stream.lib")
#pragma comment(lib, "hoops_mvo.lib")
//#pragma comment(lib, "hoops_utilsstat_md.lib")
#pragma comment(lib, "hoops_mfcu.lib")

#endif

#include <CHoopsApp.h>
#include <HDB.h>
#include <CTDriver.h>
#include <CHoopsFrm.h>
#include <CHoopsDoc.h>
#include <HBaseModel.h>
#include <HTools.h>
#include <HBaseView.h>
#include <HUtility.h>
#include <HSelectionSet.h>
#include <CHoopsView.h>
#include <HBaseOperator.h>
#include <HOpCameraOrbit.h>
#include <HMarkupManager.h>
#include <HImUtility.h>
#include <HImManager.h>
#include <HIC.h>
#include <HOpSelectAperture.h>