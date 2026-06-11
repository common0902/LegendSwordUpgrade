#include"BattleEvent.h"
#include"BATTLE.h"

class HealEvent : public BattleEvent
{
public:
	HealEvent(BattleScene& scene) : BattleEvent(scene) {}
	virtual ~HealEvent() = default;
	void Start() {
		cout << "키를 눌러 힐을 받으세요.\n";
		WaitInput();
		cout << "Heal";
		battleScene.curPlayerHp += 10;
		battleScene.DrawBaseUI();
		WaitInput();
	}

};
