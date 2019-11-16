#include "GameManager.h"



GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::Init()
{
	gameState = Play;

	player1_img = Texture(U"../data/player/leftboard.png");
	player2_img = Texture(U"../data/player/rightboard.png");
	earth_img = Texture(U"../data/bg/earth_bg.png");
	ginnga_img = Texture(U"../data/bg/ginnga_bg.png");
	//Type1_©E
	enemy_img_type1[0] = Texture(U"../data/enemy/type1/enemy1.png");
	enemy_img_type1[1] = Texture(U"../data/enemy/type1/enemy2.png");
	enemy_img_type1[2] = Texture(U"../data/enemy/type1/enemy6.png");
	enemy_img_type1[3] = Texture(U"../data/enemy/type1/enemy8.png");
	enemy_img_type1[4] = Texture(U"../data/enemy/type1/enemy12.png");
	//Type2_’¼ü‘Å‚Â
	enemy_img_type2[0] = Texture(U"../data/enemy/type2/enemy3.png");
	enemy_img_type2[1] = Texture(U"../data/enemy/type2/enemy13.png");
	enemy_img_type2[2] = Texture(U"../data/enemy/type2/enemy14.png");
	enemy_img_type2[3] = Texture(U"../data/enemy/type2/enemy15.png");
	enemy_img_type2[4] = Texture(U"../data/enemy/type2/enemy16.png");
	//Type3_ƒ‰ƒ“ƒ_ƒ€‘Å‚Â
	enemy_img_type3[0] = Texture(U"../data/enemy/type3/enemy4.png");
	enemy_img_type3[1] = Texture(U"../data/enemy/type3/enemy9.png");
	enemy_img_type3[2] = Texture(U"../data/enemy/type3/enemy10.png");
	enemy_img_type3[3] = Texture(U"../data/enemy/type3/enemy17.png");
	enemy_img_type3[4] = Texture(U"../data/enemy/type3/enemy22.png");
	

	/*enemy_img[4] = Texture(U"../data/enemy/enemy5.png");
	enemy_img[6] = Texture(U"../data/enemy/enemy7.png");
	enemy_img[10] = Texture(U"../data/enemy/enemy11.png");
	enemy_img[17] = Texture(U"../data/enemy/enemy18.png");
	enemy_img[18] = Texture(U"../data/enemy/enemy19.png");
	enemy_img[19] = Texture(U"../data/enemy/enemy20.png");
	enemy_img[20] = Texture(U"../data/enemy/enemy21.png");	
	enemy_img[22] = Texture(U"../data/enemy/enemy23.png");
	enemy_img[23] = Texture(U"../data/enemy/enemy24.png");
	enemy_img[24] = Texture(U"../data/enemy/enem25.png");*/

	bullet_img = Texture(U"../data/bullet.png");
	number_img = Texture(U"../data/numbers.png");
	score_img = Texture(U"../data/score.png");
	time_img = Texture(U"../data/time.png");
	earth_hp_img = Texture(U"../data/hp_ui/earth_hp.png");
	hpbar_img=Texture(U"../data/hp_ui/hp_bar.png");
	hpwords_img = Texture(U"../data/hp_ui/hp.png");
	ultwords_img = Texture(U"../data/ult_ui/ult.png");
	energybar_img = Texture(U"../data/ult_ui/energy_bar.png");
	enemykilled_img = Texture(U"../data/enemykilled.png");

	sceneManager = new SceneManager;
	sceneManager->Init();

	

}

void GameManager::Update()
{

	sceneManager->Update(gameState);

	if (KeyUp.down())
	{
		gameState -= 1;
	}
	else if (KeyDown.down())
	{
		gameState += 1;
	}


}

void GameManager::Exit()
{
	sceneManager->Exit();
	delete sceneManager;
	sceneManager = 0;
}
