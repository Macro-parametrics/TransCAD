#pragma once

#include ".\PmeObject.h"
#include ".\PmeStdAssemblyConstraintType.h"

class PmeAssembly;
class PmePart;
class PmeReference;

class PmeStdAssemblyConstraint
	: public PmeObject
{
	PME_DECLARE_RUNTIME_TYPE( PmeStdAssemblyConstraint )

public:
	PmeStdAssemblyConstraint( PmeAssembly * pAssembly );
	PmeStdAssemblyConstraint( PmeAssembly * pAssembly, const CString & name );
	virtual ~PmeStdAssemblyConstraint(void);
	
	virtual PmeStdAssemblyConstraintType GetType(void) const = 0;

	CString GetName(void) const { return m_name; }
	PmeAssembly * GetAssembly(void) const { return m_pAssembly;} 

	void SetName( const CString & name );
	void GiveDefaultName(void);

	virtual void UpdateConstraint(void) = 0;

	MrAxis2 GetTransformedCSYS(void) { return m_transfCSYS; }


	MrMatrix GetRotationMatrix( MrVector v1, MrVector v2 );
	MrMatrix GetRotationMatrix( MrVector v1, MrVector v2, double angle );
	MrAxis2 RotateCoordinate( MrMatrix rotationMatrix, MrAxis2 coordinate );
	MrVector Translation( MrVector v1, MrVector v2 );
	MrVector Translation( MrVector v1, double d );

	bool IsPlanarFace( FACE * pFace );
	bool IsLinearEdge( EDGE * pEdge );
	bool IsOutside( MrAxis2 coAxis, MrAxis2 refAxis );

	void ApplyParallel(PmePart * pPart, MrVector v1, MrVector v2);

	MrAxis2 SetTranslationResult(MrAxis2 partCSYS, MrVector t);
	void SetTransformedCSYS(MrAxis2 transfCSYS) { m_transfCSYS = transfCSYS; }

private:
	bool CheckName(const CString & name) const;

private:
	CString m_name;
	PmeAssembly * m_pAssembly;
	MrAxis2 m_transfCSYS;
};