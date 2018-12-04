
TransCADps.dll: dlldata.obj TransCAD_p.obj TransCAD_i.obj
	link /dll /out:TransCADps.dll /def:TransCADps.def /entry:DllMain dlldata.obj TransCAD_p.obj TransCAD_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0500 /DREGISTER_PROXY_DLL \
		$<
# _WIN32_WINNT=0x0500 is for Win2000, change it to 0x0400 for NT4 or Win95 with DCOM

clean:
	@del TransCADps.dll
	@del TransCADps.lib
	@del TransCADps.exp
	@del dlldata.obj
	@del TransCAD_p.obj
	@del TransCAD_i.obj
