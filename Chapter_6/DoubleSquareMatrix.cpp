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

DoubleSquareMatrix& DoubleSquareMatrix::
                    operator=(const DoubleSquareMatrix& z)
{
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            matrix[i][j] = z.matrix[i][j];
        }
    }

    return *this;
}

DoubleSquareMatrix DoubleSquareMatrix::operator-() const
{
    DoubleSquareMatrix w;
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            w.matrix[i][j] = -matrix[i][j];
        }
    }
    return w;
}

DoubleSquareMatrix DoubleSquareMatrix::
                    operator+(const DoubleSquareMatrix& z) const
{
    DoubleSquareMatrix w;
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            w.matrix[i][j] += z.matrix[i][j];
        }
    }
    return w;
}

DoubleSquareMatrix DoubleSquareMatrix::
                    operator-(const DoubleSquareMatrix& z) const
{
    DoubleSquareMatrix w;
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            w.matrix[i][j] -= z.matrix[i][j];
        }
    }
    return w;
}

DoubleSquareMatrix DoubleSquareMatrix::
                    operator*(const double& z) const
{
    DoubleSquareMatrix w;
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            w.matrix[i][j] *= z;
        }
    }
    return w;
}

void FreeMatrixMemory(DoubleSquareMatrix& z)
{
    for (int i = 0; i < z.mNumRows; i++)
    {
        delete[] z.matrix[i];
    }
    delete[] z.matrix;
} 
