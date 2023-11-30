# Proyecto: Biblioteca
Este proyecto permite generar la simulación de una biblioteca al buscar algún libro según sea por el título, autor, o bien, por su categoria. En donde si lo buscas por título te desplegara los libros que tengan ese título; en autor te despliega todos los libros disponibles y ordena a los autores en orden alfabetico; por último para la categoria, te  ordena en orden alfabético los títulos de todos los libros de dicha categoria.

## Descripción del avance 1
En este avance se pudo implementar el uso de un algoritmo de ordenamiento (en este caso implemente el "Merge Sort") para poder ordenar en orden alfabetico, ya sea por autor o titulo. Es por ello que se puede apreciar lo visto en clase de algoritmos de ordenamiento.

## Descripción del avance 2
En este avance se implementa un árbol AVL como estructura de datos para guardar y acceder de una manera más eficiente a ellos. Entregando sin necesidad de un método de ordenamiento los datos ya ordenados.

### Cambios sobre el primer avance
1. Cambio 1: Cambié mi estructura de datos de vector a árbol AVL, estando estos ya ordenados en el mismo árbol. Esto debido a que ya en la misma estructura de datos de un árbol AVL me permite tener de manera ordenada mis datos
2. Se agregó dentro del menú una opción de salir, para que muestre en ciclo las opciones hasta que el usuario decida salirse.
3. Por el momento no se hace uso del método de ordenamiento mergeSort, debido a que ya dentro del mismo árbol AVL da los datos ordenados alfabéticamente
4. 
## Descripción del avance 3
Lo que se realizo en este avance fue colocar dos usuarios distintos, dependiendo quién sea el que inicie sesión será distinto el menu que apareza, siendo que el bibliotecario tendrá la posibilidad de agregar o eliminar un libro dentro del archivo.

### Cambios sobre el segundo avance
1. Cambio 1: Se agrego la opción de distinguir usurario, teniendo al usuario normal y al bibliotecario, donde el usuario solo tendrá la posibilidad de ver que libros están disponibles, mientras que el bibliotecario puede agregar, eliminar o ver todos los libros que hay en la biblioteca.
2. Cambio 2: Si el usuario quiere ver los libros ya sea por título, autor o categoria, según la opción que escoja le mostrara todos los títulos, autores, o bien, categorias disponibles.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Para que funcione el código se requiere de un archivo .txt en donde se encuentran almacenados varios libros, donde se menciona el titulo, autor y categoria; estos tres separados por un espacio.

Al iniciar el programa se muestra que se ponga el nombre de usuario y la contraseña.
Si se coloca en usuario "usuario" y contraseña "67890" se le desplegara 4 opciones
Siendo:
1. Buscar libro por título.
2. Buscar libro por autor.
3. Buscar libro por categoría.
4. Salir del programa
   
Si se coloca en usuario "bibliotecario" y contraseña "12345" se le abrirá el menú del bibliotecario:
Siendo:
1. Buscar libro por título.
2. Buscar libro por autor.
3. Buscar libro por categoría.
4. Agregar libro
5. Eliminar libro
6. Mostrar biblioteca completa
7. Salir del programa

## Descripción de las salidas del avance de proyecto
Las salidas dependerán del método que seleccione el usuario/bibliotecario.

* Si el usurario selecciono la primera opción:
Se mostrará los títulos que estén disponibles, para que al buscarlo le muestre toda la ficha del libro.
* Si el usuario selecciona la opción 2:
Saldrán todos los autores que hay disponibles, para que posteriormente al elegir un autor se le despliegue el autor con todos los libros disponibles.
* Si el usuario selecciona la opción 3:
Se mostrarán las categorias que hay, para que de esta forma cuando el usuario coloque su categoria a buscar se le desplieguen todos los libros disponibles de esa categoria.

Si es bibliotecario:
* Si selecciona la opción 4:
Se le hará agregar el título, autor y categoria del libro. Mostrando un mensaje de libro agregado correctamente

* Si selecciona la opción 5:
Se le hará escribir el título del libro a eliminar y se eliminará del txt

* Si selecciona la opción 6:
Se mostrará todos los libros disponibles.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Genero un buen análisis de complejidad de los algoritmos al buscar uno de los más eficientes en función al tamaño de los datos y su rendimiento, el cual puede manejar gran cantidad de datos. Esto debido a su complejidad de tiempo, teniendo que tanto en el mejor como en el peor caso su complejidad es de O(n log n) haciéndolo un algoritmo bueno al trabajar con grandes conjuntos de datos, ya que, si por ejemplo hacemos una comparación con el algortitmo de ordenación de QuickSort en el peor de los casos tiende a generar una mayor cantidad de operaciones.
También se realiza un buen análisis de complejidad en cuanto a las estructuras de datos, ya que al estar implementando vectores ayuda a facilitar y hacer más eficiente la función del programa.

Viendo la complejidad usada en algunas secciones del código tenemos:

*Complejidad de la búsqueda de los libros:  Según el título, autor o categoria buscada, su implemetación tiene una complejidad O(n), ya que "n" es el número de libros en la biblioteca. Esta complejidad se debe a que necesita recorrer la lista de libros en su totalidad para encontrar con cuál coincide y poder encontrar el deseado.
*Complejidad en el método de ordenamiento: Usando el algoritmo "merge sort" tiene una complejidad de O(n log n), de igual forma "n" es el número de libros en la biblioteca. Siendo eficiente este algoritmo incluso para una gran colección de libros.

Con todo esto se puede decir que la complejidad final del programa es tanto O(n log n) y O(n), siendo O(n log n) la complejidad dominante, sirviendo para la ordenacion de los libros. Es por ello que el programa es eficiente en terminos de ordenamiento y búsqueda. Además, un detalle es que la implementación del método merge tiene solo una complejiadad de O(n) y el método mergeSort una complejidad de O(log n), pero al implementar dentro de mergeSort el método sort se llega a una complejidad final de O(n log n), esto también explicado dentro de los comentarios del programa en Libro.h al principio del método de sort y merge sort.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
En la estructura de datos implementada hay varias funciones entre ellas:

* El método de add: Este sirve para agregar un nuevo elemento dentro del árbol, siendo que para lograr esto debe hacer un recorrido comenzando desde la raíz del árbol y dsplazandose a través de los nodos. Este tiene una complejidad de O(log n)

* Método de búsqueda: Para buscar un dato, también es necesario recorrer todo el árbol desde la raíz, donde de va basando en comparaciones, decidiendo si buscar en el subárbol izquierdo, el subárbol derecho o bien si ya se encontro el valor buscado. Teniendo de igual forma que en el peor de los casos será de una complejidad de O(log n). Siendo n el número de nodos en el árbol.
Todo el método de busqueda se basa en la comparación, tomando que si el valor de busqueda es menor al nodo, la búsqueda continua en el subárbol izquierdo, mientras que si es mayor, la búsqueda continua en el subárbol derecho y si es igual significa que se encontró el nodo y la busqueda termina.

* Hay otros métodos que aún no implemento como "remove" que de igual forma debe encontrar un nodo y luego realizar las rotaciones necesarias para manetener un equilibrio en el álbol. Siendo de una complejidad de O( log n). También los métodos de inorde o preorder, donde se visita a los nodos del árbol solo una vez en un recorrido, dando una complejidad de O(n), siendo 'n' la cantiadad de nodos en el árbol.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Dentro de todo lo que compone el programa podemos encontrar distintos tipos de complejidad como O(1), O(n), O(n log n) y O(log n).
* Complejidad O(1):
Dentro del código lo que viene siendo complejidad O(1) son operaciones de entrada y salida, donde se involucran comparaciones simples, tal como:
- La verificación de la apertura del archivo
- La verificación de usuario y contraseña
- La obtención del usuario para el switch

* Compeljidad O(n):
Sea compeljidad se puede ver cuando se quiere leer una cantidad de n libros, aplicándose en:
- La lectura del archivo, leyendo n cantidad de líneas en el archivo
- Insertar valores dentro del vector
- Operaciones de busqueda dentro del vector
- Eliminar valores dentro del vector

* Compejidad O(log n):
Todo lo que tiene que ver con el árbol AVL tiene una complejidad 0(log n), como lo sería el insertar datos dentro del árbol, su operación de búsqueda, su operación para agergar y eliminar valores.
Siendo que el árbol AVL tiene diferencia de alturas entre el subárbol izquierdo y el derecho de cada nodo, donde debe estar en "equilibrio" es decir en un rango de -1, 0, 1. Esto garantiza que la altura del árbol sea proporcional al logaritmo del número de nodos en el peor de los casos.

* Compeljidad O(n log n):
Esta compeljidad se puede ver en el ordenamiento merge sort, siendo n la cantidad de elementos a ordenar. Siendo que este se puede ver cada que aplico este algoritmod e ordenamiento para mostrar al usuario todos los libros ordenados alfabéticamente.

* La complejidad total del programa se ve dominada por el método de ordenamiento y la estructura de datos. Tomando en cuenta que la complejidad del método de ordenamiento es O(n log n) y la del árbol AVL es de O(log n) se puede denominar que la complejidad dominante es la de O(n log n).


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
*Hago uso del algoritmo de ordenamiento Merge Sort para poder ordenar alfabéticamente los libros según lo que el usuario elija. Este algoritmo fue el implementado, debido a que su eficiencia en terminos de tiempo, al tener una complejidad de O(n long n), este a diferencia de otros algoritmos como el Bubble Sort o el Insertion Sort en el peor de los casos se sigue manteniendo en la misma complejidad y no sufre un cambio significativo en el tiempo de ejecución si llega a crecer el tamaño de los datos que se requieren acomodar. Además, implementando el Mege Sort al dividir los datos que tengo a la mitad, hace de mayor facilidad su implementación, adicionalmente su complejidad espacial es de O(n) al  tener una capacidad para dividir la lista original en sublistas más pequeñas y administrar el espacio. Esto demuestra la capacidad de poder seleccionar y aplicar un algoritmo de ordenamiento adecuado al problema.
Otro punto sería que a pesar de llegar a ocupar más espcaio en la memoria en comparación a otros algoritmos, ya que requiere crear y guardar en dos vectores distintos e ir acomodando, sin embargo, se tiene un control sobre este uso de la memoria, siendo que las copias temporales de los datos, son predecibles y controladas, ya que si se aplica la eliminación de copias innecesarias, minimizaría el impacto en la memoria. 

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Seleccione como estructura de datos un árbol AVL, debido a que tiene diversas ventajas como:
* Una búsqueda eficiente: El árbol AVL garantiza una búsqueda en tiempo logarítmico O(log n), siendo bueno para una gran colección de libros/datos.
* Matiene el orden: Es decir, manitiene los datos almacenados ordenados en función al valor, ayudando a facilitar y tener una menor complejidad la búsqueda.
* Equilibrio automático: El árbol AVL hace que el árbol se mantenga equilibrad por lo que de esta forma evita que se haga un árbol binario desequilibrado.
  
Ahora haciendo una comparativa de por qué un árbol AVL y otro método no:
* Una lista enlazada no ordenada, su búsqueda tendría una complejidad O(n), siendo que requeire de explorar cada elemneto de la lista.
* Una lista doblemente ligada puede ser funcional al querer hacer una inserción o eliminación, sin embargo, cuando se trata de una mayor cantidad de datos mantiene una eficiencia de búsqueda de O(lon n), además de mantener el orden.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Agrego métodos de búsqueda para consultar la información tal como los get para búsqueda de título, autor o categoira, siendo búsquedas con una complejidad de O(log n), lo cuál asegura que las consultas realizadas sea hagan de manera más eficientes, incluso con una mayor cantiadad de datos.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Hago uso de Streams de archivos, donde utlizo idstream para abrir y leer mi archivo .txt, cargando la información de este archivo externo. Despues de leer los datos, los carga dentro de mi estructura de datos, que en este caso fue el árbol AVL, mandando llamar mi función add cada que se lee una línea del archivo.
Por último cierro adecuadamente el archivo.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Dentro de mi código tengo la opción para que el bibliotecario pueda agregar un libro, o bien, eliminar. Teniendo que cuando ya sea agregue o elimine, se hace directamente en el archivo .txt.
Dónde primero mando abrir el archivo para posteriormente hacer la modificación correspondiente. 