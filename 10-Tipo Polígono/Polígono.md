# Poligono:

Polígono = { pol = n, p1, p2, ..., p20, c / n ϵ N con n ϵ [3,20]; p1, p2, ..., p20 ϵ Punto; c ϵ Color}

# Operaciones:

* AddVertice: Polígono x Punto → Vacio (La funcion no retorna ningun valor pero modifica a polígono)

* GetVertice: Polígono x N → Punto

* SetVertice: Polígono x N x Punto → Vacio (La funcion no retorna ningun valor pero modifica a polígono)

* RemoveVertice: Polígono → Vacio (La funcion no retorna ningun valor pero modifica a polígono)

* GetCantidadDeLados: Polígono → N

* GetPerimetro: Polígono → R

* IsIgual: Polígono x Polígono → Bool
#### Sea pol1 = (n1, p1, p2, ... , p20, c1) y pol2 = (n2, q1, q2, ... , q20, c2) ϵ Poligono
#### IsIguaal (pol1, pol2) =
##### true                 si n1 = n2 , p1 = q1, p2 = q1, ... , p20 = q20, c1 = c2;
##### false                e.o.c
