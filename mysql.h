#pragma once
#include<fstream>
#include<iostream>
#include <msclr\marshal_cppstd.h>
#include<sstream>
#include<string>
#include<mysql.h>
#include"mysql.h"
using namespace std;
#ifndef MYSQL_H
#define MYSQL_H
#pragma warning( disable : 4996)
class mysql {
private:
	MYSQL *conn;
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	const char *_local;
	const char *_user;
	const char *_pw;
	const char *_DB;
	int _port;

public:
	//mysql(string local, string user, string pw, string DB,int port);
	void link();
	void link(string local, string user, string pw, string DB, int port);
	int query(string query);
	MYSQL_RES* select(string select1, string select2, string table, string specify);
	MYSQL_RES* readData(string table);
	MYSQL_RES* order(string table, string order);
	MYSQL_RES* select_query(string item, string table, string specify);
	int insert(string table, string column, string value);
	int update(string table, string value, string select, string specify);
};
extern mysql user;
#endif // !MYSQL_H


