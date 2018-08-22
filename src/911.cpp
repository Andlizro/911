//============================================================================
// Name        : 911.cpp
// Author      : Grupo # 2 
// Version     :
// Copyright   : Proyecto de la clase de Sistemas Operativos
//============================================================================

#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
#include "comisaria.h"
#include "Hospital.h"
int max_patrullas = 10;
int main() {
	
	int njor;
	string jor[4]={"Matutina","Vespertina","Nocturna","Madrugada"};
	njor = rand() % 4;
	cout << "Se esta trabajando en jornada: "<<jor[njor];
	pthread_t hilosPatrulla[3];
	for (int i = 0; i < 3; i++) {
		//Asi se realiza el llamado del hilo de hospital
		//pthread_create(&hilosPatrulla[i],nullptr,Hospital::atenderMedico,nullptr);
		//Asi se realiza el llamado del hilo de comisaria
		pthread_create(&hilosPatrulla[i], nullptr,Comisaria::atenderSituacion, nullptr);
	}

	pthread_join(hilosPatrulla[0], nullptr);
	pthread_join(hilosPatrulla[1], nullptr);
	pthread_join(hilosPatrulla[2], nullptr);

	return 0;
}
