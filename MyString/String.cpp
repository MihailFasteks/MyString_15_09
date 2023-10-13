//
//  String.cpp
//  MyString
//
//  Created by Michalis on 12.10.2023.
//

#include "String.hpp"
#include <iostream>
using namespace std;
 unsigned int MyString::count=0;
MyString::MyString()
{
    lenght=80;
    str=new char[lenght];
    count++;
}
MyString::MyString(const char* s)
{
    lenght = (int)strlen(s) + 1;
        str = new char[lenght];
        strcpy(str, s);
    count++;
}
MyString::~MyString()
{
    delete[]str;
    count--;
}

MyString::MyString(const MyString& obj) {
    str = new char[strlen(obj.str) + 1];
    strcpy(str, obj.str);

    lenght = obj.lenght;
    count++;
}
   void MyString::MyStrcpy(MyString & obj)
{
       str = new char[strlen(obj.str) + 1];
           strcpy(str, obj.str);

           lenght = obj.lenght;
   }
   bool MyString::MyStrStr(const char * str)
{
       int i = 0, j = 0;

           while (this->str[i] != '\0') 
           {
               if (this->str[i] == str[j])
               {
                   while (this->str[i] == str[j])
                   {
                       i++;
                       j++;
                   }

                   if (str[j] == '\0')
                   {
                       return true;
                   }
                       
               }
               else
               {
                   i++;
               }
           }

           return false;
   }
   int MyString:: MyChr(char c)
{
       for (int i = 0; i < strlen(str) + 1; i++)
               if (str[i] == c)
                   return i;
           return -1;
       }
   
   int MyString::MyStrLen()
{
       return (int)strlen(str);
   }
  void MyString::MyStrCat(MyString& b)
{
      int newLenght = (int)strlen(str) + (int)strlen(b.str);
          char* newStr = new char[newLenght + 1];

          strcpy(newStr, str);

          for (int i = (int)strlen(str), j = 0; i < newLenght; i++)
              newStr[i] = b.str[j++];

          newStr[newLenght] = '\0';

          lenght = newLenght;
          str = newStr;
  }
    void MyString::MyDelChr(char c)
{
        char* NewStr = new char[strlen(str)+1];
            
            for (int i = 0, j = 0; i < strlen(str) + 1; i++)
                if (str[i] != c)
                    NewStr[j++] = str[i];


            lenght = (int)strlen(str);
            str = NewStr;
    }
    int MyString::MyStrCmp(MyString &b)
{
        if (strlen(str) < strlen(b.str))
                return -1;
            else if (strlen(str) > strlen(b.str))
                return 1;
            else
                return 0;
    }

void MyString::Input() 
{
    char buff[100];
    
    cout << "> ";
    cin.getline(buff, sizeof(buff));

    str = new char[strlen(buff) + 1];
    strcpy(str, buff);
}
void MyString::Print() const 
{
    cout << str;
}
void MyString::SetStr(const char* st)
{
    str = new char[strlen(st) + 1];
    strcpy(str, st);
}
void MyString::SetLength(int size) 
{
    if (size < 0) {
        cout << "Число должно быть больше 0" << endl;
        return;
    }
        
    lenght = size;
}

// Геттер
char* MyString::GetStr() const 
{
    return str;
}
int MyString::GetLength() const 
{
    return lenght;
}

char& MyString::operator[](const unsigned int index)
{
    if (index >= 0 && index < lenght - 1)
        return str[index];
    return str[0];
}

// Перегрузка оператора вызова ()
void MyString::operator()(const char* input) 
{
    lenght = (int)strlen(input) + 1;
    str = new char[lenght];
    strcpy(str, input);
}

// Перегрузка ввода-вывода
ostream& operator<<(ostream& os, const MyString& obj) {
    os << obj.GetStr() << endl;

    return os;
}
istream& operator>>(istream& is, MyString& obj) 
{
    cout << "istream& operator>>(istream& is, MyString& obj)" << endl;

    char buff[100];

    cin.getline(buff, strlen(buff) + 1);

    obj.SetStr(buff);

    return is;
}

// obj + char (перегрузка оператора +)
MyString operator+(const MyString obj1, const char obj2) 
{
    int newLenght = (int)strlen(obj1.GetStr()) + 2;
    char* newStr = new char[newLenght];

    strcpy(newStr, obj1.GetStr());

    newStr[newLenght - 2] = obj2;
    newStr[newLenght - 1] = '\0';

    return MyString (newStr);
}
// char + obj (перегрузка оператора +)
MyString operator+(const char obj2, const MyString obj1) 
{
    int newLenght = (int)strlen(obj1.GetStr()) + 2;
    char* newStr = new char[newLenght];

    strcpy(newStr, obj1.GetStr());

    newStr[newLenght - 2] = obj2;
    newStr[newLenght - 1] = '\0';

    return MyString(newStr);
}
// obj + int (перегрузка оператора +)
MyString operator+(const MyString obj1, const int quantity) {
    int newLenght = (int)strlen(obj1.GetStr()) + quantity + 1;
    char* newStr = new char[newLenght];

    strcpy(newStr, obj1.GetStr());

    for (int i = (int)strlen(obj1.GetStr()); i < newLenght - 1; i++)
        newStr[i] = 'a';

    newStr[newLenght - 1] = '\0';

    return MyString(newStr);
}
// int + obj (перегрузка оператора +)
MyString operator+(const int quantity, const MyString obj1)
{
    int newLenght = (int)strlen(obj1.GetStr()) + quantity + 1;
    char* newStr = new char[newLenght];

    strcpy(newStr, obj1.GetStr());

    for (int i = (int)strlen(obj1.GetStr()); i < newLenght - 1; i++)
        newStr[i] = 'a';
        
    newStr[newLenght - 1] = '\0';

    return MyString(newStr);
}
// obj++
MyString operator++(MyString& obj, int) 
{
    MyString temp(obj);

    int newLenght = (int)strlen(obj.GetStr()) + 2;
    char* newStr = new char[newLenght];

    strcpy(newStr, obj.GetStr());

    newStr[newLenght - 2] = 'b';
    newStr[newLenght - 1] = '\0';

    obj.SetStr(newStr);
    obj.SetLength(newLenght);

    return temp;
}
// ++obj
MyString& operator++(MyString& obj) 
{
    int newLenght = (int)strlen(obj.GetStr()) + 2;
    char* newStr = new char[newLenght];

    for (int i = 1; i < newLenght - 1; i++)
        newStr[i] = obj.GetStr()[i - 1];

    // strcpy_s(newStr, newLenght - 1, obj.GetStr());

    newStr[0] = 'b';
    newStr[newLenght - 1] = '\0';

    obj.SetStr(newStr);
    obj.SetLength(newLenght);

    return obj;
}
MyString& MyString::operator=(const MyString& right) {
    if (this != &right) {
        delete[] str; 

        str = new char[right.lenght];
        lenght = right.lenght;

        for (int i = 0; i < lenght; ++i)
            str[i] = right.str[i];
    }

    return *this;
}
MyString::MyString(MyString&&)
{
    
}
MyString& MyString::operator=(MyString&& obj)
{
    cout << "Move = \n";

            str = obj.str;
            obj.str = nullptr;

            lenght = obj.lenght;
            obj.lenght = 0;

            return *this;
}
