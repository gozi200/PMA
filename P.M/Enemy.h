#pragma once
#include"Actor.h"

class Actor_Manager; //�w�b�_�[���C���N���[�h���Ȃ��̂́A���݂��ɌĂэ����Đ�����Փ˂�����邽��

class Enemy : public Actor {
public:
	int counter;
	int fire_rate;

	Enemy(int, int, Actor_Manager*); //Enemy(�v���C���[�̉摜�n���h��,�e(��)�̉摜�n���h��,�L�[�|�C���^)

	~Enemy();

	void Spawn(int, int, double); //Actor�Ő錾�������z�֐����Đ錾

	void Update();
};