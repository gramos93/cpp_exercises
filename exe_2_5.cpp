#include <iostream>
#include <cassert>

int main(int argc, char* argv[])
{
    double A[2][2] = {{4, 10}, {1, 1}};
    double inv_A[2][2];
    int rows =  sizeof(A) / sizeof(A[0]);  
    
    double det = (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
    printf("A's determinant is %f.\n", det);

    // Invert matrix if det is non zero
    if (det != 0)
    {
        double B[2][2] = {{A[1][1], -1 * A[0][1]},
                          {-1 * A[1][0], A[0][0]}};
                          
        for (int i = 0; i < rows; i++ )
        {
            for (int j = 0; j < rows; j++)
            {   
                inv_A[i][j] = (1/det) * B[i][j];
                printf("Inverse of A[%i][%i] : %f\n", i, j, inv_A[i][j]);
            }
        }
    }
    return 0;
}