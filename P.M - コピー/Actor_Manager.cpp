#include"DxLib.h"
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include "Actor_Manager.h"

//////////////////////////////////////////////////////////
//TODO: ここではなく、リソース管理クラスを作成して、画像やサウンドを一括で管理するとロードの短縮が可能

Actor_Manager::Actor_Manager(char* set_key) :gameover_flag(false), score(0) { //画像のロード
	player_graphc_handle = LoadGraph("Picture/Enemy.png",0); //""の中にファイル名
	enemy_graphc_handle = LoadGraph("Picture/DamageEnemy.png",0);
	bullet_graphc_handle = LoadGraph("", 0);
	head_graphc_handle = LoadGraph("", 0);

	actor[0] = new Player(player_graphc_handle, head_graphc_handle, set_key, this); //Actor(player)のインスタンス化

	for (int i = 1; i < ACTOR_MAX; ++i) {
		actor[i] = new Enemy(enemy_graphc_handle, bullet_graphc_handle, this); //Actor(enemy)のインスタンス化
	}
}

//////////////////////////////////////////////////////////

Actor_Manager::~Actor_Manager() { //解放
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

void Actor_Manager::Game_Init() { //ゲーム開示時のプレイヤーの座標
	actor[0]->Spawn(WINDOW_X /2, WINDOW_Y /2, -PI / 2);
}
void Actor_Manager::Update() { //ActorのUpdate関数の呼び出しとイベント(敵の発生など)の発生
	for (int i = 0; i < ACTOR_MAX; ++i) {
		actor[i]->Update();
	}
	//////////////////////////////////////////////////////////////////////////
	//とりあえずランダムで敵を生成。ここで敵の配置を行う
	int spawn = GetRand(254-2) + 1;
	int dice = GetRand(30);

	if (dice == 1) {
		if (!actor[spawn]->Get_Exist()) {
			actor[spawn]->Spawn(GetRand(WINDOW_X), 20, PI / 2);
		}
	}
	/////////////////////////////////////////////////////////////////////////
	//github test
	if (!actor[0]->Get_Exist()) { //プレイヤーが死んだとき
		gameover_flag = true;
	}
}

void Actor_Manager::Render() {
	for (int i = 0; i < ACTOR_MAX; ++i) {
		actor[i]->Render();
	}
	DrawFormatString(0, 20, GetColor(0, 0, 0), "Score:%d", score);
}

void Actor_Manager::Render_Hp() { //hit_pointの描画
		actor[0]->Render_Hit_Point();
}

void Actor_Manager::Judge() { //当たり判定(ここではHit関数を呼ぶだけ)
///////////////////////////////////////////////////////////////
//TODO: もっといい書き方無いかなぁ？

	for (int i = 0; i < ACTOR_MAX; ++i) { //全actorの確認(弾を撃つ方）
		if (actor[i]->Get_Exist()) {

			for (int j = 0; j < BULLET_MAX; ++j) { //全ての弾の確認
				if (actor[i]->GetBullet(j)->Get_Exist()) {

					for (int k = 0; k < ACTOR_MAX; ++k) { //全actorの確認(弾を撃たれるほう)
						if (actor[k]->Get_Exist()) {
							if (actor[i]->Get_Hostility_flag() != actor[i]->Get_Hostility_flag()) { //同士討ち回避

								int bullet_x = actor[i]->GetBullet(j)->Get_X();
								int bullet_y = actor[i]->GetBullet(j)->Get_Y();
								double bullet_collision = actor[i]->GetBullet(j)->Get_Collision();

								int target_x = actor[k]->Get_X();
								int target_y = actor[k]->Get_Y();
								double target_collision = actor[k]->Get_Collision();

								if ((bullet_x - target_x)*(bullet_x - target_x) + (bullet_y - target_y) * (bullet_y - target_y) < //とりあえず円と円での当たり判定(距離<　半径*半径)
									(bullet_collision + target_collision) * (bullet_collision + target_collision)) { //√a^2 + b^2 でif文用に直すと (bx - tx)^2 + (by - ty)^2 > (b_collision + t_collision)^2 となる

									actor[k]->Hit(actor[i]->GetBullet(j));
									actor[i]->GetBullet(j)->Hit();
									score += 100; //とりあえず
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

										//↓Objectクラスを継承したクラスなら引数にすることが可能
Actor * Actor_Manager::Nealest_Actor(Object* reqest_object) { //プレイヤーに一番近いactorを返す
															 //その他の条件として、hostilityが異なっているObject
															 //　　　　　　　　　　遠すぎる敵は無視
															 //　　　　　　　　　　該当するものがない場合はNULLを返す
	Actor* return_actor = NULL;
	int range = -1; //一番近くにいるActor同士の距離の変数

	int reqest_x = reqest_object->Get_X();
	int reqest_y = reqest_object->Get_Y();

	for (int i = 0; i < ACTOR_MAX; ++i) { //条件に合うものを探す
		if (actor[i]->Get_Exist()) {
			if (reqest_object->Get_Hostility_flag() != actor[i]->Get_Hostility_flag()) { //reqest_objectが敵対してるものに絞り込み
				int target_x = actor[i]->Get_X();
				int target_y = actor[i]->Get_Y();
				 
				//targetとreqest_objectの距離
				int tmp_range = (target_x - reqest_x) * (target_x - reqest_x) + 
								(target_y - reqest_y) * (target_y - reqest_y);
			
				if (range != -1) {
					if (tmp_range < range) { //tmp_rangeとrangeを比較して小さいほうをrangeに入れる
						range = tmp_range;
						return_actor = actor[i]; //actorの数だけ繰り返す
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