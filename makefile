main: praias.cpp praias.h test.cpp
	g++ praias.cpp test.cpp -g -o main -g

clean : 
	rm -f *.o 
	rm -f main
