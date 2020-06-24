#include <iostream>
#include <vector>


template<typename T>
class chart_list
{
protected:
    unsigned short colums;
    std::vector<std::vector<T>> buffer;
public:   
    chart_list() : colums(0){}
    chart_list(unsigned short colums) : colums(colums){}
    ~chart_list(){}
    
    void setToColumn(T buffer, unsigned short const column_id)
    {
        try
        {
            this->buffer[column_id] = buffer;
        }
        catch(std::out_of_range e) 
        {
            this->buffer.resize(column_id+1);
            this->buffer[column_id] = buffer;
        }
    }
    void addToColumn(T const buffer, unsigned short const column_id)
    {
        try
        {
            this->buffer[column_id] = buffer;
        }
        catch(std::out_of_range e) 
        {
            this->buffer.resize(column_id+1);
            this->buffer[column_id] = buffer;
        }
    }
};