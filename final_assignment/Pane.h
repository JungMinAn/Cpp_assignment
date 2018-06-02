#pragma once
#include <ncurses.h>
class Pane{
public:
    Pane(int x, int y, int width, int height);
    virtual ~Pane();
    virtual void Draw();
    int m_width, m_height;
    int m_x, m_y;
    WINDOW* m_pWindow;
};