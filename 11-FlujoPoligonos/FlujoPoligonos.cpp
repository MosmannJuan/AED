/* Mosmann, Juan Ignacio
AED 2020
Leer puntos desde un archivo */

#include <iostream>
#include <fstream>
#include <cstdint>
#include <array>

struct Punto{double x,y;};

//struct Color {uint8_t r, g, b ;}; usando esta definicion de color solo tomaba de a 1 digito para cada coordenada de color

struct Color {unsigned r, g, b ;};

struct Poligono {
    unsigned n;
    std::array <Punto, 20> puntos;
    Color c;};

void MostrarPunto(const Punto&); /*Muestra por la salida estándar un punto con el formato (x,y)*/

std::string GetHtmlrgb (Color); //Se usa para mostrar el color

bool ExtraerPunto(std::istream&, Punto&);

bool ExtraerPuntos(std::istream&, Poligono&);

bool ExtraerColor(std::istream&, Color&);

void AddVertice (Poligono&, const Punto&); //Agrega al final del array de puntos del poligono el punto ingresado en el argumento

void ExtraerPoligono(std::istream&, Poligono&);

void MostrarPoligono(const Poligono&);

int main(){
    std::ifstream in ("datos.txt");
    Poligono pol;
    pol.n = 0;

    ExtraerPoligono(in, pol);

    MostrarPoligono(pol);


}

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

void MostrarPunto(const Punto& p){
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
bool ExtraerColor(std::istream& in, Color& c){
    char coma;
    in >> c.r;
    in >> coma;
    in >> c.g;
    in >> coma;
    in >> c.b;
    std::cout << GetHtmlrgb(c) <<"\n";
    return bool (in);
}

bool ExtraerPunto(std::istream& in, Punto& p){
    char car;
    in >> p.x;
    in >> car;
    in >> p.y;
    in >> car;
    MostrarPunto(p);
   return bool (in);
}

bool ExtraerPuntos(std::istream& in, Poligono& pol){
    unsigned i{0};
    Punto p;
    while(ExtraerPunto(in, p)){
        AddVertice (pol, p);
    }
return bool (in);
}

void ExtraerPoligono(std::istream& in, Poligono& pol){
    char car;
    ExtraerColor(in, pol.c);
    in >> car;
    ExtraerPuntos(in, pol);
}
