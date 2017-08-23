#include"Bullet.h"
#include"Define.h"

#include<cmath>

Bullet::Bullet(int set_bullet_graphic_handle, bool set_hostility_flag) {

	graphic_handle = set_bullet_graphic_handle;

	collision = COLLISION;

	damage = BULLET_POWER;;

	hostility_flag = set_hostility_flag;
}

void Bullet::Shot(int set_x, int set_y, double set_angle) {
	x = set_x;
	y = set_y;
	angle = set_angle;

	exist = true;
}

void Bullet::Update() {

	x = int(x + cos(angle) * 10); //TODO: 弾の種類によって弾の速度を変える
								  //60FPSで毎秒600ピクセル移動
	y = int(y + sin(angle) * 10); //

	if (x < 0 || WINDOW_X < x|| y < 0 || y > WINDOW_Y) { //TODO: 壁との当たり判定のところで消すので、ここのはとりあえずのもの
		exist = false;
	}
}

int Bullet::Get_Damage() {
	return damage;
}

void Bullet::Hit() {
	exist = false;
}