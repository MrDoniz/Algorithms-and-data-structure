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

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"
#include "pair_t.hpp"

using namespace std;


typedef vector_t<pair_t<double>> pair_vector_t;

class sparse_vector_t
{
public:
  sparse_vector_t(const vector_t<double>&); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia
  
  sparse_vector_t& operator=(const sparse_vector_t&); // operador de asignación

  ~sparse_vector_t();
  
  // getters
   int get_nz(void) const;
   int get_n(void) const;
   
   // operaciones
   double scal_prod(const vector_t<double>&);
   double scal_prod(const sparse_vector_t&);
   
   int search_vels(const double a);
   
   // E/S
   void write(ostream& = cout) const;

private:
  pair_vector_t pv_; // valores + índices
  int     nz_;       // nº de valores distintos de cero = tamaño del vector
  int     n_;        // tamaño del vector original
  
  bool is_not_zero(double, double = 1e-6) const;
};



// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v):
pv_(), nz_(0), n_(v.get_size()){
  for (int i = 0; i < v.get_size(); ++i)
    if (is_not_zero(v[i]))
      ++nz_;
    
  pv_.resize(nz_);
  nz_=0;
  
  for (int i = 0; i < v.get_size(); ++i)
    if (is_not_zero(v[i])){
      pv_[nz_].set(v[i], i);
      ++nz_;
    }
}


// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w)
{
  *this = w; // invocamos directamente al operator=
}



// operador de asignación
sparse_vector_t&
sparse_vector_t::operator=(const sparse_vector_t& w)
{
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}



sparse_vector_t::~sparse_vector_t()
{}



inline int
sparse_vector_t::get_nz() const
{
  return nz_;
}



inline int
sparse_vector_t::get_n() const
{
  return n_;
}



void
sparse_vector_t::write(ostream& os) const
{ 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << endl;
}



ostream&
operator<<(ostream& os, const sparse_vector_t& sv)
{
  sv.write(os);
  return os;
}



bool
sparse_vector_t::is_not_zero(double v, double eps) const
{
  return fabs(v) > eps;
}



// operaciones
// FASE III
double
sparse_vector_t::scal_prod(const vector_t<double>& v)
{
  double s = 0, value = 0, value1 = 0;
  assert (v.get_size() == get_n());
  for (int i = 0; i < get_nz(); ++i){
    value  = v.get_val(pv_[i].get_inx());  //Obtener valor de vector_t
    value1 = pv_[i].get_val();             //Obtener valor de sparse_vector_t
    if (value != 0)
      s = s + (value * value1);
  }
  return s;
}



/// FASE IV
double
sparse_vector_t::scal_prod(const sparse_vector_t& sv)
{
  double s = 0;
  assert (sv.get_n() == get_n());
  for (int i = 0; i < get_nz(); ++i)
    for (int j = 0; j < sv.get_nz(); ++j)
      if (pv_[i].get_inx() == sv.pv_[j].get_inx())
        s = s + (pv_[i].get_val() * sv.pv_[j].get_val());
  return s;
}



//Método
#define EPS 1e-6
bool is_equal(const double a, const double b, const double epsilon = EPS)
{
  return (fabs(a - b) < epsilon);
}



int sparse_vector_t::search_vels(const double a){
  int value = -1;
  for(int i = 0; i < get_nz(); ++i)
    if(is_equal(a, pv_[i].get_val()))
      value = pv_[i].get_inx();
  return value;
}