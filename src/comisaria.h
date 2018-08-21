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
#include <time.h>
#include <windows.h>
using namespace std;

pthread_mutex_t situacion = PTHREAD_MUTEX_INITIALIZER;
int v_proceso, v_zona;
string zonas[4] = { "zona_A", "zona_B", "zona_C", "zona_D" };
int contzona[4] = { 0, 0, 0, 0 };
class Comisaria {

public:
	int max_patrullas;
	vector<pthread_t> hiloPatrullas;
	vector<Oficial*> oficiales;
	Comisaria(int, int);
	void* atenderSituacion(void*);
};

// Constructor de la clase comisaria
Comisaria::Comisaria(int max_patrulla) {
	this->max_patrullas = max_patrulla;
	for (int i = 0; i < max_patrulla; i++) {
		Oficial * nuevoOficial = new Oficial(i,i);
		this->oficiales.push_back(nuevoOficial);
	}
}

void* Comisaria::atenderSituacion(void* data) {
	srand(time(NULL));
	pthread_mutex_lock(&situacion);
	v_zona = rand() % 5;
	cout << "Patrulla " << (int) data << "atendiendo situacion en"
			<< zonas[v_zona] << endl;
	Sleep(500);
	contzona[v_zona]++; // Aumenta el contador de zona
	cout << "Patrulla en camino: estimando llegada" << rand() % 30 + 10
			<< "minutos" << endl;
	Sleep(1000);
	v_proceso = rand() % 11; // Variable que indica las situaciones en las que puede caer una patrulla

	//Situacion en la que puede atrapar a un delicuente
	if (v_proceso >= 0 && v_proceso <= 4) {
		if (rand() % 2 + 0 == 0) {
			cout << "Patrulla lleva detenido hacia la comisaria" << endl;
			Sleep((rand() % 4 + 1) * 1000);
			cout << "Patrulla " << (int) data << " llego a la central" << endl;
		} else {
			cout << "Patrulla tuvo incidente en el camino" << endl;
			Sleep((rand() % 4 + 1) * 1000);
			cout << "Patrulla " << (int) data << " llego a la central" << endl;
		}
	} else {
		//Situacion en la que pide refuerzos
		if (v_proceso > 4 && v_proceso <= 5) {
			cout << "Salen refuerzos " << rand() % 3 + 1
					<< " patrullas van en camino" << endl;
			Sleep((rand() % 2 + 0) * 1000);
			//Operacion aleatoria de a que refuerzo llamara si bombero o ambulancia
			if (rand() % 3 == 0) {
				cout << "Hay heridos patrulla requiere hambulancia" << endl;
				cout << "Ambulancia va en camino... " << endl;
				cout << "Ambulancia llego a " << zonas[v_zona] << endl;
				cout << "Ambulancia atendiendo heridos...." << endl;
				cout << "Policia patrullando zona..." << endl;
				Sleep(rand() % 4 + 1);
				cout
						<< "Se resolvio con los refuerzos, se capturo a los individuos"
						<< endl;
				cout << "Patrullas van en camino a comisaria, con los detenidos"
						<< endl;
				cout << "Ambulancia regresa a la central" << endl;
				cout << "Patrullas llegaron a comisaria" << endl;
				cout << "Patrulla regresa a la central" << endl;
				cout << "Ambulancia llego a la central" << endl;

			} else {
				if (rand() % 3 == 1) {
					cout << "Hay situacion critica patrulla requiere bomberos"
							<< endl;
					cout << "Bomberos van en camino... " << endl;
					cout << "Bombero llego a " << zonas[v_zona] << endl;
					cout << "Bombero atendiendo situacion" << endl;
					Sleep(rand() % 4 + 1);
					cout << "La situacion se resolvio " << endl;
					cout << "Patrullas vuelven a comisaria" << endl;
					cout << "Bomberos vuelven a central" << endl;
				}
			}

		} else {
			//Situacion en la que la situacion no se pudo solucionar
			if (v_proceso > 5 && v_proceso <= 10) {
				cout << "El delincuente escapo" << endl;
				cout << "Patrulla" << (int) data << "patrullando la zona"
						<< zonas[v_zona] << endl;
				Sleep((rand() % 2 + 0) * 1000);
				if (rand() % 2 == 0) {
					cout << "La patrulla encontro al delincuente" << endl;
					cout << "La patrulla vuelve a comisaria con el delicuente"
							<< endl;

				} else {
					cout << "La patrulla no encontro al delincuente" << endl;
					cout << "La patrulla vuelve a comisaria"
							<< endl;
				}
			 contzona[v_zona]++;
			}
		}
	}
	//Verificar las zonas conflictivas, en caso de ser mayor a 5 indica una zona con mucha incidencia
	for(int i = 0; i<4; i++){
		if(contzona[i]>=5){
			cout << "Se han detectado muchos delitos en  " << zonas[i] << " enviando patrulla a resguardar "<<endl;
			contzona[i] = 0;
		}
	}
	pthread_mutex_unlock(&situacion);

	return nullptr;
}

#endif /* COMISARIA_H_ */
