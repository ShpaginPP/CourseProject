#include <iostream>
#include "Tank.h"
#include "Factory.h"
using namespace std;

int main()
{
	Tank Data;
	Data.CreateTank();
	Data.Save();
	Data.Print();
	Data.Load();
	Data.Edit();
	Data.Print();
	Data.Save();
	Data.Load();
	Data.Print();
	Data.Edit();
	Data.Print();
	Data.Save();
	return 0;
}