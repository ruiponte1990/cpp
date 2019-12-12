CXX = g++

CXXFLAGS = -Wall -g

.PHONY: hello clean

hello: hello.o
	$(CXX) $(CXXFLAGS) -o hello hello.o

clean:
	-rm hello hello.o