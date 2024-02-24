#include <vector>

class IDamageBuffObserver {
public:
    virtual ~IDamageBuffObserver() = default;
    virtual void onDamageBuff(int& amount) = 0;
};

class ObserverCharacter {
public:
    ObserverCharacter(int baseDamage) : baseDamage(baseDamage) {}
    virtual ~ObserverCharacter() = default;

    void attach(IDamageBuffObserver* observer) {
        observers.push_back(observer);
    }

    void detach(IDamageBuffObserver* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    int getBaseDamage() const {
        return baseDamage;
    }

    int getTotalDamage() const {
        int totalDamage = baseDamage;
        for (const auto& observer : observers) {
            observer->onDamageBuff(totalDamage);
        }
        return totalDamage;
    }

private:
    int baseDamage;
    std::vector<IDamageBuffObserver*> observers;
};

class DamageBuff : public IDamageBuffObserver {
public:
    DamageBuff(int amount) : buffAmount(amount) {}

    virtual void onDamageBuff(int& damage) override {
        damage += buffAmount;
    }
private:
    int buffAmount;
};