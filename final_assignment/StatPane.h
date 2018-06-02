#include "Pane.h"

class StatPane : Pane{
public:
    char* al, *bl, *cl, *dl1, *dl2;
    StatPane(int x, int y, int width, int height);
    void Draw();
    ~StatPane();
};