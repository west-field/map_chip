#include "Map.h"
#include "DxLib.h"

//コンストラクタ初期化子
Map::Map() :
	m_handle(-1)
{
}
Map::~Map()
{

}
//グラフィックのロード、アンロード
void Map::load()
{
	m_handle = LoadGraph("data/mapchip.png");
}
void Map::unload()
{
	DeleteGraph(m_handle);
}

//描画
void Map::draw()
{
	DrawGraph(0, 0, m_handle, true);
}