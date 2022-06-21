#include<iostream>
#include<string>
#include<mysql.h>
#include"level.h"
using namespace std;
int level(string section,string rank) {
	cout <<"section " <<section << endl;
	cout <<"rank " << rank << endl;
	int limit;
	if (section == "Scout") {
		if (rank== "members") {
			limit = 1;
		}
		else if (rank== "Patrol Leader" || rank== "Assistant Patrol Leader") {
			limit = 3;
		}
	}
	if (section == "Venture Scout") {
		limit = 3;
	}
	if (section == "Rover Scout") {
		limit = 5;
	}
	if (section == "Scouter") {
		limit = 5;
	}
	return limit;
}