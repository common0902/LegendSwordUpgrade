#include "Player.h"
#include "CHGData.h"

void Player::ApplyTotem(const CHGData& data)
{
    const int defaultAttackSpeed = 1;
    const int defaultMaxHP = 100;

    attackSpeed = defaultAttackSpeed + data.haveTotem.at(L"1").first;
    MaxHp = defaultMaxHP + data.haveTotem.at(L"♥").first * 10;
}
