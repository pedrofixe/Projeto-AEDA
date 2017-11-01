main: GPS.cpp GPS.h praias.cpp praias.h test.cpp
	g++ GPS.cpp praias.cpp test.cpp -std=c++11 -g -o main -g

clean : 
	rm -f *.o 
	rm -f *.d
	rm -f main
