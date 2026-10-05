CXX = g++
CXXFLAGS = -Wall -g

all: calc_app

calc_app: main.o libcalculator.a
	$(CXX) $(CXXFLAGS) -o calc_app main.o -L. -lcalculator

main.o: main.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c main.cpp

libcalculator.a: calculator.o
	ar rcs libcalculator.a calculator.o

calculator.o: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c calculator.cpp

clean:
	rm -f *.o *.a calc_app
