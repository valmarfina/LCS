#ifndef RGR_MARFINA_EXCEPTIONS_H
#define RGR_MARFINA_EXCEPTIONS_H

#include "String.h"

// базовый класс исключений
class Exception
{
public:
  //конструктор, принимающий в качестве параметра указатель на массив символов (итого: строка с символами)
  Exception(const char *message);
  //возвращает сообщение об ошибке
  String getMessage() const;
private:
  //строка сообщения об ошибке
  String message_;
};

//производный класс исключения (открыт файл для чтения)
class FileIsNotOpenException : public Exception
{
public:
  //конструктор без параметров
  FileIsNotOpenException();
};

//производный класс исключения (содержит ли файл для чтения пустые строки)
class FileWithEmptyStringException : public Exception
{
public:
  //конструктор без параметров
  FileWithEmptyStringException();
};

//производный класс исключения (выходит ли индекс за пределы диапазона)
class IndexOutOfRangeException : public Exception
{
public:
  //конструктор без параметров
  IndexOutOfRangeException();
};

#endif //RGR_MARFINA_EXCEPTIONS_H
