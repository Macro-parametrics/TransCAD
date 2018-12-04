#pragma once

#include <map>
#include ".\PmeObject.h"
#include ".\PmeBaseList.h"

class PmeFeature;

class PmeFeatures
	: public PmeObject
	, public PmeBaseList<PmeFeature *>
{
	typedef PmeBaseList<PmeFeature *> BaseList;
	typedef std::map<PmeFeature *, bool> UpdateMap;

	PME_DECLARE_RUNTIME_TYPE(PmeFeatures)
public:
	PmeFeatures(void);
	virtual ~PmeFeatures(void);

	void Add(PmeFeature * item);
	void Update(PmeFeature * item);
	PmeFeature * FindByName(const CString & name) const;

	bool IsUpdated(PmeFeature * item) const;
	void MustUpdate(PmeFeature * item);

private:
	UpdateMap m_updateFlags;
};
