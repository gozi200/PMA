#pragma once
#include"Object.h"

//QOESTION: ���O�͉���

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