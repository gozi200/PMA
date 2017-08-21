#pragma once
#include"Actor.h"
#include"Define.h"

///////////////////////////////
//Actor���̂��̂��Ǘ�����N���X//
///////////////////////////////
class Actor_Manager {
private:
	Actor* actor[ACTOR_MAX]; //Actor�̃|�C���^�z���錾
					 
	bool gameover_flag;

	int score;

	int player_graphc_handle;
	int enemy_graphc_handle;
	int bullet_graphc_handle;
	int head_graphc_handle;

public:
	Actor_Manager(char*); //�v���C���[�̑���̓L�[�{�[�h���͂ɂȂ邽�߁A�����ɃL�[�m�F����������
	
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