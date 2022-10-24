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
	//グラフィックデータのハンドル
	int m_handle;
};