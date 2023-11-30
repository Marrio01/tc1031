 /* main.cpp
 *
 *  Created on: 18/09/2023 
 *      Author: Mario Godínez Chavero
 */
#include "Libro.h"
#include "avl.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>



using namespace std;


int main() {

  AVL<Libro> arbolAVL; //Creo una intancia de clase AVL para almacenar los libro en un árbol AVL   
  vector<Libro> biblioteca; //Creo un vector para almacenar todos los libros

  ifstream archivo("Libros.txt");

  if(!archivo){
    cout << "No se pudo abrir archivo" << endl;
    return 1;
  }
  string linea;
// Complejidad O(n), siendo n el número de líneas que tiene el archivo
  while (getline(archivo,linea)){
    istringstream ss(linea);
    string Titulo, Autor, Categoria;
    if (ss >> Titulo >> Autor >> Categoria){
      //Agregar libros dento del árbol AVL es de una complejidadO(log n)
    arbolAVL.add(Libro(Titulo, Autor, Categoria));
      //Agregar libros dento del vector es de una complejidadO(n)
    biblioteca.push_back(Libro(Titulo, Autor, Categoria));
  } else {
      cout << "Error al leer una línea del archivo" << endl;
    }
  }
  archivo.close();

//Hago filtro de bibiolecario o usuario común
  string tipo = "";
  string username;
  int password;

  cout << "Ingrese su nombre de usuario: ";
  cin >> username;

  cout << "Ingrese su contraseña: ";
  cin >> password;

  if (username == "bibliotecario" && password == 12345){
    tipo = "bibliotecario";
  
  } else if (username == "usuario" && password == 67890){
    tipo = "usuario";
  }
  
  int opcion;
  bool salir = false;

  
  while (!salir) {
    if (tipo == "usuario") {
    cout << endl << "Elige la opcion de busqueda: " << endl;
    cout << "1. Buscar libro por titulo" << endl;
    cout << "2. Buscar libro por autor" << endl;
    cout << "3. Buscar libro por categoria" << endl;
    cout << "4. Salir del programa" << endl;
    cin >> opcion;


  switch(opcion){ 
    case 1: {
      //Muestro Títlos disponibles
      cout << "Títulos disponibles: " << endl << endl;
      //La complejidad de ordenamiento que se esat haciendo es de O(n log n)
      mergeSort(biblioteca, 0, biblioteca.size() - 1, [](const Libro& a, const Libro& b) {
          return a.getTitulo() < b.getTitulo();
      });

      for (const Libro& libro : biblioteca) {
            cout << "* " << libro.getTitulo() << endl << endl;
      }
      //Se hace la busqueda 
      cout << "Introduce titulo a buscar: " << endl;
      string tituloBuscado;
      cin >> tituloBuscado;

      Libro libroBuscado(tituloBuscado, "", "");
      vector<Libro> librosEncontrados; 
//La operación de busqueda dentro de un árbol AVL es de complejidad O(log n)
      arbolAVL.getLibrosTitulo(tituloBuscado, librosEncontrados);
  //Muestra los libros encontrados
      if(!librosEncontrados.empty()){
        cout << "Libro encontrado por título: " << tituloBuscado << endl << endl;
        for (const Libro &libro : librosEncontrados){
        cout << libro << endl << endl;
        }
      }else {
        cout << "No se econtro el libro" << endl;

      }
      break;
    }

    case 2:{
       //Muestro Autores disponibles
      cout << "Autores disponibles: " << endl << endl;
      mergeSort(biblioteca, 0, biblioteca.size() - 1, [](const Libro& a, const Libro& b) {
        return a.getAutor() < b.getAutor();
      });
      
      string ultimoAutor = "";
      for(const Libro& libro : biblioteca){
        if (libro.getAutor() != ultimoAutor){
          cout << "* " << libro.getAutor() << endl << endl;
          ultimoAutor = libro.getAutor();
        }
      }

      //Se hace la busqueda 
      cout << "Introduce el autor a buscar: " << endl;
      string autorBuscado;
      cin >> autorBuscado;

      Libro autorLibro("", autorBuscado, ""); //objeto temporal
      vector<Libro> librosEncontrados; 

      arbolAVL.getLibrosAutor(autorBuscado, librosEncontrados);

      //Muestra los libros encontrados
      if (!librosEncontrados.empty()){
        cout << "Libro encontrado por autor: " << autorBuscado << endl;
        for (const Libro &libro : librosEncontrados){
        cout << libro << endl;
        }
      }else {
        cout << "No se encontraron libro de ese autor" << endl;
      }
      break;
    }

    case 3: {
      //Muestro Categorias disponibles
      cout << "Categorias disponibles: " << endl << endl;
      mergeSort(biblioteca, 0, biblioteca.size() - 1, [](const Libro& a, const Libro& b) {
        return a.getCategoria() < b.getCategoria();
      });

      string ultimoAutor = "";
      for(const Libro& libro : biblioteca){
        if (libro.getCategoria() != ultimoAutor){
          cout << "* " << libro.getCategoria() << endl << endl;
          ultimoAutor = libro.getCategoria();
        }
      }

      //Se hace la busqueda 
      cout << "Introduce la categoría a buscar: " << endl;
        string categoriaBuscada;
        cin >> categoriaBuscada;

        vector<Libro> librosEncontradosPorCategoria;

        arbolAVL.getLibrosCategoria(categoriaBuscada, librosEncontradosPorCategoria);

      //Muestra los libros encontrados
        if (!librosEncontradosPorCategoria.empty()){
          cout << "Libro encontrado por categoría: " << categoriaBuscada << endl;
          for (const Libro &libro : librosEncontradosPorCategoria){
          cout << libro << endl << endl;
          }
        }else {
          cout << "No se encontraron libros de esa categoría" << endl;
        }
        break;
      }

    case 4: //salida
    salir = true;
    cout << "Saliendo del programa" << endl;
    break;

    default:
      cout << "Opción inválida" << endl;
    }  



      
      
  } else if(tipo == "bibliotecario"){
      cout << endl << "Elige la opcion de busqueda: " << endl;
      cout << "1. Buscar libro por titulo" << endl;
      cout << "2. Buscar libro por autor" << endl;
      cout << "3. Buscar libro por categoria" << endl;
      cout << "4. Agregar Libro" << endl;
      cout << "5. Eliminar libro" << endl;
      cout << "6. Mostrar la biblioteca completa" << endl;
      cout << "7. Salir" << endl;
      cin >> opcion;


      switch(opcion){ 
        case 1: {
          //Muestro Títlos disponibles
          cout << "Títulos disponibles: " << endl << endl;
          mergeSort(biblioteca, 0, biblioteca.size() - 1, [](const Libro& a, const Libro& b) {
              return a.getTitulo() < b.getTitulo();
          });

          for (const Libro& libro : biblioteca) {
                cout << "* " << libro.getTitulo() << endl << endl;
          }
          //Se hace la busqueda 
          cout << "Introduce titulo a buscar: " << endl;
          string tituloBuscado;
          cin >> tituloBuscado;

          Libro libroBuscado(tituloBuscado, "", "");
          vector<Libro> librosEncontrados; 

          arbolAVL.getLibrosTitulo(tituloBuscado, librosEncontrados);
      //Muestra los libros encontrados
          if(!librosEncontrados.empty()){
            cout << "Libro encontrado por título: " << tituloBuscado << endl << endl;
            for (const Libro &libro : librosEncontrados){
            cout << libro << endl << endl;
            }
          }else {
            cout << "No se econtro el libro" << endl;

          }
          break;
        }

        case 2:{
           //Muestro Autores disponibles
          cout << "Autores disponibles: " << endl << endl;
          mergeSort(biblioteca, 0, biblioteca.size() - 1, [](const Libro& a, const Libro& b) {
            return a.getAutor() < b.getAutor();
          });

          string ultimoAutor = "";
          for(const Libro& libro : biblioteca){
            if (libro.getAutor() != ultimoAutor){
              cout << "* " << libro.getAutor() << endl << endl;
              ultimoAutor = libro.getAutor();
            }
          }

          //Se hace la busqueda 
          cout << "Introduce el autor a buscar: " << endl;
          string autorBuscado;
          cin >> autorBuscado;

          Libro autorLibro("", autorBuscado, ""); //objeto temporal
          vector<Libro> librosEncontrados; 

          arbolAVL.getLibrosAutor(autorBuscado, librosEncontrados);

          //Muestra los libros encontrados
          if (!librosEncontrados.empty()){
            cout << "Libro encontrado por autor: " << autorBuscado << endl;
            for (const Libro &libro : librosEncontrados){
            cout << libro << endl;
            }
          }else {
            cout << "No se encontraron libro de ese autor" << endl;
          }
          break;
        }

        case 3: {
          //Muestro Categorias disponibles
          cout << "Categorias disponibles: " << endl << endl;
          mergeSort(biblioteca, 0, biblioteca.size() - 1, [](const Libro& a, const Libro& b) {
            return a.getCategoria() < b.getCategoria();
          });

          string ultimoAutor = "";
          for(const Libro& libro : biblioteca){
            if (libro.getCategoria() != ultimoAutor){
              cout << "* " << libro.getCategoria() << endl << endl;
              ultimoAutor = libro.getCategoria();
            }
          }

          //Se hace la busqueda 
          cout << "Introduce la categoría a buscar: " << endl;
            string categoriaBuscada;
            cin >> categoriaBuscada;

            vector<Libro> librosEncontradosPorCategoria;

            arbolAVL.getLibrosCategoria(categoriaBuscada, librosEncontradosPorCategoria);

          //Muestra los libros encontrados
            if (!librosEncontradosPorCategoria.empty()){
              cout << "Libro encontrado por categoría: " << categoriaBuscada << endl;
              for (const Libro &libro : librosEncontradosPorCategoria){
              cout << libro << endl << endl;
              }
            }else {
              cout << "No se encontraron libros de esa categoría" << endl;
            }
            break;
          }

        case 4: {
          string nuevoTitulo, nuevoAutor, nuevaCategoria;
          cout << "Ingrese el titulo del nuevo libro: ";
          cin.ignore();
          getline(cin, nuevoTitulo);
          cout << "Ingrese el autor del nuevo libro: ";
          getline(cin, nuevoAutor);
          cout << "Ingrese la Categoria del nuevo libro: ";
          getline(cin, nuevaCategoria);

          ofstream archivo("Libros.txt", ios::app);
          if (archivo.is_open()){
            archivo << nuevoTitulo << " " << nuevoAutor << " " << nuevaCategoria << endl;

            cout << "Libro agregado correctamente" << endl;
            archivo.close();
          } else{
            cout << "Error al abrir archivo" << endl;
          }

          Libro nuevoLibro(nuevoTitulo, nuevoAutor, nuevaCategoria);
          arbolAVL.add(nuevoLibro);
          biblioteca.push_back(nuevoLibro);
          break;
        }

        case 5: {
          string tituloEliminar;
          cout << "Ingrese el titulo del libro a eliminar: ";
          cin.ignore();
          getline(cin, tituloEliminar);

          if(arbolAVL.find(Libro(tituloEliminar, "", ""))){
            //Elimino libro del arbol
            arbolAVL.remove(Libro(tituloEliminar, "", ""));
          } else {
            cout << "Libro no encontrado" << endl;
          }

          // Buscar el libro en el vector biblioteca
          auto it = find_if(biblioteca.begin(), biblioteca.end(), [tituloEliminar](const Libro& libro) {
              return libro.getTitulo() == tituloEliminar;
          });

          if (it != biblioteca.end()) {
              // Eliminar el libro del vector biblioteca
              biblioteca.erase(it);
          } else {
              cout << "Libro no encontrado en el vector biblioteca." << endl;
          }

          //Eliminar del archivo de texto
          ofstream archivo("Libros.txt");
          if (archivo.is_open()) {
              bool libroEncontrado = false; // Variable para verificar si se encontró el libro

              for (const Libro& libro : biblioteca) {
                  if (libro.getTitulo() == tituloEliminar) {
                      libroEncontrado = true;
                      continue; // No escribe el libro que se quiere eliminar en el archivo
                  }

                  archivo << libro.getTitulo() << " " << libro.getAutor() << " " << libro.getCategoria() << endl;
              }

              archivo.close();

              if (!libroEncontrado) {
                  cout << "Libro eliminado" << endl;
              } else {
                  cout << "Libro no encontrado. No se ha eliminado del archivo." << endl;
              }
          } else {
              cout << "Error al abrir archivo" << endl;
          }

          break;
        }


        case 6: {
          cout << "Biblioteca completa: " << endl;
          mergeSort(biblioteca, 0, biblioteca.size() - 1, [](const Libro& a, const Libro& b) {
              return a.getTitulo() < b.getTitulo();
          });
          for (const Libro &libro : biblioteca){
            cout << libro << endl;
          }
          break;
        }
        
        case 7: //salida
        salir = true;
        cout << "Saliendo del programa" << endl;
        break;

        default:
          cout << "Opción inválida" << endl;
        }  
    }


      
    else {
      cout << "Usuario o contraseña incorrectos" << endl << endl;;
      return main();
  }
}
return 0;
  
}