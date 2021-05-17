#include <iostream>
#include "String.h"
#include "functions.h"

//печатает номер пары последовательностей, сами последовательности, вызывает функцию LCS
void serchOfLCS(String const &str1, String const &str2, int number);
std::ofstream out("D:\\study\\POLYTEC\\algoritms\\RGR_Marfina\\out.txt");

int main()
{
  std::ifstream file1("D:\\study\\POLYTEC\\algoritms\\RGR_Marfina\\str1.txt");
  std::ifstream file2("D:\\study\\POLYTEC\\algoritms\\RGR_Marfina\\str2.txt");
  try
  {
    if (!file1)
    {
      throw FileIsNotOpenException();
    }
    if (!file2)
    {
      throw FileIsNotOpenException();
    }
    std::cout << "FILES OPEN!\n";

  }
    //проверка, открыты ли файлы или нет
  catch (FileIsNotOpenException &error)
  {
    std::cout << error.getMessage() << "\n";
    return 0;
  }
  //переменная, в которую записывается номер пары последовательностей
  int number = 0;
  //чтение из файлов
  while (!(file1.eof()) && !(file2.eof()))
  {
    try
    {
      String string1;
      String string2;
      number++;
      file1 >> string1;
      file2 >> string2;
      serchOfLCS(string1, string2, number);
    }
      //проверка наличия или отсутствия пустых строк в файлах
    catch (FileWithEmptyStringException &error)
    {
      out << "-----PAIR OF SEQUENCES № " << number << "-----\n";
      out << error.getMessage() << "\n";
      return 0;
    }
      //проверка выхода индекса за пределы диапазона
    catch (IndexOutOfRangeException &error)
    {
      std::cout << error.getMessage() << "\n";
      return 0;
    }
  }
  file1.close();
  file2.close();
  out.close();
  return 0;
}

//печатает номер пары последовательностей, сами последовательности, вызывает функцию LCS
void serchOfLCS(String const &str1, String const &str2, int number)
{
  out << "-----PAIR OF SEQUENCES № " << number << "-----\n";
  out << str1;
  out << str2 << "\n";
  out << LCS(str1, str2) << "\n\n";
}
