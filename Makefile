CXX=g++
CXXFLAGS=-std=c++11

all: 
	$(CXX) $(CXXFLAGS) Main.cpp Member.cpp Member.h -o a.out
	./a.out
	$(CXX) $(CXXFLAGS) Test.cpp Member.cpp Member.h -o Test.out
	./Test.out
