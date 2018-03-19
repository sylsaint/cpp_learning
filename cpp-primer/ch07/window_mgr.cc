#include<iostream>
#include "screen.h"

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.width*s.height, ' ');
}
Screen &Window_mgr::displayScreen(ScreenIndex i)
{
    Screen &s = screens[i];
    return s.display(std::cout);
}

Window_mgr &Window_mgr::set(Screen s)
{
    screens.push_back(s);
    return *this;
}

int main()
{
    Window_mgr wm;

    wm.set(Screen{10, 5, 'c'});
    std::cout << "before: ";
    wm.displayScreen(0);
    std::cout << std::endl;
    wm.clear(0);
    std::cout << "after : ";
    wm.displayScreen(0);
    std::cout << std::endl;
    return 0;
}
