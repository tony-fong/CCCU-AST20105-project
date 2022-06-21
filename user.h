#pragma once
#include<string>
using namespace std;
#ifndef USER_H
#define USER_H
class users{
private:
	string _ID;
	string _Name;
	int _limit;
public:
	void setID(string ID);
	void setName(string name);
	void setlimit(int limit);

	string getID();
	string getName();
	int getlimit();

};
extern users USER;
#endif // !USER_H

