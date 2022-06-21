#include<regex>
#include<ctime>
#include<iostream>
#include"mysql.h"
string date() {
	time_t nowtime;
	nowtime = time(0);
	tm *ltm = localtime(&nowtime);
	string year = to_string(ltm->tm_year + 1900);
	string mon = to_string(ltm->tm_mon + 1);
	string day = to_string(ltm->tm_mday);
	string hour = to_string(ltm->tm_hour);
	string min = to_string(ltm->tm_min);
	string sec = to_string(ltm->tm_sec);
	string nowdate = year + "-" + mon + "-" + day + " " + hour + ":" + min + ":" + sec;

	return nowdate;
}