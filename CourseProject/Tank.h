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
	string name;		//названиеВ
	string country;		//принадлежность
	string firepower;	//мощность
	string weapon;		//Тип вооружения
	string caliber;		//калибр вооружения
	string area;		//метод пеоедвижения
	string date;		//дата изготовления
	string amount;		//количество в ангаре
	string weight;		//вес
	string crew;		//число экипажа

	Tank CreateTank();
	void Save();//Сохранение танка в файл tanks.txt
	void Load();
	void Edit();//редактирование танка
	void Print();//вывод всех танков
	void Delete();
};


