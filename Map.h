#pragma once


class Map
{
public:
	Map();
	virtual ~Map();

	//グラフィックのロード、アンロード
	void load();
	void unload();

	//描画
	void draw();

private:
	//マップチップの数を取得する
	int chipNumX();
	int chipNumY();
	int chipNum();
private:
	//グラフィックデータのハンドル
	int m_handle;
	//グラフィックのデータ
	int m_graphWidth;
	int m_graphHeight;
};