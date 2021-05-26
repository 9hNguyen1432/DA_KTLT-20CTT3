#include "Header.h"
void delete_space(string& str) {
	string temp;
	int i;
	for (i = str.length()-1; i>=0; i--) {
		if (str[i] == ' ') {
			continue;
		}
		else {
			break;
		}
	}
	for(int j = 0; j <= i; j++) {
		str[j] = temp[j];
	}
	return;
}