#include <CtrlLib/CtrlLib.h>
#include "drink.h"

using namespace Upp;

struct MyAppWindow : public TopWindow
{
	Switch base;
	Label baseLbl;
	Switch size;
	Label sizeLbl;
	Switch temp;
	Label tempLbl;
	
	MyAppWindow()
	{
		Open();
		Rect active = GetVisibleScreenView();	
		const int LBLSIZE  = 120;
		const int CTRLWIDTH = 200;
		const int RADIOHEIGHT  = 40;
		const int MARGIN = 12;
		int w = active.GetWidth();
		int h = active.GetHeight();
		Title("Drink Order").Zoomable().Sizeable();
		baseLbl.SetLabel("Drink Base:");
		Add(baseLbl.HSizePosZ(MARGIN).TopPosZ(MARGIN));
		Add(base.HSizePosZ(LBLSIZE).VSizePosZ(MARGIN));
		base.Add(COFFEE,"Coffee");
		base.Add(TEA, "Tea");
		base.Add(CREAM, "Cream");
		base.SetVertical();
	};
		
};

GUI_APP_MAIN
{
	MyAppWindow app;
	app.Run();
}
