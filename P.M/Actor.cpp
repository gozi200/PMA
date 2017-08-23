#include"Actor.h"
#include"DxLib.h"
#include"Define.h"

void Actor::Hit(Bullet* set_bullet) {//BulletがActorにヒットしたときに呼ばれる
	hit_point -= set_bullet->Get_Damage();

	if (hit_point <= 0) {
		exist = false;
	}
}

Bullet* Actor::GetBullet(int i) { //判定時に呼び出される
	return bullet[i]; //引数の数値のインデックスのバレットを返す
}

void Actor::Render() {
	if (exist) {//存在フラグがtrueの時のみ

		//TODO: プレイヤーとエネミーの大きさを個別に変えられるように
		DrawRotaGraph(x, y, 0.5, angle + PI / 2, graphic_handle, TRUE, 0); //DXライブラリ関数(X座標,Y座標,拡大率,角度,画像ハンドル,透過,反転)

		for (int i = 1; i < BULLET_MAX; ++i) { //弾の描画も一括管理することで、多様な描画処理に対応
			bullet[i]->Bullet_Render();			   //TODO: 画像を読み込ませるヘッダーを作り読み込みは各１回ずつで済むように
		}
	}
}

void Actor::Render_Hit_Point() {
	if (exist) {
		int color;

		if (hostility_flag) {
			color = GetColor(255, 0, 0);//GetColor関数でRGB指定して色を取得
		}
		else {
			color = GetColor(0, 255, 0);
		}

		DrawBox(x - 10, y - 20, x + 10,					y - 17, GetColor(0, 0, 0), FALSE);
		DrawBox(x - 10, y - 20, x - 10 + hit_point / 5, y - 17, color, TRUE);
	}
}