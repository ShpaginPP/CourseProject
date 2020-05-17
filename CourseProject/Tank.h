#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Factory.h"

using namespace std;

class Factory;
class Tank:public Factory
{
public:
	string name;		//���������
	string country;		//��������������
	string firepower;	//��������
	string weapon;		//��� ����������
	string caliber;		//������ ����������
	string area;		//����� ������������
	string date;		//���� ������������
	string amount;		//���������� � ������
	string weight;		//���
	string crew;		//����� �������

	Tank CreateTank();
	void Save();//���������� ����� � ���� tanks.txt
	void Load();
	void Edit();//�������������� �����
	void Print();//����� ���� ������
	void Delete();
};


