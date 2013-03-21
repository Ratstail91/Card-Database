#include "operations.h"

#include "console_colors.h"
#include "counter.h"

#include "sqlite3.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int SearchCallback(void* cp, int columnCount, char** entries, char** columnNames) {
	Counter& counter = *((Counter*)(cp));

	//table title
	if (counter.calls == 0) {
		for (int i = 0; i < columnCount; i++) {
			cout << left << setw(15) << columnNames[i];
		}
		cout << endl;
	}

	//each entry
	for (int i = 0; i < columnCount; i++) {
		ccset(FG_YELLOW);
		cout << left << setw(15) << entries[i];
	}
	cout << endl;

	ccset(CONSOLE_DEFAULT);

	//24 entries to a page
	counter++;
	if (counter.calls % 24 == 0) {
		cout << "Press any key to continue, or Q to quit now . . . ";
		char c = cin.get();
		if (c == 'q' || c == 'Q') {
			return 1;
		}
	}

	return 0;
}

int Search(sqlite3* db) {
	cout << "Enter your search parameters:" << endl;
	cout << PROMPT;

	string input, query = "SELECT card_name, mana_cost, power, toughness FROM card_list";
	getline(cin, input);

	//leave blank to search the entire database
	if (input.size() > 0) {
		query = query + " WHERE " + input + ";";
	}
	else {
		query += ";";
	}

	cout << "Searching..." << endl;

	char* errmsg = NULL;
	Counter c;
	sqlite3_exec(db, query.c_str(), &SearchCallback, (void*)(&c), &errmsg);

	if (errmsg) {
		cerr << "Error: " << errmsg << endl;
		sqlite3_free(errmsg);
		return 1;
	}

	return 0;
}