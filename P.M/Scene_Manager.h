#pragma once

class Scene_Manager; //�O���錾 Scene�N���X�̒���Scene_Manager�N���X���g�p����

class Scene {
protected:
	Scene_Manager* scene_manager;

public:
	Scene(Scene_Manager* pManager) {
		scene_manager = pManager;
	}

	virtual void Update() {}; //�X�V

	virtual void Render() {}; //�`��
};

class Scene_Manager {
	char* key;
public:
//���̃V�[���̃|�C���^
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
		scene->Update(); //�X�V
	}

	void Render() {
		scene->Render(); //�`��
	}
};