#include"Object.h"
#include"DxLib.h"
#include"Define.h"

Object::Object() :exist(false) {}

bool Object::Get_Exist() const{
	return exist;
}

int Object::Get_X() const{
	return x;
}

int Object::Get_Y() const{
	return y;
}

double Object::Get_Collision() const{
	return collision;
}

double Object::Get_Angle() const{
	return angle;
}

double Object::Get_Hostility_flag() const{
	return hostility_flag;;
}

void Object::Render() {
	if (exist) { //existがtrueの時のみ描画
		DrawRotaGraph(x, y, 1.0, angle + PI / 2, graphic_handle, TRUE, 0); //DXライブラリ関数(X座標,Y座標,拡大率,角度,画像ハンドル,透過,反転)
	}							//↑角度が右に90°回転してるため修正
}

void Object::Bullet_Render() {
	if (exist) { //existがtrueの時のみ描画
		DrawRotaGraph(x, y, 0.1, angle + PI / 2, graphic_handle, TRUE, 0); //DXライブラリ関数(X座標,Y座標,拡大率,角度,画像ハンドル,透過,反転)
	}							//↑角度が右に90°回転してるため修正
}