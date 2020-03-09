// AUTOR: Daniel Dóniz García
// FECHA: 8 mar 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

class rational_t {
	public:
	  rational_t(const int = 0, const int = 1);
	  ~rational_t() {}
	  
	  //Getters
	  int getNum() const;
	  int getDen() const;
	  
	  //Setters
	  void setNum(const int);
	  void setDen(const int);

	  double value(void) const;
	  rational_t opposite(void) const;
	  rational_t reciprocal(void) const;

	  bool isEqual(const rational_t&, const double precision = EPSILON) const;
	  bool isGreater(const rational_t&, const double precision = EPSILON) const;
	  bool isLess(const rational_t&, const double precision = EPSILON) const;

	  rational_t add(const rational_t&) const;
	  rational_t substract(const rational_t&) const;
	  rational_t multiply(const rational_t&) const;
	  rational_t divide(const rational_t&) const;

	  void write(ostream& os = cout) const;
	  void read(istream& is = cin);
	  
	private:
	  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);