#pragma once
#include "BaseScene.h"
#include "Player.h"
#include"Player2.h"
#include"UI.h"
#include "enemyType1.h"
#include"enemyType2.h"
#include"enemyType3.h"

class PlayScene :
	public BaseScene
{
	ULT *ultUI;

public:
	PlayScene();
	~PlayScene();

	//UI *UI_;

	void Init() override;
	void Update() override;
	void Exit();

private:

	//“G‚Ì’µ‚Ë•Ô‚·
	void CaculateAngleE(enemyType1*b1, BaseObject*b2);
	//‹Ê‚Ì’µ‚Ë•Ô‚·
	void CaculateAngleB(BaseBullet*b1, BaseObject*b2);
	//“|‚·”»’è
	void HitEnemyE(enemyType1*type1, EnemyBaseObject*typeother);
	void HitEnemyB(BaseBullet*b1, EnemyBaseObject*type);


};

