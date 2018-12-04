#pragma once
#include "pmestdsolidfeature.h"

class PmeReference;
 
class PmeStdSolidLoftFacesFeature :
	public PmeStdSolidFeature
 {
 	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidLoftFacesFeature)
 public:
	 PmeStdSolidLoftFacesFeature(PmePart * pPart);
	 
	 PmeStdSolidLoftFacesFeature(PmePart * pPart,
		 PmeReference * pFace1,
		 double param1,
		 PmeReference * pFace2,
		 double param2);

	 virtual ~PmeStdSolidLoftFacesFeature(void);

	 PmeReference * GetFace1(void) const {return m_Face1;}
	 PmeReference * GetFace2(void) const {return m_Face2;}
	 double GetParam1(void) const {return m_param1;}
	 double GetParam2(void) const {return m_param2;}
	 virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidLoftFacesFeature;}
	 virtual void Update(void);	

 protected:
	 BODY * LoftSolid(FACE *& pFace_1, FACE *& pFace_2);

// 	 void AttachName(BODY *& pBody);
// 	 void AttachVertexName_pointbased(BODY *& pBody);
// 	 void AttachFaceName_pointbased(BODY *& pBody);

 private:
	 PmeReference * m_Face1;
	 PmeReference * m_Face2;
	 double m_param1;
	 double m_param2;
};