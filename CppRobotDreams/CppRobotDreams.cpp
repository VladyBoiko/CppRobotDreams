#include <iostream>
//#include <random>
#include <ctime>

using namespace std;

enum Classes {
    Mage = 1,
    Warrior = 2
};

int main()
{
    //random_device rd;
    //mt19937 gen(rd());
    //uniform_int_distribution<int> distribution(1, 2);
    srand(time(NULL));

    string name, className;
    float health = 100, maxHealth = 100;
    int characterClass = Classes::Mage, power =  5, damage = 10;

    cout << "Enter your character name: ";
    cin >> name;
    cout << "Enter your character helth: ";
    cin >> health;
    maxHealth = health;

    while (className.empty()) {
        cout << "Enter your character class(1 - Mage, 2 - Warrior): ";
        cin >> characterClass;

        switch (characterClass)
        {
            case Classes::Mage:
                className = "Mage";
                break;
            case Classes::Warrior:
                className = "Warrior";
                break;
            default:
                cout << "You entered invalid number of character class. Try again." << endl;
                break;
        }
    }

    do {
        cout << "Enter your character power(max power = 10): ";
        cin >> power;
    } while (power <= 0 || power >= 10);

    cout << endl 
        << "Okay, " << name
        << ", you are the " << className 
        << " with " << health << " health and " 
        << power << " power." 
        << endl << endl;
    
    int randomNumber;
    while (health > 0) {
        cout << "Enter damage: ";
        cin >> damage;
        
        if (damage > 0) {
            if (characterClass == Classes::Mage) {
                if (damage > 2 * power) {
                    /*randomNumber = distribution(gen);*/
                    randomNumber = rand() % 2;
                    cout << randomNumber << endl;
                    if (randomNumber == 1) {
                        if (damage % 2 == 0) {
                            health -= damage * 2;
                        }
                        else {
                            health -= damage;
                        }
                    }
                    else {
                        cout << "No damaged." << endl;
                    }
                }
                else {
                    if (damage % 2 == 0) {
                        health -= damage * 2;
                    }
                    else {
                        health -= damage;
                    }
                }
            }

            else if (characterClass == Classes::Warrior) {
                if (damage % 2 != 0){
                    if (health <= maxHealth * 0.3 && power < damage * 3) {
                        health -= (damage * 3 - power);
                    }
                    else {
                        health -= damage * 3;
                    }
                }
                else {
                    cout << "No damaged." << endl;
                }
            }
        }
        else {
            cout << "Enter valid damage number(> 0)." << endl;
        }

        cout << "New character health: " << health << endl;
        /*if (damage > 0) {
            if (characterClass == Classes::Warrior) {
                if (damage % 2 != 0) {
                    if (health < maxHealth * 0.3 && power < damage * 3) {
                            health -= (damage * 3 - power);
                    }
                    else
                        health -= damage * 3;
                }
                else{
                    cout << "No damaged." << endl;
                }
            }
            else{
                if (damage > 2 * power) {
                    randomNumber = distribution(gen);
                    cout << randomNumber << endl;
                    if (randomNumber == 1) {
                        cout << "No damaged." << endl;
                    }
                    else {
                        if (damage % 2 == 0) {
                            health -= damage * 2;
                        }
                        else {
                            health -= damage;
                        }
                    }
                }
                else {
                    if (damage % 2 == 0) {
                        health -= damage * 2;
                    }
                    else {
                        health -= damage;
                    }
                }
            }
        }

        else {
            cout << "Enter valid damage number(>=0)." << endl;
        }

        cout << "New character health: " << health << endl;*/
    }

    if (health <= 0)
    {
        cout << "---WASTED---" << endl;
    }

    return 0;
}
