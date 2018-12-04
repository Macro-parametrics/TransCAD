#pragma once

class SPAtransf;

struct IPmeTransformable
{
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody) = 0;
};