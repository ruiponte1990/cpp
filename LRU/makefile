CXX = g++

CXXFLAGS = -Wall -g -std=c++11

.PHONY: clean

# this will be where you put the final LRU rule
# all: testLRU.o
# 	$(CXX) $(CXXFLAGS) -o testLRU testLRU.o

testList: testList.o
	$(CXX) $(CXXFLAGS) -o testList testList.o

testHashMap: testHashMap.o
	$(CXX) $(CXXFLAGS) -o testHashMap testHashMap.o

clean:
	-rm -f testList testList.o testHashMap testHashMap.o