#pragma once
#include"Actor.h"

class Actor_Manager; //ヘッダーをインクルードしないのは、お互いに呼び合って生じる衝突を避けるため

class Player: public Actor {
private:
	char* key; //※１メインループから取得

public:
	Player(int, int, char*, Actor_Manager*); //Player(プレイヤーの画像ハンドル,弾の画像ハンドル,キーポインタ)
					 //※１charを指定することでメインループから取得
	~Player();

	void Spawn(int, int, double); //Actorで宣言した仮想関数を再宣言

	void Update();
};