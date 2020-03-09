// AUTOR: Daniel Dóniz García
// FECHA: 8 mar 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2

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
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}



bool rational_t::is_greater(const rational_t& r, const double precision) const{
  return (value() - r.value()) > precision;
}



bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);
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
  rational_t c(a.add(b));
  return c;
}



rational_t operator-(const rational_t& a, const rational_t& b) {
  rational_t c(a.substract(b));
  return c;
}



rational_t operator*(const rational_t& a, const rational_t& b) {
  rational_t c(a.multiply(b));
  return c;
}



rational_t operator/(const rational_t& a, const rational_t& b) {
  rational_t c(a.divide(b));
  return c;
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