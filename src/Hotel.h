/*
 * Hotel.h
 *
 *  Created on: 27/10/2014
 *      Author: John Doe
 */

#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_
#include "Quarto.h"
#include<vector>
#include<iostream>
using namespace std;

class Hotel{
	float quarto_base_price;
	float quarto_frente_tax;
	float quarto_tras_tax;
	vector<Quarto *> quartos;
	float sala_base_price;

public:
	Hotel(){}
	vector<Quarto *> get_quartos(){return this->quartos;}
	void add_quarto(Quarto *q);
	void set_quarto_base_price(float price){this->quarto_base_price = price; return;}
	void set_sala_base_price(float price){this->sala_base_price = price; return;}
	float get_quarto_base_price(){return this->quarto_base_price;}
	void set_quarto_frente_tax(float tax){this->quarto_frente_tax = tax; return;}
	void set_quarto_tras_tax(float tax){this->quarto_tras_tax = tax; return;}
	void update_quartos_tax();
	//void update_quarto_base();
	float get_quarto_tax(string location);
};


#endif /* SRC_HOTEL_H_ */
