#include <iostream>


int main(int argc, char* argv[])
{
    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double A[3][3] = {{1.0, 5.0, 0.0},
                      {7.0, 1.0, 2.0},
                      {0.0, 0.0, 1.0}};

    double B[3][3] = {{-2.0, 0.0, 1.0},
                      {1.0, 0.0, 0.0},
                      {4.0, 1.0, 0.0}};
    
    double w[3], x[3];
    
    for (int i=0; i<3; i++)
    {
        w[i] = u[i] - 3.0*v[i];
        x[i] = u[i] - v[i];
    }

    double y[3], z[3], C[3][3], D[3][3];
    int j = 0;

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k = 0; k < 3; ++k)
            {
                D[i][j] += A[i][k] * B[k][j];
            }
            y[i] += A[i][j] * u[i];
            C[i][j] = 4 * A[i][j] - 3 * B[i][j];
        }

        z[i] = y[i] - v[i];
    }    

    return 0;
}