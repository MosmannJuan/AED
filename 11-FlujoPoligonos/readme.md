# Autor de la resolución:
## Usuario Github: MosmannJuan
## Mosmann, Juan Ignacio
## Legajo N° 158.964-7

# Trabajo N° 11: "Flujo de datos de polígono"

# Etapa 1: Análisis del problema.
## Enunciado: Desarrollar un programa con funciones que envíen y reciban a traves de flujos (estándar o alguno en particular) una cantidad indefinida de polígonos.

## *Hipótesis de trabajo:* Se utilizarán las definiciones anteriormente usadas de tipo Punto, tipo Color y tipo Poligono. Se desarrollará la solución del problema mediante la definición de funciones. Para las pruebas se mostrará por pantalla el poligono extraído utilizando una función, verificando que conicida con los polígonos enviados de forma automática y con los polígonos escritos manualmente en archivos distintos.

# **Etapa 2: Diseño de la solución**

## **Funciones "Enviar"**

#### *Representación visual (En PseudoCódigo)*

* Polígono 
* Flujo de Salida
* EnviarPoligono (EnviarColor + mientras haya puntos en el polígono: EnviarPunto)

## **Funciones "Extraer"**

#### *Representación visual (En PseudoCódigo)*

* Flujo de Entrada
* Mientras pueda extraerpoligono: 
* ExtraerPoligono (ExtraerColor + ExtraerPuntos(mientras pueda extraer un punto): ExtraerPunto + MostrarPoligono)

## *Problemas encontrados:*
* Al usar el tipo de datos uint8_t para las coordenadas del color, ExtraerColor solo tomaba un digito de cada numero (Solucionado extrayendo a las coordenadas como int y asignandolas a cada parte del color, de esta forma se realiza el cambio de tipo de dato de forma automática, para enviarlos o mostrarlos, es necesario solicitar que lo hagan en forma de entero, en caso contrario, c++ lo considera como un caracter debido a que ocupa 1 byte).
* Para poder hacer que las funciones retornen un booleano si se lograba extraer lo solicitado, no basto con solo retornar el istream, se debio agregar delante bool con el nombre del flujo entre parentesis luego.
* El flujo solo permitía extraer un único polígono. (Esto sucedía porque el flujo quedaba en un estado erróneo al finalizar la extracción del poligono y encontrarse con un problema para seguir "extrayendo poligono", para solucionarlo se debió hacer un "clear" del flujo).

### *Resultados*

#### El programa funciona de forma esperada, logrando enviar, extraer y mostrar en pantalla una cantidad indefinida de polígonos extrayendo tanto de forma automática como manual (tanto desde un archivo como por consola a través del uso del teclado)

#### *Observaciones:* 
* Se adjunta el archivo datos2.txt ya que es el archivo manual utilizado, se podría modificar tanto como se quiera siempre que se respete el nombre del archivo y el formato para los poligonos y el programa funcionará sin problemas.
* No se adjunta el archivo datos.txt ya que al ejecutar el programa, el mismo se creará de forma automática.
