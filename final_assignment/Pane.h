// C++ BattleShip Proj
// total date : 2018-05-29 ~ 2018-06-02
// Pane : 2018-05-29
// 학번 : 20171644 이름 : 안중민 / student num : 20171644 name : JungMinAn
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