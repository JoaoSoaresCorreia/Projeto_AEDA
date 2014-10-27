/*
 * Hotel.cpp
 *
 *  Created on: 27/10/2014
 *      Author: John Doe
 */
#include "Hotel.h"

void Hotel::update_quartos_tax() {

	for (unsigned int i = 0; i < quartos.size(); i++) {
		cout<<quartos[i]->get_location()<<endl;
		cout<<get_quarto_tax(quartos[i]->get_location())<<endl;
		float k = get_quarto_tax(quartos[i]->get_location());
		cout<<"K= "<<k<<endl;
		quartos[i]->set_tax(k);
		cout<<quartos[i]->get_tax()<<endl;
	}

	return;
}

float Hotel::get_quarto_tax(string location) {

	if (location == "frente")
		return this->quarto_frente_tax;
	else if (location == "traseiras")
		return this->quarto_tras_tax;

	return 10;
}

void Hotel::add_quarto(Quarto *q){

	q->set_base_price(this->quarto_base_price);
	this->quartos.push_back(q);

	/*
	 * Problema: Preço base engloba quarto simples e duplo e depois faz-se um add ao preço base para quartos duplos
	 * -------------------------------------------------OU---------------------------------------------------------
	 * Tem que se arranjar maneira para se adicionar um preço base para quartos simples e quartos duplos!!!!!!!!!!
	 * */

}

/*
void Hotel::update_quarto_base() {

	if(quartos.size() != 0){
		quartos[0]->set_base_price(this->quarto_base_price);
	}

	return;
}
*/
