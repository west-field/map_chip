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
	//�O���t�B�b�N�f�[�^�̃n���h��
	int m_handle;
};