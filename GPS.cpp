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

	double a = pow(sin(this->graus - gp2.graus), 2) + cos(this->)

}



unsigned int GPS::getGraus() const {
	return graus;
}
unsigned int GPS::getMinutos() const {
	return minutos;
}
unsigned int GPS::getSegundos() const {
	return segundos;
}

ostream & operator<< (ostream & os,const GPS & input) {

	return (os << input.getGraus() << "º" << input.getMinutos() << '\'' << input.getSegundos() << '\"');
}