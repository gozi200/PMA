#include"DxLib.h"
#include"Result.h"
#include"First_Stage.h"
#include"Actor_Manager.h"

void First_Stage::Update() {
	Game();

	if (CheckHitKey(KEY_INPUT_Y)) { //�{���� actor_manager->Get_Gameover_Flag() ������
		scene_manager->scene = new Result(scene_manager); //���݂̃V�[����Result�V�[������
		delete this; //this...�����o�֐������s���ꂽ���̃I�u�W�F�N�g�̃|�C���^�@�̉��
	}
}

void First_Stage::Render() {// �Q�[����ʂ����
	scenery->Stage_1(); //�Ƃ肠�����@
	DrawFormatString(0, 0, GetColor(0, 0, 0), "�Q�[�����");
	DrawFormatString(600, 360, GetColor(0, 0, 0), "Y�������Ă�������");
}

void First_Stage::Game() { //�X�e�[�W�P�̓��e�������ɏ����Ă������I

///////////////�������S�̓I�ɂ��܂����f����ĂȂ��H
	actor_manager->Judge();
	actor_manager->Update();
	actor_manager->Render();
	actor_manager->Render_Hp();
//////////////�X�R�A�͏o�邪�AHP��v���C���[�A�G�͏o�Ȃ��B
	
}