/*Mosmann, Juan Ignacio
AED 2020
Triangulo y Polígono
01/09/2020*/

#include <array>

struct Punto{double x, y;};

enum struct Colores {Rojo, Azul, Amarillo, Verde, Violeta, Naranja, Blanco, Negro};

enum struct ClasifLados {
    Triangulo, Cuadrilatero, Pentagono, Hexagono, Heptagono, Octagono, Eneagono, Decagono, Undecagono, 
    Dodecagono, Tridecagono, Tetradecagono, Pentadecagono, Hexadecagono, Heptadecagono, Octadecagono, 
    Eneadecagono, Isodecagono;};

struct Triangulo {Punto a, b, c; Colores color;};

struct Poligono {
    unsigned n;
    std::array <Punto, 20> puntos;
    Colores color;};

//Funciones Triangulo

void SetColor (Triangulo &t, Colores color);

Colores GetColor (const Triangulo&);

std::array <Punto, 3> GetPuntos (const Triangulo&);

double CalcularPerimetro (const Triangulo &);



//Funciones Poligono

void SetColor (Poligono &p, Colores color);

Colores GetColor (const Poligono&);

ClasifLados ClasifPoligono (const Poligono&);

void AgregarPuntoAlFinal (Poligono&);

void QuitarPuntoDelFinal (Poligono&);
