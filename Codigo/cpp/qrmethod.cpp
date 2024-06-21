#include <iostream>
#include <cmath>
#include <vector>

#include "qrmethod.h"
#include "matrix.h"
#include "utils.h"

// Default constructor
QRMethod::QRMethod() {}

// Overloaded constructor
QRMethod::QRMethod(SquareMatrix a, double error) {
    this->a = a;
    this->error = error;
}

// Destructor
QRMethod::~QRMethod() {}

// Calculate the Q and R Matrices
SquareMatrix QRMethod::calculateQRMatrix(SquareMatrix a) {
    size_t n = a.matrix.size();
    SquareMatrix q(std::vector<std::vector<double>> (n, std::vector<double>(n)));
    SquareMatrix r(std::vector<std::vector<double>> (n, std::vector<double>(n)));
    a.transpose();

    for(size_t i = 0; i < n; i++) {
        for(size_t j = 0; j < n; j++) {
            r.matrix[i][j] = 0.0;
        }
    }
    
    double norm, sum;
    std::vector<double> v, teste;
    std::vector<double> sumVector(n);

    for(long long i = 0; i < n; i++) {
        
        for (long long j = 0; j < n; j++) sumVector[j] = 0.0;
        
        v = a.matrix[i];

        for(long long j = 0; j < i; j++) {
            r.matrix[j][i] = dotProduct(q.matrix[j], a.matrix[i]);
            sumVector = vectorAddition(
                sumVector, 
                escalarMultiply(q.matrix[j], r.matrix[j][i])
            );
        }  

        v = vectorSubtraction(v, sumVector);

        norm = Norm(v);
        r.matrix[i][i] = norm;

        std::cout << norm << std::endl;
        q.matrix[i] = escalarMultiply(v, (double)(1/norm));
    }  
    q.transpose();
    
    std::cout << "Q: " << std::endl;
    q.printMatrix();

    std::cout << "R: " << std::endl;
    r.printMatrix();

    return q;
}

// Checks the convergence of matrix A
bool QRMethod::checkConvergence(SquareMatrix a) {
    for(size_t i = 1; i < a.matrix.size(); i++) {
        for(size_t j = 0; j < i; j++) {
            if(std::abs(a.matrix[i][j]) > this->error) {
                return false;
            }
        }
    }
    return true;
}

// Calculate the eigenvectors
std::vector<double> QRMethod::run() {
    /*convergence = false;
    a_aux = this->a;
    while(!converge) {
        q, r = calculateQRMatrix(a_aux);
        a_aux = matrixMultiply(r, q)
        convergence = checkConvergence(a_aux)
    }

    this->eigenvectorMatrix = a_aux;*/

    SquareMatrix a_aux = this->a;
    SquareMatrix q = calculateQRMatrix(a_aux);

    std::vector<double> a = {1.0, 2.0, 3.0, 4.0};

    std::cout << "A: " << std::endl;
    this->a.printMatrix();
    return a;
}

