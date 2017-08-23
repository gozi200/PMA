#include"Enemy.h"
#include"DxLib.h"
#include"Define.h"
#include"Actor_Manager.h"

#include<cmath>

Enemy::Enemy(int set_actor_graphic_handle,
	int set_bullet_graphic_handle,
	Actor_Manager* set_actor_manager) {

	graphic_handle = set_actor_graphic_handle;

	actor_manager = set_actor_manager;

	collision = COLLISION; //Define.h�̒萔

	counter = COUNTER; //Define�萔
	fire_rate = FIRE_RATE; //Define�萔

	hostility_flag = true;

	for (int i = 0; i < BULLET_MAX; ++i) { //�e�̃C���X�^���X��
		bullet[i] = new Bullet(set_bullet_graphic_handle, hostility_flag);
	}
}

Enemy::~Enemy() {
	for (int i = 0; i < BULLET_MAX; ++i) { //new�������̂�delete
		delete bullet[i];
	}
}

void Enemy::Spawn(int set_x, int set_y, double set_angle) { //Actor�N���X�ɏ����Ă��ǂ�
	x = set_x;	       //
	y = set_y;		   //Player�̍��W�Ɉ����Ɏw�肳�ꂽ�l�����̂܂ܑ��
	angle = set_angle; //

	exist = true;
	hit_point = 100; //�Ƃ肠����
}

void Enemy::Update() {
	if (exist) {//�����Ă���Enemy���Ώ�
		Actor* point_object = actor_manager->Nealest_Actor(this); //Enemy�������������̃|�C���^���i�[����ϐ���������
																 //�����l��Nealest_Actor�̈�����^����
																 //this�Ƃ͎������g�̃|�C���^�̂���

		if (point_object != NULL) { //�Ώۂ����Ȃ��ꍇ��NULL��Ԃ�
									//�t�ɉ����̃|�C���^�������Ă���΁A�����ɓːi
			double point_x = point_object->Get_X();
			double point_y = point_object->Get_Y();

			angle = atan2(point_y - y, point_x - x); //atan2�Ƃ� ��_��(0,0)�Ƃ����Ƃ��̈����̍��W�ւ̊p�x���Ԃ��Ă���
		}

		x = static_cast<int>(x + cos(angle) * 3);// TODO: �G�ɂ���Ĉړ����x��ς���
												 // 60FPS�Ƃ����Ƃ��ɕb��180�s�N�Z���ړ�
		y = static_cast<int>(y + sin(angle) * 3);//

		for (int i = 0; i < BULLET_MAX; ++i) { // �e�̃A�b�v�f�[�g
			bullet[i]->Update();
		}

		for (int i = 0; i < BULLET_MAX; ++i) { // �e�̃A�b�v�f�[�g
			if (!bullet[i]->Get_Exist()) {
				bullet[i]->Shot(x, y, angle);

				break;
			}
		}
	}
}