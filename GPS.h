#ifndef GPS_H
#define GPS_H

#include <iostream>

class GPS {

	unsigned int graus;
	unsigned int minutos;
	unsigned int segundos;
public:

	GPS();
	GPS(unsigned int graus, unsigned int minutos, unsigned int segundos);
	double distance(const GPS & gps2);
	unsigned int getGraus() const;
	unsigned int getMinutos() const;
	unsigned int getSegundos() const;

};
std::ostream& operator <<(std::ostream & os,const GPS & input);


class CoordenadasErradas {
	
	GPS input;

public:

	CoordenadasErradas(GPS input);

	GPS getGPS()
	{
		return input;
	}


};


#endif