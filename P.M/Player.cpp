#include"Player.h"
#include"DxLib.h"
#include"Define.h"
#include"Actor_Manager.h"

Player::Player(int set_actor_graphic_handle,
			   int set_head_graphic_handle,
		   	   char set_key[KEY_NUMBER],
			   Actor_Manager* set_actor_manager) {

	key = set_key;
	graphic_handle = set_actor_graphic_handle;
	actor_manager = set_actor_manager;

	collision = COLLISION; //Define.h�̒萔

	hostility_flag = false;

	bullet[0] = new Bullet(set_head_graphic_handle,hostility_flag);	//bullet�̃C���X�^���X��
}

Player::~Player() {
	delete	bullet[0]; //new�������̂�delete
}

void Player::Spawn(int set_x, int set_y, double set_angle) { //Actor�N���X�ɏ����Ă��ǂ�
	x = set_x;	       //
	y = set_y;		   //Player�̍��W�Ɉ����Ɏw�肳�ꂽ�l�����̂܂ܑ��
	angle = set_angle; //

	exist = true;
	hit_point = PLAYER_HP; //Define.h�̒萔
}

void Player::Update() {
	bullet[0]->Update(); //�e�̃A�b�v�f�[�g

//////////////////////////////////////////////////
//TODO: �L�[�����Controller�N���X(��)�����

		//�E�Ɉړ�
	if (key[KEY_INPUT_LEFT] == 1) {
		if (x > 0) {
			x += static_cast<int>(PLAYER_SPEED);
		}
	}

	//���Ɉړ�
	if (key[KEY_INPUT_RIGHT] == 1) {
		if (x < WINDOW_X) {
			x -= static_cast<int>(PLAYER_SPEED);
		}
	}

	//�W�����v
	if (key[KEY_INPUT_SPACE] == 1) {
		//�W�����v�̏���
	}

	//Shot(������)
	if (key[KEY_INPUT_Z] == 1) {
		if (!bullet[0]->Get_Exist()) {
			bullet[0]->Shot(x, y, angle);
		}
	}

	//�U��(���H)
	if (key[KEY_INPUT_X == 1]) {

	}
	///////////////////////////////////////////////////////
}
