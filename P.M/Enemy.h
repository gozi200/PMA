#pragma once
#include"Actor.h"

class Actor_Manager; //ヘッダーをインクルードしないのは、お互いに呼び合って生じる衝突を避けるため

class Enemy : public Actor {
public:
	int counter;
	int fire_rate;

	Enemy(int, int, Actor_Manager*); //Enemy(プレイヤーの画像ハンドル,弾(頭)の画像ハンドル,キーポインタ)

	~Enemy();

	void Spawn(int, int, double); //Actorで宣言した仮想関数を再宣言

	void Update();
};