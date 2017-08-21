#pragma once
#include"Actor.h"
#include"Define.h"

///////////////////////////////
//Actorそのものを管理するクラス//
///////////////////////////////
class Actor_Manager {
private:
	Actor* actor[ACTOR_MAX]; //Actorのポインタ配列を宣言
					 
	bool gameover_flag;

	int score;

	int player_graphc_handle;
	int enemy_graphc_handle;
	int bullet_graphc_handle;
	int head_graphc_handle;

public:
	Actor_Manager(char*); //プレイヤーの操作はキーボード入力になるため、引数にキー確認を持たせる
	
	~Actor_Manager();
	
	bool Get_Gameover_Flag();
	
	int Get_Score();
	
	void Game_Init();
	
	void Update();
	
	void Render();
	
	void Render_Hp();
	
	void Judge();
	
	Actor* Nealest_Actor(Object*);
};