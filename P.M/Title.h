#pragma once
#include"Scene_Manager.h"

class Title :public Scene {
public:
	Title(Scene_Manager* pManager) :Scene(pManager){}

	~Title(){}

	void Update();
	void Render();
};