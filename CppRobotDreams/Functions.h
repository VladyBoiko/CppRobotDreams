#include "PlayerVariables.h"
#include <vector>
#include<string>
#pragma once

int StrongestPlayerId(const std::vector<Player>& players);
void IntegerVectorReader(const std::vector<int>& Vector, const std::string& Value);
std::vector<int> MaxDamageDealers(const std::vector<int>& Damage);
std::vector<int> MinDamageDealers(const std::vector<int>& Damage);
std::vector<int> HealDealers(const std::vector<int>& Damage);
std::vector<int> ZeroDamageDealers(const std::vector<int>& Damage);
int TotalAmountOfDamage(const std::vector<int>& Damage, const std::string& type);