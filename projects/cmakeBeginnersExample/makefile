CXX = g++
CXXFLAGS = -Wall -std=c++11

calculator: main.o add.o subtract.o
	$(CXX) main.o add.o subtract.o -o calculator

main.o: main.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c main.cpp

add.o: add.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c add.cpp

subtract.o: subtract.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c subtract.cpp

clean:
	rm -f *.o calculator