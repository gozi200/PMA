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

	collision = COLLISION; //Define.hの定数

	hostility_flag = false;

	bullet[0] = new Bullet(set_head_graphic_handle,hostility_flag);	//bulletのインスタンス化
}

Player::~Player() {
	delete	bullet[0]; //newしたものはdelete
}

void Player::Spawn(int set_x, int set_y, double set_angle) { //Actorクラスに書いても良い
	x = set_x;	       //
	y = set_y;		   //Playerの座標に引数に指定された値をそのまま代入
	angle = set_angle; //

	exist = true;
	hit_point = PLAYER_HP; //Define.hの定数
}

void Player::Update() {
	bullet[0]->Update(); //弾のアップデート

//////////////////////////////////////////////////
//TODO: キー操作はControllerクラス(仮)を作る

		//右に移動
	if (key[KEY_INPUT_LEFT] == 1) {
		if (x > 0) {
			x += static_cast<int>(PLAYER_SPEED);
		}
	}

	//左に移動
	if (key[KEY_INPUT_RIGHT] == 1) {
		if (x < WINDOW_X) {
			x -= static_cast<int>(PLAYER_SPEED);
		}
	}

	//ジャンプ
	if (key[KEY_INPUT_SPACE] == 1) {
		//ジャンプの処理
	}

	//Shot(頭投げ)
	if (key[KEY_INPUT_Z] == 1) {
		if (!bullet[0]->Get_Exist()) {
			bullet[0]->Shot(x, y, angle);
		}
	}

	//攻撃(剣？)
	if (key[KEY_INPUT_X == 1]) {

	}
	///////////////////////////////////////////////////////
}
