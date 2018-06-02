// C++ BattleShip Proj
// total date : 2018-05-29 ~ 2018-06-02
// StatPane : 2018-05-29
// 학번 : 20171644 이름 : 안중민 / student num : 20171644 name : JungMinAn
#include "Pane.h"

class StatPane : Pane{
public:
    char* al, *bl, *cl, *dl1, *dl2;
    StatPane(int x, int y, int width, int height);
    void Draw();
    ~StatPane();
};