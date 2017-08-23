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

	collision = COLLISION; //Define.hの定数

	counter = COUNTER; //Define定数
	fire_rate = FIRE_RATE; //Define定数

	hostility_flag = true;

	for (int i = 0; i < BULLET_MAX; ++i) { //弾のインスタンス化
		bullet[i] = new Bullet(set_bullet_graphic_handle, hostility_flag);
	}
}

Enemy::~Enemy() {
	for (int i = 0; i < BULLET_MAX; ++i) { //newしたものはdelete
		delete bullet[i];
	}
}

void Enemy::Spawn(int set_x, int set_y, double set_angle) { //Actorクラスに書いても良い
	x = set_x;	       //
	y = set_y;		   //Playerの座標に引数に指定された値をそのまま代入
	angle = set_angle; //

	exist = true;
	hit_point = 100; //とりあえず
}

void Enemy::Update() {
	if (exist) {//生きているEnemyが対象
		Actor* point_object = actor_manager->Nealest_Actor(this); //Enemyが向かう方向のポインタを格納する変数＆初期化
																 //初期値はNealest_Actorの引数を与える
																 //thisとは自分自身のポインタのこと

		if (point_object != NULL) { //対象がいない場合はNULLを返す
									//逆に何かのポインタが入っていれば、そこに突進
			double point_x = point_object->Get_X();
			double point_y = point_object->Get_Y();

			angle = atan2(point_y - y, point_x - x); //atan2とは 基準点を(0,0)としたときの引数の座標への角度が返ってくる
		}

		x = static_cast<int>(x + cos(angle) * 3);// TODO: 敵によって移動速度を変える
												 // 60FPSとしたときに秒速180ピクセル移動
		y = static_cast<int>(y + sin(angle) * 3);//

		for (int i = 0; i < BULLET_MAX; ++i) { // 弾のアップデート
			bullet[i]->Update();
		}

		for (int i = 0; i < BULLET_MAX; ++i) { // 弾のアップデート
			if (!bullet[i]->Get_Exist()) {
				bullet[i]->Shot(x, y, angle);

				break;
			}
		}
	}
}