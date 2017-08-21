#pragma once

#include"Object.h"
#include"Bullet.h"
#include"Define.h"

////////////////////////////
//Player�N���X��Enemy�N���X���ꊇ�ŊǗ�����N���X

class Actor:public Object {
protected:
	Bullet* bullet[BULLET_MAX];

	int hit_point;//Actor�̗̑�

	float gravity;

public:
	virtual void Spawn(int,int,double) = 0; //������x���W�A�����W�A�p�x
	
	virtual void Update() = 0;

	void Hit(Bullet*); //�_���[�W�݂̂łȂ��A�e���̂��������邱�Ƃŏ�񂪑������Ƃ�(�����Ȃ�)�Ȃǂɂ��Ή�

	Bullet* GetBullet(int);

	void Render();

	void Render_Hit_Point();
};