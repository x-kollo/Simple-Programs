#include "menu.h"

int main()
{
    menu mn("Rating",3);
    mn.setHeadFillSymb('~');
    mn.AddItem("First item!",1);
    mn.AddItem("Second", 2);
    mn.AddItem("Third", 3);
    mn.setBottomTitle(false);
    mn.setColor(mn.LIGHTGREEEN,mn.BLACK);
    mn.setBorders('|','|');
 //   mn.setSize(150,100);
    mn.ShowMenu();
 
    system("pause");
    return 0;
}