#pragma once

#include <map>
#include ".\PmeObject.h"
#include ".\PmeBaseList.h"

class PmeExplicitModelObject;
class PmeSolid;

class PmeExplicitModel
	: public PmeObject
	, public PmeBaseList<PmeExplicitModelObject *>
{	
	typedef PmeBaseList<PmeExplicitModelObject *> BaseList;
	typedef std::map<PmeExplicitModelObject *, bool> UpdateMap;

	PME_DECLARE_RUNTIME_TYPE(PmeExplicitModel)
public:
	PmeExplicitModel(void);
	virtual ~PmeExplicitModel(void);

    void Add(PmeExplicitModelObject * item);
	void Update(PmeExplicitModelObject * item);
	PmeExplicitModelObject * FindByName(const CString & name) const;
	void Clear(void);
	void Delete(SizeType index);

	bool IsUpdated(PmeExplicitModelObject * item) const;

	void SetSolid(PmeSolid * pItem);
	PmeSolid * GetSolid(void) const;
private:
	UpdateMap m_updateFlags;
	PmeSolid * m_pSolid;
};
