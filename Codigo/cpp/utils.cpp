#include <iostream>
#include <cmath>
#include <vector>
#include "matrix.h"
#include "utils.h"

double dotProduct(std::vector<double> v1, std::vector<double> v2) {
    double dotProd = 0;
    for(size_t i = 0; i < v1.size(); i++) {
        dotProd += v1[i] * v2[i];
    }
    return dotProd;
}

double Norm(std::vector<double> v) {
    double sum = 0;
    for(size_t i=0; i < v.size(); i++) 
        sum += v[i] * v[i];
    return std::sqrt(sum);    
}

std::vector<double> vectorAddition(std::vector<double> v1, std::vector<double> v2) {
    size_t n = v1.size();
    std::vector<double> result(n);

    for (size_t i = 0; i < n; i++) {
        result[i] = v1[i] + v2[i];
    }

    return result;
}

std::vector<double> vectorSubtraction(std::vector<double> v1, std::vector<double> v2) {
    size_t n = v1.size();
    std::vector<double> result(n);

    for (size_t i = 0; i < n; i++) {
        result[i] = v1[i] - v2[i];
    }

    return result;
}

std::vector<double> escalarMultiply(std::vector<double> v, double escalar) {
    for(size_t i=0; i < v.size(); i++)
        v[i] *= escalar;
    return v;
}

Matrix matrixMultiply(Matrix m1, Matrix m2) {
    std::cout << "not implemented yet" << std::endl;
}
