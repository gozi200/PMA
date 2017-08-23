#include"DxLib.h"
#include"Title.h"
#include"Scene_Manager.h"
#include"First_Stage.h"

void Title::Update() {
	if (CheckHitKey(KEY_INPUT_UP)) {
		scene_manager->scene = new First_Stage(scene_manager); //���݂̃V�[����Game�V�[������
		delete this; //this...�����o�֐������s���ꂽ���̃I�u�W�F�N�g�̃|�C���^�@�̉��
	}
}

void Title::Render() { //TODO: �^�C�g����ʂ����
	DrawFormatString(0, 0, GetColor(255, 255, 255),"�^�C�g�����");
	DrawFormatString(600, 360, GetColor(255, 255, 255), "���������Ă�������");
}