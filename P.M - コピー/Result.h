#pragma once
#include"Scene_Manager.h"

class Result :public Scene {
public:
	Result(Scene_Manager* pManager):Scene(pManager){}

	~Result(){}

	void Update();
	void Render();
};