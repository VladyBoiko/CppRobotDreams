#include <string>
#include <map>
#include <vector>
#include "Damage.h"
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

struct PlayerFromClan {
    std::string playerName;
    float playerPower;
};



class Character
{
public:
    void SetWeapon(std::shared_ptr<Weapon> weapon) {
        this->weapon = weapon;
    }

    std::shared_ptr<Weapon> GetWeapon() const {
        return weapon;
    }

    void SetDamageModifier(std::shared_ptr<DamageModifier> modifier) {
        this->damageModifier = modifier;
    }

    float GetModifiedDamage(float CurrentHealth, float Damage) const {
        return damageModifier->CalculateDamage(CurrentHealth, Damage);
    }
private:
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<DamageModifier> damageModifier;
};


