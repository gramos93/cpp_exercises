#include <iostream>
#include <cmath>
// #include <cassert>
#include <memory>

#include "DoubleSquareMatrix.hpp"

DoubleSquareMatrix::DoubleSquareMatrix()
{
    matrix = new double* [mNumRows];
    for (int i = 0; i < mNumRows; i++)
    {
        matrix[i] = new double [mNumCols];
    }
}

DoubleSquareMatrix::DoubleSquareMatrix(double a, double b, double c, double d)
{
    double matrixContent[4] = {a, b, c, d};
    matrix = new double* [mNumRows];

    for (int i = 0; i < mNumRows; i++)
    {
        matrix[i] = new double [mNumCols];
        for (int j = 0; j < mNumCols; j++)
        {
            matrix[i][j] = matrixContent[j];
        }
    }
}

DoubleSquareMatrix::DoubleSquareMatrix(const DoubleSquareMatrix& z)
{
    for(int i = 0; i < mNumRows; i++)
    {
        for(int j = 0; j < mNumCols; j++)
        {
            matrix[i][j] = z.matrix[i][j];
        }
    }
}

