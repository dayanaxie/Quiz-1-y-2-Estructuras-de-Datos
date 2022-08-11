// Utilizando arreglos en C++ escriba una estructura de datos que le permita modelar un tren de N vagones y escriba una función que reciba el tren por parámetro, luego liste los 10 primeros y los 10 últimos asientos disponibles. Eso hace que el tren por definición tenga alguna forma de marcar los asientos ya ocupados. 

// Dayana Xie Li
// Carnet 2022097967
// Quiz 1 y 2 Estructuras de Datos

#define CANTIDAD_VAGONES  4
#define CANTIDAD_ASIENTOS  12
#define MITAD_DEL_VAGONES (((CANTIDAD_ASIENTOS * CANTIDAD_VAGONES) / 2) / CANTIDAD_ASIENTOS)
#define MITAD_DE_ASIENTOS (((CANTIDAD_ASIENTOS * CANTIDAD_VAGONES) / 2) % CANTIDAD_ASIENTOS)
#define DISPONIBLE 1
#define OCUPADO 0

#include <iostream>
using namespace std;

int buscarAsientosDisponibles(bool tren [CANTIDAD_VAGONES][CANTIDAD_ASIENTOS]){
    int contador = 0;
    // recorrer los vagones
    for(int vagon = 0; vagon < CANTIDAD_VAGONES; vagon++){
        // recorrer los asientos
        for(int asiento = 0; asiento < CANTIDAD_ASIENTOS; asiento++){
            // verificar que el contador sea menor que 10
            if (contador < 10){
                // verificar que sea antes de la mitad de vagones
                if (vagon < MITAD_DEL_VAGONES){
                    // verificar que este disponible
                    if (tren[vagon][asiento] == DISPONIBLE){
                        cout << "Primeros asientos disponibles: " << "Vagon: " << vagon << " Asiento: " << asiento <<endl;
                        ++contador;
                    }
                }
                // si esta despues de la mitad
                else{
                    // verificar que seste antes del limite entre primeros y ultimos
                    if (asiento <= MITAD_DE_ASIENTOS){
                        if (tren[vagon][asiento] == DISPONIBLE){
                            cout << "Primeros asientos disponibles: " << "Vagon: " << vagon << " Asiento: " << asiento <<endl;
                            ++contador;
                        }
                    }
                }
            }
            // si es mayor a 10
            else {
                // verificar que sea menor que 20
                if (contador < 20){
                    // verificar que se encuentre entre los ultimos vagones
                    if (vagon >= MITAD_DEL_VAGONES){
                        if (tren[vagon][asiento] == DISPONIBLE){
                            cout << "Ultimos asientos disponibles: " << "Vagon: " << vagon << " Asiento: " << asiento <<endl;
                            ++contador;
                        }
                    }
                    // verificar que sea de los ultimos vagones
                    else{
                        if (asiento >= MITAD_DE_ASIENTOS){
                            if (tren[vagon][asiento] == DISPONIBLE){
                                cout << "Ultimos asientos disponibles: " << "Vagon: " << vagon << " Asiento: " << asiento <<endl;
                                ++contador;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}


int main (){
    bool tren [CANTIDAD_VAGONES][CANTIDAD_ASIENTOS] = {
        {DISPONIBLE,OCUPADO,OCUPADO,DISPONIBLE,OCUPADO,DISPONIBLE,OCUPADO,DISPONIBLE,OCUPADO,DISPONIBLE,DISPONIBLE,DISPONIBLE},
        {DISPONIBLE,DISPONIBLE,DISPONIBLE,DISPONIBLE,OCUPADO,DISPONIBLE,OCUPADO,OCUPADO,DISPONIBLE,DISPONIBLE,OCUPADO,DISPONIBLE},
        {OCUPADO,OCUPADO,OCUPADO,DISPONIBLE,DISPONIBLE,DISPONIBLE,DISPONIBLE,DISPONIBLE,DISPONIBLE,OCUPADO,DISPONIBLE,OCUPADO}
    };
    buscarAsientosDisponibles(tren);
    return 0;
}