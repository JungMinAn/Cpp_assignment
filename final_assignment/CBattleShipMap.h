#include "Pane.h"

#define MAP_SIZE 8

class CBattleShipMap : Pane{
public:
char m_mapData[MAP_SIZE][MAP_SIZE];
    CBattleShipMap(int x, int y, const char* name);
    void Draw();
    ~CBattleShipMap();
};