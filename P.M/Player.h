#pragma once
#include"Actor.h"

class Actor_Manager; //�w�b�_�[���C���N���[�h���Ȃ��̂́A���݂��ɌĂэ����Đ�����Փ˂�����邽��

class Player: public Actor {
private:
	char* key; //���P���C�����[�v����擾

public:
	Player(int, int, char*, Actor_Manager*); //Player(�v���C���[�̉摜�n���h��,�e�̉摜�n���h��,�L�[�|�C���^)
					 //���Pchar���w�肷�邱�ƂŃ��C�����[�v����擾
	~Player();

	void Spawn(int, int, double); //Actor�Ő錾�������z�֐����Đ錾

	void Update();
};