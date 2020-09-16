# Punto:

## Punto = {p = (x, y) / x ,y ϵ R}

# Operaciones:

* SumarPuntos: Punto x Punto → Punto
#### Sean p1 = (x1, y1), p2 = (x2, y2) ϵ Punto
#### SumarPuntos(P1, P2) = (a, b) / a = x1 + x2 , b = y1 + y2

* LeerPunto: vacio → Punto

* MostrarPunto: Punto → vacio (La funcion no retorna ningun valor pero tiene un efecto de lado)

* ProductoPorEscalar: R x Punto → Punto
#### Sea k ϵ R y p = (x, y) ϵ Punto
#### ProductoPorEscalar(k,p) = (a, b) / a = k * x, b = k * y 

* GetCuadrante: Punto → CuadrantesyEjes (enumerado)

* RestarPuntos: Punto x Punto → Punto

* GetDistancia: Punto x Punto → R

* GetDistanciaAlOrigen: Punto → R

* CoordenadasPolares: Punto → Punto

* ProductoEscalar: Punto x Punto → R

* MoverPunto: Punto x Punto → Punto

* IsIgual: Punto x Punto → Bool
