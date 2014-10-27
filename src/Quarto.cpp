/*
 * Quarto.cpp
 *
 *  Created on: 27/10/2014
 *      Author: John Doe
 */
#include"Quarto.h"

int Simples::_ID=0;
int Duplo::_ID=0;

Quarto::Quarto(string location) {
	this->location = location;
	this->base_price=0;
	this->tax=0;
}

void Quarto::set_base_price(float price){
	base_price=price;
	return;
}


Simples::Simples(string location):Quarto(location), id(_ID+=1){
}

float Simples::get_cost(){
	return Quarto::get_base_price() + Quarto::get_tax()*Quarto::get_base_price();
}

Duplo::Duplo(string location):Quarto(location), id(_ID+=1){
}

float Duplo::get_cost(){
	return Quarto::get_base_price() + Quarto::get_tax()*Quarto::get_base_price();
}
