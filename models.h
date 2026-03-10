#ifndef UNTITLED2_MODELS_H
#define UNTITLED2_MODELS_H

#include <string>
using namespace std;

struct Character {
    string name;
    int attack;
    int health;
};

inline bool compareCharacters(const Character &a, const Character &b) {
    if (a.attack != b.attack) {
        return a.attack < b.attack;
    }
    else {
        return a.health < b.health;
    }
}

#endif //UNTITLED2_MODELS_H