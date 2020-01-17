#ifndef DOUBLESQUAREMATRIXHEADERDEF
#define DOUBLESQUAREMATRIXHEADERDEF 

#include <iostream>

class DoubleSquareMatrix
{
    private:
    // Class is a 2x2, no need for a rows and cols def.
        double mNumRows;
        double mNumCols;
        double** matrix;

    public:
        // CONSTRUCTORS:
        // Initializes all matrix elements to 0.
        DoubleSquareMatrix();
        DoubleSquareMatrix(double a, double b, double c, double d);
        // Copy constructor.
        DoubleSquareMatrix(const DoubleSquareMatrix& z);

        // METHODS :
        double Determinant();
        DoubleSquareMatrix Invert(DoubleSquareMatrix& z);
        
        // OPERATORS :
        DoubleSquareMatrix& operator=(const DoubleSquareMatrix& z);
        DoubleSquareMatrix operator-() const;
        DoubleSquareMatrix operator+(const DoubleSquareMatrix& z) const;
        DoubleSquareMatrix operator-(const DoubleSquareMatrix& z) const;
        DoubleSquareMatrix operator*(const double& x) const;
        
        double& operator[](int idx);

        void FreeMatrixMemory(int numRows, DoubleSquareMatrix);
};

#endif
