#pragma once

class Actor_Manager; //Actor_Manager�̓v���C���[�ɂ��G�ɂ��e�ɂ����ɂ��K�v�Ȃ̂ŁA���N���X�ɐ錾

class Object {
protected:
	bool exist; //���݃t���O

	int x; //���W�@��
	int y; //���W�@�c
	double angle;  //�p�x

	double collision;//�����蔻��

	bool hostility_flag; //�G�ӁA�G���̈Ӂ@true��false�̂ݍU���\�B�t���R��B
	
	int graphic_handle; //�ǂݍ��񂾉摜��\������̂Ɏg�p

	Actor_Manager* actor_manager; //�O���錾�ɓ���

public:
	Object();

	virtual void Update() = 0; //���S���z�֐�(����`�֐�) �֐��̖����Ɂ��O�����Đ錾�B
							   //�p�����ł͒�`�ł����A�p����̃N���X�ŕK���Đ錾�y�ђ�`���Ȃ���΂Ȃ�Ȃ��B
							   //���܂�́u�p�������N���X����`����̂ŁA���̃N���X�ł͒�`���܂���v�Ƃ������ƁB

/////////////////////////////////
////const��t���邱�ƂŁA�����o�ϐ��̒l��ς��Ȃ����Ƃ��
////�擪�ł͂Ȃ������ɕt���邱�ƂŃI�u�W�F�N�g�̕ύX�͕s�\�����A���\�b�h�Ăяo���Ȃ�\��

	bool Get_Exist()const;

	int Get_X()const;
	int Get_Y()const;
	double Get_Angle()const;

	double Get_Collision()const;

	double Get_Hostility_flag()const;

////////////////////////////////

	virtual void Render();

};