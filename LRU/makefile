CXX = g++

CXXFLAGS = -Wall -g -std=c++11

.PHONY: clean

testList: testList.o
	$(CXX) $(CXXFLAGS) -o testList testList.o

testHashMap: testHashMap.o
	$(CXX) $(CXXFLAGS) -o testHashMap testHashMap.o

testLRU: testLRU.o
	$(CXX) $(CXXFLAGS) -o testLRU testLRU.o

clean:
	-rm -f testList testList.o testHashMap testHashMap.o testLRU testLRU.o