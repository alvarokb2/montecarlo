/* 
 * File:   main.cpp
 * Author: Alvaro Cabedo Vasquez
 *
 * Created on 29 de octubre de 2014, 08:46 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>


using namespace std;

/*
 * 
 * 
 * 
 */
//Funcion que calcula el costo total
int CalcularCosto(float _ocio, int _fallas, int _valvulas){
        return (_ocio)*30 + (_fallas * _valvulas * 10);

}

//Montecarlo
void Simular(int _valvulas, float _horas){
    float __horas = 0;
    int fallas = 0;
    int aleatorio = 0; 
    float ocio = 0;
    if(_valvulas == 1){                 //simulacion para cambiar 1 valvula a la vez
        while(__horas <= _horas){
            aleatorio = rand()%100;     //generacion numero aleatorio
            if(aleatorio < 5){          
                __horas += 20;
            }
            else if(aleatorio > 4 && aleatorio <= 14){
                __horas += 40;
            }
            else if(aleatorio > 14 && aleatorio < 44){
                __horas += 55;
            }
            else if(aleatorio > 44 && aleatorio < 74){
                __horas += 70;
            }
            else if(aleatorio > 74 && aleatorio < 94){
                __horas += 85;
            }
            else if(aleatorio > 94){
                __horas += 100;
            }
            if(__horas < _horas){                       
                ocio += 1;                              
                __horas += ocio;
                fallas++;
            }
        }  
    }
    else if(_valvulas == 3){            //simulacion para cambiar 1 valvula a la vez
        while(__horas <= _horas){       
            aleatorio = rand()%100;     //generacion numero aleatorio
            if(aleatorio < 10){
                __horas += 170;
            }
            else if(aleatorio > 9 && aleatorio <= 29){
                __horas += 175;
            }
            else if(aleatorio > 29 && aleatorio < 69){
                __horas += 180;
            }
            else if(aleatorio > 69 && aleatorio < 89){
                __horas += 185;
            }
            else if(aleatorio > 89){
                __horas += 190;
            }
            if(__horas < _horas){
                ocio += 2.25;
                __horas += ocio;
                fallas++;
            }
        }  
    }
    cout << endl << "Valvulas cambiadas por cada Falla: " << _valvulas << endl;
    cout << "Numero de Fallas registradas: " << fallas << endl;
    cout << "Horas de ocio: " << ocio << endl;    
    cout << "Costo: " << CalcularCosto(ocio, fallas, _valvulas) << endl;
}


//Funcion Principal
int main(int argc, char** argv) {
    int horas;
    
    cout << endl << "Opciones de la simulación:"<<endl;
    cout << "1) 1000 horas de simulación" <<endl;
    cout << "2) 10000 horas de simulación" <<endl;
    cout << "3) 100000 horas de simulación" <<endl;
    cout << "4) 1000000 horas de simulación" <<endl;
    cout << "Ingrese el numero de su opción: ";
    cin >> horas;
    cout << endl;
    
    if (horas > 0 && horas <=4){
        switch(horas){
            case 1:
                Simular(1,1000);
                Simular(3,1000);
                break;
            case 2:
                Simular(1,10000);
                Simular(3,10000);
                break;
            case 3:
                Simular(1,100000);
                Simular(3,100000);
                break;
            case 4:
                Simular(1,1000000);
                Simular(3,1000000);
                break;
                
        }
    }
    else{
        cout << "opcion no valida" << endl;
    }
    return 0;
}
