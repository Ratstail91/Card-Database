CXXFLAGS+=-std=c++0x -static
DFLAGS=-DDEBUG
LIB=
OBJ=sqlite3.o console_colors.o
SRC=main.cpp operations.cpp search.cpp

all: debug

release: $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) $(OBJ) $(LIB)

debug: $(OBJ)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(SRC) $(OBJ) $(LIB)

clean:
	-$(RM) *.o *.exe *.db

shell: $(OBJ)
	$(CC) $(CFLAGS) -o sqlite3 shell.c $(OBJ)
