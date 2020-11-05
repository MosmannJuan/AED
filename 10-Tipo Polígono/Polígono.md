# Poligono:

* Primera implementación (Utilizando array para almacenar puntos de forma estática, preestableciendo un máximo)
Polígono = { pol = n, p1, p2, ..., p20, c / n ϵ N con n ϵ [3,20]; p1, p2, ..., p20 ϵ Punto; c ϵ Color} 

* Segunda implementación (Utilizando punteros para poder almacenar los puntos de forma dinámica, para lo cual se debió definir una estructura adicional Nodo)

Nodo = { n = p, signodo / p ϵ Punto, signodo ϵ Z} //signodo representará la siguiente dirección de memoria

Polígono = { pol = primerpunto, c / primerpunto ϵ Z, c ϵ Color } //primerpunto representará la dirección de memoria del primer Nodo de la lista de puntos

# Operaciones:

* AddVertice: Polígono x Punto → Vacio (La funcion no retorna ningun valor pero modifica a polígono)

* GetVertice: Polígono x N → Punto

* SetVertice: Polígono x N x Punto → Vacio (La funcion no retorna ningun valor pero modifica a polígono)

* RemoveVertice: Polígono → Vacio (La funcion no retorna ningun valor pero modifica a polígono)

* GetCantidadDeLados: Polígono → N

* GetPerimetro: Polígono → R

* MostrarPoligono: Polígono → Vacío (La función no retorna ningun valor pero posee un efecto de lado)

* IsIgual: Polígono x Polígono → Bool
#### Sea pol1 = (PrimerPunto1, c1) y pol2 = (PrimerPunto2, c2) ϵ Poligono y sean p1, p2, p3, ..., pn los puntos correspondientes a la lista para cada Polígono
#### IsIgual (pol1, pol2) =
##### true                 si  p1.1 = p1.2, p2.1 = p2.2, p3.1 = p3.2, ..., pn.1 = pn.2 ,c1 = c2;
##### false                e.o.c
