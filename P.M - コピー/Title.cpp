#include"DxLib.h"
#include"Title.h"
#include"Scene_Manager.h"
#include"First_Stage.h"

void Title::Update() {
	if (CheckHitKey(KEY_INPUT_UP)) {
		scene_manager->scene = new First_Stage(scene_manager); //現在のシーンにGameシーンを代入
		delete this; //this...メンバ関数が実行された時のオブジェクトのポインタ　の解放
	}
}

void Title::Render() { //TODO: タイトル画面を作る
	DrawFormatString(0, 0, GetColor(255, 255, 255),"タイトル画面");
	DrawFormatString(600, 360, GetColor(255, 255, 255), "↑を押してください");
}