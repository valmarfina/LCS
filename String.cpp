#include <iostream>

#include "String.h"
#include "exceptions.h"
#include "cstring"

//конструктор без параметров (пустая строка, длина = 0)
String::String():
  length_(0),
  ourString_(nullptr) {}

//конструктор, принимающий в качестве параметра размер строки (пустая строка указанного размера)
String::String(int newLength)
{
  length_ = newLength;
  ourString_ = new char[newLength + 1];
  ourString_[newLength] = '\0';
}

//конструктор, принимающий в качестве параметра указатель на массив символов (строка с символами)
String::String(const char *newString)
{
  length_ = strlen(newString);
  ourString_ = new char[length_ + 1];

  for (int i = 0; i < length_; i++)
  {
    ourString_[i] = newString[i];
  }
  ourString_[length_] = '\0';
}

//конструктор копирования
String::String(const String &otherString)
{
  if (this != &otherString)
  {
    this->length_ = strlen(otherString.ourString_);
    this->ourString_ = new char[this->length_ + 1];

    for (int i = 0; i < this->length_; i++)
    {
      this->ourString_[i] = otherString.ourString_[i];
    }
    this->ourString_[this->length_] = '\0';
  }
}

//деструктор
String::~String()
{
  delete[] ourString_;
  length_ = 0;
}

//возвращает длину строки
int String::getLength() const
{
  return length_;
}

//возвращает указатель на массив символов
char *String::getOurString() const
{
  return ourString_;
}

//оператор индекса: возвращает символ с указанным индексом
char &String::operator[](int index) const
{
  //проверка того, что индекс больше или равен нулю и меньше длины строки
  if ((index < 0) || (index >= length_))
  {
    throw IndexOutOfRangeException();
  }
  return ourString_[index];
}

//оператор присваивания копированием
String &String::operator=(const String &otherString)
{
  if (this == &otherString)
  {
    return *this;
  }
  String temp(otherString);
  std::swap(*this, temp);
  return *this;
}

//оператор сравнения строк
bool const String::operator==(const String &otherString) const
{
  if (this->length_ != otherString.length_)
  {
    return false;
  }
  for (int i = 0; i < this->length_; i++)
  {
    if (this->ourString_[i] != otherString.ourString_[i])
    {
      return false;
    }
  }
  return true;
}

//добавляет символ в конец строки и увеличивает ее размер
void String::pushBack(const char &newElement)
{
  String temporaryString(this->length_);
  for (int i = 0; i < this->length_; i++)
  {
    temporaryString.ourString_[i] = this->ourString_[i];
  }
  delete[] this->ourString_;

  this->length_ = temporaryString.length_ + 1;
  this->ourString_ = new char[this->length_ + 1];

  for (int i = 0; i < temporaryString.length_; i++)
  {
    this->ourString_[i] = temporaryString.ourString_[i];
  }
  this->ourString_[this->length_ - 1] = newElement;
  this->ourString_[this->length_] = '\0';

}

//переставляет элементы массива в обратном порядке
void String::reverse()
{
  String temporaryString;
  for (int i = this->length_ - 1; i >= 0; i--)
  {
    temporaryString.pushBack(this->ourString_[i]);
  }

  for (int i = 0; i < this->length_; i++)
  {
    this->ourString_[i] = temporaryString.ourString_[i];
  }
}

//Дружественная функция: оператор вывода строки
std::ostream &operator<<(std::ostream &out, const String &string)
{
  for (int i = 0; i < string.length_; i++)
  {
    out << string.ourString_[i];
  }
  return out;
}

//Дружественная функция: оператор ввода строки в string
std::istream &operator>>(std::istream &in, String &string)
{
  char symbol = '0';
  while ((symbol != '\n'))
  {
    in.get(symbol);

    //случай, когда строка пуста
    if ((symbol == '\n') && (string.getLength() == 0))
    {
      throw FileWithEmptyStringException();
    }

    char *tempString = new char[string.length_ + 1];

    for (int i = 0; i < string.length_; i++)
    {
      tempString[i] = string.ourString_[i];
    }
    tempString[string.length_] = symbol;
    delete[] string.ourString_;

    string.length_++;
    string.ourString_ = new char[string.length_ + 1];
    for (int i = 0; i < string.length_; i++)
    {
      string.ourString_[i] = tempString[i];
    }
    delete[] tempString;

    string.ourString_[string.length_] = '\0';
  };
  return in;
}
