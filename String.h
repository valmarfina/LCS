#ifndef RGR_MARFINA_STRING_H
#define RGR_MARFINA_STRING_H

#include<iostream>

class String
{
public:
  //конструктор без параметров (всего: пустая строка, длина которой равна 0)
  String();
  //конструктор, принимающий в качестве параметра размер строки (итого: пустая строка указанного размера)
  String(int newLength);
  //конструктор, принимающий в качестве параметра указатель на массив символов (итого: строка с символами)
  String(const char *newString);
  //констуктор копирования
  String(const String &otherString);
  //destructor
  ~String();

  //возвращает длину строки
  int getLength() const;
  //возвращает указатель на массив символов
  char *getOurString() const;

  //оператор индекса: возвращает символ с указанным индексом
  char &operator[](int index) const;
  //оператор присваивания
  String &operator=(const String &otherString);
  //оператор сравнения строк
  bool const operator==(const String &otherString) const;
  //добавляет символ в конец строки и увеличивает ее размер (используется в функции поиска LCS)
  void pushBack(const char &newElement);
  //переставляет элементы массива в обратном порядке (используется в функции поиска LCS)
  void reverse();

  //Дружественная функция: оператор вывода строки
  friend std::ostream &operator<<(std::ostream &out, const String &string);
  //Дружественная функция: оператор ввода строки
  friend std::istream &operator>>(std::istream &in, String &string);

private:
  //длина строки
  int length_;
  //указатель строки
  char *ourString_;
};

#endif //RGR_MARFINA_STRING_H
