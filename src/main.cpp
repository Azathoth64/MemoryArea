#include <azathoth64/memory/area.h>

#include <iostream>

typedef struct Minion {
    int id;
    int hp;
} Minion;

Minion *spawn_minion(int id, int hp) {
    Minion *tmp = new Minion;

    tmp->hp = hp;
    tmp->id = id;

    return tmp;
}

int main() {

    Azathoth64::Memory::Area area{8000008};

    std::cout << area.toString();

    std::cout << "Operation was started.\n";

    for (int i = 0; i <= 1'000'000; ++i) {
        area.malloc(spawn_minion(i, 100));
    }

    std::cout << "Operation was ended.\n";

    std::cout << area.toString();

}