#include "column.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{

    vector<string> str_v;
    str_v.push_back("Line");
    str_v.push_back("Line");
    str_v.push_back("Line");
    vector<string> str_v2;
    str_v2.push_back("Line");
    str_v2.push_back("Line");
    str_v2.push_back("Line");
    vector<string> str_v3;
    str_v3.push_back("Line");
    str_v3.push_back("Line");
    str_v3.push_back("Line");
    vector<string> str_v4;
    str_v4.push_back("Line");
    str_v4.push_back("Line");
    str_v4.push_back("Line");
    column<string> column3;
    column3.setToColumn(str_v,3);
    column3.print();
    
    column<string> column2;
    column2.setToColumn(str_v2,2);
    column2.print();

    column<string> column1;
    column1.setToColumn(str_v3,1);
    column1.print();

    column<string> column0;
    column0.setToColumn(str_v4,0);
    column0.print();

    COORD crd;
    crd.X = 0;
    crd.Y = str_v4.size()+1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
    system("pause");
    return 0;
}