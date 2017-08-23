#include"Actor.h"
#include"DxLib.h"
#include"Define.h"

void Actor::Hit(Bullet* set_bullet) {//Bullet��Actor�Ƀq�b�g�����Ƃ��ɌĂ΂��
	hit_point -= set_bullet->Get_Damage();

	if (hit_point <= 0) {
		exist = false;
	}
}

Bullet* Actor::GetBullet(int i) { //���莞�ɌĂяo�����
	return bullet[i]; //�����̐��l�̃C���f�b�N�X�̃o���b�g��Ԃ�
}

void Actor::Render() {
	if (exist) {//���݃t���O��true�̎��̂�

		//TODO: �v���C���[�ƃG�l�~�[�̑傫�����ʂɕς�����悤��
		DrawRotaGraph(x, y, 0.5, angle + PI / 2, graphic_handle, TRUE, 0); //DX���C�u�����֐�(X���W,Y���W,�g�嗦,�p�x,�摜�n���h��,����,���])

		for (int i = 1; i < BULLET_MAX; ++i) { //�e�̕`����ꊇ�Ǘ����邱�ƂŁA���l�ȕ`�揈���ɑΉ�
			bullet[i]->Bullet_Render();			   //TODO: �摜��ǂݍ��܂���w�b�_�[�����ǂݍ��݂͊e�P�񂸂ōςނ悤��
		}
	}
}

void Actor::Render_Hit_Point() {
	if (exist) {
		int color;

		if (hostility_flag) {
			color = GetColor(255, 0, 0);//GetColor�֐���RGB�w�肵�ĐF���擾
		}
		else {
			color = GetColor(0, 255, 0);
		}

		DrawBox(x - 10, y - 20, x + 10,					y - 17, GetColor(0, 0, 0), FALSE);
		DrawBox(x - 10, y - 20, x - 10 + hit_point / 5, y - 17, color, TRUE);
	}
}