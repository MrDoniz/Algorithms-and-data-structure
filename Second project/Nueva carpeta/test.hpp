// Sumar los elementos de un vector
//main.cpp
/*	Z
vector_t<double> z;
  z.read(), z.write();
  
  cout << "Suma de los elementos del vector_t<double>: " << scalProd(z) << endl << endl;
*/
/* 	V
  cout << "Suma de los elementos del vector_t<double>: " << scalProd(v) << endl << endl;
*/

//vector_t.hpp
/*	Z
template<class T> T addVector(const vector_t<T>& z) {
  double addVector = 0;
  for (int i = 0; i < z.getSize(); i++)
    addVector = addVector + v[z]
  return addVector;
}
*/
/*	V
template<class T> T addVector(const vector_t<T>& v) {
  double addVector = 0;
  for (int i = 0; i < v.getSize(); i++)
    addVector = addVector + v[i]
  return addVector;
*/
// es de hacer el operator+ de dos vectores 
//main.cpp
  cout << "Suma de vector_t<double>: " << scalProd(v, w) << endl << endl;
  
  vector_t<rat
//vector_t.hpp
template<class T> T scalProd(const vector_t<T>& v, const vector_t<T>& w) {
  assert (v.getSize() == w.getSize());
  double scalProd = 0;
  for (int i = 0; i < v.getSize(); i++)
    scalProd = scalProd + v[i] + w[i];
  return scalProd;
}

/*
Sumar los elementos de un vector

Hacer el operator+ de dos vectores 

Desarrolla un método de la clase matrix_t que muestre por pantalla su submatriz diagonal inferior. Su cabecera debe ser:

template <class T> void matrix_t<T>::inferior_diagonal(void);


*/