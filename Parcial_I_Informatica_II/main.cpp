#include <Funciones.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // [1] Extración materias pensúm Ing. Electrónica;
    //      *Apertura y lectura de archivo;

    char* Pensúm[46][5]; char Lectura[65]; ifstream folder; unsigned int C;
    folder.open("Materias.txt"); int Estudio[46];
    //      *Creación estructura de datos;
    for (C = 0; C < 46; C++){
        folder.getline(Lectura, 65);
        Pensúm[C][0] = SeparadorFrases(1, Lectura);
        Pensúm[C][1] = SeparadorFrases(2, Lectura);
        Pensúm[C][2] = SeparadorFrases(3, Lectura);
        Pensúm[C][3] = SeparadorFrases(4, Lectura);

        if (((atoi(Pensúm[C][2]) * 48)/16) - atoi(Pensúm[C][3]) < 0) Estudio[C] = 0;
        else Estudio[C] = ((atoi(Pensúm[C][2]) * 48)/16) - atoi(Pensúm[C][3]);

    }


    folder.close();

    // [2] Inicio de la aplicación con bienvenida;
    Picazo("Arte.txt");
    cout << endl;

    // [3] Asignación materias matriculadas con su horario;
    //      *Cantidad de materias matriculadas;



    return 0;
}
