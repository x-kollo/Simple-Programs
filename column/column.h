#include <iostream>
#include <vector>
#include <windows.h>

template<typename T>
class column
{
private:
    unsigned short column_id;
    std::vector<T> buffer;
    char *title;
public:   
    column() : column_id(0)
    {
        title = new char[16];
    }
    column(unsigned short const column_id, std::vector<T> const & buffer) : column_id(column_id), buffer(buffer){}
    column(unsigned short column_id, const char* title) : column_id(column_id), title(new char[strlen(title)])
    {
        strcpy(this->title, title);
    }
    column(unsigned short column_id, const char* title, std::vector<T> const & buffer) : column_id(column_id), title(new char[strlen(title)]), buffer(buffer)
    {
       strcpy(this->title, title); 
    }
    ~column()
    {
        delete[] title;
    }
    
    void setToColumn(std::vector<T> const & buffer, unsigned short const column_id)
    {
        this->buffer = buffer;
        this->column_id = column_id;
    }
    void setTitle(const char* title)
    {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }
    void clear()
    {
        buffer.clear();
    }
    void print(unsigned short const tab_count = 1, bool const isTitle = false, bool const isLast = false)
    {
        COORD crd;
        crd.X = 0;
        crd.Y = 0;
       
        for(unsigned short i = 0;i<column_id;i++)
        {
            for(int j = 0;j<tab_count;j++)
                std::cout<<"\t";
        }
        if(isTitle)
            std::cout << this->title<<std::endl;    
        for(auto const & el : buffer)
        {
            for(unsigned short i = 0;i<column_id;i++)
            {
                for(int j = 0;j<tab_count;j++)
                    std::cout<<"\t";
            }
               
            std::cout << el << std::endl;           
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
       if(isLast)
       {
            crd.X = 0;
            crd.Y = buffer.size()+1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
       }
    }
};