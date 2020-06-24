#include "chart_list.h"
#include <iostream>
#include <string>
#include "column.h"

int main()
{
    std::vector<std::string> vec;
    vec.push_back("Valera");
    vec.push_back("Petro");
    vec.push_back("Ignat");
    column<std::vector<std::string>> col1;
    col1.setColumn((unsigned short)0,vec);
    chart_list<decltype(col1)> table; 
    system("pause");
    return 0;
}