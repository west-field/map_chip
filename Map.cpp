#include "Map.h"
#include "DxLib.h"

//�R���X�g���N�^�������q
Map::Map() :
	m_handle(-1)
{
}
Map::~Map()
{

}
//�O���t�B�b�N�̃��[�h�A�A�����[�h
void Map::load()
{
	m_handle = LoadGraph("data/mapchip.png");
}
void Map::unload()
{
	DeleteGraph(m_handle);
}

//�`��
void Map::draw()
{
	DrawGraph(0, 0, m_handle, true);
}