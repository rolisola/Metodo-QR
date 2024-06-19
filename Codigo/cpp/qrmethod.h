#ifndef QRMETHOD_H
#define QRMETHOD_H

#include <vector>
#include "matrix.h"

class QRMethod {
    public:
        SquareMatrix a;
        double error;
        SquareMatrix eigenvectorMatrix;
        QRMethod();
        QRMethod(SquareMatrix a, double error);
        ~QRMethod();
        std::vector<double> run();
    private:
        SquareMatrix calculateQRMatrix(SquareMatrix a);
        bool checkConvergence(SquareMatrix a);  
};

#endif