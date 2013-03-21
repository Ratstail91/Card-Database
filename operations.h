#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include "sqlite3.h"

void Search(sqlite3*);
void New(sqlite3*);
void Update(sqlite3*);
void Delete(sqlite3*);

#define PROMPT ">>"

#endif
