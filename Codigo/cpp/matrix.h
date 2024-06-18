#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
    public:
        std::vector<std::vector<double>> matrix;
        Matrix();
        Matrix(std::vector<std::vector<double>> matrix);
        ~Matrix();
        void printMatrix();
};

class SquareMatrix : public Matrix {
    public:
        SquareMatrix();
        SquareMatrix(std::vector<std::vector<double>> matrix);
        ~SquareMatrix();
        void transpose();
};

#endif