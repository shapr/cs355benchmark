#
# My first Makefile, whee!
#

CXX = g++
CXXFLAGS = -pedantic -Wno-long-long -Wno-missing-field-initializers -Wall -W -Wundef -Wendif-labels -Wshadow -Wcast-align -Wwrite-strings -Wdisabled-optimization -Wold-style-cast -Woverloaded-virtual -O2 -pipe -ffor-scope -fno-gnu-keywords

.PHONY: all

all: BenchDriver # fraction.o fracmain

# abstractarray absary

BenchDriver: BenchDriver.o

BenchDriver.o: BenchDriver.h

myprogram: abstractarray.o absary.o
	$(CXX) $+ -o $@

