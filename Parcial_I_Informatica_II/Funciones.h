#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
using namespace std;

// *Mostrar una imagen en consola;
void Picazo( const char* TxT ){

    ifstream folder; char Pixel;
    folder.open(TxT);
    while(folder.get(Pixel)){
        cout << Pixel;
    }
    folder.close();

}
// *Obtener un fragmento de un arreglo de caracteres;
char * SeparadorFrases(int n, const char* texto) {
    int ContadorFrases = 1;
    char* resultado = new char[65];
    int Inicio = 0, Final = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == ',') {
            if (ContadorFrases == n) {
                Final = i;
                break;
            }
            Inicio = i+1;
            ContadorFrases++;
        }
    }
    if (ContadorFrases < n) {
        resultado[0] = '\0';
        return 0;
    }
    for (int i = 0; i < Final-Inicio; i++) {
        resultado[i] = texto[Inicio+i];
    }
    resultado[Final-Inicio] = '\0';
    return resultado;
}





#endif // FUNCIONES_H
