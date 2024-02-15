#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "PlayerVariables.h"

int StrongestPlayerId(const std::vector<Player>& players) {

	float PlayerPower = players[0].MeleeAtack + players[0].RangeAtack;
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

void IntegerVectorReader(const std::vector<int>& Vector, const std::string& Value) {
	std::cout << Value << ":" << std::endl;

	for (int number : Vector)
	{
		std::cout << number << std::endl;
	}

	std::cout << std::endl;
}

std::vector<int> MaxDamageDealers(const std::vector<int>& Damage) {
	std::vector<int> MaxDamage;
	int max = Damage[0];
	//auto max = std::max_element(Damage.begin(), Damage.end());

	for (int damage : Damage)
	{
		if (damage > max) {
			max = damage;
		}
	}

	for (int i = 0; i < Damage.size(); ++i)
	{
		if (Damage[i] == max)
		{
			MaxDamage.push_back(i+1);
		}
	}
	
	return MaxDamage;
}

std::vector<int> MinDamageDealers(const std::vector<int>& Damage) {
	std::vector<int> MinDamage;
	int min = 0;

	for (int damage : Damage)
	{
		if (damage > 0)
		{
			min = damage;
			break;
		}
	}

	for (int damage : Damage)
	{
		if (damage < min && damage > 0) {
			min = damage;
		}
	}

	for (int i = 0; i < Damage.size(); ++i)
	{
		if (Damage[i] == min)
		{
			MinDamage.push_back(i + 1);
		}
	}

	return MinDamage;
}

std::vector<int> HealDealers(const std::vector<int>& Damage) {
	std::vector<int> Heal;

	for (int i = 0; i < Damage.size(); ++i)
	{
		if (Damage[i] < 0)
		{
			Heal.push_back(i + 1);
		}
	}

	return Heal;
}

std::vector<int> ZeroDamageDealers(const std::vector<int>& Damage) {
	std::vector<int> Nothing;

	for (int i = 0; i < Damage.size(); ++i)
	{
		if (Damage[i] == 0)
		{
			Nothing.push_back(i + 1);
		}
	}

	return Nothing;
}

int TotalAmountOfDamage(const std::vector<int>& Damage, const std::string& type) {
	int Amount = 0;

	if (type == "heal") {
		for (int heal : Damage)
		{
			if (heal < 0) {
				Amount += heal;
			}
		}
	}

	else if (type == "damage"){
		for (int damage : Damage)
		{
			if (damage > 0) {
				Amount += damage;
			}
		}
	}

	return Amount;
}