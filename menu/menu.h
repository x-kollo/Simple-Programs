// menu.h
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class menu
{
private:
    std::string title;
    std::size_t last_item;
    std::vector<std::string> item_names;
    char h_fill_symb;
    bool isLeft = false;
public:
    menu() : title(""), last_item(0), h_fill_symb('-'){};
    menu(std::string Title, std::size_t Last_Item) :  title(Title), last_item(Last_Item), h_fill_symb('-') 
    {
        for(std::size_t i = 0;i<last_item;++i)
            item_names.push_back(" - ");
    };
    ~menu(){};


    std::string getTitle() { return title; }
    std::size_t getItems() { return last_item; }
    std::vector<std::string> & getItemNames() { return item_names; }

    void setHeadFillSymb(const char h_fill_symb) { this->h_fill_symb = h_fill_symb; } 
    void setLeft(bool pos = true) { isLeft = pos; } 
    void AddItem(std::string name, int pos)
    {
        item_names[pos-1] = name;
    }

    void ShowMenu()
    {
        std::cout << std::setw(title.size()+16) << std::setfill(h_fill_symb) 
        << this->title << std::setw(title.size()+16) << std::setfill(h_fill_symb) << h_fill_symb << std::endl;

        for(std::size_t i = 1;i<=last_item;++i)
            std::cout << "[" << i << "] " << item_names[i-1] << std::endl;
    }
};