//============================================================================
// Name        : 911.cpp
// Author      : Grupo # 2 
// Version     :
// Copyright   : Proyecto de la clase de Sistemas Operativos
//============================================================================

#include <iostream>
using namespace std;
#include "oficial.h"

int main() {

	Oficial of = Oficial(1,1);
	cout << "Tipo de oficial:" <<of.getTipoOficial() << endl;
	cout << "Jornada:" << of.getJornada() << endl;
	cout << "Arma: " << of.getArma() << endl;
	return 0;
}
