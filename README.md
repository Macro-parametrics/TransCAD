# TransCAD
![TransCAD](./img/TransCAD.png)

TransCAD is a 3D CAD model translator with MPA(Macro parametrics approach) between commercial CAD systems.

MPA is a methodology of exchange of model data between CAD systems using macro file, wich is modeling commands set of each commercial CAD system.

* [MPA homepage](http://macro-parametrics.org/)
* [TransCAD Git repository](https://github.com/Macro-parametrics/TransCAD)

# Compiling
Development Environment
>OS: Windows  
>Compilier: Visual Studio 2010  
>Language: C++  

Compiling TransCAD requires ACIS and HOOPS of SPATIAL.
ACIS and HOOPS are a commercial library. However, if you are students or educators in university, you can use ACIS and HOOPS freely.

In this section, we assume that you already have ACIS and HOOPS license.
To compile TransCAD, you should use specific version of ACIS and HOOPS.
* ACIS : version R25
* HOOPS : version 1919

Step 1.  
Download ACIS and HOOPS library and extract them

Step 2.  
Add environment variables
1. ACIS  
Variable name: A3DT  
Variable location: yourPath\acisR25

2. HOOPS  
Variable name: HOOPS_INSTALL_DIR  
Variable location: yourPath\HOOPS-1919_VS_2010

Step 3.  
Add variable locations to Path  
1. ACIS  
>%A3DT%\NT_VC_DLL\code\bin  
>%A3DT%\NT_VC12_DLLD\code\bin

2. HOOPS  
>%HOOPS_INSTALL_DIR%\bin\nt_i386_vc12  
>%HOOPS_INSTALL_DIR%\bin\nt_i386_vc12d

Step 4.
1. Make a "RegBin" folder
2. [Download](https://drive.google.com/drive/folders/1iva5vPoeQD-UxPmxVsCZVrgDkP8xZQOv?usp=sharing) additional files and paste those file into RegBin folder
3. Copy files and paste into RegBin folder

< Hoops files >
- base_stream.dll
- hoops_mfcu1919_vc10.dll
- hoops_mfcu1919_vc10d.dll
- hoops_mvo1919_vc10.dll
- hoops_mvo1919_vc10d.dll
- hoops_stream1919_vc10.dll
- hoops_stream1919_vc10d.dll
- hoops1919_vc10.dll
- hoops1919_vc10d.dll

< ACIS files >
- SpaACIS.dll
- SpaACISd.dll
- SPAAcisDs.dll
- SpaHBridge.dll
- SpaHBridged.dll
- SPAIAcis.dll
- SPAIInterop.dll
- SPAIInteropC.dll
- SPAIop.dll
- SPAIopAcisC.dll
- SPAIopC.dll
- SPAXAcis.dll
- SPAXAcisBase.dll
- SPAXAcisKernel.dll
- SPAXAcisMeshDS.dll
- SPAXAssemblyRep.dll
- SPAXBase.dll
- SPAXBoundaryRep.dll
- SPAXCommon.dll
- SPAXGeometryRepresentation.dll
- SPAXicuuc38.dll
- SPAXIges.dll
- SPAXInterop.dll
- SPAXIop.dll
- SPAXIopAcis.dll
- SPAXPMIRep.dll
- SPAXStep.dll
- SPAXVisualizationAsm.dll
- SPAXVisualizationRep.dll


Extract to TransCAD source code folder  
The folder structure is shown below.  
>TransCAD
>>-RegBin  
>>-Src  
>>-TransCAD.sln  

Step 5.
Building TransCAD
