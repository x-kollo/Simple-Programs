// menu.h
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <windows.h>

class menu
{
public:
enum Color
{
    BLACK = '0',
    BLUE = '1',
    GREEN = '2',
    AQUA = '3',
    RED = '4',
    PURPLE = '5',
    YELLOW = '6',
    WHITE = '7',
    GRAY = '8',
    LIGHTBLUE = '9',
    LIGHTGREEEN = 'A',
    LIGHTAQUA = 'B',
    LIGHTRED = 'C',
    LIGHTPURPUR = 'D',
    LIGHTYELLOW  = 'E',
    BRIGHTWHITE  = 'F',
}; 
private:
    std::string title;
    std::size_t last_item;
    std::vector<std::string> item_names;
    char h_fill_symb;
    bool isLeft = false;
    short width = 16;
    char borders[2] = {'[',']'}; 
    Color colors[2] = {BLACK,WHITE};
    bool buttom = false;
  //  int size[2] = { 20,30 };

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
  /*  void setSize(int X, int Y)
    {
        size[0] = X;
        size[1] = Y;
    }*/
    void setBottomTitle(bool type) {buttom = type;}
    bool getBottomTitle() { return buttom; }
    void setColor(Color text,Color background)
    {
        this->colors[0] = Color(background);
        this->colors[1] = Color(text);
    }
    void setHeadFillSymb(const char h_fill_symb) { this->h_fill_symb = h_fill_symb; } 
    void setLeft(bool pos = true) { isLeft = pos; } 
    void setWidth(int W) { width = W; }
    void setBorders(const char Left, const char Right)
    {
        borders[0] = Left;
        borders[1] = Right;
    }
    void AddItem(std::vector<std::string> & names)
    {
        item_names = names;
    }
    void AddItem(std::string name, int pos) 
    {
        item_names[pos-1] = name;
    }
    void ShowMenu()
    {


        std::string str = "color ";
        str.push_back(colors[0]);
        str.push_back(colors[1]);
        system(str.c_str());
        str.clear();
        std::cout << std::setw(width+title.size()) << std::setfill(h_fill_symb) 
        << this->title << std::setw(width) << std::setfill(h_fill_symb) << h_fill_symb << std::endl;

        for(std::size_t i = 1;i<=last_item;++i)
             std::cout << borders[0] << i << borders[1] << " " << item_names[i-1] << std::endl;
        
        if(!buttom)
        std::cout << std::setw(width+title.size()) << std::setfill(h_fill_symb) 
        << h_fill_symb  << std::setw(width) << std::setfill(h_fill_symb) << h_fill_symb << std::endl;
        else
        std::cout << std::setw(width+title.size()) << std::setfill(h_fill_symb) 
        << this->title  << std::setw(width) << std::setfill(h_fill_symb) << h_fill_symb << std::endl;
    }
};