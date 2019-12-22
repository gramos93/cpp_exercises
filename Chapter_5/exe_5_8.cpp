#include <iostream>
#include <memory>
#include <cassert>

double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);

double CalculateDet(double** A, int m, int n);

int main(int argc, char* argv[])
{
    int rows = 3;
    double** A = AllocateMatrixMemory(rows, rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            A[i][j] = 1 + i + j;
            printf("A[%i][%i] = %f\n", i, j, A[i][j]);
        }
    }
    std::cout << "\nCalling CalculateDet function.\n";
    double det_A = CalculateDet(A, rows, rows);
    
    std::cout << "The determinant of A is : " << det_A << "\n";

    FreeMatrixMemory(rows, A);

    return 0;
}

double CalculateDet(double** A, int m, int n)
{
    /*
    This function calculates the deterninant of a matrix given a 
    matrix pointer and it's dimensions.
    ------------------------------------------------------------------
    params.
        - ** A : amtrix pointer.
        - m    : Number of rows.
        - n    : Number of cols.
    output.
        - det : determinant of the matrix.
    */

    double det = 0.0;
    double f = -1.0;

    if (m == 1)
    {
        return (A[0][0]);
    }
    else
    {
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // std::cout << "\nAllocating memory for sub-matrix.\n";
                double** B = AllocateMatrixMemory(m-1, n-1);

                // Construct B skipping the row and column being calculated.
                for (int k = 0, r_b = 0; k < m; k++)
                {
                    if (k == i){continue;}

                    for (int g = 0, c_b = 0; g < n; g++)
                    {
                        if (g == j){continue;}

                        B[r_b][c_b] = A[k][g];
                        c_b++;
                    }
                    r_b++;
                }

                f = f == -1.0 ? 1.0 : -1.0;
                double det_b = CalculateDet(B, m - 1, n - 1);

                det += f * A[i][j] * det_b;
                
                FreeMatrixMemory(m, B);
            }
        }

        return det;
    }
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
