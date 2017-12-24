#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <vector>


class data
{
	unsigned int dia, mes, ano;

	std::string Mes;
	std::vector<std::string> meses = {"Janeiro", "Fevereiro","Marco", "Abril","Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };

public:

	data();
	data(unsigned int dia, unsigned int mes, unsigned int ano);
	~data();

	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAno() const;
	std::string getInfo() const;

	void setDia(unsigned int dia);
	void setMes(unsigned int mes);
	void setAno(unsigned int ano);

	bool operator==(const data& data1) const;
	bool operator<(const data& data1) const;

	

};

std::ostream& operator<<(std::ostream& os, const data& data1);




#endif