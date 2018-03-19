#ifndef __SCREEN__
#define __SCREEN__ 20

#include<string>
#include<cassert>
#include "window.h"

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
    public:
        typedef std::string::size_type pos;
        using pos1 = std::string::size_type;
        // constructor
        Screen() = default;
        Screen(pos ht, pos wd):
            height(ht), width(wd) {}
        Screen(pos ht, pos wd, char c=' '):
            height(ht), width(wd), contents(ht*wd, c) {}
        char get() const { return contents[cursor]; }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos w, pos c);
        Screen &set(char);
        Screen &set(pos, pos, char);
        Screen &display(std::ostream &os);
        const Screen &display(std::ostream &os) const;
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
        void do_display(std::ostream &os) const { os << contents; }
};

Screen &Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}
Screen &Screen::set(pos r, pos c, char ch)
{
    assert(r*width+c < height*width);
    contents[r*width+c] = ch;
    return *this;
}

Screen &Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}

const Screen &Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}
Screen &Screen::move(pos w, pos c)
{
    cursor += w * width + c;
    return *this;
}

#endif
