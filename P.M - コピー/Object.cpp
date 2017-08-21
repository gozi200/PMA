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
	if (exist) { //exist‚ªtrue‚Ì‚Ì‚İ•`‰æ
		DrawRotaGraph(x, y, 1.0, angle + PI / 2, graphic_handle, TRUE, 0); //DXƒ‰ƒCƒuƒ‰ƒŠŠÖ”(XÀ•W,YÀ•W,Šg‘å—¦,Šp“x,‰æ‘œƒnƒ“ƒhƒ‹,“§‰ß,”½“])
	}							//ªŠp“x‚ª‰E‚É90‹‰ñ“]‚µ‚Ä‚é‚½‚ßC³
}
