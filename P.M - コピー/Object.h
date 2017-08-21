#pragma once

class Actor_Manager; //Actor_Managerはプレイヤーにも敵にも弾にも頭にも必要なので、基底クラスに宣言

class Object {
protected:
	bool exist; //存在フラグ

	int x; //座標　横
	int y; //座標　縦
	double angle;  //角度

	double collision;//当たり判定

	bool hostility_flag; //敵意、敵性の意　trueはfalseのみ攻撃可能。逆も然り。
	
	int graphic_handle; //読み込んだ画像を表示するのに使用

	Actor_Manager* actor_manager; //前方宣言に同じ

public:
	Object();

	virtual void Update() = 0; //完全仮想関数(未定義関数) 関数の末尾に＝０をつけて宣言。
							   //継承元では定義できず、継承後のクラスで必ず再宣言及び定義しなければならない。
							   //↑つまりは「継承したクラスが定義するので、このクラスでは定義しません」ということ。

/////////////////////////////////
////constを付けることで、メンバ変数の値を変えないことを約束
////先頭ではなく末尾に付けることでオブジェクトの変更は不可能だが、メソッド呼び出しなら可能に

	bool Get_Exist()const;

	int Get_X()const;
	int Get_Y()const;
	double Get_Angle()const;

	double Get_Collision()const;

	double Get_Hostility_flag()const;

////////////////////////////////

	virtual void Render();

};