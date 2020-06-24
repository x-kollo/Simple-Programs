template<typename T>
class column 
{
private:
    unsigned short column_id;
    T cln_buffer;
public:
    column() : column_id(0){}
    column(unsigned short id, T & buffer) : column_id(id), cln_buffer(buffer){}
    ~column(){}

    void setColumn(unsigned short id, T & buffer) 
    {
        column_id = id;
        this->cln_buffer = buffer;
    }
    void clear()
    {
        this->cln_buffer.clear();
    }
  //  friend std::ofstream & operator<<(std::ofstream & os, column & col)
    void Print()
    {
        for(auto el : cln_buffer)
        {
            std::cout << el <<std::endl;
        }
    }
};
