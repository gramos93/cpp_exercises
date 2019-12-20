#include <iostream>
#include <memory>
#include <cassert>

double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);

void Multiply(double** A, double** B, 
              const int a[2], const int b[2], 
              double** &x);

int main(int argc, char* argv[])
{
    const int a[2] = {3, 2};
    const int b[2] = {2, 3};

    double** A = AllocateMatrixMemory(a[0], a[1]); 
    double** B = AllocateMatrixMemory(b[0], b[1]);
    double** x = AllocateMatrixMemory(a[0], b[1]);

    printf("\nConstructing matrix A....\n");
    // Construct matrix A.
    for (int i=0; i<a[0]; i++)
    {
        for(int j=0; j<a[1]; j++)
        {
            A[i][j] = 1.0;
            printf("A[%i][%i] := %f\n", i, j, A[i][j]);
        }
    }
    printf("\nConstructing matrix B....\n");
    // Construct matric B.
    int k = 0;
    for (int i=0; i<b[0]; i++)
    {
        for(int j=0; j<b[1]; j++)
        {
            k++;
            B[i][j] = (double) k;
            printf("B[%i][%i] := %f\n", i, j, B[i][j]);
        }
    }

    printf("\nChecking matrices sizes : [%i x %i] . [%i x %i]\n", a[0], a[1], b[0], b[1]);
    printf("Calculating x = AB....\n");

    assert(a[1] == b[0]);
    Multiply(A, B, a, b, x);

    FreeMatrixMemory(a[0], A);
    FreeMatrixMemory(b[0], B);
    FreeMatrixMemory(a[0], x);

    return 0;
}

double** AllocateMatrixMemory(int numRows, int numCols)
{
    /*
    This function allocates memory for a matrix given it's dimensions.
    ------------------------------------------------------------------
    params.
        - numRows : Number of rows.
        - numCols : Number of cols.
    output.
        - matrix : The pointer to the matrix.
    */

    double** matrix;
    matrix = new double* [numRows];
    for (int i=0; i<numRows; i++)
    {
        matrix[i] = new double [numCols];
    }
    return matrix;
}

void FreeMatrixMemory(int numRows, double** matrix)
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

void Multiply( double** A, double** B, const int a[2], const int b[2], double** &x)
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
                printf("A[%i][%i] * B[%i][%i] + ", i, k, k, j);
                x[i][j] += A[i][k] * B[k][j];
            }
            printf(" = %3.f\n",x[i][j]);
        }
    }
}
