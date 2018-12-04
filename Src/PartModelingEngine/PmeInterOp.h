#pragma once

#ifdef _DEBUG
#pragma comment(lib, "SPAIInteropd.lib")
#pragma comment(lib, "SPAIAcisd.lib")
#pragma comment(lib, "SpaACISd.lib")
// #pragma comment(lib, "SPAXBased.lib")
// #pragma comment(lib, "SPAXInteropd.lib")
// #pragma comment(lib, "SPAXAcisBased.lib")
// #pragma comment(lib, "SpaACISd.lib")
// #pragma comment(lib, "SPADefeatured.lib")
#else
#pragma comment(lib, "SPAIInterop.lib")
#pragma comment(lib, "SPAIAcis.lib")
#pragma comment(lib, "SpaACIS.lib")
// #pragma comment(lib, "SPAXBase.lib")
// #pragma comment(lib, "SPAXInterop.lib")
// #pragma comment(lib, "SPAXAcisBase.lib")
// #pragma comment(lib, "SpaACIS.lib")
// #pragma comment(lib, "SPADefeature.lib")
#endif


#include <SPAIAcisDocument.h>
#include <SPAIConverter.h>
#include <SPAIDocument.h>
#include <SPAIFile.h>