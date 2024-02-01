#include <vector>
#include <string>
#pragma once

void IntegerVectorReader(std::vector<int> Vector, std::string String);
std::vector<int> MaxDamageDealers(std::vector<int> Damage);
std::vector<int> MinDamageDealers(std::vector<int> Damage);
std::vector<int> HealDealers(std::vector<int> Damage);
std::vector<int> ZeroDamageDealers(std::vector<int> Damage);
int TotalAmountOfDamage(std::vector<int> Damage, std::string type);