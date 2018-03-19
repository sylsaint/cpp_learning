#ifndef __WINDOW_MGR__
#define _WINDOW_MGR__ 10

#include<vector>

class Screen;

class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
        Screen &displayScreen(ScreenIndex);
        Window_mgr &set(Screen);
    private:
        std::vector<Screen> screens;
};
#endif

