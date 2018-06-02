#include "StatPane.h"

StatPane::StatPane(int x, int y, int width, int height) : Pane(x, y, width, height){
    mvwprintw(m_pWindow, 0, 3, "< STATUS >");
    al = new char[6];
    bl = new char[5];
    cl = new char[4];
    dl1 = new char[3];
    dl2 = new char[3];
    for (int i = 0; i<5; i++){al[i] = 'A';}
    for (int i = 0; i<4; i++){bl[i] = 'B';}
    for (int i = 0; i<3; i++){cl[i] = 'C';}
    for (int i = 0; i<2; i++){dl1[i] = 'D';}
    for (int i = 0; i<2; i++){dl2[i] = 'D';}
    al[5] = '\0';
    bl[4] = '\0';
    cl[3] = '\0';
    dl1[2] = '\0';
    dl2[2] = '\0';
}

void StatPane::Draw(){
    wattron(m_pWindow, COLOR_PAIR(2));
    mvwprintw(m_pWindow, 1, 2, "AIRCRAFT : %s", al);
    mvwprintw(m_pWindow, 2, 2, "BATTLESHIP : %s", bl);
    mvwprintw(m_pWindow, 3, 2, "CRUISER : %s", cl);
    mvwprintw(m_pWindow, 4, 2, "DESTROYER : %s %s", dl1, dl2);
    wattroff(m_pWindow, COLOR_PAIR(2));
    wrefresh(m_pWindow);
}

StatPane::~StatPane(){
 delwin(m_pWindow);   
}