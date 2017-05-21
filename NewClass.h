#pragma once
#include <iostream>
class NewClass
{
public:
	NewClass();
	explicit NewClass(const double &d);
	NewClass(const NewClass &nc);
	NewClass(NewClass &&nc);
	~NewClass();

	NewClass & operator=(const NewClass &nc);
	NewClass & operator=(NewClass &&nc);
	NewClass & operator+=(const NewClass &nc);
	NewClass & operator+=(NewClass &&nc);

	friend NewClass operator+(const NewClass & l, const NewClass & r);
	friend NewClass && operator+(const NewClass & l, NewClass && r);
	friend NewClass && operator+(NewClass && l, const NewClass & r);
	friend NewClass && operator+(NewClass && l, NewClass && r);

	friend std::ostream & operator<<(std::ostream &os, const NewClass &nc);
	
	static int getLastID();

private:
	double *res;
	static int LastID;
	int id;
};

