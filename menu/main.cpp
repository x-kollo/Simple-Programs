#include "menu.h"

int main()
{
    menu mn("Rating",14);
    mn.setHeadFillSymb('~');
    mn.AddItem("First item!",1);
    mn.AddItem("Second", 2);
    mn.AddItem("Third", 3);
    mn.setBorders('|','|');
    mn.ShowMenu();
    system("pause");
    return 0;
}