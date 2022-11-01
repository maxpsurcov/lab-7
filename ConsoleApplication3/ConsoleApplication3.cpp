// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*У всіх завданнях реалізовані функції або методи повинні генерувати
відповідні виключення. Обробку виключень потрібно виконувати головною
функцією, яка повинна демонструвати обробку всіх перехоплених виключень.
Функції, реалізовані в завданнях, повинні виконувати перевірку переданих
параметрів і генерувати виключення у випадку помилкових. Усі функції
реалізуються в чотирьох варіантах:
• без специфікації виключень;
• зі специфікацією throw();
• с конкретною специфікацією з відповідним стандартним виключенням;
• специфікація із власним реалізованим виключенням.
Власне виключення повинне бути реалізоване в трьох варіантах: як
порожній клас, як незалежний клас із полями-параметрами функції, як
спадкоємець від стандартного виключення з полями. Перехоплення й обробку
виключень повинна виконувати головна функція.*/

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <string>
#include "StructLine.h"
using namespace std;

class MyExcept1 {};

class MyExcept2 {
    string msg;
public:
    MyExcept2(const string& s) : msg(s) {}
    const char* message() const { return msg.c_str(); }
};

class MyExcept3 : public invalid_argument {
    double num;
public:
    MyExcept3(const string msg, double n) : invalid_argument(msg), num(n) {}
    double arg() const { return num; }
};
void root1(int a1, int b1, int a2, int b2) {
    
    float d;
    d = a1 * b2 - a2 * b1;
    if (d != 0) {
        if (a1 == 0 and b1 == 0) {

           
        }
        else {
            cout << "succses. line1 valid" << endl;
        }
        if (a2 == 0 and b2 == 0) {
           
        }
        else {
           
            cout << "succses. line2 valid" << endl;
        }
    }
    else {
        cout << "d = 0" << endl;
    }

   
    
}

void root2(int a1, int b1, int a2, int b2) throw() {
    float d;
    d = a1 * b2 - a2 * b1;
    if (d != 0) {
         if (a1 == 0 and b1 == 0) {
          

        }
        else {
             cout << "succses. line1 valid" << endl;
        }
         if (a2 == 0 and b2 == 0) {
           
        }
        else {

             cout << "succses. line2 valid" << endl;
        }
    }
    else {
        cout << "d = 0" << endl;
    }

   
}

void root3(int a1, int b1, int a2, int b2) throw(invalid_argument) {
  
    float d;
    d = a1 * b2 - a2 * b1;
    if (d != 0) {
        if (a1 == 0 and b1 == 0) {
           
            throw invalid_argument("A and B = 0");
        }
        else {
            
            cout << "succses. line1 valid" << endl;
        }
        if (a2 == 0 and b2 == 0) {
            cout << "succses. line2 valid" << endl;
            throw invalid_argument("A and B = 0");

        }
        else {
            cout << "succses. line2 valid" << endl;
        }
    }
    else {
        throw invalid_argument("d = 0");
    }
  
}

void root4_1(int a1, int b1, int a2, int b2) throw(MyExcept1) {
    
       
   
        float d;
        d = a1 * b2 - a2 * b1;
        if (d != 0) {
            if (a1 == 0 and b1 == 0) {
              
                throw MyExcept1();
            }
            else {
                cout << "succses. line1 valid" << endl;
            }
            if (a2 == 0 and b2 == 0) {
               
                throw MyExcept1();
            }
            else {
                cout << "succses. line2 valid" << endl;

            }
        }
        else {
            throw MyExcept1();
        }
}

void root4_2(int a1, int b1, int a2, int b2) throw(MyExcept2) {
    
       
   
    float d;
    d = a1 * b2 - a2 * b1;
    if (d != 0) {
        if (a1 == 0 and b1 == 0) {
            throw MyExcept2("A and B = 0 in line1");
          
        }
        else {
            cout << "succses. line1 valid" << endl;
        }
        if (a2 == 0 and b2 == 0) {
            throw MyExcept2("A and B = 0 in line2");
        }
        else {
            cout << "succses. line2 valid" << endl;

        }
    }
    else {
        throw MyExcept2("D = 0");
    }
}

void root4_3(int a1, int b1, int a2, int b2) throw(MyExcept3) {
  
    float d;
    d = a1 * b2 - a2 * b1;
    if (d != 0) {
        if (a1 == 0 and b1 == 0) {
          
            throw MyExcept3(" Ошибка в переменных первой прямой которые равняются : ", a1);
        }
        else {
            cout << "succses. line1 valid" << endl;
        }
        if (a2 == 0 and b2 == 0) {
            throw MyExcept3(" Ошибка в переменных второй прямой которые равняются : ", a2);
            
        }
        else {
           
            cout << "succses. line2 valid" << endl;
        }
    }
    else {
        throw MyExcept3(" Ошибка в переменной которая равняется : ", d);
    }
}

void launcher(void (*func)(int, int, int,int)) {
    Ext Line1, Line2;
    Line1.a = 10;
    Line1.b = 5;
    Line1.c = 0;

    Line2.a = 0;
    Line2.b = 4;
    Line2.c = 0;
    
    func(Line1.a, Line1.b, Line2.a, Line2.b);
}
using namespace std;
int main()
{
    int x = 500;
    int y = 0;
    

   cout << "The End..." << endl;
   setlocale(LC_ALL, "rus");
   

   try {
       launcher(root1);
   }
   catch (...) {
       cout << "Произошло исключение в функции root1" << endl;
   }

   try {
       launcher(root2);
   }
   catch (...) {
       cout << "Произошло исключение в функции root2" << endl;
   }

   try {
       launcher(root3);
   }
   catch (invalid_argument& e) {
       cout << e.what() << endl;
   }

   try {
       launcher(root4_1);
   }
   catch (MyExcept1) {
       cout << "Произошло исключение MyExcept1 в функции root4_1" << endl;
   }

   try {
       launcher(root4_2);
   }
   catch (MyExcept2& e) {
       cout << e.message() << endl;
   }

   try {
      launcher(root4_3);
   }
  catch (MyExcept3& e) {
      cout <<  " " << e.arg() << endl;
 }
    return 0;
}


////.17. Функція визначає, чи існують прямі A1x + B1y + C1 = 0 та A2x + B2y +
//C2 = 0 якщо вираз d = A1B2 –A2B1 не дорівнює нулю.Прямі задаються
//структурою із трьома полями
//
