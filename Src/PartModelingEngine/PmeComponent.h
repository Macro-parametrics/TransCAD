#pragma once

#include <vector>
#include ".\PmeObject.h"
#include ".\PmeAssemblyComponentType.h"

class PmePart;

class PmeComponent
	: public PmeObject
{
	typedef std::vector <PmeObject*> Components;

	PME_DECLARE_RUNTIME_TYPE(PmeComponent)

public:
	PmeComponent( PmePart* pPart );
	PmeComponent( void );
	virtual ~PmeComponent( void );
	
	// Add functions
	void AddComponent( PmeComponent * pComp );
	void AddPart( PmePart * pPart );

	// Get functions
	int GetSize( void );
	int GetComponentsSize( void );
	int GetPartsSize( void );
	
	PmeObject* GetItem( int i ) { return m_components[ i ]; }
	PmeComponent* GetComponent( int i );
	PmePart * GetPart( int i );
	PmePart * GetPart( void ) const { return m_pPart; }

	CString GetName(void) const { return m_name; }
	CString GetParentName() const { return m_parent_name; }
	PmeObject* GetParent() const { return m_pParent; }
	PmeAssemblyComponentType GetCompType() const { return m_compType; }

	MrAxis2 GetPlacement( void ) const { return m_placement; }
	MrTransformation GetMatrix() const { return m_matrix; }

	// Set functions
	void SetPart( PmePart * pPart ) { m_pPart = pPart; }

	void SetName( CString name ) { m_name = name; }
	void SetParentName( CString val ) { m_parent_name = val; }
	void SetParent( PmeObject* val ) { m_pParent = val; }
	void SetCompType( PmeAssemblyComponentType val ) { m_compType = val; }

	void SetPlacement(const MrAxis2 & placement) {m_placement = placement;}
	void SetMatrix( MrTransformation val ) { m_matrix = val; }
	
	void UpdateAllFaceNames( PmePart * pPart );
	void UpdateAll();
	void Clear();
	
	BOOL IsUpdated() const { return isUpdated; }
	void IsUpdated( BOOL val ) { isUpdated = val; }

private:
	Components m_components;	// contains components or parts
	PmeObject* m_pParent;
	PmePart * m_pPart;

	CString m_name;
	CString m_parent_name;

	PmeAssemblyComponentType m_compType;
		
	MrTransformation m_matrix;
	MrAxis2 m_placement;
	
	BOOL isUpdated;
};
