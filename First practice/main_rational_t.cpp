
#include <iostream>
#include <cmath>
#include "rational_t.hpp"
#include <stdlib.h>
//Declarar el espacio de trabajo
using namespace std;

// FASE III: función de búsqueda
bool search(const rational_t* v, const int n, const rational_t& x)
{
  bool busqueda = false;
    for(int i=0;(i<n)&&(busqueda!=true);i++){
      busqueda = v[i].equal(x);
      }
    return busqueda;
}
//Funcion principal
int main()
{ rational_t a(1, 2), b(3), c;
  int opcion;
  int op1, op2;
  do{
    cout<<"Practica 1: Numeros Racionales"<<endl;
    cout <<"-------------------------------------"<<endl;
    //Menu principal
    cout<<"-------------------/ Menu /-------------"<<endl;
    cout << "0. Si desea salir"<< endl;
    cout << "1. Si quieres visualizar los valores"<< endl;
    cout << "2. Si quiere entrar al menu de comparaciones "<<endl;
    cout << "3. Si desea buscar un numero racional en el vector"<<endl;
    cout << "4. Si desea hacer una operaciones basicas entre fraccionarios."<<endl ;
    cout << "6. Si desea hacer el reciproco de un fraccionarios."<<endl ;
    cout<<"--------------------------------------------------------------"<<endl;
    cout << "Introduzca la opcion que quiera realizar -> ";
    cin >> opcion;
    cout<<"---------------------------------------------------------"<<endl;

    //Implementacion del Menu
	   switch (opcion){
       case 1: system("clear");
          cout<<"Los numeros racionales son:"<<endl;
          cout << "a: ";
          a.write();
          cout << "b: ";
          b.write();
          cout <<"Por favor, introduzca un numero racional:"<<endl;
          c.read();
          cout << "c: ";
          c.write();
       break;

       case 2:
       system("clear");
       do{
         //Menu secundario.
         cout<<"-------------------/ Menu de Comparaciones /-------------"<<endl;
         cout << "0. Si desea regresar al menu principal"<< endl;
         cout << "1. Si quieres igualar dos numeros fraccionarios"<< endl;
         cout << "2. Si quieres ver si uno es mayor que el otro"<< endl;
         cout << "3. Si quieres ver si uno es menor que el otro"<< endl;
         cout<<"---------------------------------------------------------"<<endl;
         cout << "Introduzca la opcion que quiera realizar -> ";
         cin >> op2;
         cout<<"---------------------------------------------------------"<<endl;
         switch(op2){
           //Comparacion si es igual a que b
           case 1:
           if(a.equal(b)){
             cout<< a.value()<<" y "<<b.value()<<" Son iguales"<<endl;
           }
           else
             cout<<a.value()<<" y "<<b.value()<<" NO son iguales"<<endl;
           break;
           //comparacion si a es mayor o igual que b
           case 2:
             system("clear");
             if(a.greater(b)){
               cout<<a.value()<<" Es mayor que " <<b.value()<<endl;
             }
             else{
               cout<<a.value()<<" No es mayor que " <<b.value()<<endl;
             }
           break;
           //comparacion si a es menor que b
           case 3:
             system("clear");
             if(a.less(b)){
               cout <<a.value()<<" es menor que " <<b.value()<<endl;
             }
             else{
               cout<<a.value()<<" no es menor que " <<b.value()<<endl;
             }
           break;
           //Si el usuario presiona otro boton
           default: cout << "Opcion no valida, por favor introduzca una opcion de la lista" <<endl;
           break;

         }
       }
       while (op2 != 0);
        system("clear");

        break;
      // FASE III
        case 3:
        {
          system("clear");
          int n;
          cout << "Introduce n: ";
          cin >> n;
          rational_t *v = new rational_t[n];
          if (v != NULL) {
            for (int i = 0; i < n; i++) {
              v[i] = rational_t(1, pow(2, i));
              v[i].write();
            }

            rational_t x(1, pow(2, 3));
            bool b = search(v, n, x);
            cout << "Valor " << x.value() << (b ? "" : "no") << " encontrado" << endl;
            cout <<"--------------------------------------------------------------"<<endl;
            delete[] v;
          }
          else {
            cerr << "ERROR: no se ha podido reservar memoria dinámica" << endl;
            return 1;
          }
        }
        break;
        // FASE IV
        case 4:
        system("clear");
        do{
          //Menu secundario.
          cout<<"------------------- Operaciones basicas -------------"<<endl;
          cout << "0. Si desea regresar al menu principal"<< endl;
          cout << "1. Si quieres sumar numeros fraccionarios"<< endl;
          cout << "2. Si quieres restar numeros fraccionarios"<< endl;
          cout << "3. Si quieres multiplicar numeros fraccionarios"<< endl;
          cout << "4. Si quieres dividir numeros fraccionarios"<< endl;
          cout<<"---------------------------------------------------------"<<endl;
          cout << "Introduzca la opcion que quiera realizar -> ";
          cin >> op1;
          cout<<"---------------------------------------------------------"<<endl;
          switch(op1){
            //Suma
            case 1:
              system("clear");
              cout << "a + b: ";
              a.add(b).write();
              return 0;
            break;
            //resta
            case 2:
              system("clear");
              cout << "a - b: ";
              a.substract(b).write();
              return 0;
            break;
            //Multiplicacion
            case 3:
              system("clear");
              cout << "a * b: ";
              a.multiply(b).write();
              return 0;
            break;
            //Division
            case 4:
              system("clear");
              cout << "a / b: ";
              a.divide(b).write();
              return 0;
            break;
            //casi de que presione otro boton
        	   default: cout << "Opcion no valida, por favor introduzca una opcion nueva" <<endl;
             break;
          }
        }
        while (op1 != 0);
         system("clear");

      break;
      //Opuesto de a
      case 5:
         system("clear");
         cout << "Opuesto de a: ";
         a.opposite().write();
      break;
      //Reciproco de B
      case 6:
         system("clear");
         cout << "Recíproco de b: ";
         b.reciprocal().write();
     break;

     break;
     //modificacion (Es par?)
     case 7:
      system("clear");
     if(a.numeropar()){
       cout<< a.get_den()<<" es par"<<endl;
     }
     else
       cout<<a.get_den()<<" no es par"<<endl;
     break;


      //caso de que presione otra letra
      default: cout << "Opcion no valida, por favor introduzca una opcion nueva" <<endl;
      break;
  }

}

  while (opcion != 0);
   system("clear");
   cout<<"Por favor espere, saliendo..."<<endl;

/*
  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  cout << "Opuesto de a: ";
  a.opposite().write();
  cout << "Recíproco de b: ";
  b.reciprocal().write();

  // FASE III: ejemplo
   int n;
  cout << "Introduce n: ";
   cin >> n;
  rational_t *v = new rational_t[n];
   if (v != NULL) {
     for (int i = 0; i < n; i++) {
       v[i] = rational_t(1, pow(2, i));
       v[i].write();
     }

     rational_t x(1, pow(2, 3));
     bool b = search(v, n, x);
     cout << "Valor " << x.value() << (b ? "" : "no") << " encontrado" << endl;

     delete[] v;
   }
   else {
     cerr << "ERROR: no se ha podido reservar memoria dinámica" << endl;
     return 1;
   }

  // FASE IV
   cout << "a + b: ";
  a.add(b).write();

  cout << "b - a: ";
   b.substract(a).write();

  cout << "a * b: ";
  a.multiply(b).write();

   cout << "a / b: ";
   a.divide(b).write();

  return 0;*/


}
