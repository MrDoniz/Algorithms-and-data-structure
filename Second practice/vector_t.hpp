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

using namespace std;

template<class T> class vector_t {
  public:
    vector_t(const int = 0);
    ~vector_t();
    
    void resize(const int);
    
    // Getters
    T getVal(const int) const;
    int getSize(void) const;
    
    // Setters
    void setVal(const int, const T);
    
    // Getters-Setters
    T& at(const int);
    T& operator[](const int);
    
    // Getters constantes, solo pueden invocar otros metodos const.
    const T& at(const int) const;
    const T& operator[](const int) const;

    void write(ostream& = cout) const;
    void read(istream& = cin);

  private:
    T *v_;
    int sz_;
    
    void build(void);
    void destroy(void);
};



template <class T> vector_t<T>::vector_t(const int n) {
  sz_ = n;
  build();
}



template <class T> vector_t<T>::~vector_t() {
  destroy();
}



//Constructor
template <class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}


//Destructor
template<class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}


//Redimencionar vector.
template<class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}



template<class T> inline T vector_t<T>::getVal(const int i) const {
  assert(i >= 0 && i < getSize());
  return v_[i];
}



template<class T> inline int vector_t<T>::getSize() const {
  return sz_;
}



template<class T> void vector_t<T>::setVal(const int i, const T d) {
  assert(i >= 0 && i < getSize());
  v_[i] = d;
}



template<class T> T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < getSize());
  return v_[i];
}



template<class T> T& vector_t<T>::operator[](const int i) {
  return at(i);
}



template<class T> const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < getSize());
  return v_[i];
}



template<class T> const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}



template<class T> void vector_t<T>::write(ostream& os) const { 
  os << getSize() << ":\t";
  for (int i = 0; i < getSize(); i++)
    os << at(i) << "\t";
  os << endl;
}



template<class T> void vector_t<T>::read(istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
// Solo para scalProd de T
template<class T> T scalProd(const vector_t<T>& v, const vector_t<T>& w) {
  assert (v.getSize() == w.getSize());
  double scalProd = 0;
  for (int i = 0; i < v.getSize(); i++)
    scalProd = scalProd + v[i] * w[i];
  return scalProd;
}


// Solo para scalProd de rational_t
double scalProd(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  assert (v.getSize() == w.getSize());
  double scalProd = 0;
  for (int i = 0; i < v.getSize(); i++)
    scalProd = scalProd + (v[i] * w[i]).value();
  return scalProd;
  // rational_t scalProd;
  // for (int i = 0; i < v.getSize(); i++)
    // scalProd = scalProd + (v[i] * w[i]);
  // scalProd.write();
  // return scalProd.value();
}
