#include<regex>

#include"checkType.h"
#include"mysql.h"
string checkType(string code) {
	regex T("^T");
	regex S("^S");
	regex L("^L");
	if (regex_search(code, T)) {
		return "tent";
	}
	else if (regex_search(code, S)) {
		return "stove";
	}
	else if (regex_search(code, L)) {
		return "lantern";
	}
}