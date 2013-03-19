RM=del
CXXFLAGS=-std=c++0x
DFLAGS=-DDEBUG
LIB=
OBJ=sqlite3.o
SRC=main.cpp

all: debug

release: $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) $(OBJ) $(LIB)

debug: $(OBJ)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(SRC) $(OBJ) $(LIB)

clean:
	$(RM) *.o *.exe *.db

sqlite3.o:
	$(CC) -c sqlite3.c
