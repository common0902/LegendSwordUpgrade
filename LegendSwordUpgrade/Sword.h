#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;

enum class UpgradeResult { SUCCESS, DOWN, BREAK };

//struct GameState;

class Sword
{
public:
    //GameState& gameState;
    int damage = 10;
    int tier = 0;
    int upgradeCost = 100;
    int sellCost = 50;
    vector<string> image;
public:
    Sword() = default;
    ~Sword() = default;

    float GetSuccessChance() const;
    float GetBreakChance() const;
    float GetDownChance() const;
    UpgradeResult TryUpgrade();
    bool IsMaxTier() const;
    int GetDamageByTier(int t) const;
    int GetUpgradeCostByTier(int t) const;
    int GetSellCost() const;
};
