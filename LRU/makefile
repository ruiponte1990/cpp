CXX = g++

CXXFLAGS = -Wall -g -std=c++11

.PHONY: testList clean

testList: testList.o
	$(CXX) $(CXXFLAGS) -o testList testList.o

clean:
	-rm testList testList.o 