make: 
	g++ -std=c++11 src/*.cpp -o game -Iinclude -L. -ltcod -ltcodxx -Wl,-rpath=. -Wall


run:
	./game

