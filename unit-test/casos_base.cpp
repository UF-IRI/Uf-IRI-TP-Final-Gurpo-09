#include "gmock/gmock.h"
#include "main_test.cpp"

namespace Casos_Base::tests {
	TEST(Leer_archivo, lista_paciente)
	{
		int n = 0;
		Paciente* lista_aux = new Paciente[n];
		Paciente aux;
		aux.DNI = 10242582;
		aux.Nombre = "Cersty";
		aux.Apellido = "Thurston";
		aux.sexo = 'F';
		aux.Natalicio = "9 / 6 / 1970";
		aux.Estado = "internado";
		aux.id_os = "Medicus";

		CargarListaPac(lista_aux, &n);

		EXPECT_EQ(lista_aux[0].DNI, aux.DNI);
		EXPECT_EQ(lista_aux[0].Nombre, aux.Apellido);
		EXPECT_EQ(lista_aux[0].sexo, aux.sexo);
		EXPECT_EQ(lista_aux[0].Natalicio, aux.Natalicio);
		EXPECT_EQ(lista_aux[0].Estado, aux.Estado);
		EXPECT_EQ(lista_aux[0].id_os, aux.id_os);
		delete[] lista_aux;
	}

	TEST(Leer_archivo, lista_consulta)
	{
		int n = 0;
		Consulta* lista_aux = new Consulta[n];
		Consulta aux;
		string auxstr;
		int dia, mes, anio;
		istringstream ss;
		struct tm auxtm;

		aux.DniPac = 43963883;
		aux.FechaSolicitado = "14 / 05 / 1987";

		auxstr = "30";
		dia = stoi(auxstr);

		auxstr = "07";
		mes = stoi(auxstr);

		auxstr = "1987";
		anio = stoi(auxstr);

		ss.str(to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio) + " 00:00:00");
		ss >> get_time(&auxtm, "%d/%m/%Y %H:%M:%S");

		aux.FechaTurno = mktime(&auxtm);
		aux.Presento = 0;
		aux.matricula = "11 - 089 - 2377";

		CargarListaCon(lista_aux, &n);

		EXPECT_EQ(lista_aux[0].DniPac, aux.DniPac);
		EXPECT_EQ(lista_aux[0].FechaSolicitado, aux.FechaSolicitado);
		EXPECT_EQ(lista_aux[0].FechaTurno, aux.FechaTurno);
		EXPECT_EQ(lista_aux[0].matricula, aux.matricula);
		EXPECT_EQ(lista_aux[0].Presento, aux.Presento);
		delete[] lista_aux;
	}

	TEST(lerr_archivo, lista_contacto)
	{
		int n = 0;
		Contacto* lista_aux = new Contacto[n];
		Contacto aux;
		aux.Celular = "+54(176)68420326";
		aux.Direccion = "Nebraska";
		aux.DniPac = 18902837;
		aux.mail = "MelodieMercier1@nowhere.com";
		aux.Telefono = "+ 54(801)04193744";

		CargarListaContacto(lista_aux, &n);

		EXPECT_EQ(lista_aux[0], aux);

		EXPECT_EQ(lista_aux[0].DniPac, aux.DniPac);
		EXPECT_EQ(lista_aux[0].Celular, aux.Celular);
		EXPECT_EQ(lista_aux[0].Direccion, aux.Direccion);
		EXPECT_EQ(lista_aux[0].mail, aux.mail);
		EXPECT_EQ(lista_aux[0].Telefono, aux.Telefono);
		delete[] lista_aux;
	}

	TEST(lerr_archivo, lista_medico)
	{
		int n = 0;
		Medico* lista_aux = new Medico[n];
		Medico aux;
		aux.Matricula = "03 - 957 - 5455";
		aux.Nombre = "Jacinta";
		aux.Apellido = "Ralston";
		aux.Especialidad = "geriatria";
		aux.Telefono = "+54(929)89112253";
		aux.Activo = 0;

		CargarListaMed(lista_aux, &n);

		EXPECT_EQ(lista_aux[0], aux);

		EXPECT_EQ(lista_aux[0].Matricula, aux.Matricula);
		EXPECT_EQ(lista_aux[0].Nombre, aux.Nombre);
		EXPECT_EQ(lista_aux[0].Apellido, aux.Apellido);
		EXPECT_EQ(lista_aux[0].Especialidad, aux.Especialidad);
		EXPECT_EQ(lista_aux[0].Telefono, aux.Telefono);
		EXPECT_EQ(lista_aux[0].Activo, aux.Activo);
		delete[] lista_aux;
	}
}