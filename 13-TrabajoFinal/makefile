Poligono: Poligono.o PoligonoTest.o Color.o Punto.o
	g++ Poligono.o Color.o Punto.o PoligonoTest.o -o Poligono

PoligonoArray: PoligonoArray.o PoligonoArrayTest.o Color.o Punto.o
	g++ PoligonoArray.o PoligonoArrayTest.o Color.o Punto.o -o PoligonoArray

Color: Color.o ColorTest.o
	g++ Color.o ColorTest.o -o Color

Punto: Punto.o PuntoTest.o
	g++ Punto.o PuntoTest.o -o Punto

FlujoPoligonos: FlujoPoligonos.o FlujoPoligonosTest.o Poligono.o Color.o Punto.o
	g++ FlujoPoligonos.o FlujoPoligonosTest.o Poligono.o Color.o Punto.o -o FlujoPoligonos 

FlujoPoligonosArray: FlujoPoligonosArray.o FlujoPoligonosTest.o PoligonoArray.o Color.o Punto.o
	g++ FlujoPoligonosArray.o FlujoPoligonosTest.o PoligonoArray.o Color.o Punto.o -o FlujoPoligonosArray 

FlujoPoligonos.o: FlujoPoligonos.cpp
	g++ -c FlujoPoligonos.cpp 
	
FlujoPoligonosTest.o: FlujoPoligonosTest.cpp
	g++ -c FlujoPoligonosTest.cpp

FlujoPoligonosArray.o: FlujoPoligonosArray.cpp
	g++ -c FlujoPoligonosArray.cpp

FlujoPoligonosArrayTest.o: FlujoPoligonosArrayTest.cpp
	g++ -c FlujoPoligonosArrayTest.cpp

Poligono.o: Poligono.cpp
	g++ -c Poligono.cpp

PoligonoTest.o: PoligonoTest.cpp
	g++ -c PoligonoTest.cpp

Color.o: Color.cpp
	g++ -c Color.cpp

ColorTest.o: ColorTest.cpp
	g++ -c ColorTest.cpp

Punto.o: Punto.cpp
	g++ -c Punto.cpp

Puntotest.o: PuntoTest.cpp
	g++ -c PuntoTest.cpp

PoligonoArray.o: PoligonoArray.cpp
	g++ -c PoligonoArray.cpp

PoligonoArrayTest.o: PoligonoArrayTest.cpp
	g++ -c PoligonoArrayTest.cpp
