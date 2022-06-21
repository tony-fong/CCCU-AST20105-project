#include"mysql.h"
#include"user.h"
#include"loan.h"
void loan() {
	mysql loan;

	MYSQL_RES *res_set;
	MYSQL_ROW row;
	int num;

	loan.link();
	res_set = loan.select("*", "borrow", "userID", USER.getID());
	num = mysql_num_fields(res_set);
	//cout << num << endl;
	while (row = mysql_fetch_row(res_set)) {
		for (int i = 0; i < num; i++) {
			if (row[6] == NULL && row[i] != NULL) {
				cout << row[i];
				cout << " | ";
			}
		}cout << endl;
	}
	
}

