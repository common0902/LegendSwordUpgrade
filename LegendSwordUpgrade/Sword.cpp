#include "Sword.h"

float Sword::GetSuccessChance() const
{
    if (tier < 5)  return 90.0f - tier * 6.0f;
    if (tier < 10) return 60.0f - (tier - 5) * 7.0f;
    return 25.0f - (tier - 10) * 3.0f;
}

float Sword::GetBreakChance() const
{
    if (tier < 5)  return 0.0f;
    if (tier < 10) return (tier - 4) * 4.0f;
    return 20.0f + (tier - 10) * 10.0f;
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
        damage += 5;
        upgradeCost = (int)(upgradeCost * 1.5f);
        return UpgradeResult::SUCCESS;
    }
    else if (roll < GetSuccessChance() + GetBreakChance())
    {
        tier = 0;
        damage = 10;
        upgradeCost = 100;
        return UpgradeResult::BREAK;
    }
    else
    {
        if (tier > 0)
        {
            tier--;
            damage -= 5;
            upgradeCost = (int)(upgradeCost / 1.5f);
        }
        return UpgradeResult::DOWN;
    }
}

bool Sword::IsMaxTier() const { return tier >= 15; }