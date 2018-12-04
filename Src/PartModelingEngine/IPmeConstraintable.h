#pragma once

class PmeStdSketchEditor;

struct IPmeConstraintable
{
	virtual void SetGNode(g_node * pGNode) = 0;
	virtual g_node * GetGNode(void) const = 0;
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor) = 0;
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor) = 0;
};
