#include"mysql.h"
#include"byCategory.h"
void Output(MYSQL_RES *res_set) {
	MYSQL_ROW row;
	int i = 0;
	int num = mysql_num_fields(res_set);
	while (row = mysql_fetch_row(res_set)) {
		for (i = 0; i < num; i++) {
			//cout << row[i] << " ";
			printf("%s\t |", row[i]);

		}printf("\n");
		
	}cout << endl;
}
void category() {
	
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	
	mysql display;
	display.link();

	for (int i = 0; i < 3; i++) {
		string type[3] = { "tent", "stove", "lantern" };
		display.link();
		//cout << type[i];
		res_set = display.select_query("*", type[i], "where conditions ='good' and status = 'in'");
		cout << type[i] << endl;
		Output(res_set);
		mysql_free_result(res_set);
	}
	
}