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
        delete[] resultado;
        return 0;
    }
    for (int i = 0; i < Final-Inicio; i++) {
        resultado[i] = texto[Inicio+i];
    }
    resultado[Final-Inicio] = '\0';
    return resultado;
}
// *Verificar sí una materia pertenece o no al Pensúm;
int buscar_entero_pensum(int entero_buscado, char* Pensum[][5]){

    for(int i = 0; i < 46; i++){

        if(atoi(Pensum[i][0]) == entero_buscado){
            return i;
        }
    }
    return -1;
}
// *Obtener la lista de materias matriculadas;
int * ListaMaterias( char* Pensúm[][5], unsigned int Materias){

    unsigned int Contador; bool Permitida = true; long int Entrada; int Posición;
    int* Resultante = new long int[Materias];
    for (int C = 0; C < Materias; C++){
        Resultante[0] = 0;
    }

    cout << "[-> Una a una coloca el codigo de cada materia matriculada\n";
    while (Contador < Materias){
        cout << "[-> ";
        cin >> Entrada;
        Permitida = true;

        for (int C = 0; C < Materias; C++) {
            if (Entrada == Resultante[C]){
                Permitida = false;
            }
        }
        if(Permitida){
            Posición = buscar_entero_pensum(Entrada, Pensúm);
            if ( Posición == -1){
                cout << "[-> Codigo no reconocido.\n";

            }
            else{
                cout << "[-> La materia " << Pensúm[Posición][1] << " fue agrega correctamente.\n";
                Resultante[Contador] = Entrada;
                Contador++;

            }

        }
        else cout << "[-> No se aceptan materias duplicadas, selecciona una distinta.\n";
    }
    return Resultante;

}

#endif // FUNCIONES_H
