//
//  String.hpp
//  MyString
//
//  Created by Michalis on 12.10.2023.
//


#pragma once
#include <iostream>
using namespace std;
class MyString
{
    char* str;
   unsigned int lenght;
public:
    static unsigned int count;
    MyString();
    MyString(const char* s);
    ~MyString();
    
    void MyStrcpy(MyString & obj);// копирование строк
    bool MyStrStr(const char * str);// поиск подстроки в строке
    int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
    int MyStrLen();// возвращает длину строки
    void MyStrCat(MyString& b); // объединение строк
    void MyDelChr(char c); // удаляет указанный символ
    int MyStrCmp(MyString &b); // сравнение строк
    void Input();
    void Print() const;
    MyString(const MyString& obj);
    void SetStr(const char*);
    void SetLength(int );
    char* GetStr() const;
    int GetLength() const;
    char& operator[](const unsigned int);
        void operator()(const char*);

};
ostream& operator<<(ostream&, const MyString&);
istream& operator>>(istream&, MyString&);

MyString operator+(const MyString, const char);
MyString operator+(const char, const MyString);
MyString operator+(const int, const MyString);
MyString operator+(const MyString, const int);
MyString operator++(MyString& obj, int);
MyString& operator++(MyString& obj);
