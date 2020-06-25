#include "column.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
    vector<double> d_vec;
    vector<int> i_vec;
    vector<string> s_vec;
    for(int i = 0;i<10;i++)
        d_vec.push_back(0.50+i+i/2);
    for(int i = 0;i<10;i++)
        i_vec.push_back(i+i*2);
    for(int i = 0;i<10;i++)
        s_vec.push_back("Name " + to_string(i));
    column<double> d_col(0,d_vec);
    column<int> i_col(1,i_vec);
    column<string> s_col(2,s_vec);
    d_col.setTitle("Doubles");
    i_col.setTitle("Ints");
    s_col.setTitle("Strings");
    s_col.print(2,true);
    i_col.print(2,true);
    d_col.print(2,true, true);

    system("pause");
    return 0;
}