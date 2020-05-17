#pragma once
class Tank;
class Factory 
{
public:
	virtual	Tank CreateTank() = 0;
	virtual void Load() = 0;
	virtual void Edit() = 0;
	virtual void Save() = 0;
	virtual void Print() = 0;
	virtual void Delete() = 0;
};

