#include "Map.h"
#include "DxLib.h"
#include "game.h"
#include <cassert>

namespace
{
	//�}�b�v�`�b�v1�̃T�C�Y
	constexpr int kChipSize = 32;

	//�`�b�v�̐�
	constexpr int kChipNumX = Game::kScreenWidth / kChipSize;
	constexpr int kChipNumY = Game::kScreenHeight / kChipSize;

	//�}�b�v�f�[�^
	constexpr int kMapData[kChipNumY][kChipNumX] =
	{
		{ 0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
}

//�R���X�g���N�^�������q
Map::Map() :
	m_handle(-1),
	m_graphWidth(0),
	m_graphHeight(0)
{
}
Map::~Map()
{

}
//�O���t�B�b�N�̃��[�h�A�A�����[�h
void Map::load()
{
	m_handle = LoadGraph("data/mapchip.png");
	GetGraphSize(m_handle, &m_graphWidth, &m_graphHeight);
}
void Map::unload()
{
	DeleteGraph(m_handle);
}

//�`��
void Map::draw()
{
	for (int x = 0; x < kChipNumX; x++)
	{
		for (int y = 0; y < kChipNumY; y++)
		{
			const int chipNo = kMapData[y][x];
			assert(chipNo >= 0);
			assert(chipNo < chipNum());
			int graphX = (chipNo % chipNumX()) * kChipSize;
			int graphY = (chipNo / chipNumX()) * kChipSize;

			DrawRectGraph(x * kChipSize, y * kChipSize,
				graphX, graphY, kChipSize, kChipSize,
				m_handle, true, false);
		}
	}
}
//�}�b�v�`�b�v�̐����擾����
int Map::chipNumX()
{
	return (m_graphWidth / kChipSize);
}
int Map::chipNumY()
{
	return (m_graphHeight / kChipSize);
}
int Map::chipNum()
{
	return (chipNumX() * chipNumY());
}