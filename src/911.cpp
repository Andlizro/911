//============================================================================
// Name        : 911.cpp
// Author      : Grupo # 2 
// Version     :
// Copyright   : Proyecto de la clase de Sistemas Operativos
//============================================================================

#include <iostream>
using namespace std;
#include "comisaria.h"
int max_patrullas = 10;
int main() {

	pthread_t hilosPatrulla[3];
	for(int i=0; i<3;i++){
	pthread_create(&hilosPatrulla[i],nullptr,Comisaria::atenderSituacion,nullptr);
	}



	pthread_join(hilosPatrulla[0],nullptr);
	pthread_join(hilosPatrulla[1],nullptr);
	pthread_join(hilosPatrulla[2],nullptr);


	return 0;
}
