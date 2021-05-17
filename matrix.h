#ifndef RGR_MARFINA_MATRIX_H
#define RGR_MARFINA_MATRIX_H

#include <iostream>

#include "exceptions.h"

template<typename T>
class Matrix
{
public:
  //конструктор без параметров (пустая матрица, размером которой 0 * 0)
  Matrix();
  //конструктор, принимающий количество строк и столбцов (пустая матрица заданного размера)
  Matrix(int newRows, int newColumns);
  //конструктор копирования
  Matrix(const Matrix &otherMatrix);

  Matrix(const Matrix &&otherMatrix) = delete;
  Matrix<T> &operator=(Matrix<T> &&otherMatrix) = delete;

  //деструктор
  ~Matrix();//+

  //возвращает количество строк матрицы
  int getRows() const;
  //возвращает количество столбцов матрицы
  int getColumns() const;

  //оператор индекса: возвращает строку с указанным индексом
  T *operator[](int rowIndex);
  //оператор присваивания
  Matrix &operator=(const Matrix &otherMatrix);

  //Дружественная функция: оператор вывода строки
  template<typename Q>
  friend std::ostream &operator<<(std::ostream &cout, const Matrix<Q> &matrix);
  //Дружественная функция: оператор ввода строки
  template<typename M>
  friend std::istream &operator>>(std::istream &cin, Matrix<M> &matrix);

private:
  //указатель матрицы
  T **ourMatrix_;
  //строки матрицы
  int rows_;
  //столбцы матрицы
  int columns_;
};

//конструктор без параметров (итог: пустая матрица, размер которой 0 * 0)
template<typename T>
Matrix<T>::Matrix():
  ourMatrix_(nullptr),
  rows_(0),
  columns_(0) {}

//конструктор, принимающий в качестве параметра количество строк и столбцов (итого: пустая матрица заданного размера)
template<typename T>
Matrix<T>::Matrix(int newRows, int newColumns)
{
  rows_ = newRows;
  columns_ = newColumns;
  ourMatrix_ = new T *[rows_];
  for (int i = 0; i < rows_; i++)
  {
    ourMatrix_[i] = new T[columns_];
  }
}

//конструктор копирования
template<typename T>
Matrix<T>::Matrix(const Matrix &otherMatrix)
{
  if (this != &otherMatrix)
  {
    rows_ = otherMatrix.rows_;
    columns_ = otherMatrix.columns_;
    ourMatrix_ = new T *[rows_];
    for (int i = 0; i < rows_; i++)
    {
      ourMatrix_[i] = new T[columns_];
      for (int j = 0; j < columns_; j++)
      {
        ourMatrix_[i][j] = otherMatrix.ourMatrix_[i][j];
      }
    }
  }
}

//деструктор
template<typename T>
Matrix<T>::~Matrix()
{
  for (int i = 0; i < rows_; i++)
  {
    delete[] ourMatrix_[i];
  }
  delete[] ourMatrix_;
  rows_ = 0;
  columns_ = 0;
}

//возвращает количество строк матрицы
template<typename T>
int Matrix<T>::getRows() const
{
  return rows_;
}

//возвращает количество столбцов матрицы
template<typename T>
int Matrix<T>::getColumns() const
{
  return columns_;
}

//оператор индекса: возвращает строку с указанным индексом
template<typename T>
T *Matrix<T>::operator[](int rowIndex)
{
//проверка того, что индекс больше или равен нулю, меньше длины строки
  if ((rowIndex < 0) || (rowIndex >= rows_))
  {
    throw IndexOutOfRangeException();
  }
  return ourMatrix_[rowIndex];
}

//оператор присваивания
template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &otherMatrix)
{
  if (this == &otherMatrix)
  {
    return *this;
  }
  T temp(otherMatrix);
  std::swap(*this, otherMatrix);
  return *this;
}

//Дружественная функция: оператор вывода строки
template<typename T>
std::ostream &operator<<(std::ostream &cout, const Matrix<T> &matrix)
{
  for (int i = 0; i < matrix.rows_; i++)
  {
    for (int j = 0; j < matrix.columns_; j++)
    {
      cout << " " << matrix.ourMatrix_[i][j];
    }
    cout << std::endl;
  }
  cout << std::endl;
  return cout;
}

//Дружественная функция: оператор ввода строки
template<typename T>
std::istream &operator>>(std::istream &cin, Matrix<T> &matrix)
{
  for (int i = 0; i < matrix.rows_; i++)
  {
    for (int j = 0; j < matrix.columns_; j++)
    {
      cin >> matrix.ourMatrix_[i][j];
    }
  }
  return cin;
}

#endif //RGR_MARFINA_MATRIX_H
