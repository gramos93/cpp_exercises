#include <iostream>
#include <cmath>

void stats(double& u, double& v, double* x, int p);

int main(int argc, char* argv[])
{
    const int size = 4;
    double* x = new double [size]; // For every `new`, it's double.
    double u, v;

    x[0] = 2, x[1] = 9.5, x[2] = 3, x[3] = 0.98;

    stats(u, v, x, size);
    std::cout << "The mean is : " << u << "\n";
    std::cout << "The standard deviation is : " << v << "\n";
    
    delete [] x;

    return 0;
}

void stats(double& u, double& v, double* x, int p)
{
    /*
        This function calculates the mean (u) and the standard variance (v)
        given a vector (x) and it's length (p).

        param(s):
        ------------------------------------------------------------------
        u = double precision number
        v = double precision number
        p = integer.
        v = double precision pointer to vector.
    */

    u = 0;
    v = 0;

    // Calculate mean u.
    for (int i=0; i<p ; i++)
    {
        u += x[i];
    }
    u /= p;

    // Caluculate standard deviation v.
    for (int j=0; j<p; j++)
    {
        v += pow((x[j] -u), 2);
    }
    v = sqrt(v / (p - 1)); 
}
