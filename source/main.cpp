#include "sqlite3.h"

#include "operations.h"

#include <iostream>
#include <string>

using namespace std;

int main(int, char**) {
	sqlite3* db;

	if (sqlite3_open("cards.db",&db) != SQLITE_OK) {
		cerr << "Error: Failed to open database; " << sqlite3_errmsg(db) << endl;
		return 1;
	}

	cout << "Card Database by Kayne Ruse" << endl;

	//TODO: run initial startup scripts

	bool running = true;
	string input;

	while(running) {
		cout << "Choose an option: [S]earch, [N]ew, [U]pdate, [D]elete or [Q]uit?" << endl;
		cout << PROMPT;
		getline(cin, input);

		switch(input[0]) {
			case 's':
			case 'S':
				Search(db);
			break;

			case 'n':
			case 'N':
				New(db);
			break;

			case 'u':
			case 'U':
				Update(db);
			break;

			case 'd':
			case 'D':
				Delete(db);
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