#pragma once
#include"Object.h"

//QOESTION: 名前は仮で

class Bullet : public Object {
private:
	int damage;

public:
	Bullet(int, bool);

	void Shot(int, int, double);

	void Update();

	int Get_Damage();

	void Hit();
};