#include"user.h";
void users::setID(string ID) {
	_ID = ID;
}
void users::setName(string name) {
	_Name = name;
}
void users::setlimit(int limit) {
	_limit = limit;
}

string users::getID() {
	return _ID;
}
string users::getName() {
	return _Name;
}
int users::getlimit() {
	return _limit;
}