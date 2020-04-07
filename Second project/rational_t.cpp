// AUTOR: Daniel Dóniz García
// FECHA: 8 mar 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMPILACIÓN: $ clear; g++ -g rational_t.cpp main_p2.cpp -o main_p2
// COMPILACIÓN: $ make
// EJECUCIÓN:   $ ./main_p2 < data.txt
//GUÍA DE ESTILO DE GOOGLE: https://google.github.io/styleguide/cppguide.html

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d){
  assert(d != 0);
  num_ = n, den_ = d;
}



inline int rational_t::getNum() const {
  return num_;
}



inline int rational_t::getDen() const {
  return den_;
}


  
void rational_t::setNum(const int n) {
  num_ = n;
}


  
void rational_t::setDen(const int d) {
  assert(d != 0);
  den_ = d;
}



inline double rational_t::value() const { 
  return double(getNum()) / getDen();
}



rational_t rational_t::opposite() const { 
  return rational_t((-1)*getNum(), getDen());
}



rational_t rational_t::reciprocal() const { 
  return rational_t(getDen(), getNum());
}



// comparaciones
bool rational_t::isEqual(const rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}



bool rational_t::isGreater(const rational_t& r, const double precision) const{
  return (value() - r.value()) > precision;
}



bool rational_t::isLess(const rational_t& r, const double precision) const {
  return r.isGreater(*this, precision);
}


// operaciones
rational_t rational_t::add(const rational_t& r) const {
  return rational_t(getNum() * r.getDen() + getDen() * r.getNum(), getDen() * r.getDen());
}



rational_t rational_t::substract(const rational_t& r) const {
  return add(r.opposite());
}



rational_t rational_t::multiply(const rational_t& r) const {
  return rational_t(getNum() * r.getNum(), getDen() * r.getDen());
}



rational_t rational_t::divide(const rational_t& r) const {
  return multiply(r.reciprocal());
}


// FASE I: operadores
rational_t operator+(const rational_t& a, const rational_t& b) {
  return a.add(b);
}



rational_t operator-(const rational_t& a, const rational_t& b) {
  return b.substract(a);
}



rational_t operator*(const rational_t& a, const rational_t& b) {
  return a.multiply(b);
}



rational_t operator/(const rational_t& a, const rational_t& b) {
  return a.divide(b);
}



// E/S
void rational_t::write(ostream& os) const {
  os << getNum() << "/" << getDen() << "=" << value() << endl;
}



void rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}



ostream& operator<<(ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}


istream& operator>>(istream& is, rational_t& r) {
  r.read(is);
  return is;
}