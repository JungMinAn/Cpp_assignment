#ifndef SHIP_H
#define SHIP_H
#include <ncurses.h>
#include <cstring>

class Ship{
public:
    Ship(const char* name, char type, const char* pos, int size, int direction);
    int m_HP;
    const char* m_name, *m_position;
    char m_Type;
    int m_Size, m_direction;
    char** positions;

    ~Ship();
    const char* GetName();
    char** GetPosition();
    int GetSize();
    char GetType();
    bool HitCheck(char* p);
};
#endif