#pragma once

#include"Object.h"
#include"Bullet.h"
#include"Define.h"

////////////////////////////
//PlayerクラスとEnemyクラスを一括で管理するクラス

class Actor:public Object {
protected:
	Bullet* bullet[BULLET_MAX];

	int hit_point;//Actorの体力

	float gravity;

public:
	virtual void Spawn(int,int,double) = 0; //引数はx座標、ｙ座標、角度
	
	virtual void Update() = 0;

	void Hit(Bullet*); //ダメージのみでなく、弾自体を持たせることで情報が増えたとき(属性など)などにも対応

	Bullet* GetBullet(int);

	void Render();

	void Render_Hit_Point();
};