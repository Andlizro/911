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
int id_patrulla;
class Comisaria {

public:
	int max_patrullas;
	vector<pthread_t> hiloPatrullas;
	vector<Oficial*> oficiales;
	Comisaria(int);
	static void* atenderSituacion(void* data) {

		pthread_mutex_lock(&situacion);

		srand(time(NULL));
		v_zona = rand() % 4;
		id_patrulla = rand() % 10;
		cout << "---------------------------------------------" << endl;
		cout << "Patrulla  " << id_patrulla << " atendiendo situacion en "
				<< zonas[v_zona] << endl;
		cout << "---------------------------------------------" << endl;
		Sleep(1000);
		contzona[v_zona]++; // Aumenta el contador de zona
		cout << "Patrulla en camino: estimando llegada " << rand() % 30 + 10
				<< " minutos" << endl;
		Sleep(1000);
		v_proceso = rand() % 2; // Variable que indica las situaciones en las que puede caer una patrulla
		cout << "v_proceso " << v_proceso << endl;
		//Situacion en la que puede atrapar a un delicuente
		if (v_proceso == 0) {
			if (rand() % 2 == 0) {
				cout << "Patrulla lleva detenido hacia la comisaria" << endl;
				Sleep(5000);
				cout << "Patrulla " << id_patrulla << "  llego a la central"
						<< endl;
			} else {
				cout << "La patrulla tuvo incidente en el camino" << endl;
				Sleep(5000);
				cout << "Patrulla " << id_patrulla << "  llego a la central"
						<< endl;
			}
		} else {
			//Situacion en la que pide refuerzos
			if (v_proceso == 1) {

				cout << "Salen refuerzos: " << rand() % 3 + 1
						<< " patrullas van en camino" << endl;

				//Operacion aleatoria de a que refuerzo llamara si bombero o ambulancia
				if (rand() % 3 == 0) {
					cout << "Hay heridos patrulla requiere ambulancia" << endl;
					Sleep(1000);
					cout << "Ambulancia va en camino... " << endl;
					Sleep(1000);
					cout << "Ambulancia llego a " << zonas[v_zona] << endl;
					Sleep(1000);
					cout << "Ambulancia atendiendo heridos...." << endl;
					Sleep(1000);
					cout << "Policia patrullando zona..." << endl;
					Sleep(1000);
					Sleep(rand() % 4 + 1);
					cout
							<< "Se resolvio con los refuerzos, se capturo a los individuos"
							<< endl;
					Sleep(1000);
					cout
							<< "Patrullas van en camino a comisaria, con los detenidos"
							<< endl;
					Sleep(1000);
					cout << "Ambulancia regresa a la central" << endl;
					Sleep(1000);
					cout << "Patrullas llegaron a comisaria" << endl;

				} else {
					if (rand() % 3 == 1) {
						cout
								<< "Hay situacion critica patrulla requiere bomberos"
								<< endl;
						Sleep(500);
						cout << "Bomberos van en camino... " << endl;
						Sleep(1000);
						cout << "Bombero llego a " << zonas[v_zona] << endl;
						Sleep(1000);
						cout << "Bombero atendiendo situacion" << endl;
						Sleep(5000);
						cout << "La situacion se resolvio " << endl;
						Sleep(1000);
						cout << "Patrullas vuelven a comisaria" << endl;
						Sleep(1000);
						cout << "Bomberos vuelven a central" << endl;
					} else {
						if (rand() % 3 == 2) {
							cout
									<< "Las patrullas llegaron  a auxiliar patrulla  "
									<< id_patrulla << endl;
							Sleep(500);
							cout << "Patrullas atendiendo situacion " << endl;
							Sleep(3000);
							if (rand() % 2 == 0) {
								cout << "Las patrullas encontraron al delincuente"
										<< endl;
								Sleep(1000);
								cout
										<< "Las patrullas vuelven a comisaria"
										<< endl;

							} else {
								cout << "Las patrullas perdieron al delicuente"
										<< endl;
								Sleep(1000);
								cout << "Los refuerzos vuelven a comisaria"
										<< endl;
							}

						}
					}
				}

			} else {
				//Situacion en la que la situacion no se pudo solucionar
				if (v_proceso == 2) {
					cout << "El delincuente escapo" << endl;
					cout << "Patrulla" << id_patrulla << " patrullando la zona"
							<< zonas[v_zona] << endl;
					Sleep(500);
					if (rand() % 2 == 0) {
						cout << "La patrulla encontro al delincuente" << endl;
						Sleep(1000);
						cout
								<< "La patrulla vuelve a comisaria con el delicuente"
								<< endl;

					} else {
						cout << "La patrulla no encontro al delincuente"
								<< endl;
						Sleep(1000);
						cout << "La patrulla vuelve a comisaria" << endl;
					}
					contzona[v_zona]++;
				}
			}
		}
		//Verificar las zonas conflictivas, en caso de ser mayor a 5 indica una zona con mucha incidencia
		for (int i = 0; i < 4; i++) {
			if (contzona[i] >= 5) {
				cout << "Se han detectado muchos delitos en  " << zonas[i]
						<< " enviando patrulla a resguardar " << endl;
				contzona[i] = 0;
			}
		}
		cout << "------------------------------------------" << endl;
		pthread_mutex_unlock(&situacion);

		return nullptr;
	}
};

// Constructor de la clase comisaria
Comisaria::Comisaria(int max_patrulla) {
	this->max_patrullas = max_patrulla;
	for (int i = 0; i < max_patrulla; i++) {
		Oficial * nuevoOficial = new Oficial(i, i);
		this->oficiales.push_back(nuevoOficial);
	}
}

#endif /* COMISARIA_H_ */
