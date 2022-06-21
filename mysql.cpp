#include"mysql.h"
void mysql::link() {
	string line;
	string local = "localhost";
	string user = "root";
	string pw = "root";
	string DB = "borrow_system";
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

	_local = local.c_str();
	_user = user.c_str();
	_pw = pw.c_str();
	_DB = DB.c_str();
	_port = port;

	conn = mysql_init(NULL);
	conn = mysql_real_connect(conn, _local, _user, _pw, _DB, _port, NULL, 0);

	if (!conn) {
		cout << "fail" << endl;
		system("pause");
		exit(0);
	}
	
}
void mysql::link(string local, string user, string pw, string DB, int port) {
	_local = local.c_str();
	_user = user.c_str();
	_pw = pw.c_str();
	_DB = DB.c_str();
	_port = port;
	conn = mysql_init(NULL);
	conn = mysql_real_connect(conn, _local, _user, _pw, _DB, _port, NULL, 0);

	if (!conn) {
		cout << "fail" << endl;
		system("pause");
		exit(0);
	}
}
int mysql::query(string query) {
	const char *sql = query.c_str();
	int check = mysql_query(conn, sql);
	return check;
}
MYSQL_RES* mysql::readData(string table) {
	string temp = "select * from "+table;
	const char *test = temp.c_str();
	mysql_query(conn, test);
	res_set = mysql_store_result(conn);
	return res_set;
}



MYSQL_RES* mysql::select_query(string item, string table,string specify) {
	string temp = "Select " + item + " From " + table + " " + specify;
	//cout << temp;
	const char *sql = temp.c_str();
	mysql_query(conn, sql);
	res_set = mysql_store_result(conn);
	return res_set;
	mysql_close(conn);
}

MYSQL_RES* mysql::select(string select1,string table, string select2,string specify) {
	string temp = "select "+select1+" from "+ table +" where "+ select2  +  " = '" + specify + "'";
	const char *sql = temp.c_str();
	//cout << temp << endl;
	int check = 0;
	check = mysql_query(conn, sql);
	res_set = mysql_store_result(conn);
	return res_set;
	mysql_close(conn);
	
	
}
int mysql::insert(string table, string column, string value) {
	string temp = "INSERT INTO " + table + "(" + column + ")" + " VALUES " + "(" + value + ")";
	//cout << temp << endl;
	//cout << endl;
	const char *sql = temp.c_str();
	int check = mysql_query(conn, sql);
	return check;
	mysql_close(conn);
}
int mysql::update(string table, string value, string select, string specify) {
	string temp = "UPDATE " + table + " SET " + value + " where " + select + "= " + "'" + specify + "'";
	//cout << temp << endl;
	const char *sql = temp.c_str();
	int check = mysql_query(conn, sql);
	return check;
	mysql_close(conn);
}
