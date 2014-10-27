/*
 * Quarto.h
 *
 *  Created on: 27/10/2014
 *      Author: John Doe
 */

#ifndef SRC_QUARTO_H_
#define SRC_QUARTO_H_

/*Includes for this class*/
#include <string>
using namespace std;



class Quarto{
	float base_price;
	float tax; /*Taxa de location (Se frente X se trazeira Y)*/
	string location;
public:
	Quarto(string location);
	float get_base_price(){return base_price;}
	void set_base_price(float price);
	string get_location(){return location;}
	void set_tax(float taxa){this->tax=taxa; return;}
	float get_tax(){return this->tax;}
	virtual float get_cost() = 0;
	virtual int get_id() = 0;
};

class Simples : public Quarto{
	int id;
	static int _ID;
public:
	Simples(string location);
	float get_cost();
	int get_id(){return this->id;}
};

class Duplo : public Quarto{
	int id;
	static int _ID;
public:
	Duplo(string location);
	float get_cost();
	int get_id(){return this->id;}
};



#endif /* SRC_QUARTO_H_ */
