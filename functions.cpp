#include "functions.h"
#include <iomanip>

//максимальный размер матрицы, которая может быть записана в файл
const int MAX_SIZE_OF_MATRIX_FOR_OUTPUT = 2500;
const int SETW_FOR_MATRIX = 2;

//заполнение матрицы
void fillMatrix(int height, int width, Matrix<int> &matrix, String const &str1, String const &str2)
{
  //заполнить матрицу 0 (первый столбец и первая строка)
  for (int j = 0; j < width; j++)
  {
    matrix[0][j] = 0;
  }
  for (int i = 0; i < height; i++)
  {
    matrix[i][0] = 0;
  }
  //матрица заполняется в соответствии с соответствующим правилом (для поиска длины)
  for (int i = 1; i < height; i++)
  {
    for (int j = 1; j < width; j++)
    {
      if (str2[i - 1] == str1[j - 1])
      {
        (matrix[i])[j] = (matrix[i - 1])[j - 1] + 1;
      }
      else
      {
        (matrix[i])[j] = std::max((matrix[i - 1])[j], (matrix[i])[j - 1]);
      }
    }
  }
}

//проверка наличия общей подпоследовательности
bool commonSubsequence(int height, int width, Matrix<int> &matrix, String const &str1, String const &str2)
{
  if ((matrix[height - 1])[width - 1] == 0)
  {
    return "no longest common subsequence found!";
  }
  else
  {
    out << "Length of longest common subsequence:\n";
    out << (matrix[height - 1])[width - 1] << "\n\n";
  }
  //запись матрицы в файл (в случае, если матрица не превышает MAX_SIZE_OF_MATRIX_FOR_OUTPUT)
  if (height * width < MAX_SIZE_OF_MATRIX_FOR_OUTPUT)
  {
    outputMatrix(str1, str2, matrix);
  }
  else
  {
    out << "THE MATRIX IS TOO GREAT TO CARRY OUT IT!\n\n";
  }
  return true;
}

//обратный проход
void backtracking(int height, int width, Matrix<int> &matrix, String &lcs, String const &str1, String const &str2)
{
  //пройти через матрицу, начиная с последнего элемента
  while (height != 0 && width != 0)
  {
    if (str2[height - 1] == str1[width - 1])
    {
      lcs.pushBack(str2[height - 1]);
      --height;
      --width;
    }
    else
    {
      if ((matrix[height])[width - 1] > (matrix[height - 1])[width])
      {
        --width;
      }
      else
      {
        --height;
      }
    }
  }
}

//возвращает LCS
String LCS(String const &str1, String const &str2)
{
  int height = str2.getLength();
  int width = str1.getLength();
  Matrix<int> matrix(height, width);

  //заполнение матрицы
  fillMatrix(height, width, matrix, str1, str2);

  //проверка наличия общей подпоследовательности
  commonSubsequence(height, width, matrix, str1, str2);

  String lcs;

  //обратный проход
  backtracking(height, width, matrix, lcs, str1, str2);

  //LCS необходимо перевернуть, так как после прохождения по матрице она записывается, начиная с последнего
  lcs.reverse();
  out << "LARGEST TOTAL SEQUENCE: \n";
  return lcs;
}

//выводит матрицу в нужном виде
void outputMatrix(String const &str1, String const &str2, Matrix<int> &matrix)
{
  out << "THE MATRIX:\n";
  out << "    ";

  for (int i = 0; i < str1.getLength(); i++)
  {
    out << std::setw(SETW_FOR_MATRIX + 1) << str1.getOurString()[i];
  }

  // после записи 1-й последовательности пишем матрицу, а перед каждой строкой матрицы пишем элемент 2-й последовательности
  for (int i = 0; i < matrix.getRows(); i++)
  {
    //запись для всех строк матрицы, кроме 0-й (содержит элемент 2-й последовательности)
    if (i != 0)
    {
      out << str2.getOurString()[i - 1] << " ";
      for (int j = 0; j < matrix.getColumns(); j++)
      {
        out << std::setw(SETW_FOR_MATRIX) << (matrix[i])[j] << " ";
      }
      out << "\n";
    }
    else
    {
      //запись для 0-й строки матрицы (она отличается от остальных тем, что не содержит элемента 2-й последовательности)
      out << "  ";
      for (int j = 0; j < matrix.getColumns(); j++)
      {
        out << std::setw(SETW_FOR_MATRIX) << (matrix[i])[j] << " ";
      }
      out << "\n";
    }
  }
  out << "\n";
}
