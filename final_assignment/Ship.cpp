#include "Ship.h"
#include <iostream>
using namespace std;

Ship::Ship(const char* name, char type, const char* pos, int size, int direction) : m_name(name), m_Type(type), m_position(pos), m_Size(size), m_direction(direction){
    m_HP = m_Size;
    positions = new char*[m_Size];
    if (m_direction == 1){
        for (int i = 0; i<m_Size; i++){
            positions[i] = new char[2];
            positions[i][0] = m_position[0] + i;
            positions[i][1] = m_position[1];
        }
    }
    else {
        for (int i = 0; i<m_Size; i++){
            positions[i] = new char[2];
            positions[i][0] = m_position[0];
            positions[i][1] = m_position[1] + i;
        }
    }
}

Ship::~Ship(){
}

const char* Ship::GetName(){
    return m_name;
}

char** Ship::GetPosition(){
    return positions;
}

int Ship::GetSize(){
    return m_Size;
}

char Ship::GetType(){
    return m_Type;
}

bool Ship::HitCheck(char* p){
    for (int i = 0; i<m_Size; i++){
        if (strcmp(p, positions[i]) == 0){
            m_HP--;
            return true;
        }
    }
    return false;
}


