#ifndef GPS_H
#define GPS_H

#include <iostream>

class GPS {

	double latitude;
	double longitude;
public:

	GPS();
	GPS(double latitude, double longitude);
	double distance(const GPS & gps2);
	double getLatitude() const;
	double getLongitude() const;
	

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