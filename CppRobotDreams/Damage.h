#include <string>
#pragma once

class Weapon
{
public:
    virtual ~Weapon() {};
    virtual float GetDamage() const = 0;
    virtual std::string GetName() const = 0;

private:

};

class Riffle : public Weapon
{
public:
    virtual float GetDamage() const override {
        return 25.0f;
    }
    virtual std::string GetName() const override {
        return "LR16 FS-CQB Carbine";
    }

private:

};

class Pistol : public Weapon
{
public:
    virtual float GetDamage() const override {
        return 49.0f;
    }
    virtual std::string GetName() const override {
        return "Desert Eagle";
    }

private:

};

class Shotgun : public Weapon
{
public:
    virtual float GetDamage() const override {
        return 20.0f;
    }
    virtual std::string GetName() const override {
        return "Double Eagle Shotgun M58A Tactical";
    }

private:

};

class Knife : public Weapon
{
public:
    virtual float GetDamage() const override {
        return 60.0f;
    }
    virtual std::string GetName() const override {
        return "M9 bayonet";
    }

private:

};

class DamageModifier {
public:
    virtual float CalculateDamage(float CurrentHealth, float Damage) = 0;
    virtual ~DamageModifier() {};
};

class MultiplicationDamageModifier : public DamageModifier {
public:
    MultiplicationDamageModifier(float multiplicator) {
        this->multiplicator = multiplicator;
    }
    virtual float CalculateDamage(float CurrentHealth, float Damage) override {
        CurrentHealth -= Damage * multiplicator;
        return CurrentHealth;
    }
private:
    float multiplicator;
};

class AdditionDamageModifier : public DamageModifier {
public:
    AdditionDamageModifier(float addition) {
        this->addition = addition;
    }
    virtual float CalculateDamage(float CurrentHealth, float Damage) override {
        float modifiedDamage = Damage + addition;
        if (modifiedDamage > 0) {
            CurrentHealth -= modifiedDamage;
        }
        return CurrentHealth;
    }
private:
    float addition;
};

class ParityDamageModifier : public DamageModifier {
public:
    ParityDamageModifier(float multiplicator) {
        this->multiplicator = multiplicator;
    }
    virtual float CalculateDamage(float CurrentHealth, float Damage) override {
        if ((int)Damage % 2 == 0) {
            CurrentHealth -= Damage * multiplicator;
        }
        else {
            CurrentHealth -= Damage;
        }
        return CurrentHealth;
    }
private:
    float multiplicator;
};