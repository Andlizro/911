/*
 * Hospital.h
 *
 *  Created on: 21 ago. 2018
 *      Author: RRodriguez
 */

#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include <iostream>
using namespace std;
#include <time.h>
#include <windows.h>

pthread_mutex_t situacion_medica = PTHREAD_MUTEX_INITIALIZER;
int v_procesoM, id_ambulancia, v_ta, v_herida, v_accidente, v_enfermedad,v_golpe, v_ambulancia,v_quemadura,v_intox;
string tipo_accidente[3] = { "Grave", "Muy grave", "Leve" };
string heridas[6] = { "Fractura", "Quemadura", "Disparo", "Accidente", "Intoxicacion","Enfermedad" };
string ambulancia[2] = { "UVI movil", "Ambulancia" };
string c_accidente[4] = { "Choque", "Ebriedad", "Ir al volante con el telefono","Distraido" };
string c_enfermedad[4] = { "Problemas con el higado", "Convulsiones","Malestar", "Problemas respiratorios" };
string c_golpe[4] = { "Bajando las escaleras", "Caida de un edificio", "Caida en bicicleta", "Caida por deslizon" };
string c_quemadura[3] = {"explosivos","fuego", "mal uso de la cocina"};
string c_intoxicacion[4] = {"Comida vencida","Alcoholizacion", "Pesticidas","Productos Quimicos"};


class Hospital{
public:
static void * atenderMedico(void*) {
	pthread_mutex_lock(&situacion_medica);
	srand(time(NULL));
	//Variables del proceso
	v_procesoM = rand() % 6; // Variable de manejo del proceso
	v_ambulancia = rand() % 2; // Tipo de ambulancia
	id_ambulancia = 1 + rand() % 10; // ID de la ambulancia
	v_herida = rand() % 6; // Tipo de herida
	v_golpe = rand() % 4; // Tipo de golpe
	v_zona = rand()%6; // Zona del incidente
	v_ta = rand() %3; // Tipo de accidente
	v_quemadura = rand()%3; //Tipo de quemadura
	v_intox = rand() %4; // Tipo de intoxicacion

	cout << "El hospital recibe solicitud de situacion " << tipo_accidente[v_ta] << endl; Sleep(1000);

	switch(v_procesoM){
				case 0:	//Atencion de fracturas
					cout << "Causa de la urgencia:" << heridas[0] << endl; Sleep(1000);
					cout << "El hospital decidio enviar " << ambulancia[v_ambulancia] <<endl; Sleep(1000);
					cout << ambulancia[v_ambulancia] << " "<< id_ambulancia <<" va en camino a " << zonas[v_zona] << endl; Sleep(3000);
					cout << "La ambulancia llego " << endl; Sleep(1000);
					cout << "Causa de la herida: " << c_golpe[v_golpe] << endl;Sleep(1000);
					cout << ambulancia[v_ambulancia] << " regresa al hospital con el herido" << endl; Sleep(4000);
					cout << ambulancia[v_ambulancia] << " llega al hospital" << endl;
				break;
				case 1: // Atencion de Quemaduras
					cout << "Causa de la urgencia:" << heridas[1] << endl; Sleep(1000);
					cout << "El hospital decidio enviar " << ambulancia[v_ambulancia] <<endl; Sleep(1000);
					cout << ambulancia[v_ambulancia] <<" "<< id_ambulancia << " va en camino a " << zonas[v_zona] << endl; Sleep(3000);
					cout << "La ambulancia llego " << endl; Sleep(1000);
					cout << "Causa de la herida: " << c_quemadura[v_quemadura] << endl;Sleep(1000);
					cout << ambulancia[v_ambulancia] << " regresa al hospital con el herido" << endl; Sleep(4000);
					cout << ambulancia[v_ambulancia] << " llega al hospital" << endl;
				break;
				case 2: // Atencion de disparos
					cout << "Causa de la urgencia:" << heridas[2] << endl; Sleep(1000);
					cout << "El hospital decidio enviar " << ambulancia[v_ambulancia] <<endl; Sleep(1000);
					cout << ambulancia[v_ambulancia] <<" "<< id_ambulancia << " va en camino a " << zonas[v_zona] << endl; Sleep(3000);
					cout << "La ambulancia llego " << endl; Sleep(1000);
					if(rand()%2==0){
						cout << "¡Hay un delincuente en la zona!" << endl; Sleep(1000);
						cout << "Ambulancia decidio pedir refuerzos policiacos " << endl;Sleep(1000);
						cout << "La policia va en camino..." << endl; Sleep(3000);
						cout << "La policia llego" << endl; Sleep(1000);
						cout << "La policia detiene al delincuente" << endl; Sleep(1000);
						cout << "La policia regresa a comisaria con el delincuente" << endl; Sleep(1000);
						cout << "La ambulancia atiende al herido" << endl; Sleep(1000);

					}else{
						cout << "La ambulancia atiende al herido" << endl; Sleep(1000);

					}
					cout << ambulancia[v_ambulancia] << " regresa al hospital con el herido" << endl; Sleep(4000);
					cout << ambulancia[v_ambulancia] << " llega al hospital" << endl;
				break;
				case 3: //Atencion de accidentes
					cout << "Causa de la urgencia:" << heridas[3] << endl; Sleep(1000);
					cout << "El hospital decidio enviar " << ambulancia[v_ambulancia] <<endl; Sleep(1000);
					cout << ambulancia[v_ambulancia] <<" "<< id_ambulancia << " va en camino a " << zonas[v_zona] << endl; Sleep(3000);
					cout << "La ambulancia llego " << endl; Sleep(1000);
					cout << "Causa del accidente: " << c_accidente[v_accidente] << endl;Sleep(1000);
					cout << ambulancia[v_ambulancia] << " regresa al hospital con el herido" << endl; Sleep(4000);
					cout << ambulancia[v_ambulancia] << " llega al hospital" << endl;
				break;
				case 4: // Atencion de intxocacion
					cout << "Causa de la urgencia:" << heridas[4] << endl; Sleep(1000);
					cout << "El hospital decidio enviar " << ambulancia[v_ambulancia] <<endl; Sleep(1000);
					cout << ambulancia[v_ambulancia] << " "<< id_ambulancia <<" va en camino a " << zonas[v_zona] << endl; Sleep(3000);
					cout << "La ambulancia llego " << endl; Sleep(1000);
					cout << "Causa de la intoxicacion: " << c_intoxicacion[v_intox] << endl;Sleep(1000);
					cout << ambulancia[v_ambulancia] << " regresa al hospital con el herido" << endl; Sleep(4000);
					cout << ambulancia[v_ambulancia] << " llega al hospital" << endl;
				break;
				case 5: // Atencion de enfermedades
					cout << "Causa de la urgencia:" << heridas[5] << endl; Sleep(1000);
					cout << "El hospital decidio enviar " << ambulancia[v_ambulancia] <<endl; Sleep(1000);
					cout << ambulancia[v_ambulancia] << " "<< id_ambulancia <<" va en camino a " << zonas[v_zona] << endl; Sleep(3000);
					cout << "La ambulancia llego " << endl; Sleep(1000);
					cout << "Causa de la urgencia: " << c_enfermedad[v_enfermedad] << endl;Sleep(1000);
					cout << ambulancia[v_ambulancia] << " regresa al hospital con el enfermo" << endl; Sleep(4000);
					cout << ambulancia[v_ambulancia] << " llega al hospital" << endl;
				break;
	}
	pthread_mutex_unlock(&situacion_medica);
	return nullptr;

}

};


#endif /* HOSPITAL_H_ */
