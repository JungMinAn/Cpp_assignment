// C++ BattleShip Proj
// total date : 2018-05-29 ~ 2018-06-02
// CBattleShipMap : 2018-05-29 ~ 2018-05-31
// 학번 : 20171644 이름 : 안중민 / student num : 20171644 name : JungMinAn
#include "Pane.h"

#define MAP_SIZE 8

class CBattleShipMap : Pane{
public:
char m_mapData[MAP_SIZE][MAP_SIZE];
    CBattleShipMap(int x, int y, const char* name);
    void Draw();
    ~CBattleShipMap();
};