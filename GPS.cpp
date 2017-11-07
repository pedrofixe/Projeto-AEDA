#include "GPS.h"

#include <cmath>

#define pi atan(1)*4

using namespace std;

GPS::GPS()
{}


GPS::GPS(unsigned int graus, unsigned int minutos, unsigned int segundos) : graus(graus), minutos(minutos), segundos(segundos){
	if (0 > graus > 90 || 0 > minutos > 60 || 0 > segundos > 60)
		throw CoordenadasErradas(*this);
}


double degreesToRadians(double input) {

	return (input*pi/180);
}

double GPS::distance(const GPS & gps2) {

	

}



double GPS::getLatitude() const {
	return latitude;
}
double GPS::getLatitude() const {
	return longitude;
}


ostream & operator<< (ostream & os,const GPS & input) {

	return (os << input.getLatitude() << " , " << input.getLongitude());
}