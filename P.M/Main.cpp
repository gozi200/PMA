#include"DxLib.h"
#include"Title.h"
#include"Define.h"
#include"Actor_Manager.h"
#include"Scene_Manager.h"

/////�L�[�̓��͏�Ԃ��X�V����
int UpdateKey(char* key) {
	char tmpKey[KEY_NUMBER]; //���݂̃L�[�̓��͏�Ԃ����[

/////�S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < KEY_NUMBER; ++i) {
		if (tmpKey[i] != 0) { //i�Ԗڂ̃L�[��������Ă�������Z
			++key[i];
		}
		else { //������Ă��Ȃ����0��
			key[i] = 0;
		}
	}
	return 0;
}

/////////������false�Ȃ烋�[�v�𔲂��A�Q�[���I��
bool Process(char key[256]) {
	if (ScreenFlip())return false; //����ʂƓ���ւ���
	if (ProcessMessage())return false; //windows����̐����m�F�������ōs��
	if (ClearDrawScreen())return false; //���݂����ʂ̗���ʂ�����
	if (GetHitKeyStateAll(key))return false; //�L�[�{�[�h�̓��͂��擾
	
	return true;
}
////////

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR,int) {//win32�Ȃ̂�WinMain
	ChangeWindowMode(true);//windowmode��
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);//�E�B���h�E�̉�ʂ̑傫���Ǝg�p����F�̏���
	if (DxLib_Init() == -1)return -1;// �c�w���C�u�������������� �G���[���N�����璼���ɏI��
	SetWindowText("P.M"); //�E�B���h�E�^�C�g��
	
	char key[KEY_NUMBER]; //�L�[�擾

	SetDrawScreen(DX_SCREEN_BACK); //�������ɗ���ʂɕ`��

	Scene_Manager* scene_manager; //�Ǘ��V�X�e���𓮓I�m��

	scene_manager = new Scene_Manager(key);

	scene_manager->scene = new Title(scene_manager); //�^�C�g���𓮓I�m��

	while (ProcessMessage() != -1) {
		int startTime = GetNowCount();
		ScreenFlip();
		ClearDrawScreen();

		//�Q�[�����[�v
		scene_manager->Render();
		scene_manager->Update();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;

		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - startTime));
	}

	//�N���X�̉��
	delete scene_manager;

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}