#include "exceptions.h"

// базовый класс исключений
Exception::Exception(const char *message):
  message_(message) {}

//возвращает сообщение об ошибке
String Exception::getMessage() const
{
  return message_;
}

//производный класс исключения (открыт файл для чтения)
FileIsNotOpenException::FileIsNotOpenException():
  Exception("ERROR! FILE NOT OPENED FOR READING") {}

//производный класс исключения (содержит ли файл для чтения пустые строки)
FileWithEmptyStringException::FileWithEmptyStringException():
  Exception("ERROR! THE FILE TO READ CONTAINS AN EMPTY LINE.") {}

//производный класс исключения (выходит ли индекс за пределы диапазона)
IndexOutOfRangeException::IndexOutOfRangeException():
  Exception("ERROR! INDEX OUT OF RANGE. ") {}

