#pragma once

class Scene_Manager; //前方宣言 Sceneクラスの中でScene_Managerクラスを使用する

class Scene {
protected:
	Scene_Manager* scene_manager;

public:
	Scene(Scene_Manager* pManager) {
		scene_manager = pManager;
	}

	virtual void Update() {}; //更新

	virtual void Render() {}; //描画
};

class Scene_Manager {
	char* key;
public:
//今のシーンのポインタ
	Scene* scene;

	Scene_Manager(char* pKey) {
		key = pKey;
	}

	~Scene_Manager() {
		delete scene;
	}

	char* GetKey() {
		return key;
	}

	void Update() {
		scene->Update(); //更新
	}

	void Render() {
		scene->Render(); //描画
	}
};