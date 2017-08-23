#include"DxLib.h"
#include"Title.h"
#include"Define.h"
#include"Actor_Manager.h"
#include"Scene_Manager.h"

/////キーの入力状態を更新する
int UpdateKey(char* key) {
	char tmpKey[KEY_NUMBER]; //現在のキーの入力状態を収納

/////全てのキーの入力状態を得る
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < KEY_NUMBER; ++i) {
		if (tmpKey[i] != 0) { //i番目のキーが押されていたら加算
			++key[i];
		}
		else { //押されていなければ0に
			key[i] = 0;
		}
	}
	return 0;
}

/////////ここがfalseならループを抜け、ゲーム終了
bool Process(char key[256]) {
	if (ScreenFlip())return false; //裏画面と入れ替える
	if (ProcessMessage())return false; //windowsからの生存確認を自動で行う
	if (ClearDrawScreen())return false; //現在いる画面の裏画面を消去
	if (GetHitKeyStateAll(key))return false; //キーボードの入力を取得
	
	return true;
}
////////

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR,int) {//win32なのでWinMain
	ChangeWindowMode(true);//windowmodeに
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);//ウィンドウの画面の大きさと使用する色の情報量
	if (DxLib_Init() == -1)return -1;// ＤＸライブラリ初期化処理 エラーが起きたら直ちに終了
	SetWindowText("P.M"); //ウィンドウタイトル
	
	char key[KEY_NUMBER]; //キー取得

	SetDrawScreen(DX_SCREEN_BACK); //処理中に裏画面に描画

	Scene_Manager* scene_manager; //管理システムを動的確保

	scene_manager = new Scene_Manager(key);

	scene_manager->scene = new Title(scene_manager); //タイトルを動的確保

	while (ProcessMessage() != -1) {
		int startTime = GetNowCount();
		ScreenFlip();
		ClearDrawScreen();

		//ゲームループ
		scene_manager->Render();
		scene_manager->Update();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;

		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - startTime));
	}

	//クラスの解放
	delete scene_manager;

	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}