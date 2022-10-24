#pragma once


class Map
{
public:
	Map();
	virtual ~Map();

	//�O���t�B�b�N�̃��[�h�A�A�����[�h
	void load();
	void unload();

	//�`��
	void draw();

private:
	//�}�b�v�`�b�v�̐����擾����
	int chipNumX();
	int chipNumY();
	int chipNum();
private:
	//�O���t�B�b�N�f�[�^�̃n���h��
	int m_handle;
	//�O���t�B�b�N�̃f�[�^
	int m_graphWidth;
	int m_graphHeight;
};