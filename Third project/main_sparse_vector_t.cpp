// AUTOR: Daniel Dóniz García
// FECHA: 2 abr 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN 1: $ g++ -g main_sparse_vector_t.cpp -o main_sparse_vector_t
// COMPILACIÓN 2: $ make
// EJECUCIÓN    : $ ./main_sparse_vector_t < data_sparse_vector_t.txt

#include <iostream>
#include <cmath>

#include "vector_t.hpp"
#include "sparse_vector_t.hpp"


using namespace std;

int main()
{
  vector_t<double> v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  cout << "v1= " << v1;
  cout << "v2= " << v2;
  cout << "v3= " << v3;
  cout << endl;
  
  sparse_vector_t sv1(v1), sv2(v2), sv3(v3);
  cout << "sv1= " << sv1;
  cout << "sv2= " << sv2;
  cout << "sv3= " << sv3;
  cout << endl;
  
  cout << "sv3 * v1= " << sv3.scal_prod(v1) << endl;
  cout << "sv3 * sv2= " << sv3.scal_prod(sv2) << endl;
  cout << "Indice del primer valor coincidente= " << sv3.search_vels(0) << endl;
  
  return 0;
}