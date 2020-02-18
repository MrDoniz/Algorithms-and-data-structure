// AUTOR: Daniel Dóniz García
// FECHA: 17 feb 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdlib.h> //exit

# define EPSILON 1e-6

using namespace std;

class rational_t {
  public:
    //Constructor por defecto.
    rational_t(const int = 0, const int = 1);
    //Destructor.
    ~rational_t();
    
    //Methods
    
    //Getters.
    int getNum() const;
    int getDen() const;
    //Setters.
    void set_num(const int);
    void set_den(const int);
    
    double value(void) const;

    // FASE II
    bool isEqual(const rational_t&, const double precision = EPSILON) const;
    bool isGreater(const rational_t&, const double precision = EPSILON) const;
    bool isLess(const rational_t&, const double precision = EPSILON) const;
    bool isEqualZero(const rational_t&, const double precision = EPSILON) const;

    // FASE III
    double add(const rational_t&) const;
    double substract(const rational_t&) const;
    double multiply(const rational_t&) const;
    double divide(const rational_t&) const;
    
    
    void write(ostream& = cout) const;
    void read(istream& = cin);
    
  private:
    int num_;
    int den_;
};