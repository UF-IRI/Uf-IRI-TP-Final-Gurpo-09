#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef struct UltimaConsulta {

	int DniPac;
	string FechaSolicitado;
	time_t FechaTurno;
	bool Presento;
	string matricula;
}Consulta;

typedef struct Contactos {

	int DniPac;
	string Telefono;
	string Celular;
	string Direccion;
	string mail;
}Contacto;


typedef struct Medicos {

	string Matricula;
	string Nombre;
	string Apellido;
	string Telefono;
	string Especialidad;
	bool Activo;
}Medico;

typedef struct Pacientes {

	int DNI;
	string Nombre;
	string Apellido;
	char sexo;
	string Natalicio;
	string Estado;
	string id_os;

}Paciente;

void CargarListaPac(Paciente*& listaPac, int* n);
void resizePac(Paciente*& lista, int* tamanioactual, int cantidadAumentar);

void CargarListaCon(Consulta*& listaCons, int* n);
void resizeCon(Consulta*& lista, int* tamanioactual, int cantidadAumentar);

void CargarListaContacto(Contacto*& lista, int* n);
void resizeContacto(Contacto*& lista, int* tamanioactual, int cantidadAumentar);

void CargarListaMed(Medico*& lista, int* n);
void resizeMed(Medico*& lista, int* tamanioactual, int cantidadAumentar);

void BuscarPaciente(UltimaConsulta*& listaConsultas, int nConsultas, Paciente*& listaPac, int nPaciente, Paciente*& Archivar, int* n_archivar, Paciente*& NOArchivar, int* n_NOarchivar);
time_t ultimaConsulta(unsigned int DNI, UltimaConsulta*& lista, int nconsultas);

void  contactar(Paciente*& lista, int nLista, Contacto*& listaContac, int nContac, Medico*& listaMed, int nMed, Consulta*& listaCon, int nCon);
void fpArchivar(Paciente*& Aux, int nArchivar);
void Secretaria();
