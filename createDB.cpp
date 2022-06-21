#include<mysql.h>
#include<fstream>
#include<string>
#include<sstream>
#include<regex>
#include"mysql.h"
#include"createDB.h"
bool createDB() {
	string line;
	string local = "localhost";
	string user = "root";
	string pw = "root";
	string DB = "";
	string Sport;
	int port = 0;
	ifstream file;
	file.open("config.txt");
	if (file) {
		getline(file, line);
		istringstream iss(line);
		getline(iss, local, '|');
		getline(iss, user, '|');
		getline(iss, pw, '|');
		getline(iss, DB, '|');
		getline(iss, Sport, '|');
		port = stoi(Sport);
	}

	local = local.c_str();
	user = user.c_str();
	pw = pw.c_str();
	DB = DB.c_str();	
	port = port;

	mysql database;

	database.link(local, user, pw,DB,port);
	int check = database.query("CREATE DATABASE borrow_system;");
	if (check == 0) {
		return true;
	}else {
		//cout << "error";
		return false;
	}
}
void creatTable() {
	mysql table;
	
	table.link();
	int borrow_check = table.query("CREATE TABLE `borrow` (`userID` varchar(10) NOT NULL,`name` varchar(20) NOT NULL,`code` varchar(10) NOT NULL,`type` varchar(10) NOT NULL,`ItemName` varchar(20) NOT NULL,`outDate` datetime DEFAULT NULL,`inDate` datetime DEFAULT NULL)");
	int lantern_check = table.query("CREATE TABLE `lantern` (`code` varchar(50) NOT NULL,`name` varchar(50) NOT NULL,`brand` varchar(50) NOT NULL,`type` varchar(50) NOT NULL,`date` varchar(50) NOT NULL,`conditions` varchar(50) NOT NULL,`status` varchar(50) NOT NULL,`size` varchar(50) NOT NULL,`lantern` varchar(50) NOT NULL,`fuel` varchar(50) NOT NULL)");
	int stove_check = table.query("CREATE TABLE `stove` (`code` varchar(50) NOT NULL,`name` varchar(50) NOT NULL,`brand` varchar(50) NOT NULL,`type` varchar(50) NOT NULL,`date` varchar(50) NOT NULL,`conditions` varchar(50) NOT NULL,`status` varchar(50) NOT NULL,`stove` varchar(50) NOT NULL,`fuel` varchar(50) NOT NULL)");
	int tent_check = table.query("CREATE TABLE `tent` (`code` varchar(100) NOT NULL,`name` text NOT NULL,`brand` varchar(50) NOT NULL,`type` varchar(50) NOT NULL,`date` int(11) NOT NULL,`conditions` varchar(50) NOT NULL,`status` varchar(50) NOT NULL,`ppl` int(50) NOT NULL,`tent` varchar(50) NOT NULL,`doors` int(10) NOT NULL,`layer` varchar(10) NOT NULL,`color` varchar(50) NOT NULL)");
	int user_check = table.query("CREATE TABLE `user` ( `ID` varchar(10) NOT NULL, `Name` varchar(100) NOT NULL, `Section` varchar(100) NOT NULL, `Password` int(100) NOT NULL, `Address` varchar(100) NOT NULL, `Rank` varchar(100) NOT NULL )");
	cout << borrow_check << endl;
	cout << lantern_check << endl;
	cout << stove_check << endl;
	cout << tent_check << endl;
	cout << user_check << endl;
}

void insertuserData() {
	mysql data;

	string line[100];
	string id[20];
	string name[20];
	string section[20];
	string password[20];
	string address[20];
	string ranking[20];
	int	linecount = 0;
	regex venture("VEN");
	regex rover("ROV");
	regex scout("SCT");
	regex scouter("SCM");

	//get file
	ifstream file;
	file.open("user.txt");
	//get file contxt 

	for (int i = 0; i < 30; i++) {
		getline(file, line[i]);
		//cout << i << "line :" << line[i] << endl;
		if (line[i] != "") {
			linecount++;
		}
	}

	for (int i = 0; i < linecount; i++) {
		data.link();
		if (regex_search(line[i], venture)) {
			//cout << i << " " << line[i] << endl;
			istringstream iss(line[i]);
			getline(iss, id[i], '|');
			getline(iss, name[i], '|');
			getline(iss, section[i], '|');
			getline(iss, password[i], '|');
			getline(iss, address[i], '|');
			string temp = "'" + id[i] + "', " + "'" + name[i] + "', " + "'" + section[i] + "', " + "'" + password[i] + "', " + "'" + address[i] + "', " + "''";
			//cout << temp << endl;
			data.insert("user", "`ID`, `Name`, `Section`, `Password`, `Address`, `Rank`", temp);
		}
		if (regex_search(line[i], rover)) {
			//cout << i << " " << line[i] << endl;
			istringstream iss(line[i]);
			getline(iss, id[i], '|');
			getline(iss, name[i], '|');
			getline(iss, section[i], '|');
			getline(iss, password[i], '|');
			getline(iss, address[i], '|');
			string temp = "'" + id[i] + "', " + "'" + name[i] + "', " + "'" + section[i] + "', " + "'" + password[i] + "', " + "'" + address[i] + "', " + "''";
			//cout << temp << endl;
			data.insert("user", "`ID`, `Name`, `Section`, `Password`, `Address`, `Rank`", temp);
		}
		if (regex_search(line[i], scout)) {
			//cout << i << " " << line[i] << endl;
			istringstream iss(line[i]);
			getline(iss, id[i], '|');
			getline(iss, name[i], '|');
			getline(iss, section[i], '|');
			getline(iss, password[i], '|');
			getline(iss, address[i], '|');
			getline(iss, ranking[i], '|');
			string temp = "'" + id[i] + "', " + "'" + name[i] + "', " + "'" + section[i] + "', " + "'" + password[i] + "', " + "'" + address[i] + "', " + "'" + ranking[i] + "'";
			//cout << temp << endl;
			data.insert("user", "`ID`, `Name`, `Section`, `Password`, `Address`, `Rank`", temp);
		}
		if (regex_search(line[i], scouter)) {
			//cout << i << " " << line[i] << endl;
			istringstream iss(line[i]);
			getline(iss, id[i], '|');
			getline(iss, name[i], '|');
			getline(iss, section[i], '|');
			getline(iss, password[i], '|');
			getline(iss, address[i], '|');
			getline(iss, ranking[i], '|');
			string temp = "'" + id[i] + "', " + "'" + name[i] + "', " + "'" + section[i] + "', " + "'" + password[i] + "', " + "'" + address[i] + "', " + "'" + ranking[i] + "'";
			//cout << temp << endl;
			data.insert("user", "`ID`, `Name`, `Section`, `Password`, `Address`, `Rank`", temp);
		}

	}
}
void insertitemDate() {
	mysql item;

	string code[30];
	string itemname[30];
	string brand[30];
	string type[30];
	string purchase[30];
	string condition[30];
	string status[30];
	string ppl[30];
	string tent[30];
	string door[30];
	string layer[30];
	string colour[30];
	string stove[30];
	string fuel[30];
	string size[30];
	string Eline[100];
	
	int Elinecount = 0;
	int i = 0;

	ifstream file;
	file.open("camp_equipment.txt");
	
	regex Tent("^T");
	regex Stove("^S");
	regex Lantern("^L");
	for (i = 0; i < 30; i++) {
		getline(file, Eline[i]);
		if (Eline[i] != "") {
			Elinecount++;
		}
	}
	/*cout << Elinecount << endl;
	for (i = 0; i < Elinecount; i++) {
		cout << i << " "<< line[i] << endl;
	}*/
	//cout << endl;
	for (i = 0; i < Elinecount; i++) {
		item.link();
		if (regex_search(Eline[i], Tent)) {
			//cout << i << " " << line[i] << endl;
			istringstream iss(Eline[i]);
			getline(iss, code[i], '|');
			getline(iss, itemname[i], '|');
			getline(iss, brand[i], '|');
			getline(iss, type[i], '|');
			getline(iss, purchase[i], '|');
			getline(iss, condition[i], '|');
			getline(iss, status[i], '|');
			getline(iss, ppl[i], '|');
			getline(iss, tent[i], '|');
			getline(iss, door[i], '|');
			getline(iss, layer[i], '|');
			getline(iss, colour[i], '|');
			string temp = "'" + code[i] + "', " + "'" + itemname[i] + "', '" + brand[i] + "', " + "'" + type[i] + "', " + "'" + purchase[i] + "', " + "'" + condition[i] + "', " + "'" + status[i] + "', " +
				          "'" + ppl[i] + "' , " + "'" + tent[i] + "', " + "'" + door[i] + "', "+ "'" + layer[i] + "', " + "'" + colour[i] + "'";
			//cout << temp << endl;
			item.insert("tent", "`code`, `name`, `brand`, `type`, `date`, `conditions`, `status`, `ppl`, `tent`, `doors`, `layer`, `color`", temp);
		}
		if (regex_search(Eline[i], Stove)) {
			//cout << i << " " << line[i] << endl;
			istringstream iss(Eline[i]);
			getline(iss, code[i], '|');
			getline(iss, itemname[i], '|');
			getline(iss, brand[i], '|');
			getline(iss, type[i], '|');
			getline(iss, purchase[i], '|');
			getline(iss, condition[i], '|');
			getline(iss, status[i], '|');
			getline(iss, stove[i], '|');
			getline(iss, fuel[i], '|');
			string temp = "'" + code[i] + "', " + "'" + itemname[i] + "', '" + brand[i] + "', " + "'" + type[i] + "', " + "'" + purchase[i] + "', " + "'" + condition[i] + "', " + "'" + status[i] + "', " + "'" + stove[i] + "', " +
						  "'" + fuel[i] + "'";
			//cout << temp << endl;
			item.insert("stove", "`code`, `name`, `brand`, `type`, `date`, `conditions`, `status`, `stove`, `fuel`", temp);
		}
		if (regex_search(Eline[i], Lantern)) {
			//cout << i << " " << line[i] << endl;
			istringstream iss(Eline[i]);
			getline(iss, code[i], '|');
			getline(iss, itemname[i], '|');
			getline(iss, brand[i], '|');
			getline(iss, type[i], '|');
			getline(iss, purchase[i], '|');
			getline(iss, condition[i], '|');
			getline(iss, status[i], '|');
			getline(iss, size[i], '|');
			getline(iss, stove[i], '|');
			getline(iss, fuel[i], '|');
			string temp = "'" + code[i] + "', " + "'" + itemname[i] + "', '" + brand[i] + "', " + "'" + type[i] + "', "  "'" + purchase[i] + "', " + "'" + condition[i] + "', " + "'" + status[i] + "', " + "'" + stove[i] + "', " + "'" + size[i] +
						 "', " + "'" + fuel[i] + "'";
			//cout << temp << endl;
			item.insert("lantern", "`code`, `name`, `brand`, `type`, `date`, `conditions`, `status`, `size`, `lantern`, `fuel`", temp);
		}
	}
	
}