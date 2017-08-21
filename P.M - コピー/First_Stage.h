#pragma once
#include"Scenery.h"
#include"Scene_Manager.h"
#include"Actor_Manager.h"

class First_Stage:public Scene {
public:
	char key[KEY_NUMBER]; //ƒL[æ“¾

	Actor_Manager* actor_manager;
	Scenery* scenery;

	First_Stage(Scene_Manager* pManager):Scene(pManager){
		actor_manager = new Actor_Manager(key);
		scenery = new Scenery();
	}

	~First_Stage(){
		delete actor_manager;
		delete scenery;
	}

	void Update();
	void Render();

	void Game();
};