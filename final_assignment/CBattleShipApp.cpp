#include "CBattleShipApp.h"
#include <ctime>
#include <iostream>
#include <cstdlib>


void CBattleShipApp::Init(){
    initscr();
    start_color();
    cbreak();
    refresh();
    srand(time(0));

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    Dm_pMap = new CBattleShipMap(4, 2, "Defender");
    Am_pMap = new CBattleShipMap(4, 13, "Attacker");
    m_pStatPane = new StatPane(30, 3, 35, 6);
    m_pinputPane = new InputPane(30, 15, 35, 5);
}
int dp;
char* CBattleShipApp::randpos(int n){
    bool success = 0;
    int ap, np;
    int c = 0;
    while (success != 1 && c<100){
        success = 1;
        c++;
        ap = 'A' + rand() % (9-n);
        np = '1' + rand() % (9-n);
        dp = 0 + rand() % 2;
        if (dp == 1){
            for (int i = 0; i<n; i++){
                if (Dm_pMap->m_mapData[ap-'A' + i][np-'1'] != '0'){
                    success = 0;
                    break;
                }
            }
            if (success == 1){
                for (int j = 0; j<n; j++){
                    Dm_pMap->m_mapData[ap-'A' + j][np-'1'] = 'F'-n;
                }
            }
        }
        else {
            for (int i = 0; i<n; i++){
                if (Dm_pMap->m_mapData[ap-'A'][np-'1' + i] != '0'){
                    success = 0;
                    break;
                }
            }
            if (success == 1){
                for (int j = 0; j<n; j++){
                    Dm_pMap->m_mapData[ap-'A'][np-'1' + j] = 'F'-n;
                }
            }
        }
    }
    char* pos;
    pos = new char[2];
    pos[0] = ap;
    pos[1] = np;

    return pos;
}

void CBattleShipApp::makeship(){
    Aircraft = new Ship("AirCraft", 'A', randpos(5), 5, dp);
    BattleShip = new Ship("Battleship", 'B', randpos(4), 4, dp);
    Cruiser = new Ship("Cruiser", 'C', randpos(3), 3, dp);
    Destroyer1 = new Ship("Destroyer1", 'D', randpos(2), 2, dp);
    Destroyer2 = new Ship("Destroyer2", 'D', randpos(2), 2, dp);
}

void CBattleShipApp::Play(){
    Init();
    makeship();
    move(17, 41);
    int turn = 1;
    while(Aircraft->m_HP + BattleShip->m_HP + Cruiser->m_HP + Destroyer1->m_HP + Destroyer2->m_HP > 0){ 
        mvwprintw(m_pinputPane->m_pWindow, 3, 23, "turn : %i ", turn);
        Render();
        move(17, 41);
        keypad(m_pinputPane->m_pWindow, true);
        char inp[3] = {0,};
        scanw("%[^\n]", inp);
        if (inp[0] >='a' && inp[0] <= 'h'){
            inp[0] -= 32;
        }
        if (inp[1] == ' ' && inp[2] != 0){
            inp[1] = inp[2];
            inp[2] = 0;
        }
        int x = inp[0]-'A';
        int y = inp[1]-'1';
        if (x < 0 || x > 7 || y < 0 || y > 7 || inp[2] != 0 || inp[0] == 0){
            mvwprintw(m_pinputPane->m_pWindow, 3, 2, "Wrong Input   ");
            continue;
        }
        if (Am_pMap->m_mapData[inp[0]-'A'][inp[1]-'1'] != '0'){
            mvwprintw(m_pinputPane->m_pWindow, 3, 2, "Already called");
            continue;
        }
        turn++;
        if (Aircraft->HitCheck(inp)){
            Am_pMap->m_mapData[inp[0]-'A'][inp[1]-'1'] = 'H';
            m_pStatPane->al[Aircraft->m_HP] = ' ';

        }
        else if (BattleShip->HitCheck(inp)){
            Am_pMap->m_mapData[inp[0]-'A'][inp[1]-'1'] = 'H';
            m_pStatPane->bl[BattleShip->m_HP] = ' ';
        }
        else if (Cruiser->HitCheck(inp)){
            Am_pMap->m_mapData[inp[0]-'A'][inp[1]-'1'] = 'H';
            m_pStatPane->cl[Cruiser->m_HP] = ' ';
        }
        else if (Destroyer1->HitCheck(inp)){
            Am_pMap->m_mapData[inp[0]-'A'][inp[1]-'1'] = 'H';
            m_pStatPane->dl1[Destroyer1->m_HP] = ' ';
        }
        else if (Destroyer2->HitCheck(inp)){
            Am_pMap->m_mapData[inp[0]-'A'][inp[1]-'1'] = 'H';
            m_pStatPane->dl2[Destroyer2->m_HP] = ' ';
        }
        else {
            Am_pMap->m_mapData[inp[0]-'A'][inp[1]-'1'] = 'X';
            mvwprintw(m_pinputPane->m_pWindow, 3, 2, "Missed!       ");
            continue;
        }
        mvwprintw(m_pinputPane->m_pWindow, 3, 2, "Success!      ");
    }
    mvwprintw(m_pinputPane->m_pWindow, 3, 2, "You Win!      ");
    Render();
    Destroy();
}

void CBattleShipApp::Render(){
    mvprintw(1, 0, "<< Battle Ship Game >>");
    Dm_pMap->Draw();
    Am_pMap->Draw();
    m_pStatPane->Draw();
    m_pinputPane->Draw();

    refresh();
}

void CBattleShipApp::Destroy(){
    getch();
    endwin();
    delete Dm_pMap;
    delete Am_pMap;
}