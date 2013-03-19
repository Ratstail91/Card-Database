#include "sqlite3.h"

#include <iostream>

using namespace std;

int main(int, char**) {
	sqlite3* db;

	if (sqlite3_open("magiccards.db",&db) != SQLITE_OK) {
		cerr << "Error: Failed to open database; " << sqlite3_errmsg(db) << endl;
		return 1;
	}

	cout << "Program is operating correctly." << endl;

#ifdef DEBUG
	cout << "Debug check complete." << endl;
#endif

#ifdef FOOBAR
	cout << "Foobar check complete." << endl;
#endif

	sqlite3_close(db);
	return 0;
}