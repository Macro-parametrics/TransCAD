#include "stdafx.h"
#include "AssemSettings.h"

AssemSettings::AssemSettings()
{
	Initialize();  
}

CString AssemSettings::GetValue(const CString & key) const
{
	Entries::const_iterator i = _entries.find(key);
	if(i != _entries.end())
		return i->second.value;
	else
		return CString();
}

void AssemSettings::SetValue(const CString & key, const CString & value)
{
	CString oldValue = GetValue(key);
	if(oldValue.IsEmpty())
		return;

	_entries[key].value = value;
}

CString AssemSettings::GetStringValue(const CString & key) const
{
	return GetValue(key);
}

void AssemSettings::SetStringValue(const CString & key, const CString & value)
{
	SetValue(key, value);
}

int AssemSettings::GetIntValue(const CString & key) const
{
	CString value = GetValue(key);
	return atoi(value);
}

void AssemSettings::SetIntValue(const CString & key, int value)
{
	char buffer[256];

	_itoa(value, buffer, 10);
	SetValue(key, buffer);
}

long AssemSettings::GetLongValue(const CString & key) const
{
	CString value = GetValue(key);
	return atol(value);
}

void AssemSettings::SetLongValue(const CString & key, long value)
{
	char buffer[256];

	_ltoa(value, buffer, 10);
	SetValue(key, buffer);
}

bool AssemSettings::GetBoolValue(const CString & key) const
{
	CString value = GetValue(key);
	return (value.MakeUpper() == "TRUE") ? true : false;
}

void AssemSettings::SetBoolValue(const CString & key, bool value)
{
	if(value)
        SetValue(key, "TRUE");
	else
		SetValue(key, "FALSE");
}

double AssemSettings::GetDoubleValue(const CString & key) const
{
	CString value = GetValue(key);
	return atof(value);
}

void AssemSettings::SetDoubleValue(const CString & key, double defaultValue)
{
	char buffer[256];

	_gcvt(defaultValue, 12, buffer);
	SetValue(key, buffer);
}

void AssemSettings::InsertNewValue(const CString & key, const CString & defaultValue)
{
	CString oldValue = GetValue(key);
	if(!oldValue.IsEmpty())
		return;

	SettingPair pair;
	pair.defaultValue = defaultValue;
	pair.value = defaultValue;

	_entries[key] = pair;
}

void AssemSettings::InsertNewValue(const CString & key, bool defaultValue)
{
	CString v = (defaultValue) ? "TRUE" : "FALSE";
	InsertNewValue(key, v);
}

void AssemSettings::InsertNewValue(const CString & key, int defaultValue)
{
	char buffer[256];

	_itoa(defaultValue, buffer, 10);

	InsertNewValue(key, CString(buffer));
}

void AssemSettings::InsertNewValue(const CString & key, long defaultValue)
{
	char buffer[256];

	_ltoa(defaultValue, buffer, 10);

	InsertNewValue(key, CString(buffer));
}

void AssemSettings::InsertNewValue(const CString & key, double defaultValue)
{
	char buffer[256];

	_gcvt(defaultValue, 12, buffer);

	InsertNewValue(key, CString(buffer));
}

void AssemSettings::Initialize()
{
	InsertNewValue("AntiAliasing", true);
	InsertNewValue("DisplayList", true);
	InsertNewValue("VisualSelection", false);
	InsertNewValue("OcclusionCulling", false);
	InsertNewValue("Spriting", true);
	InsertNewValue("InteractiveShadows", true);
	InsertNewValue("BackplaneCulling", false);
	InsertNewValue("ShadowRenderingMode", SoftwareShadow);
	InsertNewValue("AxisTriad", true);
	InsertNewValue("SmoothTransition", true);
	InsertNewValue("SmoothTransitionDuration", 1.2);
	InsertNewValue("ProjectionMode", ProjOrthographic);
	InsertNewValue("TimerBasedUpdate", true);
	
	InsertNewValue("BackgroundTopColor", (long)RGB(0.3000 * 255, 0.601961 * 255, 0.601961 * 255));
	InsertNewValue("BackgroundBottomColor", (long)RGB(1.000 * 255, 0.984314 * 255, 0.971176 * 255));

	InsertNewValue("SelectionColorTransparency", 0.0);
	InsertNewValue("PolygonSelectionColor", (long)RGB(255, 0, 0));
	InsertNewValue("LineSelectionColor", (long)RGB(255, 0, 0));
	InsertNewValue("MarkerSelectionColor", (long)RGB(255, 0, 0));

	InsertNewValue("MarkupColor", (long)RGB(255, 0, 0));
	InsertNewValue("MarkupWeight", 400);
	InsertNewValue("ShadowColor", (long)RGB(45, 45, 45));
	InsertNewValue("ShadowResolution", 64);
	InsertNewValue("ShadowBlur", 4);
	InsertNewValue("ShadowMode", HShadowSoft);
	
	InsertNewValue("RenderMode", HRenderGouraud);
}