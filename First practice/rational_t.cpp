// AUTOR: Daniel Dóniz García
// FECHA: 17 feb 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 5.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1

#include "rational_t.hpp"

// Crear el constructor por defecto rational_t.
rational_t::rational_t(const int n, const int d){
  //assert(d != 0);
  num_ = n, den_ = d;
}



//El destructor ~rational_t. Vacío porque no usamos la memoria dinámica.
rational_t::~rational_t(){}



int rational_t::getNum() const{
  return num_;
}



int rational_t::getDen() const{
  return den_;
}


  
void rational_t::setNum(const int n){
  num_ = n;
}



void rational_t::setDen(const int d){
  assert(d != 0);
  den_ = d;
}


//Devuelve el valor de la fracción.
double rational_t::value() const{ 
  return double(getNum()) / getDen(); //Type cast.
}



bool rational_t::isEqual(const rational_t& r, const double precision) const{ 
  if (fabs(value() - r.value()) < precision) 
    return true;
  else 
    return false;
}



bool rational_t::isGreater(const rational_t& r, const double precision) const{ 
  if ((value() - r.value()) > precision) 
    return true;
  else 
    return false;
}



bool rational_t::isLess(const rational_t& r, const double precision) const{ 
  if ((r.value() - value()) < precision) 
    return true;
  else 
    return false;
}



bool rational_t::isEqualZero(const rational_t& r, const double precision) const{ 
  if (fabs(value()) < precision) 
    return true;
  else 
    return false;
}



//Operaciones
rational_t rational_t::add(const rational_t& r){
  rational_t add((getNum()*r.getDen() + r.getNum()*getDen()),(getDen()*r.getDen()));
  return(add);
}



rational_t rational_t::substract(const rational_t& r){
  rational_t substract((getNum()*r.getDen() - r.getNum()*getDen()),(getDen()*r.getDen()));
  return(substract);
}



rational_t rational_t::multiply(const rational_t& r){
  rational_t multiply(getNum()*r.getNum(),getDen()*r.getDen());
  return(multiply);
}



rational_t rational_t::divide(const rational_t& r){
  rational_t divide(getNum()*r.getDen(),getDen()*r.getNum());
  return(divide);
}



// E/S
// Imprime la fracción y el resultado.
void rational_t::write(ostream& os) const{
  os << getNum() << "/" << getDen() << "=" << value() << endl;
}



void rational_t::read(istream& is){
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  if(den_ == 0){
    cout << "Indeterminacion" << endl;
    exit (EXIT_FAILURE);
  }
  //assert(den_ != 0);
}