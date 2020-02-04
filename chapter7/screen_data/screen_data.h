#ifndef SCREEN_DATA_H
#define SCREEN_DATA_H

#include <string>
#include <iostream>

class Window_mgr
{
public:
    void clear();
};


class Screen
{
friend void Window_mgr::clear();
public:
    typedef std::string::size_type pos;
    Screen() = default;
     Screen(pos ht, pos wd) :
        height(ht), width(wd), contents(ht * wd, ' ') {}   
    Screen(pos ht, pos wd, char c) :
        height(ht), width(wd), contents(ht * wd, c) {}
    Screen &move(pos r, pos c)
        {cursor = r * width + c; return *this;}
    char get() const
        { return contents[cursor]; }
    char get(pos ht, pos wd) const; 
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os)
        { do_display(os); return *this; }
    const  Screen &display(std::ostream &os) const
        { do_display(os); return *this; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const {os << contents; }
};

inline
char Screen::get(pos ht, pos wd) const
{
    return contents[ht*width + wd];
}

inline
Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r*width + c] = ch;
    return *this;
}

void Window_mgr::clear()
{
    Screen myScreen(10, 20, 'X');
    cout << "清理之前myScreen的内容是: " << endl;
    cout << myScreen.contents << endl;
    myScreen.contents = "";
    cout << "清理之后myScreen的内容是: " << endl;
    cout << myScreen.contents << endl;  
}
#endif