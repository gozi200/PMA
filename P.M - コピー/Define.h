
#pragma once
//Defineは名前空間を無視してしまい、衝突の危険があるため手間だがヘッダーを作成

//ゲームの内容的に絶対に変えない(変えてほしくない)値の宣言。includeすることで呼び出し可能。

//TODO: listかvetorにできるものはする

const double PI = 3.14159265358979323846; //円周率

const int KEY_NUMBER = 256; //全てのキー

const int WINDOW_X = 1280; //画面サイズ 横
const int WINDOW_Y = 720; //画面サイズ 縦

const int ACTOR_MAX = 256; //同時に出現できるActorの数 vectorにする？

const float COLLISION = 20.0; //当たり判定の幅

const int PLAYER_HP = 12; //体力(内訳３＊４)

const float PLAYER_SPEED = 5.0; //プレイヤーの移動速度

const int ENEMY_POWER = 3; //敵の攻撃力

const int BULLET_POWER = 1; //弾自体の攻撃力

const int BULLET_MAX = 50; //一度に飛ばせる弾の数