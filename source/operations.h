#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include "sqlite3.h"

int Search(sqlite3*);
int New(sqlite3*);
int Update(sqlite3*);
int Delete(sqlite3*);

#define PROMPT ">>"

#endif
