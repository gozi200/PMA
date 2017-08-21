#include"DxLib.h"
#include"Result.h"
#include"First_Stage.h"
#include"Actor_Manager.h"

void First_Stage::Update() {
	Game();

	if (CheckHitKey(KEY_INPUT_Y)) { //本当は actor_manager->Get_Gameover_Flag() を入れる
		scene_manager->scene = new Result(scene_manager); //現在のシーンにResultシーンを代入
		delete this; //this...メンバ関数が実行された時のオブジェクトのポインタ　の解放
	}
}

void First_Stage::Render() {// ゲーム画面を作る
	scenery->Stage_1(); //とりあえず　
	DrawFormatString(0, 0, GetColor(0, 0, 0), "ゲーム画面");
	DrawFormatString(600, 360, GetColor(0, 0, 0), "Yを押してください");
}

void First_Stage::Game() { //ステージ１の内容をここに書いていこう！

///////////////ここが全体的にうまく反映されてない？
	actor_manager->Judge();
	actor_manager->Update();
	actor_manager->Render();
	actor_manager->Render_Hp();
//////////////スコアは出るが、HPやプレイヤー、敵は出ない。
	
}