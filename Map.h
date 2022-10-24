#pragma once
#include <vector>

class Map
{
public:
	Map();
	virtual ~Map();

	//�O���t�B�b�N�̃��[�h�A�A�����[�h
	void load();
	void unload();

	//�X�V
	void update();

	//�`��
	void draw();

private:
	//�}�b�v�`�b�v�ҏW�p�̃J�[�\����\��
	void drawCursor();

	//�}�b�v�`�b�v�̐����擾����
	int chipNumX();
	int chipNumY();
	int chipNum();

	//�}�b�v�f�[�^�̓��o��
	void outputData();	//�}�b�v�f�[�^���o�͂���
	void readData();	//�}�b�v�f�[�^��ǂݍ���
private:
	//�O���t�B�b�N�f�[�^�̃n���h��
	int m_handle;

	//�O���t�B�b�N�̃f�[�^
	int m_graphWidth;
	int m_graphHeight;

	//�}�b�v�`�b�v�ҏW�p�f�[�^
	int m_cursorNo;
	std::vector<int> m_mapData;


	int m_waitFrame;
};