#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
using namespace std;
// Convertir un char* a entero;
long int acti(char* Letras){

    int C = 0; bool Negative = false; long int Resultado = 0;
    while ((Letras[C] >= 48 && Letras[C] <= 57) || Letras[C] == 45){
        C++;
    }

    if (Letras[0] == 45){
        Negative = true;
    }

    for (int var = 0; var < C; var++){
        if (Letras[var] != 45){
            Resultado = (Letras[var]+-48)+(Resultado*10);
        }
    }

    if (Negative){
        Resultado *= -1;
    }
    return Resultado;
}
// *Mostrar una imagen en consola;
void Picazo( const char* TxT ){
    cout << " -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    ifstream folder; char Pixel;
    folder.open(TxT);
    while(folder.get(Pixel)){
        cout << Pixel;
    }
    cout << endl;
    folder.close();
    cout << " -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
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
int buscar_entero_pensum(int entero_buscado, char* Pensum[][4]){

    for(int i = 0; i < 92; i++){

        if(acti(Pensum[i][0]) == entero_buscado){
            return i;
        }
    }
    return -1;
}
// *Obtener la lista de materias matriculadas;
long int * ListaMaterias( char* Pensúm[][4], long int Materias){

    long int Contador = 0; bool Permitida = true; long int Entrada; int Posición;
    long int* Resultante = new long int[Materias];
    for (int C = 0; C < Materias; C++){
        Resultante[0] = 0;
    }

    cout << "[-> Una a una coloca el codigo de cada materia matriculada\n";
    while (Contador < Materias){
        cout << "[-> ";
        cin >> Entrada;
        Permitida = true;

        for (long int C = 0; C < Materias; C++) {
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
                cout << "[-> La materia" << Pensúm[Posición][1] << " fue agregada correctamente.\n";
                Resultante[Contador] = Entrada;
                Contador++;

            }

        }
        else cout << "[-> No se aceptan materias duplicadas, selecciona una distinta.\n";
    }
    return Resultante;

}
// *Obtener el horario de clases;
int ** RegistrarHorario( int n, long int * Matriculadas, char * Pensum[][4]){

    int **Horario = new int *[7];
    for(int i = 0; i < 7; i++){
        Horario[i] = new int[24];
        for(int j = 0; j < 24; j++){
            Horario[i][j] = 0;
        }
    }

    bool Flag = false; int Respuesta, Respuesta2; int MateriaElegida, HoraInicial, HoraFinal, HoraIntermedia;
    const char * dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    bool Flag2 = false, Flag3 = false;

    while(Flag == false){

        for(int i = 0; i < 7; i++){

            Flag2 = false; Flag3 = false;
            Respuesta = -1; Respuesta2 = -1;


            while(Flag2 == false){

                cout << endl << "Escoja las materias que le tocan los " << dias[i] << ":" << endl;
                cout << endl <<"0) Ninguna " << endl;

                for(int j = 0; j < n; j++){

                    int Entrada = Matriculadas[j];
                    int Posición = buscar_entero_pensum(Entrada, Pensum);


                    cout << j + 1 << ")" << " " << Pensum[Posición][1] << "." << endl;


                }

                cin >> Respuesta;

                if(Respuesta == 0){
                    Flag2 = true;
                }

                else{

                    MateriaElegida = Matriculadas[Respuesta - 1];


                    while(Flag3 == false){

                        cout << endl << "Ingrese la hora inicial de " << Pensum[buscar_entero_pensum(MateriaElegida, Pensum)][1] << ":" << endl;
                        cin >> HoraInicial;
                        cout << endl << "Ingrese la hora final de " << Pensum[buscar_entero_pensum(MateriaElegida, Pensum)][1] << ":" << endl;
                        cin >> HoraFinal;

                        if(Horario[i][HoraInicial] > 0){

                            cout << endl <<"Este intervalo de tiempo ya esta asignado, ingrese uno valido" << endl;
                        }

                        else if(Horario[i][HoraFinal] > 0 ){

                            cout << endl << "Este intervalo de tiempo ya esta asignado, ingrese uno valido" << endl;
                        }

                        else if(Horario[i][(HoraInicial+HoraFinal)/2] > 0){
                            cout << endl << "Este intervalo de tiempo ya esta asignado, ingrese uno valido" << endl;
                        }
                        else if(HoraInicial > HoraFinal || HoraFinal == HoraInicial){
                            cout << endl << "Coloque un intervalo de horas valido" << endl;
                        }
                        else{ Flag3 = true; }

                    }

                    HoraFinal--;
                    Flag3 = false;

                    Horario[i][HoraInicial] = MateriaElegida;
                    Horario[i][HoraFinal] = MateriaElegida;
                    HoraIntermedia = (HoraInicial + HoraFinal)/2;

                    if((HoraFinal-HoraInicial) != 1){
                        for(int k = HoraInicial + 1; k < HoraFinal; k++){
                            Horario[i][k] = MateriaElegida;
                        }
                    }


                    cout << endl << "Necesita ingresar otra materia? " << "[1] Si  [2] No" << endl;
                    cin >> Respuesta2;

                    if(Respuesta2 == 1){ Flag2 = false; }
                    else Flag2 = true;


                }



            }





            Flag = true;

        }
    }



    return Horario;
}
// *Mostrar el horario del usuario;
void MostrarHorario( char * Pensum[][4], int** Horario){
    const char * dias[7] = {" -------LUNES-------", " -------MARTES------", " -----MIERCOLES-----", " -------JUEVES------", " ------VIERNES------", " -------SABADO------", " ------DOMINGO------"}; int C; int K;
    long int Posición;
    cout << "     ";
    for (C = 0; C < 7; C++){
        cout << dias[C];
    }
    cout << endl;


    for (K = 0; K < 24; K++){
        cout << K << ":00";
        if (K < 10){
            cout << " ";
        }
        for (C = 0; C < 7; C++){
            Posición = buscar_entero_pensum(Horario[C][K], Pensum);
            if (Posición == -1){
                cout << " -------------------";
            }
            else{
                cout << Pensum[Posición][1];
            }
        }
        cout << endl;
    }

}
// *Sistema de recomendaciones para las horas de estudio;
void Recomendaciones( int** Horario, int Dia, int Horas_Semanales){
    int T_E_D = Horas_Semanales/(7-Dia); int C; int Horas_Disponibles = 0; int Horas_Sueño; bool Continuar;
    const char * dias[7] = {"LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES ", "SABADO", "DOMINGO"};
    int MAX = 6; int MIN = 6;
    for (C = 0; C < 24; C++){
        if (Horario[Dia][C] == 0){
            Horas_Disponibles++;
        }
    }
    cout << "[-> " << dias[Dia] << ":" << endl;
    if (T_E_D > 5){
        cout << "[-> Al parecer tu horario te exige estudiar hoy [" << T_E_D << "] horas... Por tu bienestar te recomiendo disminuirlo " << endl;
    }
    //Toma de recomendaciones
    if (Horas_Disponibles > 8){
        while (Continuar){
            if (Horas_Disponibles - (Horas_Sueño+T_E_D) < 0){
                if (Horas_Sueño > 7){
                    Horas_Sueño--;
                }
                else{
                    T_E_D--;
                }
            }
            else{
                Continuar = false;
            }
        }
    }
    if (Continuar){
        cout << "[-> WoW... Parece que hoy estas muy ocupado, aprovecha tu tiempo para dormir" << endl;
    }
    else{
        cout << "[-> Este es el plan hoy: " << " Duerme " << Horas_Sueño << " horas y estudia " << T_E_D << " horas" << endl;
        Continuar = false;
        for (MIN = 6; MIN < 16; MIN++){
            for (MAX = MIN; MAX < 20; MAX++){
                if (Horario[Dia][MAX] != 0){
                    break;
                }
                if (MAX - MIN == T_E_D){
                    cout << "[-> " << MIN << "-" << MAX << endl;
                }
            }
        }
    }
}
// *Registrar horas de estudio;
int ** RegistrarHorasDeEstudio( int n, long int * Matriculadas, int ** Horario, int* Estudio, char* Pensum[][4]){


    cout << endl << "Horas de estudio" << endl;
    int Posicion, HorasActual, HorasTotales = 0, HorasRestantes;

    for(int i = 0; i < n; i++){
        Posicion = buscar_entero_pensum(Matriculadas[i], Pensum);
        HorasActual = Estudio[i];
        HorasTotales = HorasTotales + HorasActual;
        cout << endl << i + 1 << ")" << Pensum[Posicion][1] << ":" << HorasActual << endl;
    }

    cout << n + 1 << ") " << "Horas totales" << ":" << HorasTotales << endl;

    HorasRestantes = HorasTotales;

    while(HorasRestantes > 0){


        bool Flag = false; int Respuesta, Respuesta2; int MateriaElegida, HoraInicial, HoraFinal;
        const char * dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
        bool Flag2 = false, Flag3 = false;

        while(Flag == false){

            for(int i = 0; i < 7; i++){

                Flag2 = false; Flag3 = false;
                Respuesta = -1; Respuesta2 = -1;


                while(Flag2 == false){

                    cout << endl << "Escoja las materias que quiere estudiar los " << dias[i] << ":" << endl;
                    cout << endl <<"0) Ninguna " << endl;

                    for(int j = 0; j < n; j++){

                        int Entrada = Matriculadas[j];
                        int Posición = buscar_entero_pensum(Entrada, Pensum);


                        cout << j + 1 << ")" << " " << Pensum[Posición][1] << ".";


                    }
                    cout << endl;
                    cin >> Respuesta;

                    MateriaElegida = Matriculadas[Respuesta - 1];
                    HorasActual = Estudio[Respuesta - 1];

                    if(Respuesta == 0){
                        Flag2 = true;
                    }


                    else if(HorasActual != 0){

                        while(Flag3 == false){

                            cout << endl << "Ingrese la hora inicial para estudiar " << Pensum[buscar_entero_pensum(MateriaElegida, Pensum)][1] << ":    ";
                            cout << "Tenga en cuenta que para " << Pensum[buscar_entero_pensum(MateriaElegida, Pensum)][1] << " quedan " << HorasActual << " horas asignables " << endl;

                            cin >> HoraInicial;
                            cout << endl << "Ingrese la hora final" << ":" << endl;
                            cin >> HoraFinal;

                            cout << "Esto es una prueba " << Horario[i][HoraInicial] << endl;
                            if(Horario[i][HoraInicial] > 0){

                                cout << endl <<"Este intervalo de tiempo ya esta asignado, ingrese uno valido" << endl;
                            }

                            else if(Horario[i][HoraFinal] > 0 ){

                                cout << endl << "Este intervalo de tiempo ya esta asignado, ingrese uno valido" << endl;
                            }

                            else if(Horario[i][(HoraInicial+HoraFinal)/2] > 0){
                                cout << endl << "Este intervalo de tiempo ya esta asignado, ingrese uno valido" << endl;
                            }

                            else if(HoraInicial > HoraFinal || HoraFinal == HoraInicial){
                                cout << endl << "Coloque un intervalo de horas valido" << endl;
                            }

                            else if((HoraFinal - HoraInicial) > HorasRestantes){
                                cout << endl << "El intervalo colocado excede la cantidad de horas de estudio asignables" << endl;
                            }


                            else{ Flag3 = true; cout << endl << "Intervalo de estudio asignado correctamente" << endl; }

                        }

                        HoraFinal--;
                        Flag3 = false;

                        Horario[i][HoraInicial] = -MateriaElegida;
                        Horario[i][HoraFinal] = -MateriaElegida;

                        if((HoraFinal-HoraInicial) != 1){
                            for(int k = HoraInicial + 1; k < HoraFinal; k++){
                                Horario[i][k] = -MateriaElegida;
                            }
                        }

                        Estudio[Respuesta - 1] = (HorasActual - (HoraFinal + 1 - HoraInicial));
                        HorasRestantes = (HorasRestantes - (HoraFinal + 1 - HoraInicial));

                        if(HorasRestantes < 1){ i = 8; break;}

                        cout << endl << "Desea ingresar otro intervalo de estudio? " << "[1] Si  [2] No" << endl;
                        cin >> Respuesta2;

                        if(Respuesta2 == 1){ Flag2 = false; }
                        else Flag2 = true;


                    }

                    else{cout << endl << "La materia seleccionada no tiene mas horas de estudio asignables" << endl;}


                }




            }

            Flag = true;
        }




    }

    return Horario;
}

#endif // FUNCIONES_H
