#include "menu.h"

int main()
{
    menu men("Title", 5);
    men.AddItem("First item!",1);
    men.AddItem("Second", 2);
    men.ShowMenu();

    system("pause");
    return 0;
}