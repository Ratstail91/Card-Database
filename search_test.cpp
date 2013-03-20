#include "sqlite3.h"

#include <iostream>
#include <iomanip>

using namespace std;

int search(void* first, int columnCount, char** entries, char** columnNames) {
	//only a max of 5 columns accepted
	if (columnCount > 5) {
		return 1;
	}

	//print the column headers
	if (*(bool*)(first)) {
		*(bool*)(first) = false;
		for (int i = 0; i < columnCount; i++) {
			cout << left << setw(15) << columnNames[i];
		}
		cout << endl;
	}

	//print each entry
	for (int i = 0; i < columnCount; i++) {
		cout << left << setw(15) << entries[i];
	}
	cout << endl;
	return 0;
}

int main(int, char**) {
	char* errmsg = NULL;
	sqlite3 *db;
	if (sqlite3_open("cards.db", &db) != SQLITE_OK) {
		cerr << "Failed to open the database; " << sqlite3_errmsg(db) << endl;
		return 1;
	}

	bool first = true;
	sqlite3_exec(db, "SELECT card_name, mana_cost, power, toughness FROM card_list", search, (void*)&first, &errmsg);

	if (errmsg) {
		cerr << "Failed to execute; " << errmsg << endl;
		sqlite3_free(errmsg);
	}

	sqlite3_close(db);
	return 0;
}
