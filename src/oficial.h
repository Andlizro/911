/*
 * oficial.h
 *
 *  Created on: 14 ago. 2018
 *      Author: Usuario
 */

#ifndef OFICIAL_H_
#define OFICIAL_H_
#include <stdlib.h>
#include <time.h>


class Oficial{

private:
	int tipo_oficial;
	int arma;
	int id_oficial;
	int id_patrulla;
	int jornada;
public:
	Oficial(int,int,int,int,int);
	Oficial(int,int);
	int getTipoOficial();
	int getArma();
	int getID();
	int getJornada();
	void setTipoOficial(int);
	void setArma(int);
	void setID(int);
	void setJornada(int);
};

Oficial::Oficial(int arma, int tipo, int id, int jornada,int patrulla){
	this->arma = arma;
	this->tipo_oficial = tipo;
	this->id_oficial = id;
	this->jornada= jornada;
	this->id_patrulla = patrulla;
}

Oficial::Oficial(int id_oficial, int id_patrulla){
	srand(time(NULL));
	this->id_oficial = id_oficial;
	this->id_patrulla = id_patrulla;
	this->jornada = rand() % 5;
	this->tipo_oficial =  rand() % 6;
	this->arma =  rand() % 7;
}

/* Get's*/
int Oficial::getArma(){
	return this->arma;
}

int Oficial::getID(){
	return this->id_oficial;
}

int Oficial::getJornada(){
	return this->jornada;
}

int Oficial::getTipoOficial(){
	return this->tipo_oficial;
}

//Sets

void Oficial::setArma(int arma){
	this->arma = arma;
}

void Oficial::setID(int id){
	this->id_oficial = id;
}

void Oficial::setJornada(int jornada){
	this->jornada = jornada;
}

void Oficial::setTipoOficial(int to){
	this->tipo_oficial = to;
}
#endif /* OFICIAL_H_ */
