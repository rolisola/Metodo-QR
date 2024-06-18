#include <iostream>
#include <vector>
#include <cmath>
#include "matrix.h"

// Default constructor
Matrix::Matrix() {}

// Constructor
Matrix::Matrix(std::vector<std::vector<double>> matrix) {
    this->matrix = matrix;
}

// Deep copy of Matrix
Matrix::Matrix(const Matrix& other) {
    this->matrix = other.matrix;
}

Matrix& Matrix::operator=(Matrix other) {
    if(this != &other) {
        this->matrix = other.matrix;
    }
    return *this;
}


// Destructor
Matrix::~Matrix() {}

// Print the matrix
void Matrix::printMatrix() {
    for (int i=0; i<this->matrix.size(); i++) {
        for (int j=0; j<this->matrix[i].size(); j++) {
            std::cout << this->matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Default constructor
SquareMatrix::SquareMatrix() {}

// Constructor
SquareMatrix::SquareMatrix(std::vector<std::vector<double>> matrix) : Matrix(matrix) {}

// Deep copy of Matrix
SquareMatrix::SquareMatrix(const SquareMatrix& other) : Matrix(other)  {}

SquareMatrix& SquareMatrix::operator=(SquareMatrix other) {
    if(this != &other) {
        Matrix::operator=(other);
    }
    return *this;
}

// Destructor
SquareMatrix::~SquareMatrix() {}

// Transpose the matrix
void SquareMatrix::transpose() {
    size_t n = matrix.size();

    std::vector<std::vector<double>> matrixAux(n, std::vector<double>(n));
    
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            matrixAux[j][i] = matrix[i][j];
        }
    }

    matrix = matrixAux;
}
