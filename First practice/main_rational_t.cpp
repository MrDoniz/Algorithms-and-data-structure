// AUTOR: Daniel Dóniz García
// FECHA: 17 feb 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMPILACIÓN: clear; g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

#include <iostream>
#include <cmath>

#include "rational_t.hpp"

using namespace std;

int main(){
  //Crea el objeto a, b y c. Con el constructor por defecto.
  rational_t a(1, 2), b(3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();
  
  c.read();
  cout << "c: ";
  c.write();

  // FASE II  
  rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();
  cout << "x == y? " << (x.isEqual(y)  ? "true" : "false") << endl;
  cout << "x < y? " << (x.isGreater(y) ? "true" : "false") << endl;
  cout << "x > y? " << (x.isLess(y) ? "true" : "false") << endl;
  cout << "x == 0? " << (x.isEqualZero(y) ? "true" : "false") << endl;
  
  
  // FASE III
  cout << "a + b: " << a.add(b) << endl;
  cout << "a - b: " << a.substract(b) << endl;
  cout << "a * b: " << a.multiply(b) << endl;
  cout << "a / b: " << a.divide(b) << endl;

  return 0;
}