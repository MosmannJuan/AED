/* Mosmann, Juan Ignacio
AED 2020
Main con pruebas
Leer poligonos desde un archivo */

#include "FlujoPoligonosArray.h"
#include <fstream>
#include <cassert>

int main(){
    
    //Declaración e inicialización de los poligonos a usar

    Poligono pol1;
    pol1.c = rojo;
    AddVerticeAlFinal (pol1, {0,0});
    AddVerticeAlFinal (pol1, {1,0});
    AddVerticeAlFinal (pol1, {1,1});
    AddVerticeAlFinal (pol1, {0,1});

    Poligono pol2;
    pol2.c = verde;
    AddVerticeAlFinal (pol2, {0,0});
    AddVerticeAlFinal (pol2, {1,0});
    AddVerticeAlFinal (pol2, {0,2});
    AddVerticeAlFinal (pol2, {1,1});

    Poligono pol3;
    pol3.c = verde;
    AddVerticeAlFinal (pol3,{0,0});
    AddVerticeAlFinal (pol3,{1,0});
    AddVerticeAlFinal (pol3,{0,2});
    AddVerticeAlFinal (pol3,{1,1});
    AddVerticeAlFinal (pol3,{3,4});

    //Pruebas EnviarPoligono (involucra EnviarColor, EnviarPunto y EnviarPuntos)

    std::ofstream ofs;

    ofs.open("datos.txt");
    EnviarPoligono(ofs, pol1);
    EnviarPoligono(ofs, pol2);
    EnviarPoligono(ofs, pol3);
    ofs.close();

    //Pruebas ExtraerPoligonos (involucra ExtraerColor, ExtraerPunto, ExtraerPuntos y ExtraerPoligono)

    std::ifstream inAutomatico ("datos.txt"); //Usa los datos enviados al archivo mediante EnviarPoligono de forma automática
    ExtraerPoligonos(inAutomatico);
    
    std::ifstream inManual ("datos2.txt");  //Usa un archivo creado con anterioridad de forma manual
    ExtraerPoligonos(inManual);
 
    ExtraerPoligonos(std::cin); //Usa el flujo de entrada estándar (teclado)

    std::ofstream out;
    std::ifstream inCond ("poligonosafiltrar.txt");
    
    //Pruebas IOPoligonoCondicionado

    out.open("resultados.txt"); 
    IOPoligonoCondicionado(inCond, out, 20); //Lee y envía los poligonos de perimetro mayor a 20
    out.close();


    //Pruebas IsEmpty, ExtraerYAlmacenarPoligonos y ListLength

    std::ifstream inAlm("resultados.txt"); 

    ListaPoligonos lista1;

    assert (IsEmpty(lista1)); //La lista se encuentra vacía al momento de declararla

    ExtraerYAlmacenarPoligonos (inAlm, lista1); //Extraigo los Poligonos, como leo de resultados.txt, todos los poligonos poseen perimetro mayor a 20, y los almaceno en la lista1
    //MostrarLista(lista1);

    assert(not IsEmpty(lista1)); //La lista deja de estar vacía
    assert(ListLength(lista1) == 4); //Pruebo que haya almacenado los 4 poligonos
    assert(ListLength(lista1) != 3); //Prueba del correcto funcionamiento de listlength


    //Pruebas AddPoligono e IsIgualLista

    Poligono PoligonoTest1;
    PoligonoTest1.c = {125, 125, 125};
    AddVerticeAlFinal(PoligonoTest1, {9,0});
    AddVerticeAlFinal(PoligonoTest1, {8,4});
    AddVerticeAlFinal(PoligonoTest1, {0,2.3});
    AddVerticeAlFinal(PoligonoTest1, {1,9});
    
    Poligono PoligonoTest2;
    PoligonoTest2.c = {0, 125, 255};
    AddVerticeAlFinal(PoligonoTest2, {1, 0});
    AddVerticeAlFinal(PoligonoTest2, {1, 4});
    AddVerticeAlFinal(PoligonoTest2, {2, 2.3});
    AddVerticeAlFinal(PoligonoTest2, {5, 10});
    
    Poligono PoligonoTest3;
    PoligonoTest3.c = {125, 125, 125};
    AddVerticeAlFinal(PoligonoTest3, {9, 0});
    AddVerticeAlFinal(PoligonoTest3, {13, 4});
    AddVerticeAlFinal(PoligonoTest3, {0, 2.3});
    AddVerticeAlFinal(PoligonoTest3, {1, 1.5});

    Poligono PoligonoTest4;
    PoligonoTest4.c = {42, 33, 100};
    AddVerticeAlFinal(PoligonoTest4, {2, 3});
    AddVerticeAlFinal(PoligonoTest4, {9, 2});
    AddVerticeAlFinal(PoligonoTest4, {1.4, 3});
    AddVerticeAlFinal(PoligonoTest4, {7, 9.4});

    ListaPoligonos ListaTest1;

    AddPoligono (ListaTest1, PoligonoTest4);
    AddPoligono (ListaTest1, PoligonoTest3);
    AddPoligono (ListaTest1, PoligonoTest2);
    AddPoligono (ListaTest1, PoligonoTest1);
    
    ListaPoligonos ListaTest2;
    AddPoligono (ListaTest2, PoligonoTest1);

    ListaPoligonos ListaTest3;
    AddPoligono (ListaTest3, PoligonoTest1);
    AddPoligono (ListaTest3, PoligonoTest2);
    AddPoligono (ListaTest3, PoligonoTest3);
    AddPoligono (ListaTest3, PoligonoTest4);

    assert(IsIgualLista(lista1, ListaTest1)); //Pruebo que los poligonos que se extrayeron con ExtraeryAlmacenarPoligonos sean los correctos
    assert(not IsIgualLista(lista1, ListaTest2));
    assert(not IsIgualLista(lista1, ListaTest3));
    
    //Pruebas ClasificarListaPorPerim (involucra LiberarMemoriaLista)

    ClasifPoligonosPorPerimetro clasif1;
    ClasificarListaPorPerim(lista1, clasif1, 20.0, 30.0); //Clasifica los poligonos de la lista segun su perimetro en menores a 20, mayores a 20 y menores a 30 y, por ultimo mayores a 30 
    //MostrarListaClasificada(clasif1);

    assert(IsEmpty(clasif1.Listas.at(0))); //Verifico que no hay poligonos con perimetro menor a 20
    assert(IsEmpty(lista1)); //Luego de realizar la clasificación se libera la memoria de la lista
    
    ListaPoligonos listatest4;
    AddPoligono(listatest4, PoligonoTest2);
    AddPoligono(listatest4, PoligonoTest3);

    assert(IsIgualLista(listatest4, clasif1.Listas.at(1))); //Verifico que se hayan almacenado bien los poligonos con perimetro mayor a 20 y menor a 30 

    ListaPoligonos listatest5;
    AddPoligono(listatest5, PoligonoTest1);
    AddPoligono(listatest5, PoligonoTest4);
    
    assert(IsIgualLista(listatest5, clasif1.Listas.at(2))); //Verifico que se hayan almacenado bien los poligonos con perimetro mayor a 30
    
    //Pruebas ISEmptyClasif

    assert(not IsEmptyClasif(clasif1)); //La clasificiación todavia contiene los poligonos almacenados
    LiberarMemoriaClasif(clasif1);  //Libero la memoria de la clasificación
    assert(IsEmptyClasif(clasif1)); //Ahora la clasificación esta vacía

    std::cout << "Fin.";
}