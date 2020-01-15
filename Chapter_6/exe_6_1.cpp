#include <iostream>
#include <memory>
#include <cassert>
#include "ComplexNumber.cpp"

ComplexNumber** AllocateMatrixMemory(int numRows, int numCols);
ComplexNumber** exp(ComplexNumber** A, int numRows, int numCols);

void FreeMatrixMemory(int numRows, ComplexNumber** matrix);
void MatrixSum(ComplexNumber** A, ComplexNumber** B, int numRows, int numCols);  
void Multiply(ComplexNumber** A, ComplexNumber** B,
              const int a[2], const int b[2], ComplexNumber** x);

void Multiply(ComplexNumber** A, double b,
              const int a[2], ComplexNumber** x);

void MatrixCopy(ComplexNumber** A, ComplexNumber**B, int numRows, int numCols);
void TestExp();
void TestMultOperator();
void TestMatrixMult();
void TestMatrixMultScalar();

double factorial(int n);

// Function to test the ComplexNumber class used in Exercise 6.1 from
// the book A Guide to Scientific Computing with C++.
int main(int argc, char* argv[])
{
    std::cout << "Testing complex number multiplication." << std::endl;
    TestMultOperator();
    std::cout << "\nTesting complex number matrix multiplication." << std::endl;
    TestMatrixMult();
    std::cout << "\nTesting complex number matrix multiplication by scalar." << std::endl;
    TestMatrixMultScalar();
    std::cout << "\nTesting complex number matrix exponential." << std::endl;
    TestExp();
    

    return 0;
}

void TestMultOperator()
{
    ComplexNumber z(1, 9);
    std::cout << "z * z = " << z*z << std::endl;
}

void TestMatrixMult()
{
    ComplexNumber** z = AllocateMatrixMemory(3, 3);
    std::cout << "ComplexNumber z Matrix 3x3:" << std::endl;
    // Setting matrix values.
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            z[i][j] = ComplexNumber(i + 1, 9.0 - j);
            std::cout << z[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "z * z = " << std::endl;
    ComplexNumber** x = AllocateMatrixMemory(3, 3);
    int size[2] = {3, 3};

    Multiply(z, z, size, size, x);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << x[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void TestMatrixMultScalar()
{
    ComplexNumber** z = AllocateMatrixMemory(3, 3);
    std::cout << "ComplexNumber z Matrix 3x3:" << std::endl;
    // Setting matrix values.
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            z[i][j] = ComplexNumber(i + 1, 9.0 - j);
        }
    }
    std::cout << "z / 2 = " << std::endl;
    ComplexNumber** x = AllocateMatrixMemory(3, 3);
    int size[2] = {3, 3};

    Multiply(z, 2, size, x);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << x[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Function to test the exponential of a complex matrix ; exp(A)
void TestExp()
{   
    ComplexNumber** z = AllocateMatrixMemory(3, 3);
    std::cout << "ComplexNumber Matrix 3x3:" << std::endl;

    // Setting matrix values.
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            z[i][j] = ComplexNumber(i + 1, 9.0 - j);
            std::cout << z[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    ComplexNumber** matrixExpo = AllocateMatrixMemory(3, 3);
    matrixExpo = exp(z, 3, 3);

    std::cout << "The results is :" << std::endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << matrixExpo[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    FreeMatrixMemory(3, matrixExpo);
}

//This function calculates the dot product of two matrices
void Multiply(ComplexNumber** A, ComplexNumber** B,
              const int a[2], const int b[2], ComplexNumber** x)
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
                x[i][j] = x[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

// This function overrides the Multiply function 
// to multiply a matrix by a scalar
void Multiply(ComplexNumber** A, double b,
              const int a[2], ComplexNumber** x)
{
    /*
    This function calculates the dot product of two matrices.
                            x = A*b
    ------------------------------------------------------------------
    params.
        - A     : First matrix location in memory.
        - b     : Scalar to be multiplied.
        - a     : Array containing the sizes of the matrix A.
        - x     : Address of the allocated memory for the output  
    output.
        None.
    */

    for (int i=0; i<a[0]; i++)
    {
        for(int j=0; j < a[1]; j++)
        {
            x[i][j] = A[i][j] / b;
        }
    }
}

// This function sums two complex matrices
void MatrixSum(ComplexNumber** A, ComplexNumber** B, int numRows, int numCols)
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            A[i][j] = A[i][j] + B[i][j];
        }
    }
}

// This function calculates the factorial of an integer 
double factorial(int n)
{
  return double (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

// This function calculates e^(A); where A is a complex number matrix
ComplexNumber** exp(ComplexNumber** A, int numRows, int numCols)
{
    /*
    This function calculates e^(A); where A is a complex number matrix.
    The calculation is done by :
                exp(A) = sum(k=0, inf) (A^k) / k! 
    ------------------------------------------------------------------
    params.
        - A       : Matrix of complex numbers.
        - numRows : Number of rows.
        - numCols : Number of cols.
    output.
        - expResult : Result of the calculation, double precision value.
    */

    ComplexNumber** expResult = AllocateMatrixMemory(numRows, numCols);
    ComplexNumber** matrixPower = AllocateMatrixMemory(numRows, numCols);
    ComplexNumber** matrixPowerLast = AllocateMatrixMemory(numRows, numCols);

    int size[2] = {numRows, numCols};
    int n = 100; // Approximating a large number
    
    // Setting the first iteration to the identity matrix
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            matrixPower[i][j] = 1;
            matrixPowerLast[i][j] = 1;

            if (i == j)
            {
                expResult[i][j] = 1;
            }
            else
            {
                expResult[i][j] = 0;
            }
        }
    }

    for(int k = 1; k < n; k++)
    {
        Multiply(matrixPowerLast, A, size, size, matrixPower);
        MatrixCopy(matrixPower, matrixPowerLast, numRows, numCols);
 
        Multiply(matrixPower, factorial(k), size, matrixPower);
        MatrixSum(expResult, matrixPower, numRows, numCols);
    }
    FreeMatrixMemory(numRows, matrixPower);
    FreeMatrixMemory(numRows, matrixPowerLast);
    return expResult;
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

// This function copies matrix A into B.
void MatrixCopy(ComplexNumber** A, ComplexNumber**B, int numRows, int numCols)
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            B[i][j] = A[i][j];
        }
    }
}
