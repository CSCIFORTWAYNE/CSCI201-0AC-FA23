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
	DropList dairy;
	Label dairyLbl;
	Option flavor[10];
	Label flavorLbl;
	EditString price;
	Label priceLbl;
	Button createDrink;
	
	
	
	MyAppWindow()
	{
		Open();
		Rect active = GetVisibleScreenView();	
		const int LBLSIZE  = 120;
		const int CTRLWIDTH = 200;
		const int RADIOHEIGHT  = 40;
		const int MARGIN = 12;
		int numItems = 1;
		
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
		
		sizeLbl.SetLabel("Drink Size:");
		Add(sizeLbl.HSizePosZ(MARGIN).TopPosZ(RADIOHEIGHT*numItems + MARGIN*(numItems + 1)));
		
		size.Add(SMALL, "Small");
		size.Add(MED, "Medium");
		size.Add(LARGE, "Large");
		size.SetVertical();
		Add(size.HSizePosZ(LBLSIZE).VSizePosZ(RADIOHEIGHT*numItems + MARGIN*(numItems + 1)));
		
		numItems++;
		
		tempLbl.SetLabel("Drink Temperature:");
		Add(tempLbl.HSizePosZ(MARGIN).TopPosZ(RADIOHEIGHT*numItems + MARGIN*(numItems + 1)));
		
		temp.Add(HOT, "Hot");
		temp.Add(ICE,"Iced");
		temp.Add(BLEND,"Blended");
		temp.SetVertical();
		Add(temp.HSizePosZ(LBLSIZE).VSizePosZ(RADIOHEIGHT * numItems + MARGIN*(numItems + 1)));
		
		numItems++;
		
		dairyLbl.SetLabel("Dairy Choice:");
		Add(dairyLbl.HSizePosZ(MARGIN).TopPosZ(RADIOHEIGHT * numItems + MARGIN*(numItems + 1)));
		dairy.Add("None");
		dairy.Add("Skim Milk");
		dairy.Add("Whole Milk");
		dairy.Add("Oat Milk");
		dairy.Add("Cream");
		dairy.Add("Almond Milk");
		Add(dairy.LeftPosZ(LBLSIZE, CTRLWIDTH).TopPosZ(RADIOHEIGHT * numItems + MARGIN*(numItems + 1)));
		
		flavorLbl.SetLabel("Flavors:");
		Rect dairySize = dairy.GetView();
		int vertPos = RADIOHEIGHT * numItems + MARGIN*(numItems + 1) + dairySize.GetHeight();
		Add(flavorLbl.HSizePosZ(MARGIN).TopPosZ(vertPos));
		
		
		for(int i = 0; i < 10; i++)
		{
			flavor[i].SetLabel(flavStr[i].c_str());
		}
		
		int checkDist = 20;
		int checkCount = 0;
		int left = LBLSIZE - MARGIN;
		for(int i = 0; i < 10; i++)
		{
			Add(flavor[i].LeftPosZ(LBLSIZE + left*(i%2), left).TopPosZ(vertPos + checkDist * checkCount));
			if(i%2 == 1)
			{
				checkCount++;
			}
			
		}
		
		priceLbl.SetLabel("Price:");
		Add(priceLbl.HSizePosZ(MARGIN).TopPosZ(vertPos + checkDist * checkCount));
		
		price.Disable();
		Add(price.LeftPosZ(LBLSIZE,CTRLWIDTH).TopPosZ(vertPos + checkDist * checkCount));
		
		createDrink.SetLabel("Create Drink");
		Add(createDrink.LeftPosZ(MARGIN,LBLSIZE + CTRLWIDTH).TopPosZ(vertPos + (checkDist * checkCount + 1) + MARGIN*2));
		
		Rect finalPos = createDrink.GetRect();
		int x = 7;
		SetRect(100,100,850,900);
		Size sz(850,900);
		SetMinSize(sz);
	};
		
};

GUI_APP_MAIN
{
	MyAppWindow app;
	app.Run();
}
