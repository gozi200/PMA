#include"DxLib.h"
#include"Scene_Manager.h"
#include"Result.h"
#include"Title.h"

void Result::Update() {
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		scene_manager->scene = new Title(scene_manager); //���݂̃V�[����Title�V�[������
		delete this; //this...�����o�֐������s���ꂽ���̃I�u�W�F�N�g�̃|�C���^�@�̉��
	}
}

void Result::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "���U���g���");
	DrawFormatString(600, 360, GetColor(255, 255, 255), "���������Ă�������");
}
