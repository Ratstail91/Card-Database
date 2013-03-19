CC=g++
CXXFLAGS=-std=c++0x
DFLAGS=-DDEBUG
LIB=
OBJ=sqlite3.o
SRC=hello.cpp

all: debug

release: $(OBJ)
	$(CC) $(CXXFLAGS) $(SRC) $(OBJ) $(LIB)

debug: $(OBJ)
	$(CC) $(CXXFLAGS) $(DFLAGS) $(SRC) $(OBJ) $(LIB)

clean:
	del *.o *.exe *.db

sqlite3.o:
	gcc -c sqlite3.c
