#include "Sword.h"
#include "GameState.h"

float Sword::GetSuccessChance() const
{
    const float successChance[] =
    {
        100.0f,
         98.0f,
         95.0f,
         92.0f,
         88.0f,
         84.0f,
         80.0f,
         75.0f,
         70.0f,
         65.0f,
         60.0f,
         50.0f,
         40.0f,
         30.0f,
         25.0f,
         20.0f,
         15.0f,
         13.0f,
         12.0f,
         10.0f,
    };
    if (tier < 0 || tier >= 20) return 0.0f;
    return successChance[tier];
}

float Sword::GetBreakChance() const
{
    const float breakChance[] =
    {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          2.0f,
          5.0f,
         10.0f,
         15.0f,
         25.0f,
         35.0f,
         50.0f,
         65.0f,
         78.0f,
         90.0f,
    };
    if (tier < 0 || tier >= 20) return 0.0f;
    return breakChance[tier];
}

float Sword::GetDownChance() const
{
    return 100.0f - GetSuccessChance() - GetBreakChance();
}

UpgradeResult Sword::TryUpgrade()
{
    float roll = (float)(rand() % 10000) / 100.0f;

    if (roll < GetSuccessChance())
    {
        tier++;
        damage = GetDamageByTier(tier);
        upgradeCost = GetUpgradeCostByTier(tier);
        return UpgradeResult::SUCCESS;
    }
    else if (roll < GetSuccessChance() + GetBreakChance())
    {
        tier = 0;
        damage = GetDamageByTier(0);
        upgradeCost = GetUpgradeCostByTier(0);
        return UpgradeResult::BREAK;
    }
    else
    {
        if (tier > 0)
        {
            tier--;
            damage = GetDamageByTier(tier);
            upgradeCost = GetUpgradeCostByTier(tier);
        }
        return UpgradeResult::DOWN;
    }
}

int Sword::GetUpgradeCostByTier(int t) const
{
    const int costs[] =
    {
        200,
        425,
        600,
        820,
        1070,
        1450,
        2020,
        2350,
        3600,
        4800,
        6250,
        8400,
        11050,
        14650,
        19050,
        25000,
        34000,
        50000,
        900000,
        1000000,
        0,
    };
    if (t < 0 || t > 20) return 0;
    return costs[t];
}

int Sword::GetSellCost() const
{
    const int sellCosts[] =
    {
        0,
        50,
        150,
        300,
        500,
        800,
        1200,
        1800,
        2700,
        4000,
        6000,
        9000,
        13000,
        19000,
        28000,
        41000,
        60000,
        88000,
        130000,
        190000,
        280000,
    };
    if (tier < 0 || tier > 20) return 0;
    return sellCosts[tier];
}

bool Sword::IsMaxTier() const { return tier >= 20; }

int Sword::GetDamageByTier(int t) const
{
    return (int)(10.0f * pow(1.26f, t));
}

