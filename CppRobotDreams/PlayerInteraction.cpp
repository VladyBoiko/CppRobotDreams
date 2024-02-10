#include <iostream>
#include <string>
#include <random>
#include "PlayerVariables.h"

std::string ClassName() {
    std::string className;
    int characterClass = Classes::Mage;

    while (className.empty()) {
        std::cout << "Enter your character class(1 - Mage, 2 - Warrior): ";
        std::cin >> characterClass;

        switch (characterClass)
        {
        case Classes::Mage:
            className = "Mage";
            break;
        case Classes::Warrior:
            className = "Warrior";
            break;
        default:
            std::cout << "You entered invalid number of character class. Try again." << std::endl;
            break;
        }
    }

    return className;
}

int MageDamaged(int health, int damage, int power) {
    int newHealth = health;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 2);
    int randomNumber;

    if (damage > 2 * power) {
        randomNumber = distribution(gen);
        std::cout << randomNumber << std::endl;
        if (randomNumber == 1) {
            if (damage % 2 == 0) {
                newHealth -= damage * 2;
            }
            else {
                newHealth -= damage;
            }
        }
        else {
            damage = 0;
            std::cout << "No damaged." << std::endl;
        }
    }
    else {
        if (damage % 2 == 0) {
            newHealth -= damage * 2;
        }
        else {
            newHealth -= damage;
        }
    }

    return newHealth;
}

int WarriorDamaged(int health, int maxHealth, int damage, int power) {
    int newHealth = health;

    if (health <= maxHealth * 0.3 && power < damage * 3) {
        newHealth -= (damage * 3 - power);
    }
    else {
        newHealth -= damage * 3;
    }

    return newHealth;
}