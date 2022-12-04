#include "iri.cpp"
#include "funciones.h"

int main() {
    int cantConsulta = 0;
    int cantContacto = 0;
    int cantPaciente = 0;
    int cantMedico = 0;
    int cantArchivar = 0, cantNOarchivar = 0;

    Consulta* listaCon = new Consulta[cantConsulta];
    CargarListaCon(listaCon, &cantConsulta);

    Medico* listaMed = new Medico[cantMedico];
    CargarListaMed(listaMed, &cantMedico);

    Contacto* listaContac = new Contacto[cantContacto];
    CargarListaContacto(listaContac, &cantContacto);

    Paciente* listaPac = new Paciente[cantPaciente];
    CargarListaPac(listaPac, &cantPaciente);

    Paciente* Archivar = new Paciente[cantArchivar];
    Paciente* NOArchivar = new Paciente[cantNOarchivar];

    BuscarPaciente(listaCon, cantConsulta, listaPac, cantPaciente, Archivar, &cantArchivar, NOArchivar, &cantNOarchivar);
    contactar(NOArchivar, cantNOarchivar, listaContac, cantContacto, listaMed, cantMedico, listaCon, cantConsulta);

    fpArchivar(Archivar, cantArchivar);
    Secretaria();

    delete[] listaCon;
    delete[] listaContac;
    delete[] listaMed;
    delete[] listaPac;
    delete[] Archivar;
    delete[] NOArchivar;
    return EXIT_SUCCESS;
}
