#include <iostream>
#include <memory>
#include <cassert>
#include <cmath>
#include "ComplexNumber.cpp"

ComplexNumber** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, ComplexNumber** matrix);
double exp(ComplexNumber** A, int numRows, int numCols);
int factorial(int n);

// Function to test the ComplexNumber class used in Exercise 6.1 from
// the book A Guide to Scientific Computing with C++.
int main(int argc, char* argv[])
{
    ComplexNumber** z = AllocateMatrixMemory(3, 3);
    std::cout << "ComplexNumber Matrix 3x3:" << std::endl;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; i < 3; j++)
        {
            z[i][j] = ComplexNumber(i, 10.0 - j);
            std::cout << z[i][j] << ' ';
        }
        std::cout << std::endl;
    }


    return 0;
}

//This function calculates the dot product of two matrices
// TODO : Overload for ComplexNumbers
ComplexNumber** Multiply(ComplexNumber** A, ComplexNumber** B, const int a[2], const int b[2])
{
    /*
    This function calculates the dot product of two matrices.
                            x = A.B
    ------------------------------------------------------------------
    params.
        - A     : First matrix location in memory.
        - B     : Second matrix location in memory.
        - a & b : Arrays containing the sizes of the matrix A and B respectively.
        - x     : Address of the allocated memory for the output  
    output.
        None.
    */

    for (int i=0; i<a[0]; i++)
    {
        for(int j=0; j<b[1]; j++)
        {
            for(int k = 0; k<b[0]; ++k)
            {
                // printf("A[%i][%i] * B[%i][%i] + ", i, k, k, j);
                x[i][j] += A[i][k] * B[k][j];
            }
            // printf(" = %3.f\n",x[i][j]);
        }
    }
}

// This function calculates the factorial of an integer 
int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

// This function calculates e^(A); where A is a complex number matrix
// TODO : Overload pow for ComplexNumbers
double exp(ComplexNumber** A, int numRows, int numCols)
{
    /*
    This function calculates e^(A); where A is a complex number matrix.
    The calculation is done by :
                exp(A) = sum(n=0, inf) (A^n) / n! 
    ------------------------------------------------------------------
    params.
        - A       : Matrix of complex numbers.
        - numRows : Number of rows.
        - numCols : Number of cols.
    output.
        - expResult : Result of the calculation, double precision value.
    */

   int expResult;

   for(int i = 0; i < 1000000; i++)
   {
       expResult += pow(A, i) / factorial(i);
   }

}

// This function allocates memory for a matrix given it's dimensions.
ComplexNumber** AllocateMatrixMemory(int numRows, int numCols)
{
    /*
    This function allocates memory for a matrix given it's dimensions.
    ------------------------------------------------------------------
    params.
        - numRows : Number of rows.
        - numCols : Number of cols.
    output.
        - matrix : The pointer to a ComplexNumber matrix.
    */

    ComplexNumber** matrix;
    matrix = new ComplexNumber* [numRows];
    for (int i=0; i<numRows; i++)
    {
        matrix[i] = new ComplexNumber [numCols];
    }
    return matrix;
}

// This function frees memory for a matrix given it's number of rows and it's memory location.
void FreeMatrixMemory(int numRows, ComplexNumber** matrix)
{
    /*
    This function frees memory for a matrix given it's number of rows and it's memory location.
    ------------------------------------------------------------------
    params.
        - numRows : Number of rows.
        - matrix  : Matrix location in memory.
    output.
        None.
    */

    for (int i=0; i<numRows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
