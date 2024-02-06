#include <iostream>
#include <random>
#include <vector>
#include "Functions.h"

using namespace std;

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

int StrongestPlayerId(vector<Player> players) {

    int PlayerPower = players[0].MeleeAtack + players[0].RangeAtack;
    int PlayerId = players[0].PlayerId;

    for (const Player& player : players)
    {
        if ((player.MeleeAtack + player.RangeAtack) > PlayerPower) {
            PlayerPower = player.MeleeAtack + player.RangeAtack;
            PlayerId = player.PlayerId;
        }
    }

    return PlayerId;
};

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 2);

    string name = "Character Name", className = "Mage";
    float health = 100, maxHealth = 100;
    int characterClass = Classes::Mage, power =  5, damage = 10;
    vector<int> damageArray;

    //cout << "Enter your character name: ";
    //cin >> name;
    //cout << "Enter your character helth: ";
    //cin >> health;
    //maxHealth = health;

    //while (className.empty()) {
    //    cout << "Enter your character class(1 - Mage, 2 - Warrior): ";
    //    cin >> characterClass;

    //    switch (characterClass)
    //    {
    //        case Classes::Mage:
    //            className = "Mage";
    //            break;
    //        case Classes::Warrior:
    //            className = "Warrior";
    //            break;
    //        default:
    //            cout << "You entered invalid number of character class. Try again." << endl;
    //            break;
    //    }
    //}

    //do {
    //    cout << "Enter your character power(max power = 10): ";
    //    cin >> power;
    //} while (power <= 0 || power >= 10);

    //{
    //    cout << endl
    //        << "Okay, " << name
    //        << ", you are the " << className
    //        << " with " << health << " health and "
    //        << power << " power."
    //        << endl << endl;

    //    int randomNumber;
    //    while (health > 0) {
    //        cout << "Enter damage: ";
    //        cin >> damage;

    //        //if (damage > 0) {
    //        if (characterClass == Classes::Mage) {
    //            if (damage > 2 * power) {
    //                randomNumber = distribution(gen);
    //                cout << randomNumber << endl;
    //                if (randomNumber == 1) {
    //                    if (damage % 2 == 0) {
    //                        health -= damage * 2;
    //                    }
    //                    else {
    //                        health -= damage;
    //                    }
    //                }
    //                else {
    //                    damage = 0;
    //                    cout << "No damaged." << endl;
    //                }
    //            }
    //            else {
    //                if (damage % 2 == 0) {
    //                    health -= damage * 2;
    //                }
    //                else {
    //                    health -= damage;
    //                }
    //            }
    //        }

    //        else if (characterClass == Classes::Warrior) {
    //            if (damage % 2 != 0) {
    //                if (health <= maxHealth * 0.3 && power < damage * 3) {
    //                    health -= (damage * 3 - power);
    //                }
    //                else {
    //                    health -= damage * 3;
    //                }
    //            }
    //            else {
    //                damage = 0;
    //                cout << "No damaged." << endl;
    //            }
    //        }
    //        //}
    //        //else {
    //        //    cout << "Enter valid damage number(> 0)." << endl;
    //        //}

    //        damageArray.push_back(damage);
    //        cout << "New character health: " << health << endl;
    //    }

    //    cout << "Damage array: ";
    //    for (int damageFromArray : damageArray)
    //    {
    //        cout << damageFromArray << " ";
    //    }
    //    cout << endl;

    //    if (health <= 0)
    //    {
    //        cout << "---WASTED---" << endl;
    //    }

    //    IntegerVectorReader(MaxDamageDealers(damageArray),
    //        "Max damage was dealt by");
    //    IntegerVectorReader(MinDamageDealers(damageArray),
    //        "Min damage was dealt by");
    //    IntegerVectorReader(HealDealers(damageArray),
    //        "Heal was dealt by");
    //    IntegerVectorReader(ZeroDamageDealers(damageArray),
    //        "Zero damage was dealt by");

    //    int typeOfDamage;
    //    string type;

    //    while (type.empty()) {
    //        cout << "Enter type of damage or heal(1 - damage, 2 - heal): ";
    //        cin >> typeOfDamage;

    //        switch (typeOfDamage)
    //        {
    //        case 1:
    //            type = "damage";
    //            break;
    //        case 2:
    //            type = "heal";
    //            break;
    //        default:
    //            cout << "You entered invalid number. Try again." << endl;
    //            break;
    //        }
    //    }

    //    cout << "Total ammount of " + type + " is:" <<
    //        TotalAmountOfDamage(damageArray, type);
    //}
    vector<Player> players{
        {1, Mage, 1, 5},
        {2, Mage, 2, 5},
        {3, Mage, 1, 7},
        {4, Warrior, 5, 1},
        {5, Warrior, 6, 3},
        {6, Warrior, 6, 1}
    };

    /*Player player1;
    player1.PlayerId = 1;
    player1.PlayerClass = Mage;
    player1.MeleeAtack = 1;
    player1.RangeAtack = 5;
    players.push_back(player1);

    Player player2;
    player2.PlayerId = 2;
    player2.PlayerClass = Mage;
    player2.MeleeAtack = 2;
    player2.RangeAtack = 5;
    players.push_back(player2);

    Player player3;
    player3.PlayerId = 3;
    player3.PlayerClass = Mage;
    player3.MeleeAtack = 1;
    player3.RangeAtack = 7;
    players.push_back(player3);

    Player player4;
    player4.PlayerId = 4;
    player4.PlayerClass = Warrior;
    player4.MeleeAtack = 5;
    player4.RangeAtack = 1;
    players.push_back(player4);

    Player player5;
    player5.PlayerId = 5;
    player5.PlayerClass = Warrior;
    player5.MeleeAtack = 6;
    player5.RangeAtack = 3;
    players.push_back(player5);

    Player player6;
    player6.PlayerId = 6;
    player6.PlayerClass = Warrior;
    player6.MeleeAtack = 6;
    player6.RangeAtack = 1;
    players.push_back(player6);*/

    cout << "Player with id " << 
        StrongestPlayerId(players)
        << " has the strongest character." 
        << endl;

    return 0;
}
