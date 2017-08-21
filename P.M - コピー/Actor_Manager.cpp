#include"DxLib.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include "Actor_Manager.h"

//////////////////////////////////////////////////////////
//TODO: �����ł͂Ȃ��A���\�[�X�Ǘ��N���X���쐬���āA�摜��T�E���h���ꊇ�ŊǗ�����ƃ��[�h�̒Z�k���\

Actor_Manager::Actor_Manager(char* set_key) :gameover_flag(false), score(0) { //�摜�̃��[�h
	player_graphc_handle = LoadGraph("Picture/Enemy.png",0); //""�̒��Ƀt�@�C����
	enemy_graphc_handle = LoadGraph("Picture/DamageEnemy.png",0);
	bullet_graphc_handle = LoadGraph("", 0);
	head_graphc_handle = LoadGraph("", 0);

	actor[0] = new Player(player_graphc_handle, head_graphc_handle, set_key, this); //Actor(player)�̃C���X�^���X��

	for (int i = 1; i < ACTOR_MAX; ++i) {
		actor[i] = new Enemy(enemy_graphc_handle, bullet_graphc_handle, this); //Actor(enemy)�̃C���X�^���X��
	}
}

//////////////////////////////////////////////////////////

Actor_Manager::~Actor_Manager() { //���
	for (int i = 0; i < ACTOR_MAX; ++i) {
		delete actor[i];
	}
}

bool Actor_Manager::Get_Gameover_Flag() {
	return gameover_flag;
}

int  Actor_Manager::Get_Score() {
	return score;
}

void Actor_Manager::Game_Init() { //�Q�[���J�����̃v���C���[�̍��W
	actor[0]->Spawn(WINDOW_X /2, WINDOW_Y /2, -PI / 2);
}
void Actor_Manager::Update() { //Actor��Update�֐��̌Ăяo���ƃC�x���g(�G�̔����Ȃ�)�̔���
	for (int i = 0; i < ACTOR_MAX; ++i) {
		actor[i]->Update();
	}
	//////////////////////////////////////////////////////////////////////////
	//�Ƃ肠���������_���œG�𐶐��B�����œG�̔z�u���s��
	int spawn = GetRand(254-2) + 1;
	int dice = GetRand(30);

	if (dice == 1) {
		if (!actor[spawn]->Get_Exist()) {
			actor[spawn]->Spawn(GetRand(WINDOW_X), 20, PI / 2);
		}
	}
	/////////////////////////////////////////////////////////////////////////
	//github test
	if (!actor[0]->Get_Exist()) { //�v���C���[�����񂾂Ƃ�
		gameover_flag = true;
	}
}

void Actor_Manager::Render() {
	for (int i = 0; i < ACTOR_MAX; ++i) {
		actor[i]->Render();
	}
	DrawFormatString(0, 20, GetColor(0, 0, 0), "Score:%d", score);
}

void Actor_Manager::Render_Hp() { //hit_point�̕`��
		actor[0]->Render_Hit_Point();
}

void Actor_Manager::Judge() { //�����蔻��(�����ł�Hit�֐����ĂԂ���)
///////////////////////////////////////////////////////////////
//TODO: �����Ƃ����������������Ȃ��H

	for (int i = 0; i < ACTOR_MAX; ++i) { //�Sactor�̊m�F(�e�������j
		if (actor[i]->Get_Exist()) {

			for (int j = 0; j < BULLET_MAX; ++j) { //�S�Ă̒e�̊m�F
				if (actor[i]->GetBullet(j)->Get_Exist()) {

					for (int k = 0; k < ACTOR_MAX; ++k) { //�Sactor�̊m�F(�e���������ق�)
						if (actor[k]->Get_Exist()) {
							if (actor[i]->Get_Hostility_flag() != actor[i]->Get_Hostility_flag()) { //���m�������

								int bullet_x = actor[i]->GetBullet(j)->Get_X();
								int bullet_y = actor[i]->GetBullet(j)->Get_Y();
								double bullet_collision = actor[i]->GetBullet(j)->Get_Collision();

								int target_x = actor[k]->Get_X();
								int target_y = actor[k]->Get_Y();
								double target_collision = actor[k]->Get_Collision();

								if ((bullet_x - target_x)*(bullet_x - target_x) + (bullet_y - target_y) * (bullet_y - target_y) < //�Ƃ肠�����~�Ɖ~�ł̓����蔻��(����<�@���a*���a)
									(bullet_collision + target_collision) * (bullet_collision + target_collision)) { //��a^2 + b^2 ��if���p�ɒ����� (bx - tx)^2 + (by - ty)^2 > (b_collision + t_collision)^2 �ƂȂ�

									actor[k]->Hit(actor[i]->GetBullet(j));
									actor[i]->GetBullet(j)->Hit();
									score += 100; //�Ƃ肠����
								}
							}
						}
					}
				}
			}
		}
	}
}
//////////////////////////////////////////////////////////////////

										//��Object�N���X���p�������N���X�Ȃ�����ɂ��邱�Ƃ��\
Actor * Actor_Manager::Nealest_Actor(Object* reqest_object) { //�v���C���[�Ɉ�ԋ߂�actor��Ԃ�
															 //���̑��̏����Ƃ��āAhostility���قȂ��Ă���Object
															 //�@�@�@�@�@�@�@�@�@�@��������G�͖���
															 //�@�@�@�@�@�@�@�@�@�@�Y��������̂��Ȃ��ꍇ��NULL��Ԃ�
	Actor* return_actor = NULL;
	int range = -1; //��ԋ߂��ɂ���Actor���m�̋����̕ϐ�

	int reqest_x = reqest_object->Get_X();
	int reqest_y = reqest_object->Get_Y();

	for (int i = 0; i < ACTOR_MAX; ++i) { //�����ɍ������̂�T��
		if (actor[i]->Get_Exist()) {
			if (reqest_object->Get_Hostility_flag() != actor[i]->Get_Hostility_flag()) { //reqest_object���G�΂��Ă���̂ɍi�荞��
				int target_x = actor[i]->Get_X();
				int target_y = actor[i]->Get_Y();
				 
				//target��reqest_object�̋���
				int tmp_range = (target_x - reqest_x) * (target_x - reqest_x) + 
								(target_y - reqest_y) * (target_y - reqest_y);
			
				if (range != -1) {
					if (tmp_range < range) { //tmp_range��range���r���ď������ق���range�ɓ����
						range = tmp_range;
						return_actor = actor[i]; //actor�̐������J��Ԃ�
					}
				}
				else {
					range = tmp_range;
					return_actor = actor[i];
				}
			}
		}
	}
	return return_actor;
}