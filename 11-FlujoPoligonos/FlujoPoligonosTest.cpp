/* Mosmann, Juan Ignacio
AED 2020
Main con pruebas
Leer poligonos desde un archivo */

#include "FlujoPoligonos.h"
#include <fstream>

int main(){
    std::ofstream ofs;
    Poligono pol1{
        3,
        {2,3, 9,2, 1.0,3},
        {255,255,255}
    };
    Poligono pol2{
        4,
        {9,0, 13,4, 0,2.3, 1,1.5},
        {125,125,125}
    };

    Poligono pol3{
        4,
        {1,0, 1,4, 2,2.3, 5,1.5},
        {0,125,255}
    };

    

    ofs.open("datos.txt");
    EnviarPoligono(ofs, pol1);
    EnviarPoligono(ofs, pol2);
    EnviarPoligono(ofs, pol3);
    ofs.close();

    std::ifstream inAutomatico ("datos.txt"); //Usa los datos enviados al archivo mediante EnviarPoligono de forma automática
    ExtraerPoligonos(inAutomatico);
    
    std::ifstream inManual ("datos2.txt");  //Usa un archivo creado con anterioridad de forma manual
    ExtraerPoligonos(inManual);
 
    ExtraerPoligonos(std::cin); //Usa el flujo de entrada estándar (teclado)
   
}