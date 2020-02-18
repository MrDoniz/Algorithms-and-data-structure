// AUTOR: Daniel Dóniz García
// FECHA: 17 feb 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

class rational_t {
  public:
    //Constructor por defecto.
    rational_t(const int = 0, const int = 1);
    //Destructor.
    ~rational_t() {}
    
    //Getters.
    int get_num() const;
    int get_den() const;
    //Setters.
    void set_num(const int);
    void set_den(const int);
    
    //Metodo
    double value(void) const;

    // FASE II
    bool is_equal(const rational_t&, const double precision = EPSILON) const;
    bool is_greater(const rational_t&, const double precision = EPSILON) const;
    bool is_less(const rational_t&, const double precision = EPSILON) const;
    bool is_equal_zero(const rational_t&, const double precision = EPSILON) const;

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