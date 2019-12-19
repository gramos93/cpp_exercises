#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    int len = 2;

    // Initializing main pointers and row pointers
    double** A; 
    A = new double* [len];

    double** B;
    B = new double* [len];
    
    double** C; 
    C = new double* [len];

    // Initializing columns pointers
    for (int i = 0; i < len; i++)
    {
        A[i] = new double [len];
        B[i] = new double [len];
        C[i] = new double [len];
    }

    // Assing value to the matrices.
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++ )
        {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
        }
    }

    //Calculating C = A*B.
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            for(int k = 0; k < len; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            printf("C[%i][%i] is %f\n", i, j, C[i][j]);
        }
    }

    // Delete columns memory.
    for (int i = 0; i < len; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    // Delete row memory.
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}