#include"DxLib.h"
#include"Scene_Manager.h"
#include"Result.h"
#include"Title.h"

void Result::Update() {
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		scene_manager->scene = new Title(scene_manager); //現在のシーンにTitleシーンを代入
		delete this; //this...メンバ関数が実行された時のオブジェクトのポインタ　の解放
	}
}

void Result::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "リザルト画面");
	DrawFormatString(600, 360, GetColor(255, 255, 255), "↓を押してください");
}
