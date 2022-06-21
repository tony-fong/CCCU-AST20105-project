#include<regex>
#include<string>
#include<fstream>
#include<sstream>
#include"mysql.h"
#include"insertdata.h"

int insertUserData(string txt) {
	mysql data;

	
	string id[20];
	string name[20];
	string section[20];
	string password[20];
	string address[20];
	string ranking[20];
	string line[100];
	int	linecount = 0;

	regex venture("VEN");
	regex rover("ROV");
	regex scout("SCT");
	regex scouter("SCM");
	

	//get file
	ifstream file;
	file.open(txt);
	//get file contxt 

	for (int i = 0; i < 30; i++) {
		getline(file, line[i]);
		cout << i << "line :" << line[i] << endl;
		if (line[i] != "") {
			linecount++;
		}
	}
	int success = 0;
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
			if (data.insert("user", "`ID`, `Name`, `Section`, `Password`, `Address`, `Rank`", temp) == 0) {
				success++;
			}
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
			if (data.insert("user", "`ID`, `Name`, `Section`, `Password`, `Address`, `Rank`", temp) == 0) {
				success++;
			}
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
			if (data.insert("user", "`ID`, `Name`, `Section`, `Password`, `Address`, `Rank`", temp) == 0) {
				success++;
			}
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
			if (data.insert("user", "`ID`, `Name`, `Section`, `Password`, `Address`, `Rank`", temp) == 0) {
				success++;
			}

		}
		
		
	}return success;

}
int insertItemDate(string txt) {
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
	file.open(txt);

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
	int success = 0;
	for (i = 0; i < Elinecount; i++) {
		item.link("localhost", "root", "", "borrow_system", 3308);
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
				"'" + ppl[i] + "' , " + "'" + tent[i] + "', " + "'" + door[i] + "', " + "'" + layer[i] + "', " + "'" + colour[i] + "'";
			//cout << temp << endl;
			if (item.insert("tent", "`code`, `name`, `brand`, `type`, `date`, `conditions`, `status`, `ppl`, `tent`, `doors`, `layer`, `color`", temp) == 0) {
				success++;
			}
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
			if (item.insert("stove", "`code`, `name`, `brand`, `type`, `date`, `conditions`, `status`, `stove`, `fuel`", temp) == 0) {
				success++;
			}
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
			if (item.insert("lantern", "`code`, `name`, `brand`, `type`, `date`, `conditions`, `status`, `size`, `lantern`, `fuel`", temp) == 0) {
				success++;
			}
		}return success;
	}
}
/*void request() {
	string type;
	string filename;
	cout << "plase input data type(user/item)" << endl;
	cin >> type;
	cout << "input txt file name" << endl;
	cin >> filename;
	if (type == "user") {
		cout << "inputing data to user" << endl;
		insertUserData(filename);
	}
	if (type == "item") {
		cout << "inputing data to item" << endl;
		insertItemDate(filename);
	}
}*/