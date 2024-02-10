#pragma once
enum Classes {
    Mage = 1,
    Warrior = 2
};

struct Player {
    int PlayerId;
    Classes PlayerClass;
    float MeleeAtack;
    float RangeAtack;
};
