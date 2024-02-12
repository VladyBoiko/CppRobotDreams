#include <iostream>
#include <map>
#include <vector>
#include "Functions.h"
#include "PlayerInteraction.h"
#include "PlayerVariables.h"

using namespace std;

//struct PlayerFromClan {
//    string playerName;
//    float playerPower;
//};
//
//vector<PlayerFromClan> clan;
//
//map<string, vector<PlayerFromClan>> clansMap;

//int GetPlayerCount(const string& clanName);
//int ClanFight(const string& firstClanName, const string& secondClanName);


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

    int GetCost() {
        return this->currentCost;
    }

    void ToAge(const int& years){
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
            cout << "Current building age: " << this->currentAge << endl;
        }
        
    }

private:
    int id;
    int maxAge;
    int initialCost;
    int currentCost;
    int currentAge;
private:
    void Destroy() {
        cout << "Building with id " << id << " has been destroyed." << endl;
    }
};

int main()
{
//---------------------------------------------------------------------------------
    //string name = "Character Name", className = "Mage";
    //float health = 100, maxHealth = 100;
    //int power =  5, damage = 10;
    //vector<int> damageArray;

    //cout << "Enter your character name: ";
    //cin >> name;
    //cout << "Enter your character helth: ";
    //cin >> health;
    //maxHealth = health;

    //className = ClassName();

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

    //    while (health > 0) {
    //        cout << "Enter damage: ";
    //        cin >> damage;

    //        //if (damage > 0) {
    //            if (className == "Mage") {
    //                health = MageDamaged(health, damage, power);
    //            }

    //            else if (className == "Warrior") {
    //                if (damage % 2 != 0) {
    //                    health = WarriorDamaged(health, maxHealth, damage, power);
    //                }
    //                else {
    //                    damage = 0;
    //                    cout << "No damaged." << endl;
    //                }
    //            }
    //        //}
    //        //else {
    //        //    cout << "Enter valid damage number(> 0)." << endl;
    //        //}

    //        damageArray.push_back(damage);
    //        cout << "New character health: " << health << endl;
    //    }
//---------------------------------------------------------------------------------
  
//---------------------------------------------------------------------------------
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
    //        TotalAmountOfDamage(damageArray, type)
    //        << endl;
    //}

    //vector<Player> players
    //{
    //    {1, Mage, 1, 5},
    //    {2, Mage, 2, 5},
    //    {3, Mage, 1, 7},
    //    {4, Warrior, 5, 1},
    //    {5, Warrior, 6, 3},
    //    {6, Warrior, 6, 1}
    //};

    //cout << "Player with id " << 
    //    StrongestPlayerId(players)
    //    << " has the strongest character." 
    //    << endl;
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
    /*string clanName, secondClanName, playerName;
    float  playerPower;

    string newPlayrsChecking, newClanChecking;

    do {
        cout << "Enter name of clan: ";
        cin >> clanName;
        
        do {
            cout << "Enter new player name: ";
            cin >> playerName;

            cout << "Enter this player power: ";
            cin >> playerPower;

            PlayerFromClan player = { playerName , playerPower };
            clan.push_back(player);

            cout << "Do u wanna enter one more player name?" << endl;
            cin >> newPlayrsChecking;

        } while (newPlayrsChecking != "no");

        clansMap.insert({ clanName , clan });
        clan.clear();

        cout << "Do u wanna enter one more clan name?" << endl;
        cin >> newClanChecking;
    } while (newClanChecking != "no");

    cout << "Enter existed clan name: ";
    cin >> clanName;
    cout << "Players in clan " << clanName << ": " 
        << GetPlayerCount(clanName) << endl;

    cout << "Enter first clan name: ";
    cin >> clanName;
    cout << "Enter second clan name: ";
    cin >> secondClanName;

    int fightREsult = ClanFight(clanName, secondClanName);
    if (fightREsult == 1) {
        cout << clanName <<" clan better." << endl;
    }
    else if (fightREsult == -1) {
        cout << secondClanName << " clan better." << endl;
    }
    else if (fightREsult == 0) {
        cout << "Clans power are equal." << endl;
    }*/
//---------------------------------------------------------------------------------
    vector<Building> buildings;
    string newBuildingChecking;
    int buildingId = 0, buildingMaxAge, buildingInitialCost, years;

    do {
        cout << "Enter max building age: ";
        cin >> buildingMaxAge;
        cout << "Enter building initial cost: ";
        cin >> buildingInitialCost;

        cout << "Do u wanna create one more building?(enter no to exit)" << endl;
        cin >> newBuildingChecking;

        Building building(buildingId, buildingMaxAge, buildingInitialCost);
        buildings.push_back(building);
        buildingId += 1;

    } while (newBuildingChecking != "no");
    
    for (int i = 0; i < buildings.size(); ++i) {
        cout << "Building " << i << endl;
        cout << "Building`s cost: " << buildings[i].GetCost() << endl;
        cout << endl;
    }
    string isContinue;
    do {
        cout << "Enter building id: ";
        cin >> buildingId;
        cout << "Building cost: " << buildings[buildingId].GetCost() << endl;

        if (buildings[buildingId].GetCost() == 0) {
            cout << "The building was already destroyed. Try another one..." << endl;
            continue;
        }
        while (buildings[buildingId].GetCost() > 0) {
            cout << "Enter an integer by how much you want to age the building: ";
            cin >> years;
            buildings[buildingId].ToAge(years);
            cout << "Current building cost: " << buildings[buildingId].GetCost() << endl;
        }

        cout << "Do u wanna destroy one more building?(enter no to exit)" << endl;
        cin >> isContinue;
    } while (isContinue != "no");


    return 0;
}

//int GetPlayerCount(const string& clanName) {
//    if (clansMap.find(clanName) != clansMap.end()) {
//        return clansMap[clanName].size();
//    }
//    else {
//        cout << "Clan not  existed..." << endl;
//        return 0;
//    }
//}
//
//int ClanFight(const string& firstClanName, const string& secondClanName){
//    float firstClanPower = 0, secondClanPower = 0;
//
//    if (clansMap.find(firstClanName) != clansMap.end() &&
//        clansMap.find(secondClanName) != clansMap.end()) {
//        for (const PlayerFromClan& power : clansMap[firstClanName]) {
//            firstClanPower += power.playerPower;
//        }
//
//        for (const PlayerFromClan& power : clansMap[secondClanName]) {
//            secondClanPower += power.playerPower;
//        }
//
//        if (firstClanPower > secondClanPower) {
//            return 1;
//        }
//        else if (firstClanPower < secondClanPower) {
//            return -1;
//        }
//        else if (firstClanPower = secondClanPower) {
//            return 0;
//        }
//    }
//
//    else {
//        cout << "One of the clans not existed..." << endl;
//        return 2;
//    }
//}