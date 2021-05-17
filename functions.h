#ifndef RGR_MARFINA_FUNCTIONS_H
#define RGR_MARFINA_FUNCTIONS_H

#include "matrix.h"
#include "String.h"
#include <fstream>
#include <algorithm>

extern std::ofstream out;

//печатает длину LCS, возвращает LCS
String LCS(String const &str1, String const &str2);
void fillMatrix(int height, int width, Matrix<int> &matrix, String const &str1, String const &str2);
bool commonSubsequence(int height, int width, Matrix<int> &matrix, String const &str1, String const &str2);
void backtracking(int height, int width, Matrix<int> &matrix, String &lcs, String const &str1, String const &str2);
void outputMatrix(String const &str1, String const &str2, Matrix<int> &matrix);

#endif //RGR_MARFINA_FUNCTIONS_H
