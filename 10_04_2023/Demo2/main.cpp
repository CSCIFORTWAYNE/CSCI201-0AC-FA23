#include <CtrlLib/CtrlLib.h>

using namespace Upp;

GUI_APP_MAIN
{
	TopWindow w;
	Rect r = w.GetWorkArea();
	w.Title("Hello World 2").Zoomable().Sizeable();
	w.SetRect(0,0,r.GetWidth() * .5, r.GetHeight()*.5);
	w.Run();
}
