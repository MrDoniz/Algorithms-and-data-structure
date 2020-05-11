// AUTOR: Enrique Álvarez Mesa	
// FECHA: 6/05/2020
// EMAIL: alu0101142104@ull.edu.es
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
  rpn_t(void);		// Constructor
  ~rpn_t();				// Destructor

  const int evaluate(queue_l_t<char>&);		// Recibe una cola de caracteres

private: 
  T stack_;
	void operate_(const char operador);
};



template<class T>		// Constructor
rpn_t<T>::rpn_t():
stack_()
{}



template<class T>		// Destructor
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

		if (isdigit(c))		// Para saber si es un número o un caracter
		{
		  int i = c - '0';
		  stack_.push(i);
		  cout << " (es un dígito) " << endl << "   Lo metemos en la pila..." << endl;
    }
		else {
		  cout << " (es un operador)" << endl;
		  operate_(c);
		}
	}
  
  int x = stack_.top();		// Guardo el resultado de la pila en x
	stack_.pop();					  // Elimino el valor almacenado en la pila 
	return x;		            // Retorno el valor de la operación
}



template<class T>
void
rpn_t<T>::operate_(const char c)
{
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'l' || c == 'r' || c == 'c');
  int a, b, z;
  
  b = stack_.top();
  stack_.pop();
  cout << "   Sacamos de la pila un operando: " << b <<endl;
  
  if (c != 'l' && 'r' && 'c')		// Para los operadores de aridad dos
	{
    a = stack_.top();
    stack_.pop();
    cout << "   Sacamos de la pila otro operando: " << a  <<endl;
  }
  
	switch (c)
	{
	  case '+': z = a + b;
							break;
    case '-': z = a - b;
      				break;
    case '*': z = a * b;
      				break;
    case '/': z = a / b;
      				break;
	  case '^': z = pow(a, b);
      				break;
		case 'r': z = sqrt(b);
							break;
    case 'l': z = log2(b);
      				break;
    case 'c': z = pow(b, 2);
      				break;
	}

  stack_.push(z);
	cout << "   Metemos en la pila el resultado: " << z <<endl;
}

}