#include "InputPane.h"

InputPane::InputPane(int x, int y, int width, int height) : Pane(x, y, width, height){
    mvwprintw(m_pWindow, 0, 2, "< INPUT >");
}

InputPane::~InputPane(){
    delwin(m_pWindow);
}

void InputPane::Draw(){
    wattron(m_pWindow, COLOR_PAIR(3));
    mvwprintw(m_pWindow, 1, 2, "Input position(ex A3 or c 5)");
    mvwprintw(m_pWindow, 2, 2, "Input :                     ");
    wattroff(m_pWindow, COLOR_PAIR(3));
    wrefresh(m_pWindow);
}