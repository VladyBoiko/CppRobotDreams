#include <iostream>

class Building {
public:
    Building(int _id, int _maxAge, int _initialCost)
    {
        this->id = _id;
        this->maxAge = _maxAge;
        this->initialCost = _initialCost;
        this->currentCost = _initialCost;
        this->currentAge = 0;
    }

    int GetCost() const {
        return this->currentCost;
    }

    void ToAge(const int& years) {
        if (years < 0) {
            return;
        }
        this->currentAge += years;

        if (currentAge >= maxAge) {
            this->Destroy();
            this->currentCost = 0;
        }
        else {
            this->currentCost -= (this->initialCost * years / this->maxAge);
            std::cout << "Current building age: " << this->currentAge << std::endl;
        }

    }

private:
    int id;
    int maxAge;
    int initialCost;
    int currentCost;
    int currentAge;
private:
    void Destroy() const {
        std::cout << "Building with id " << id << " has been destroyed." << std::endl;
    }
};