// C++ BattleShip Proj
// total date : 2018-05-29 ~ 2018-06-02
// InputPane : 2018-05-29
// 학번 : 20171644 이름 : 안중민 / student num : 20171644 name : JungMinAn
#include "Pane.h"

class InputPane : public Pane{
public:
    InputPane(int x, int y, int width, int height);
    ~InputPane();

    void Draw();
};