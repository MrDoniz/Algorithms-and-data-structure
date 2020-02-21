#include "rational_t.hpp"
#include <cmath>
//Constructor
rational_t::rational_t(const int n, const int d)
{ assert(d != 0);
  num_ = n, den_ = d;
}
//Funcion value que te devuelve el valor del numero racional
double rational_t::value() const
{ return double(get_num()) / get_den();
}
//Funcion que te da el opusto del racional
rational_t rational_t::opposite() const
{ return rational_t((-1)*get_num(), get_den());
}
//Funcion reciproca de rational
rational_t rational_t::reciprocal() const
{ return rational_t(get_den(), get_num());
}

//FASE II
//Funcion que te dice si a y b son iguales
bool rational_t::equal(const rational_t& r,const double precision) const
  {
    return(fabs(value()-r.value()) < precision);
}
//Funcion que te dice si a es mayor que b
bool rational_t::greater(const rational_t& r, const double precision) const
 {
   return(fabs(value()-r.value())>precision);
     cout<<value()<<" es mayor que "<<r.value()<<endl;
 }
//Funcion que te dice si a es menor que b
bool rational_t::less(const rational_t& r, const double precision) const
 {
   return(fabs(r.value()-value()) > precision);
 }
//FASE III
//Suma
 rational_t rational_t::add(const rational_t& r)
 {
   rational_t suma((get_num()*r.get_den() + r.get_num()*get_den()),(get_den()*r.get_den()));
   return(suma);
 }
//Resta
rational_t rational_t::substract(const rational_t& r)
 {
   return add(r.opposite());
 }
//Multiplicación
 rational_t rational_t::multiply(const rational_t& r)
 {
  rational_t mult(get_num()*r.get_num(),get_den()*r.get_den());
  return(mult);
 }
//División
 rational_t rational_t::divide(const rational_t& r)
 {
   return multiply(r.reciprocal());
 }
//Modificiacion
bool rational_t::numeropar(void){
return(get_den()%2 == 0);
  }

void rational_t::write(ostream& os) const
{ os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream& is)
{ cout << "Numerador: ";
  is >> num_;
  cout << "Denominador: ";
  is >> den_;
  assert(den_ != 0);
}
