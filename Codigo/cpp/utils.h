#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "matrix.h"

double dotProduct(std::vector<double> v1, std::vector<double> v2);
double Norm(std::vector<double> v);
std::vector<double> vectorAddition(std::vector<double> v1, std::vector<double> v2);
std::vector<double> vectorSubtraction(std::vector<double> v1, std::vector<double> v2);
std::vector<double> escalarMultiply(std::vector<double> v, double escalar);
Matrix matrixMultiply(Matrix m1, Matrix m2);


#endif