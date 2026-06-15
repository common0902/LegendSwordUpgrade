#include"BattleEvent.h"
#include"BATTLE.h"

class HealEvent : public BattleEvent
{
public:
	HealEvent(BattleScene& scene) : BattleEvent(scene) {}
	virtual ~HealEvent() = default;
	void Start() {
		Typing("키를 눌러 힐을 받으세요.\n",10);

		WaitInput();
		cout << "Heal";

		battleScene.curPlayerHp += 10;
		battleScene.DrawBaseUI();
	}

};


class EnemyBattleEvent : public BattleEvent
{
public:
	EnemyBattleEvent(BattleScene& scene) : BattleEvent(scene) {}
	virtual ~EnemyBattleEvent() = default;
	void Start() {

		
		Typing("적을 만났다!", 10);
		
		battleScene.curPlayerHp -= 20;


		
	}

};
