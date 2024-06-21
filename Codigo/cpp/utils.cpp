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

std::vector<std::vector<double>> matrixMultiply(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2) {
    size_t linhasM1 = m1.size();
    size_t colunasM1 = m1[0].size();
    size_t colunasM2 = m2[0].size();

    std::vector<std::vector<double>> result(linhasM1, std::vector<double>(colunasM2, 0));

    for (size_t i = 0; i < linhasM1; i++) {
        for (size_t j = 0; j < colunasM2; j++) {
            for (size_t k = 0; k < colunasM1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return result;
}
