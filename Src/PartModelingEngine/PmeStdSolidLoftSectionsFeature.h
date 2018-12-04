#pragma once
#include "pmestdsolidfeature.h"
#include ".\PmeReferences.h"
#include ".\PmeBrepType.h"
#include ".\PmeBrepReferenceAPI.h"
#include ".\PmeExplicitModelAPI.h"
#include ".\PmeExplicitModelObjectAPI.h"
#include ".\PmeExplicitModelObjectsAPI.h"
#include "IPmePattern.h"

class PmePart;
class PmeReference;
class PmeReferences;

class PmeStdSolidLoftSectionsFeature :
	public PmeStdSolidFeature,
	public IPmePattern
 {
 	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidLoftSectionsFeature)
 public:
	PmeStdSolidLoftSectionsFeature(PmePart * pPart);
	 
	PmeStdSolidLoftSectionsFeature(PmePart * pPart, 
								PmeReferences * pSections,
								bool isCut);


	virtual ~PmeStdSolidLoftSectionsFeature(void);

	PmeReferences * GetLoftSections(void) const {return m_pSections;}
	bool IsCut(void) const {return m_isCut;}

	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidLoftSectionsFeature;}
	virtual void Update(void);	
	
	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

 protected:
	void CreateSolidBody(BODY *& pBody);

 	void AttachName(BODY *& pBody);
	void GetEdgeNameFromSketchReference(FACE *& pSourceFace, PmeReference *& pSketchReference, CString & edgeName);
	bool IsEdgesSame(EDGE * pEdge1, EDGE * pEdge2);
	bool IsEdgesIncluded(EDGE * pEdge1, EDGE * pEdge2);

	//EDGE * CreateTransformedEdge(EDGE *& pEdge, MrAxis2 & coordinateSystem);

	PmeReference * GetStartSketch(void) const {return m_pStartSketch;}
	PmeReference * GetEndSketch(void) const {return m_pEndSketch;}
	

 private:
	PmeReferences * m_pSections;
	PmeReference * m_pStartSketch;
	PmeReference * m_pEndSketch;
	bool m_isCut;
};