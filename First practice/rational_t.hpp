// AUTOR: Daniel Dóniz García
// FECHA: 17 feb 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 5.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdlib.h> //Librería necesaria para usar la función exit, utilizada en la indeterminación.

# define EPSILON 1e-6

using namespace std;

class rational_t {
  public:
    //Methods
    
    //Constructor por defecto.
    rational_t(const int = 0, const int = 1);
    //Destructor.
    ~rational_t();
    
    //Getters.
    int getNum() const;
    int getDen() const;
    //Setters.
    void setNum(const int);
    void setDen(const int);
    
    double value(void) const;

    // FASE II
    bool isEqual(const rational_t&, const double precision = EPSILON) const;
    bool isGreater(const rational_t&, const double precision = EPSILON) const;
    bool isLess(const rational_t&, const double precision = EPSILON) const;
    bool isEqualZero(const rational_t&, const double precision = EPSILON) const;

    // FASE III
    rational_t add(const rational_t&);
    rational_t substract(const rational_t&);
    rational_t multiply(const rational_t&);
    rational_t divide(const rational_t&);
    
    
    void write(ostream& = cout) const;
    void read(istream& = cin);
    
  private:
    //Attributes
    int num_;
    int den_;
};