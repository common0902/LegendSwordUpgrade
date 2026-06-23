#include "Player.h"
#include "CHGData.h"

void Player::ApplyTotem(const CHGData& data)
{
    const float defaultAttackSpeed = 0;
    const float defaultMaxHP = 0;

    attackSpeed = defaultAttackSpeed + data.haveTotem.at(L"1").first * 5;
    MaxHp = defaultMaxHP + data.haveTotem.at(L"♥").first * 5;
}
