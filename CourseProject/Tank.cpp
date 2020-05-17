#include "Tank.h"

Tank Tank::CreateTank()
{
	while (true)
	{
		try
		{
			//Задание имени
			cout << "Enter a tank's name:" << endl;
			getline(cin, name);
			if (name == "")
			{
				throw(string)"There is no tank in this file";
			}
			//Задание страны
				cout << "Choose a country between USA and Russia:" << endl;
				getline(cin, country);
				if (country != "Russia" && country != "USA")
					throw (string)"You can choose only between USA and Russia";
			//Задание мощи
				cout << "Enter a quality of firepower" << endl;
				getline(cin, firepower);
				for (int i = 0; i < firepower.length(); i++)
				{
					if (((firepower[i] >= 'A') && (firepower[i] <= 'Z')) || ((firepower[i] >= 'a') && (firepower[i] <= 'z')))
					{
						throw(string)"This parameter must be numeric.";
						break;
					}
				}
			//Задание оружия
				cout << "Choose a weapon: Cannon or Howitzer" << endl;
				getline(cin, weapon);
				if (weapon != "Cannon" && weapon != "Howitzer")
					throw (string)"You can choose only between Cannon and Howitzer";
				//Задание калибра
				cout << "Enter weapon's caliber number:" << endl
					<< "for Russian weapon: Howitzer - 152 mm, Cannon - 125 mm" << endl
					<< "for USA weapon: Howitzer - 155 mm, Cannon - 120 mm" << endl;
				getline(cin, caliber);
				if (country == "Russia" && weapon == "Howitzer" && caliber != "152")
				{
					throw (string)"For a russian howitzer you can choose only 152 mm.";
				}
				else if (country == "Russia" && weapon == "Cannon" && caliber != "125")
				{
					throw (string)"For a russian cannon you can choose only 125 mm.";
				}
				else if (country == "USA" && weapon == "Howitzer" && caliber != "155")
				{
					throw (string)"For a USA howitzer you can choose only 155 mm.";
				}
				else if (country == "USA" && weapon == "Cannon" && caliber != "120")
				{
					throw (string)"For a USA cannon you can choose only 120 mm.";
				}
			//Задание местности
				{
					cout << "This is a tank, it can only move on the ground." << endl;
					getline(cin, area);
					if (area != "ground")
						throw (string)"You can choose only \"ground\" as an movament area.";
					//Задание даты
					cout << "Enter a year of assembly." << endl;
					getline(cin, date);
					if (date.length() > 4)
						throw (string)"Incorrect size of year, try again.";
					for (int i = 0; i < date.length(); i++)
					{
						if (((date[i] >= 'A') && (date[i] <= 'Z')) || ((date[i] >= 'a') && (date[i] <= 'z')))
						{
							throw(string)"This parameter must be numeric.";
							break;
						}
					}
					//Задание количества в ангаре
					cout << "Enter amount of this tanks(until 10)." << endl;
					getline(cin, amount);
					for (int i = 0; i < amount.length(); i++)
					{
						if (((amount[i] >= 'A') && (amount[i] <= 'Z')) || ((amount[i] >= 'a') && (amount[i] <= 'z')))
						{
							throw(string)"This parameter must be numeric.";
							break;
						}
					}
					int test = stoi(amount);
					if (test > 10)
						throw(string)"The hangar is designed for 10 combat vehicles";
					//Вес
					cout << "Enter a weight of your tank (from 45 tons to 70 tons)." << endl;
					getline(cin, weight);
					for (int i = 0; i < weight.length(); i++)
					{
						if (((weight[i] >= 'A') && (weight[i] <= 'Z')) || ((weight[i] >= 'a') && (weight[i] <= 'z')))
						{
							throw(string)"This parameter must be numeric.";
							break;
						}
					}
					int test1 = stoi(weight);
					if ((test1 > 70) || (test1 < 45))
						throw(string)"The a tank cannot weigh less than 45 tons and more than 70";
					//Введите экипажа
					cout << "Enter a number of people of your tank (from 2 to 5 man)." << endl;
					getline(cin, crew);
					for (int i = 0; i < crew.length(); i++)
					{
						if (((crew[i] >= 'A') && (crew[i] <= 'Z')) || ((crew[i] >= 'a') && (crew[i] <= 'z')))
						{
							throw(string)"This parameter must be numeric.";
							break;
						}
					}
					int test2 = stoi(crew);
					if ((test2 > 5) || (test2 < 2))
						throw(string)"The number of people is incorrect.";
				}
			return *this;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
		
}

void Tank::Save()
{
	ofstream fout("tanks.txt");
	fout << "Tank's name: " << name << endl
		 << "Country: " << country << endl
		 << "Firepower: " << firepower << endl
		 << "Weponry: " << weapon << endl
		 << "Caliber: " << caliber << endl
		 << "Area of movement: " << area << endl
		 << "Date of assembly: " << date << endl
		 << "Amount of Tanks in hangar: " << amount << endl
		 << "Weight: " << weight << endl
		 << "Number of people in the crew: " << crew << endl
		 << "====================================" << endl;
	fout.close();
	cout << "All data saved"<<endl;
}

void Tank::Load()
{
	try
	{
		string trash;
		ifstream fin("tanks.txt");
		if (fin.fail())
		{
			cout << "File is empty" << endl;
			return;
		}
		fin >> trash >> trash >> name;
		if (name == "\n")
		{
			throw(string)"There is no tank in this file";
		}
		fin >> trash >> country;
		if (country != "Russia" && country != "USA")
		{
			throw (string)"You can choose only between USA and Russia";
		}
		fin >> trash >> firepower;
		for(int i = 0; i > firepower.length(); i++)
		{
			if (((firepower[i] >= 'A') && (firepower[i] <= 'Z')) || ((firepower[i] >= 'a') && (firepower[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		fin >> trash >> weapon;
		if (weapon != "Cannon" && weapon != "Howitzer")
		{
			throw (string)"You can choose only between Cannon and Howitzer";
		}
		fin >> trash >> caliber;
		if (country == "Russia" && weapon == "Howitzer" && caliber != "152")
		{
			throw (string)"For a russian howitzer you can choose only 152 mm.";
		}
		else if (country == "Russia" && weapon == "Cannon" && caliber != "125")
		{
			throw (string)"For a russian cannon you can choose only 125 mm.";
		}
		else if (country == "USA" && weapon == "Howitzer" && caliber != "155")
		{
			throw (string)"For a USA howitzer you can choose only 155 mm.";
		}
		else if (country == "USA" && weapon == "Cannon" && caliber != "120")
		{
			throw (string)"For a USA cannon you can choose only 120 mm.";
		}
		fin >> trash >> trash >> trash >> area;
		if (area != "ground")
		{
			throw (string)"You can choose only \"ground\" as an movament area.";
		}
		fin >> trash >> trash >> trash >> date;
		if (date.length() > 4)
			throw (string)"Incorrect size of year, try again.";
		for (int i = 0; i < date.length(); i++)
		{
			if (((date[i] >= 'A') && (date[i] <= 'Z')) || ((date[i] >= 'a') && (date[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		fin >> trash >> trash >> trash >> trash >> trash >> amount;
		for (int i = 0; i < amount.length(); i++)
		{
			if (((amount[i] >= 'A') && (amount[i] <= 'Z')) || ((amount[i] >= 'a') && (amount[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		int test3 = stoi(amount);
		if (test3 > 10)
		{
			throw(string)"The hangar is designed for 10 combat vehicles";
		}
		fin >> trash >> weight;
		for (int i = 0; i < weight.length(); i++)
		{
			if (((weight[i] >= 'A') && (weight[i] <= 'Z')) || ((weight[i] >= 'a') && (weight[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		int test4 = stoi(weight);
		if ((test4 > 70) || (test4 < 45))
			throw(string)"The a tank cannot weigh less than 45 tons and more than 70";
		fin >> trash >> trash >> trash >> trash >> trash >> trash >> crew;
		for (int i = 0; i < crew.length(); i++)
		{
			if (((crew[i] >= 'A') && (crew[i] <= 'Z')) || ((crew[i] >= 'a') && (crew[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		int test5 = stoi(crew);
		if ((test5 > 5) || (test5 < 2))
			throw(string)"The number of people is incorrect.";
		fin.close();
		cout << "All tanks loaded from file." << endl;
	}
	catch (string err)
	{
		cout << "Error:" + err << endl;
	}
}

void Tank::Print()
{
	cout << "Tank's name: " << name << endl
		 << "Country: " << country << endl
		 << "Firepower: " << firepower << endl
		 << "Weponry: " << weapon << endl
		 << "Caliber: " << caliber << endl
		 << "Area of movement: " << area << endl
		 << "Date of assembly: " << date << endl
		 << "Amount of Tanks in hangar: " << amount << endl
		 << "Weight: " << weight << endl
		 << "Number of people in the crew: " << crew << endl
		 << "====================================" << endl;
}

void Tank::Edit()
{
	int index, iTmp, iTmp1, iTmp2, iTmp3;
	string sTmp;
	cout << "Choose an atribute to editing:" << endl
		 << "1.Tank's name. " << endl
		 << "2.Country. " << endl
		 << "3.Firepower. " << endl
		 << "4.Weaponry. " << endl
		 << "5.Caliber. " << endl
		 << "6.Area of movement. " << endl
		 << "7.Date of assembly. " << endl
		 << "8.Amount of Tanks in hangar. "<< endl
		 << "9.Weight. " << endl
		 << "10.Number of people in the crew. " << endl
		 << "0. Exit." << endl;
	cin >> index;
	if (index < 0 || index>10)
	{
		throw(string)"There is no atribute on this number.";
	}
	switch (index)
	{
	case 1:
		cout << "Initial value:" << endl
			 << name << endl
			 << "New value:" << endl;
		 cin >> sTmp;
		 if (sTmp == "")
		 {
			 throw(string)"There is no tank in this file";
		 }
		 name = sTmp;
		 break;
	case 2:
		cout << "Initial value:" << endl
             << country <<endl
			 << "Choose new country between Russia and USA:" << endl;
		cin  >> sTmp;
		if (sTmp != "Russia" && sTmp != "USA")
			throw (string)"You can choose only between USA and Russia";
		country = sTmp;
		break;
	case 3:
		cout << "Initial value:" << endl
             << firepower <<endl
			 << "New value:" << endl;
		cin  >> sTmp;
		for (int i = 0; i < sTmp.length(); i++)
		{
			if (((sTmp[i] >= 'A') && (sTmp[i] <= 'Z')) || ((sTmp[i] >= 'a') && (sTmp[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		firepower = sTmp;
		break;
	case 4:
		cout << "Initial value:" << endl
             << weapon <<endl
		     << "New weapon, choose between Cannon and Howitzer:" << endl;
		cin  >> sTmp;
		if (sTmp != "Cannon" && sTmp != "Howitzer")
			throw (string)"You can choose only between Cannon and Howitzer";
		weapon = sTmp;
		break;
	case 5:
		cout << "Initial value:" << endl
			 << caliber << endl
			 << "New value of caliber" << endl
			 << "(Russian: cannon = 125, howitzer = 152;" << endl
			 << "USA: cannon = 120, howitzer = 155.):" << endl;
		cin  >> sTmp;
		if (country == "Russia" && weapon == "Howitzer" && sTmp != "152")
		{
			throw (string)"For a russian howitzer you can choose only 152 mm.";
		}
		else if (country == "Russia" && weapon == "Cannon" && sTmp != "125")
		{
			throw (string)"For a russian cannon you can choose only 125 mm.";
		}
		else if (country == "USA" && weapon == "Howitzer" && sTmp != "155")
		{
			throw (string)"For a USA howitzer you can choose only 155 mm.";
		}
		else if (country == "USA" && weapon == "Cannon" && sTmp != "120")
		{
			throw (string)"For a USA cannon you can choose only 120 mm.";
		}
		caliber = sTmp;
		break;
	case 6:
		cout << "You can't change movement area of your tank." << endl;
		break;
	case 7:
		cout << "Initial value:" << endl
			<< date << endl
			<< "Update build year" << endl;
		cin >> sTmp;
		if (sTmp.length() > 4)
			throw (string)"Incorrect size of year, try again.";
		for (int i = 0; i < sTmp.length(); i++)
		{
			if (((sTmp[i] >= 'A') && (sTmp[i] <= 'Z')) || ((sTmp[i] >= 'a') && (sTmp[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		date = sTmp;
		break;
	case 8:
		cout << "Initial value:" << endl
			<< amount << endl
			<< "Enter amount of this tanks(until 10)." << endl;
		cin >> sTmp;
		for (int i = 0; i < sTmp.length(); i++)
		{
			if (((sTmp[i] >= 'A') && (sTmp[i] <= 'Z')) || ((sTmp[i] >= 'a') && (sTmp[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		iTmp = stoi(sTmp);
		if (iTmp > 10)
			throw(string)"The hangar is designed for 10 combat vehicles";
		amount = sTmp;
		break;
	case 9:
		cout << "Initial value:" << endl
	         << weight <<endl
			 << "Enter a new weight of your tank (from 45 tons to 70 tons)." << endl;
		cin  >> sTmp;
		for (int i = 0; i < sTmp.length(); i++)
		{
			if (((sTmp[i] >= 'A') && (sTmp[i] <= 'Z')) || ((sTmp[i] >= 'a') && (sTmp[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		iTmp1 = stoi(sTmp);
		if ((iTmp1 > 70) || (iTmp1 < 45))
			throw(string)"The a tank cannot weigh less than 45 tons and more than 70";
		amount = sTmp;
		break;
	case 10:
		cout << "Initial value:" << endl
		     << crew <<endl
			 << "Enter a number of people of your tank (from 2 to 5 man)." << endl;
		cin >> sTmp;
		for (int i = 0; i < sTmp.length(); i++)
		{
			if (((sTmp[i] >= 'A') && (sTmp[i] <= 'Z')) || ((sTmp[i] >= 'a') && (sTmp[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		iTmp2 = stoi(sTmp);
		if ((iTmp2 > 5) || (iTmp2 < 2))
			throw(string)"The number of people is incorrect.";
	case 0:
		cout << "Exit."<<endl;
		break;
	}
}

void Tank::Delete()
{
	cout << "Deleting tank;" << endl;
	name = "";
	country = "";
	firepower = "";
	weapon = "";
	caliber = "";
	area = "";
	date = "";
	amount = "";
	weight = "";
	crew = "";
	cout << "Tank deleted." << endl;
}