#include <Funciones.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // [1] Extración materias pensúm Ing. Electrónica;
    //      *Apertura y lectura de archivo;

    char* Pensúm[46][4]; char Lectura[65]; ifstream folder; unsigned int C;
    folder.open("Materias.txt");
    //      *Creación estructura de datos;
    for (C = 0; C < 46; C++){
        folder.getline(Lectura, 65);
        Pensúm[C][0] = SeparadorFrases(1, Lectura);
        Pensúm[C][1] = SeparadorFrases(2, Lectura);
        Pensúm[C][2] = SeparadorFrases(3, Lectura);
        Pensúm[C][3] = SeparadorFrases(4, Lectura);
    }


    folder.close();

    // [2] Inicio de la aplicación con bienvenida;

    Picazo("Arte.txt");
    cout << endl;

    // [3] Asignación materias matriculadas con su horario;
    //      *Cantidad de materias matriculadas;

    unsigned int Materias;
    cout << "[-> Ingrese el numero de materias que matriculo: "; cin >> Materias;

    long int* Matriculadas;

    Matriculadas = ListaMaterias(Pensúm,Materias);

    // [4] Creación horario de clases;

    int** Horario = RegistrarHorario(Materias, Matriculadas, Pensúm);

    MostrarHorario(Pensúm, Horario);

    // [5] Asignación horas de estudio;

    int* Estudio = new int[Materias];

    for (C = 0; C < Materias; C++){
        if (((atoi(Pensúm[buscar_entero_pensum(Matriculadas[C], Pensúm)][2]) * 48)/16) - atoi(Pensúm[buscar_entero_pensum(Matriculadas[C], Pensúm)][3]) < 0) Estudio[C] = 0;
        else Estudio[C] = ((atoi(Pensúm[buscar_entero_pensum(Matriculadas[C], Pensúm)][2]) * 48)/16) - atoi(Pensúm[buscar_entero_pensum(Matriculadas[C], Pensúm)][3]);
    }

    folder.open("EstudiarMaterias.txt");
    //      *Creación estructura de datos;
    for (C = 0; C < 46; C++){
        folder.getline(Lectura, 65);
        Pensúm[C][0] = SeparadorFrases(1, Lectura);
        Pensúm[C][1] = SeparadorFrases(2, Lectura);
        Pensúm[C][2] = SeparadorFrases(3, Lectura);
        Pensúm[C][3] = SeparadorFrases(4, Lectura);
    }
    folder.close();

    Horario = RegistrarHorasDeEstudio(Materias, Matriculadas, Horario, Estudio, Pensúm);

    MostrarHorario(Pensúm, Horario);







}
