#include "funciones.h"

#define DiezS 315576000


void CargarListaPac(Paciente*& listaPac, int* n){
    if (listaPac == nullptr && n==nullptr)
        return;
    fstream fp;

    fp.open("Pacientes.csv", ios::in);

    if (!(fp.is_open())) {
        return;
    }

    string headers;
    char coma = ',';
    getline(fp, headers, '\n');

    int i = 0;
    while (fp)
    {
        resizePac(listaPac, n, 1);
        fp >> listaPac[i].DNI >> coma;
        getline(fp, listaPac[i].Nombre, ',');
        getline(fp, listaPac[i].Apellido, ',');
        fp >> listaPac[i].sexo >> coma;
        getline(fp, listaPac[i].Natalicio, ',');
        getline(fp, listaPac[i].Estado, ',');
        getline(fp, listaPac[i].id_os, '\n');
        i++;
    }

    fp.close();
}

void resizePac(Paciente*& lista, int* tamanioactual, int cantidadAumentar)
{
    if (lista == nullptr && tamanioactual == nullptr)
        return;
    *tamanioactual += cantidadAumentar;
    int i = 0;
    Paciente* aux = new Paciente[*tamanioactual];
    while (i < *tamanioactual - cantidadAumentar)
    {
        aux[i] = lista[i];
        i++;
    }
    delete[] lista;
    lista = aux;
    return;
}

void CargarListaCon(Consulta*& listaCons, int* n)
{
    if (listaCons == nullptr)
        return;

    fstream fp;
    fp.open("Consultas.csv", ios::in);

    if (!(fp.is_open()))
        return;

    string headers;
    char coma = ' ';
    string espacio = "";
    getline(fp, headers, '\n');
    int dia, mes, anio;
    string str;
    string auxstr;
    stringstream date;
    struct tm aux;
    istringstream ss;

    int i = 0;
    while (fp)
    {

        resizeCon(listaCons, n, 1);
        fp >> listaCons[i].DniPac >> coma;
        getline(fp, listaCons[i].FechaSolicitado, ',');
        getline(fp, str, ',');
        fp >> listaCons[i].Presento >> coma;
        getline(fp, listaCons[i].matricula, '\n');

        date << str;

        getline(date, auxstr, '/');
        dia = stoi(auxstr);

        getline(date, auxstr, '/');
        mes = stoi(auxstr);

        getline(date, auxstr, ' ');
        anio = stoi(auxstr);

        //aux = { 0,0,0, dia,mes - 1, anio};

        ss.str(to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio) + " 00:00:00");
        ss >> get_time(&aux, "%d/%m/%Y %H:%M:%S");

        listaCons[i].FechaTurno = mktime(&aux);

        i++;
    }

    fp.close();

}

void resizeCon(Consulta*& lista, int* tamanioactual, int cantidadAumentar)
{
    if (lista == nullptr && tamanioactual == nullptr)
        return;
    *tamanioactual += cantidadAumentar;
    int i = 0;
    Consulta* aux = new Consulta[*tamanioactual];
    while (i < *tamanioactual - cantidadAumentar)
    {
        aux[i] = lista[i];
        i++;
    }
    delete[] lista;
    lista = aux;
    return;
}

void CargarListaContacto(Contacto*& lista, int* n)
{
    if (lista == nullptr)
        return;

    fstream fp;
    fp.open("Contactos.csv", ios::in);

    if (!(fp.is_open()))
        return;

    string headers;
    char coma = ',';
    getline(fp, headers, '\n');

    int i = 0;
    while (fp)
    {
        resizeContacto(lista, n, 1);
        fp >> lista[i].DniPac >> coma;
        getline(fp, lista[i].Telefono, ',');
        getline(fp, lista[i].Telefono, ',');
        getline(fp, lista[i].Celular, ',');
        getline(fp, lista[i].mail, '\n');
        i++;
    }

    fp.close();
}

void resizeContacto(Contacto*& lista, int* tamanioactual, int cantidadAumentar)
{
    if (lista == nullptr && tamanioactual == nullptr)
        return;
    *tamanioactual += cantidadAumentar;
    int i = 0;
    Contacto* aux = new Contacto[*tamanioactual];
    while (i < *tamanioactual - cantidadAumentar)
    {
        aux[i] = lista[i];
        i++;
    }
    delete[] lista;
    lista = aux;
    return;
}

void CargarListaMed(Medico*& lista, int* n)
{
    if (lista == nullptr)
        return;

    fstream fp;
    fp.open("Medicos.csv", ios::in);

    if (!(fp.is_open()))
        return;

    string headers;
    char coma = ',';
    getline(fp, headers, '\n');

    int i = 0;
    while (fp)
    {
        resizeMed(lista, n, 1);
        getline(fp, lista[i].Matricula, ',');
        getline(fp, lista[i].Nombre, ',');
        getline(fp, lista[i].Apellido, ',');
        getline(fp, lista[i].Telefono, ',');
        getline(fp, lista[i].Especialidad, '\n');
        i++;
    }

    fp.close();
}
void resizeMed(Medico*& lista, int* tamanioactual, int cantidadAumentar)
{
    if (lista == nullptr && tamanioactual == nullptr)
        return;
    *tamanioactual += cantidadAumentar;
    int i = 0;
    Medico* aux = new Medico[*tamanioactual];
    while (i < *tamanioactual - cantidadAumentar)
    {
        aux[i] = lista[i];
        i++;
    }
    delete[] lista;
    lista = aux;
    return;

}

void BuscarPaciente(UltimaConsulta*& listaConsultas, int nConsultas, Paciente*& listaPac, int nPaciente, Paciente*& Archivar, int* n_archivar, Paciente*& NOArchivar, int* n_NOarchivar)
{
    if (listaConsultas == nullptr && listaPac == nullptr && Archivar == nullptr && n_archivar == nullptr && NOArchivar == nullptr && n_NOarchivar == nullptr)
        return;

    time_t actual = time(NULL);
    int k = 0, i = 0;
    bool fueEncontrando = false;
    int cant_t;
    time_t ult_c;
    time_t diez_a = actual - (time_t)DiezS;
    int contArchivar = 0, contNOarchivar = 0;
    string internado = " internado ";
    string fallecido = " fallecido ";

    while (k < nPaciente)
    {
        fueEncontrando = false;
        i = 0;

        while (i < nConsultas)
        {
            if (listaPac[k].DNI == listaConsultas[i].DniPac)
            {
                fueEncontrando = true;
                break;
            }
            i++;
        }

        if (fueEncontrando)
        {
            ult_c = ultimaConsulta(listaPac[k].DNI, listaConsultas, nConsultas);

            if (listaPac[k].Estado == internado)
            {
                
            }
            else if (listaPac[k].Estado == fallecido)
            {
                
                resizePac(Archivar, n_archivar, 1);
                Archivar[contArchivar] = listaPac[k];
                contArchivar++;
                
               
            }
            else
            {
                
                cant_t = difftime(actual, ult_c);

                if (cant_t > diez_a)
                {
                    resizePac(Archivar, n_archivar, 1);
                    Archivar[contArchivar] = listaPac[k];
                    contArchivar++;
                   
                }
                else
                {
                    resizePac(NOArchivar, n_NOarchivar, 1);
                    NOArchivar[contNOarchivar] = listaPac[k];
                    contNOarchivar++;
                    
                }
            }
        }
        k++;

    }

    return;
}

time_t ultimaConsulta(unsigned int DNI, UltimaConsulta*& lista, int nconsultas)
{
    if (lista == nullptr)
        return -1;

    time_t aux;
    time_t fecha = { 0 };

    int i = 0;
    for (i = 0;i < nconsultas;i++)
    {
        if (DNI == lista[i].DniPac)
        {
            aux = lista[i].FechaTurno;

            if (aux > fecha)
            {
                fecha = aux;
            }
        }

    }
    return fecha;
}

void contactar(Paciente*& lista, int nLista, Contacto*& listaContac, int nContac, Medico*& listaMed, int nMed, Consulta*& listaCon, int nCon)
{
    if (lista == nullptr &&listaContac==nullptr && listaMed==nullptr && listaCon==nullptr)
        return;

    int i, j, k, l;
    fstream fp;

    fp.open("ParaContactar.csv", ios::out);

    if (!fp.is_open()) {
        return;
    }

    fp << "nombre , apellido , id_os , telefono , matriculaMed , nombreMed , apellidoMed , telefonoMed , especialidad , activo" << endl;

    bool contac, med;

    for (i = 0; i < nLista; i++)
    {
        contac = false;
        med = false;

        for (k = 0; k < nContac;k++)
        {
            if (lista[i].DNI == listaContac[i].DniPac)
            {
                contac = true;//en caso de que no tenga contacto nunca se vuevce true
            }
            if (contac)
                break; //me quedo con la pos
        }

        for (j = 0;j < nCon;j++) //hacemos todo esto por como estan conectadas las estructuras
        {
            if (lista[i].DNI == listaCon[j].DniPac)
            {
                for (l = 0; l < nMed; l++)
                {
                    if (listaCon[j].matricula == listaMed[l].Matricula)
                    {
                        med = true;
                    }
                    if (med) {
                        break;
                    }
                }
            }

        }

        if (med && contac)//si el paciente tiene contacto y medico se imprime en el archivo para archivar
        {
            fp << lista[i].Nombre << " , " << lista[i].Apellido << " , " << lista[i].id_os << " , " << listaContac[k].Telefono << " , " << listaMed[l].Matricula << " , " <<
                listaMed[l].Nombre << " , " << listaMed[l].Apellido << " , " << listaMed[l].Telefono << " , " << listaMed[l].Especialidad << " , " << listaMed[l].Activo << endl;
        }
        else if (med && !contac)//si tiene medico pero no contacto
        {
            fp << lista[i].Nombre << " , " << lista[i].Apellido << " , " << lista[i].id_os << " , " << "no tiene contacto" << " , " << listaMed[l].Matricula << " , " <<
                listaMed[l].Nombre << " , " << listaMed[l].Apellido << " , " << listaMed[l].Telefono << " , " << listaMed[l].Especialidad << " , " << listaMed[l].Activo << endl;
        }
        else if (!med && contac)
        {
            fp << lista[i].Nombre << " , " << lista[i].Apellido << " , " << lista[i].id_os << " , " << listaContac[k].Telefono << " , " << "asignar medico" << " , " <<
                "asignar medico" << " , " << "asignar medico" << " , " << "asignar medico" << " , " << "asignar medico" << " , " << "asignar medico" << endl;
        }
        else
        {
            fp << lista[i].Nombre << " , " << lista[i].Apellido << " , " << lista[i].id_os << " , " << "no tiene contacto" << " , " << "asignar medico" << " , " <<
                "asignar medico" << " , " << "asignar medico" << " , " << "asignar medico" << " , " << "asignar medico" << " , " << "asignar medico" << endl;
        }

    }

    fp.close();
    return;
}

void fpArchivar(Paciente*& Aux, int nArchivar)
{
    if (Aux == nullptr)
        return;

    ofstream fp;
    fp.open("Archivar.csv", ios::out);
    if (!(fp.is_open()))
        return;

    int i =0;
    nArchivar = nArchivar - 1;

    fp << "DNI" << ',' << "NOMBRE" << ',' << "APELLIDO" <<',' << "ID.OS" <<"ROTULO"<< endl;

    while (i < nArchivar)
    {
        fp << Aux[i].DNI << ',' << Aux[i].Nombre << ',' << Aux[i].Apellido << ',' << Aux[i].id_os << ',' << "ARCHIVADO" << endl;
        i++;
    }
    fp.close();
}

void Secretaria() 
{
    srand(time(NULL));
    fstream fp;
    fstream fp2;
    fstream fparchivar;

    fparchivar.open("Archivar.csv", ios::app);
    if (!(fparchivar.is_open()))
        return;

    fp.open("ParaContactar.csv", ios::in);
    if (!fp.is_open())
        return;

    fp2.open("Recuperados.csv", ios::out);
    if (!fp2.is_open())
        return;

    string headers = "";
    getline(fp, headers);

    string nombre, apellido, id_os;
    bool retorna;
    int obraSocial;
    int dia, mes, anio;


    string coma= ",";
    fp2 << "nombre"<<","<< "apellido"<<","<<"id_os"<<","<< "retorna" <<","<<"nuevaConsulta" << endl;

    while (fp) 
    {
        int aux = rand();
        getline(fp, nombre, ',');
        getline(fp, apellido, ',');
        getline(fp, id_os, ',');
        getline(fp, id_os, '\n');

        retorna = aux % 2; //genera un numero entre 1-2 por si vuelve o no (es booleano)

        if (retorna) {

            obraSocial = aux % 6;
            switch (obraSocial) {
            case 0:
                id_os = "OSDE";
                break;
            case 1:
                id_os = "Italiano";
                break;
            case 2:
                id_os = "Medicus";
                break;
            case 3:
                id_os = "IOSFA";
                break;
            case 4:
                id_os = "Espanyol";
                break;
            case 5:
                id_os = "Aleman";
                break;
            }

            struct tm hoy;
            time_t t = time(NULL);
            localtime_s(&hoy, &t);

            dia = aux % 31 + 1;
            mes = aux % 12 + 1;
            anio = aux % ((hoy.tm_year + 1900 + 2) - (hoy.tm_year + 1900 + 1) + 1) + (hoy.tm_year + 1900 + 1);

            fp2 << nombre << "," <<apellido << ", " << id_os << " , " <<retorna <<" , " << dia << "/" << mes << "/" << anio << endl;
        }
        else
        {
            fparchivar << nombre << "," << apellido << "," << id_os << "," << "ARCHIVADO"<<endl;
        }
    }

    fp.close();
    fp2.close();
    fparchivar.close();
}


