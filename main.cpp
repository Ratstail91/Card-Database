#include "sqlite3.h"

#include <iostream>
#include <string>

using namespace std;

int main(int, char**) {
	sqlite3* db;

	if (sqlite3_open("magiccards.db",&db) != SQLITE_OK) {
		cerr << "Error: Failed to open database; " << sqlite3_errmsg(db) << endl;
		return 1;
	}

	bool running = true;
	string input;

	cout << "Card Database by Kayne Ruse" << endl;

	while(running) {
		cout << "Choose an option: [S]earch, [N]ew, [U]pdate, [D]elete or [Q]uit?" << endl;
		cout << ">>";
		getline(cin, input);

		switch(input[0]) {
			case 's':
			case 'S':
				cerr << "Feature unimplemented" << endl;
			break;

			case 'n':
			case 'N':
				cerr << "Feature unimplemented" << endl;
			break;

			case 'u':
			case 'U':
				cerr << "Feature unimplemented" << endl;
			break;

			case 'd':
			case 'D':
				cerr << "Feature unimplemented" << endl;
			break;

			case 'q':
			case 'Q':
				running = false;
			break;

			default:
				cerr << "Unknown command, try again" << endl;
		}

		cout << endl;
	}

	cout << "Closing application" << endl;

	sqlite3_close(db);
	return 0;
}