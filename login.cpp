#include"mysql.h"
#include"level.h"
#include"user.h"
#include"login.h"
users USER;
bool login(string id, string pw) {
	
	
	mysql DB;
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	string row0;
	string row1;
	string row2;
	string row3;

	bool success = true;

		//cout << "plase input id :";
		//cin >> id;
		//cout << "plase input password :";
		//cin >> pw;
		
		//admin login
		if (id == "admin") {
			if (pw == "admin") {
				system("cls");
				//admin();
				return false;
			}
		}
		//user login
		DB.link();
		if (mysql_num_rows(DB.select("ID", "user", "ID",id)) != 0) {
			DB.link();
			if (mysql_num_rows(DB.select("Password", "user","Password", pw)) != 0) {
				cout << "login successful" << endl;
				DB.link(); 
				res_set = DB.select("Name, ID, Section , 'Rank'", "user", "ID", id);
				row = mysql_fetch_row(res_set);
				
				row0 = row[0];
				row1 = row[1];
				row2 = row[2];
				row3 = row[3];

				USER.setlimit(level(row2, row3));		
				USER.setName(row0);
				USER.setID(row1);
				cout << USER.getName();
				cout << USER.getlimit();
				cout << USER.getID();
				system("cls");
				success = false;
				return true;
			}
			else {
				system("cls");
				cout << "please login angin" << endl;
			}
		}
		else {
			system("cls");
			cout << "please login angin" << endl;
		}
	
}