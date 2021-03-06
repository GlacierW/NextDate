# Project: NextDate

CPP       = g++
CC        = gcc
OBJ       = gtest_main.o nextdate.o nextdate_unittest.o
LINKOBJ   = gtest_main.o nextdate.o nextdate_unittest.o
LINKFLAGS = -lgtest -pthread -lgcov
BIN       = gtest_nextdate
CXXFLAGS  = -Wall -fprofile-arcs -ftest-coverage
CFLAGS    = -Wall -fprofile-arcs -ftest-coverage
RM        = rm -f
GCOV_FILE = *.gcno *.gcda *.gcov

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN) $(GCOV_FILE)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS) $(LINKFLAGS)

gtest_main.o: gtest_main.cc
	$(CPP) -c gtest_main.cc -o gtest_main.o $(CXXFLAGS)

nextdate.o: nextdate.cc
	$(CPP) -c nextdate.cc -o nextdate.o $(CXXFLAGS)

nexdate_unittest.o: nexdate_unittest.cc
	$(CPP) -c nexdate_unittest.cc -o nexdate_unittest.o $(CXXFLAGS)
