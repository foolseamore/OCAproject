#include "HpUI.h"
//#include "BaseObject.h"
#include "GameManager.h"


HpUI::HpUI()
{
}


HpUI::~HpUI()
{
}

void HpUI::Init()
{
	
	rgb = Color(0, 255, 0);
	damage = 0;
	img_c = 0;
	hp_img = GameManager::Instance().GetEarthHp(); 
	hpbar_img = GameManager::Instance().GetHpBar();
	hpwords_img = GameManager::Instance().GetHpWords();
	number_img = GameManager::Instance().GetNumber();
	Game_hp = GameManager::Instance().GetHp();

	for (int i = 2; i >= 0; i--)
	{
		g_hp[i].cnt = 0;
		g_hp[i].pos.x = 806 - 38 * i;
		g_hp[i].pos.y = 507;
	}	
}
void HpUI::Update()
{
	Game_hp = GameManager::Instance().GetHp();
	Decimal_Count(g_hp, 3, Game_hp);
	ColorControl();
	hpbar_img.drawAt(750, 650);
	hpwords_img.draw(640, 510,rgb);
	DrawAnime(hp_img, 73, 5, 1,2.5f, 64, 64.f, 750, 650.f);
	for (int i = 0; i < 3; i++)
	{
		number_img(38 * g_hp[i].cnt,0, 38, 38).draw(g_hp[i].pos.x, g_hp[i].pos.y,rgb);
	}

}
void HpUI::Exit()
{

}
void HpUI::DrawAnime(Texture texture,int max_frame, int frame, int speed,float scalerate, int sizex, float sizey,int getx,float gety)
{

	img_c = img_c + speed;

	texture((img_c / frame) % max_frame*sizex, (damage/100)*64, sizex, sizey- (damage/100)*64).scaled(scalerate).drawAt(getx,gety+ (damage/100)*80);

}
void HpUI::ColorControl()
{
	if (Game_hp == 50)
	{
		rgb = Color(255, 255, 0);
	}
	else if (Game_hp <= 30)
	{

		rgb = Color(255, 255 - (damage - 50) * 5, 0);
	}
}