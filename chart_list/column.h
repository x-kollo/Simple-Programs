#include <iostream>
#include <vector>
#include <windows.h>

template<typename T>
class column
{
private:
    unsigned short colums;
    std::vector<T> buffer;
public:   
    column() : colums(0){}
    column(unsigned short colums) : colums(colums){}
    ~column(){}
    
    void setToColumn(std::vector<T> & buffer, unsigned short const column_id)
    {
        this->buffer = buffer;
        this->colums = column_id;
    }
    void print()
    {
        COORD crd;
        crd.X = 0;
        crd.Y = 0;
        for(auto el : buffer)
        {
            for(unsigned short i = 0;i<(colums);i++)
                std::cout<<"\t\t";
            std::cout << el << std::endl;           
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
       // std::cout<<"\033[<N>A";
    }
};