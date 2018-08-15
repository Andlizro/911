/*
 * comisaria.h
 *
 *  Created on: 14 ago. 2018
 *      Author: Usuario
 */

#ifndef COMISARIA_H_
#define COMISARIA_H_
#include <pthread.h>
#include <iostream>
#include <vector>
#include "oficial.h"
using namespace std;
class Comisaria{

	public:
		int max_patrullas,idPatrulla;
		vector<pthread_t> hiloPatrullas;
		vector<Oficial*> oficiales;
		Comisaria(int,int);
		void* atenderSituacion(void*);
};

// Constructor de la clase comisaria
Comisaria::Comisaria(int max_patrulla, int idPatrulla){
	this->idPatrulla = idPatrulla;
	this->max_patrullas = max_patrulla;
	for(int i = 0; i< max_patrulla; i++){
		Oficial * nuevoOficial = new Oficial(i,this->idPatrulla);
		this->oficiales.push_back(nuevoOficial);
	}
}


void* Comisaria::atenderSituacion(void* data){


	return nullptr;
}


#endif /* COMISARIA_H_ */
