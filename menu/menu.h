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
public:
    menu() : title(""), last_item(0){};
    menu(std::string Title, std::size_t Last_Item) :  title(Title), last_item(Last_Item){};
    std::string getTitle() { return title; }
    std::size_t getItems() { return last_item; }
    std::vector<std::string> & getItemNames() { return item_names; }
    
    void ShowMenu()
    {
        std::cout << "helo";
    }
};