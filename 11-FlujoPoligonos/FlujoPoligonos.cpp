/* Mosmann, Juan Ignacio
AED 2020
Definición de funciones
Leer poligonos desde un archivo */

#include "FlujoPoligonos.h"

void MostrarPoligono(const Poligono& pol){
    std::cout <<"El poligono posee " << pol.n <<" lados." <<"\n";
    std::cout <<"El color en formato rgb es: " <<GetHtmlrgb(pol.c) << "\n";
    std::cout <<"Las coordenadas de sus puntos son: ";
    unsigned i{0};
    while( i < pol.n){
        MostrarPunto(pol.puntos.at(i));
        std::cout << "; ";
        ++i;
    }
}

void MostrarPunto(Punto p){
std::cout <<"(" <<p.x <<";" <<p.y <<")" <<"\n";
}

std::string GetHtmlrgb (Color c){
    std::string red = std::to_string (c.r);
    std::string green = std::to_string (c.g);
    std::string blue = std::to_string (c.b);

    return "rgb(" + red + "," + green + "," + blue + ")";
}

void AddVertice (Poligono& pol, const Punto& pun){
    pol.puntos.at( pol.n ).x = pun.x;
    pol.puntos.at( pol.n ).y = pun.y;
    pol.n ++;
}

//Funciones Extraer

bool ExtraerColor(std::istream& in, Color& c){
    short aux;
    in >> aux;
    c.r = aux;
    in >> aux;
    c.g = aux;
    in >> aux;
    c.b = aux;
    return bool (in);
}

bool ExtraerPunto(std::istream& in, Punto& p){
    in >> p.x;
    in >> p.y;
    
   return bool (in);
}

bool ExtraerPuntos(std::istream& in, Poligono& pol){
    
    pol.n = 0;
    for(Punto p; ExtraerPunto(in, p);){
        AddVertice (pol, p);
    }
    
return bool (in);
}

bool ExtraerPoligono(std::istream& in, Poligono& pol){
    
    ExtraerColor(in, pol.c);
    ExtraerPuntos(in, pol);
    return ExtraerSeparador(in);

}

bool ExtraerPoligonos(std::istream& in){
   for (Poligono pol; ExtraerPoligono(in, pol); )
     MostrarPoligono(pol);
    
   return not in.fail();
}



//Funciones Enviar

bool EnviarPunto(std::ostream& os, Punto p){
 os << p.x << ' ' << p.y << ' ' ;
 return bool (os);
}

bool EnviarColor(std::ostream& os, Color c){
    os << static_cast <int> (c.r) << ' ' << static_cast <int> (c.g) << ' ' << static_cast <int> (c.b) << ' ' ; //El static cast es necesario para que interprete a las coordenadas rgb como numeros y no como caracteres ya que al ocupar 1 byte se considera como un caracter en codigo ascii de forma automática
    return bool (os);
}

bool EnviarPoligono(std::ostream& os, const Poligono& pol){
    EnviarColor(os, pol.c);
    unsigned i{0};
    while (i < pol.n){
        EnviarPunto(os, pol.puntos.at(i));
        ++i;
    }
    os << "# " <<"\n" ;
    return bool (os);
}

bool ExtraerSeparador (std::istream& in ){
    in.clear (); //Limpia el estado del flujo de entrada, en otro caso el booleano seguia dando falso, lo que no permitía extraer varios poligonos
    char c{'@'}; //Inicializo la variable con un valor distinto para poder verificar que se extrae el caracter deseado
    in >> c;
    return c == '#' and in;
}