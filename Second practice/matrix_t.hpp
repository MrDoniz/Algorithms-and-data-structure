// AUTOR: Daniel Dóniz García
// FECHA: 8 mar 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMPILACIÓN: $ clear; g++ -g rational_t.cpp main_p2.cpp -o main_p2
// COMPILACIÓN: $ make
// EJECUCIÓN:        $ ./main_p2 < data.txt
//GUÍA DE ESTILO DE GOOGLE: https://google.github.io/styleguide/cppguide.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T> class matrix_t {
  public:
    matrix_t(const int = 0, const int = 0);
    ~matrix_t();
    
    void resize(const int, const int);
    
    // Getters
    int getM(void) const;
    int getN(void) const;
    
    // Getters-Setters
    T& at(const int, const int);
    T& operator()(const int, const int);
    
    // Getters constantes
    const T& at(const int, const int) const;
    const T& operator()(const int, const int) const;
    
    // Operaciones y operadores
    void multiply(const matrix_t<T>&, const matrix_t<T>&);

    void write(ostream& = cout) const;
    void read(istream& = cin);

  private:
    int m_, n_; // m_ filas y n_ columnas
    vector_t<T> v_;
    
    int pos(const int, const int) const;
};



template<class T> matrix_t<T>::matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T> matrix_t<T>::~matrix_t(){}



template<class T> void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T> inline int matrix_t<T>::getM() const {
  return m_;
}



template<class T> inline int matrix_t<T>::getN() const {
  return n_;
}


//Comprobar si las filas y columnas están dentro del rango.
template<class T> T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= getM());
  assert(j > 0 && j <= getN());
  return v_[pos(i, j)];
}


//Get-Set
template<class T> T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}



template<class T> const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= getM());
  assert(j > 0 && j <= getN());
  return v_[pos(i, j)];
}



template<class T> const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}



template<class T> void matrix_t<T>::write(ostream& os) const { 
  os << getM() << "x" << getN() << endl;
  for (int i = 1; i <= getM(); ++i) {
    for (int j = 1; j <= getN(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T> void matrix_t<T>::read(istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= getM(); ++i)
    for (int j = 1; j <= getN(); ++j)
      is >> at(i, j);
}



template<class T> inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= getM());
  assert(j > 0 && j <= getN());
  return (i - 1) * getN() + (j - 1);
}


// FASE III: producto matricial
template<class T> void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert(A.getN() == B.getM());
  resize(A.getM(), B.getN());
  int aux = 0;
  
  for(int i = 1; i <= m_; i++)
    for(int j = 1; j <= n_; j++){
      for(int k = 1; k <= A.getN(); k++){
        aux = aux + (A.at(i, k) * B.at(k, j));
        at(i, j) = aux;
      }
      aux = 0;
    }
}