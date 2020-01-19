#ifndef DOUBLESQUAREMATRIXHEADERDEF
#define DOUBLESQUAREMATRIXHEADERDEF 

#include <iostream>

class DoubleSquareMatrix
{
    private:
    // Class is a 2x2, no need for a rows and cols def.
        int mNumRows = 2;
        int mNumCols = 2;
        double** matrix;

    public:
        // CONSTRUCTORS:
        // Initializes all matrix elements to 0.
        DoubleSquareMatrix();
        DoubleSquareMatrix(double matrixContent[4]);
        // Copy constructor.
        DoubleSquareMatrix(const DoubleSquareMatrix& z);

        // METHODS :
        double Determinant() const;
        DoubleSquareMatrix Invert() const;

        // OPERATORS :
        DoubleSquareMatrix& operator=(const DoubleSquareMatrix& z);
        DoubleSquareMatrix operator-() const;
        DoubleSquareMatrix operator+(const DoubleSquareMatrix& z) const;
        DoubleSquareMatrix operator-(const DoubleSquareMatrix& z) const;
        DoubleSquareMatrix operator*(const double& x) const;

        double* operator[](int idx);

    friend void FreeMatrixMemory(DoubleSquareMatrix& z);
    friend std::ostream& operator<<(std::ostream& output,
                           const DoubleSquareMatrix& z);

};

#endif
