/* Libro.h
 *
 *  Created on: 18/09/2023
 *      Author: Mario Godínez Chavero
 */
#ifndef LIBRO_H_
#define LIBRO_H_

#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Libro{

  private:
    string Titulo;
    string Autor;
    string Categoria;
    int Seleccion;

  public:

    Libro();
    Libro(const string& Titulo, const string& Autor, const string& Categoria); //Constructor
    string getTitulo() const; 
    string getAutor() const;
    string getCategoria() const;
    void FichaLibro() const; //Método para mostrar datos del libro
    bool operator <= (const Libro& otro)const; // Operador de comparación personalizado
    bool operator < (const Libro& otro) const;
    bool operator > (const Libro& otro) const;
    bool operator == (const Libro& otro) const;
    friend ostream& operator<<(ostream& os, const Libro& libro);
    int getSeleccion() const;
};


Libro::Libro(){

}

Libro::Libro(const string& Titulo, const string& Autor, const string& Categoria){
  this->Titulo = Titulo;
  this-> Autor = Autor;
  this -> Categoria = Categoria;
}

string Libro::getTitulo() const{
  return Titulo;
}

string Libro::getAutor() const{
  return Autor;
}

string Libro::getCategoria() const{
  return Categoria;
}

void Libro::FichaLibro() const{
  cout << "Titulo: " << Titulo << " | Autor: " << Autor << " | Categoria: " << Categoria << endl;
}
//Falta modificarlo para que también se pueda hacer comparación con el título del libro
bool Libro::operator<=(const Libro& otro) const{
  return (*this < otro) || (*this == otro);
}

bool Libro::operator<(const Libro& otro) const {
  if(Titulo != otro.Titulo)
    return Titulo < otro.Titulo;
  if (Autor != otro.Autor)
    return Autor < otro.Autor;
  return Categoria < otro.Categoria;
}

bool Libro::operator>(const Libro& otro) const {
  return !(*this <= otro);
}

bool Libro::operator==(const Libro& otro) const {
  return Titulo == otro.Titulo && Autor == otro.Autor && Categoria == otro.Categoria;
}

ostream& operator<<(ostream& os, const Libro& libro) {
    os << "Titulo: " << libro.getTitulo() << " | Autor: " << libro.getAutor() << " | Categoria: " << libro.getCategoria();
    return os;
}

int Libro::getSeleccion() const{
  return Seleccion;
}

//Este método merge tiene una complejidad de O(n), siendo n el tamaño total de los dos subvectores ordenados, recorriendo ambos y colocandolos en orden en el vector final.
void merge(std::vector<Libro> &v, int izquierda, int mitad, int derecha, std::function<bool(const Libro&, const Libro&)> comparador){

  int n1 = mitad - izquierda + 1;
  int n2 = derecha - mitad;

  std::vector<Libro> Izq(n1);
  std::vector<Libro> Der(n2);

  //Complejidad de los ciclos for O(n), ya que va a realizar n iteraciones
  for(int i = 0; i < n1; i++){ 
    Izq[i] = v[izquierda + i];
  }
  for(int j = 0; j < n2; j++){ 
    Der[j] = v[mitad + 1 + j];
  }

  int i = 0, j = 0, k = izquierda;

  //También la complejidad de los while sería de O(n) realizando como maximo las n compraciones de los n elementos.
  while(i < n1 && j < n2){
    if(comparador(Izq[i], Der[j])){
      v[k] = Izq[i];
      i++;
    }
    else{
      v[k] = Der[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    v[k] = Izq[i];
    i++;
    k++;
  }

  while(j < n2){
    v[k] = Der[j];
    j++;
    k++;
  }
}

//Este método sólo, sin tomar en consideración el conjunto con merge es de una compeljidad de O(log n), realizándose dos llamadas recursivas. 
//Es por ello que al juntar mergeSort con merge, su combinación nos da una complejidad final de O(n log n).
void mergeSort(std::vector<Libro> &v, int izquierda, int derecha, std::function<bool(const Libro&, const Libro&) > comparador) {
    if (izquierda < derecha) {
        int middle = izquierda + (derecha - izquierda) / 2;
        mergeSort(v, izquierda, middle, comparador);
        mergeSort(v, middle + 1, derecha, comparador);
        merge(v, izquierda, middle, derecha, comparador);
    }
  
}




#endif /* LIBRO_H_ */