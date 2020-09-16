# Color:

## Color = {c = (r, g, b) / r, g ,b ϵ N y r, g ,b ϵ [0, 255]

# Operaciones:

* Mezclar: Color x Color → Color
#### Sea c1 = (r1, g1, b1) y c2 = (r2, g2, b2) ϵ Color
#### Mezclar(c1, c2) = (r3, g3, b3) / r3 = (r1 + r2) / 2, g3 = (g1 + g2) / 2, g3 = (g1 + g2) / 2,

* MezclarConPartes: N x Color x N x Color → Color

* SumarColores: Color x Color → Color

* RestarColores: Color x Color → Color

* GetComplementario: Color → Color
#### Sea c = (r1, g1, b1) y res = (r2, g2, b2) ϵ Color
#### GetComplementario(c) = res / r2 = 255 - r1, g2 = 255 - g1, b2 = 255 - b1

* GetHtmlHex: Color → String

* GetHtmlrgb: Color → String

* IsIgual: Color x Color → Bool

#### Sea c1 = (r1, g1, b1) y c2 = (r2, g2, b2) ϵ Color
#### IsIgual (c1, c2) =  
#### * true           si r1 = r2, g1 = g2 y b1 = b2
#### * false          e.o.c
