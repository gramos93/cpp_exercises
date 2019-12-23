// This file contains execise 5.9 and 5.10.

#include <iostream>
#include <memory>

double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);
void PrintMatrix(double** M, int numRows, int numCols);
void PivotMatrix(double** A, double** b, int numRows, int numCols);
double** GaussianElim(double** A, double** b, int numRows, int numCols);

int main(int ergc, char* argv[])
{   
    const int rows = 3;
    const int cols = 3;

    double** A = AllocateMatrixMemory(rows, cols);
    double** b = AllocateMatrixMemory(rows, 1);
    double** u = AllocateMatrixMemory(rows, 1);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            A[i][j] = 2;
        }

        b[i][0] = .3125;
    }
    // Assures the matrix is non-singular.
    A[0][0] = A[2][2]= 1;
    std::cout << "Original A matrix: " << std::endl;
    PrintMatrix(A, rows, cols);

    PivotMatrix(A, b, rows, cols);
    std::cout << "Pivoted A matrix: " << std::endl;
    PrintMatrix(A, rows, cols);

    u = GaussianElim(A, b, rows, cols);
    std::cout << "Resultant u vector: " << std::endl;
    PrintMatrix(u, rows, 1);

    FreeMatrixMemory(rows, A);
    FreeMatrixMemory(rows, b);
    FreeMatrixMemory(rows, u);

    return 0;
}

void PivotMatrix(double** A, double** b, int numRows, int numCols)
{
    double tmp_A;
    double tmp_b;
    int idx;

    for (int i = 0; i < (numRows - 1); i++)
    {
        idx = i;
        
        for (int k = i + 1; k < numRows; k++)
        {
            if (A[idx][i] < A[k][i])
            {
                idx = k;
            }
        }
        if (idx != i)
        {   
            // std::cout << "Pivoting row " << i << " with row " << idx << std::endl;
            // Swap A[i] row with A[idx] row
            for (int j = 0; j < numCols; j++)
            {
                tmp_A = A[idx][j];
                A[idx][j] = A[i][j];
                A[i][j] = tmp_A;
            }
            // Swap b[i] with b[idx]
            tmp_b = b[idx][0];
            b[idx][0] = b[i][0];
            b[i][0] = tmp_b;
        }
    }
}

double** GaussianElim(double** A, double** b, int numRows, int numCols)
{
    /*
    This function solves a linear matrix system of the form Ax = b given
    the matrix A and the vector b and their dimensions.
    ********************************************************************
    ******* The matrix A must be non-singular and A[0][0] != 0.0 ******* 
    --------------------------------------------------------------------
    params.
        - A       : Matrix A (m x n) !! This matrix is being changed inplace !!
        - b       : Venctor b (m x 1) !! This vector is being changed inplace !!
        - numRows : Number of rows.
        - numCols : Number of cols.
    output.
        - matrix x: The pointer to a vector.
    */

    double** x = AllocateMatrixMemory(numRows, 1);
    
    // Calculating A^(k)_ij and b^(k)_i.
    for (int k = 0; k < (numRows - 1); k++)
    {   
        for (int i = (k + 1); i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                if (j < i) 
                {
                    A[i][j] = 0.0;
                }
                else
                {
                    A[i][j] -= A[i][k] / A[k][k] * A[k][j]; 
                }
                // printf("A^(%i)_[%i][%i] is : %f\n", (k + 1), i, j, A[i][j]);
            }

            b[i][0] -= A[i][k] / A[k][k] * b[k][0];
        }
    }

    // Calculate linear system result x.
    x[numRows - 1][0] = b[numRows - 1][0] / A[numRows -1 ][numRows - 1];

    for (int k = (numRows - 1); k > 0; k--)
    {
        for (int i = (k + 1); i < numRows; i++)
        {
            x[k][0] +=  A[k][i] * x[i][0];
        }

        x[k][0] = b[k][0] - x[k][0];
        x[k][0] *= 1 / A[k][k];
    }
    return x;
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

void PrintMatrix(double** M, int numRows, int numCols)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            printf("%f ", M[i][j]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
