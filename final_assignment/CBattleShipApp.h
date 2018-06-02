#include "StatPane.h"
#include "InputPane.h"
#include "CBattleShipMap.h"
#include "Ship.h"

class CBattleShipApp{
public:
    CBattleShipApp(){};
    void Play();
    void Init();
    void Render();
    char* randpos(int n);
    void makeship();
    void Destroy();

    CBattleShipMap* Dm_pMap;
    CBattleShipMap* Am_pMap;
    StatPane* m_pStatPane;
    InputPane* m_pinputPane;
    Ship* Aircraft;
    Ship* BattleShip;
    Ship* Cruiser;
    Ship* Destroyer1;
    Ship* Destroyer2;
    ~CBattleShipApp(){};
};