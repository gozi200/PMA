#pragma once
#include"DxLib.h"

class Scenery {
public:
	int x;
	int y;
	int graphic_handle;

	Scenery() {
		x = 0;
		y = 0;

		graphic_handle = LoadGraph("Picture/Scenery.png",0); //DX���C�u�����̊֐�
	}

	void Stage_1();
};