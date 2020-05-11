// AUTOR: Daniel Dóniz García
// FECHA: 2 abr 2020
// EMAIL: alu0101217277@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase que implementa la clase RPN (Reverse Polish Notation)

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>
#include "queue_l_t.hpp"

using namespace std;

namespace AED {

template <class T>
class rpn_t
{
public:
  rpn_t(void);
  ~rpn_t();

  const int evaluate(queue_l_t<char>&);

private: 
  T stack_;
	void operate_(const char operador);
};



template<class T>
rpn_t<T>::rpn_t():
stack_()
{}



template<class T>
rpn_t<T>::~rpn_t()
{}



template<class T>
const int 
rpn_t<T>::evaluate(queue_l_t<char>& q)
{
	while (!q.empty())
	{
    char c = q.front();
    q.pop();
    cout << "Sacamos de la cola un carácter: " << c;

		if (isdigit(c))
		{
		  int i = c - '0';    //Normalizar a código ascii la i
		  stack_.push(i);
		  cout << " (es un dígito) " << endl << "   Lo metemos en la pila..." << endl;
    }
		else {
		  cout << " (es un operador)" << endl;
      //Si lee un operador, llama al método "operate_" para realizar la operación
		  operate_(c);
		}
	}
  //Recoge el resultado introducido previamente en la pila.
  int p = stack_.top();
  //Elimina de la pila el resultado recogido.
	stack_.pop();
  return p;
  
}



template<class T>
void
rpn_t<T>::operate_(const char c)
{
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'l' || c == 'r' || c == 'c' || c == '<');
  int a, b, r;
  
  //Recoge el operador introducido previamente en la pila.
  b = stack_.top();
  //Elimina de la pila el operador recogido.
  stack_.pop();
  cout << "   Sacamos de la pila un operando: " << b <<endl;
  
  //Si el operador necesita 2 operandos.
  if (c != 'l' && c != 'r' && c != 'c'){
    //Recoge el segundo operador introducido previamente en la pila.
    a = stack_.top();
    //Elimina de la pila el operador recogido.
    stack_.pop();
    cout << "   Sacamos de la pila otro operando: " << a  <<endl;
  }
	switch (c)
	{
	  case '+':
      r = a + b;
      break;
    case '-':
      r = a - b;
      break;
    case '*':
      r = a * b;
      break;
    case '/':
      r = a / b;
      break;
	  case '^':
      r = pow(a, b);
      break;
    case 'l':
      r = log2(b);
      break;
    case 'r':
      r = sqrt(b);
      break;
    case 'c':
      r = pow(b, 2);
      break;
    case '<':
      r = a < b;
      if (r == true)
        r = a;
      else
        r = b;
      break;
	}
  stack_.push(r);
	cout << "   Metemos en la pila el resultado: " << r <<endl;
}
}