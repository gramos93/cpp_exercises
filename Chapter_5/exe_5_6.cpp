#include <cmath>
#include <iostream>

double CalculateNorm(double* x, int s, int p=2)
{
    double a = 0.0;

    for (int i=0; i<s; i++)
    {
        double temp = fabs(x[i]);
        a += pow(temp, p);
    }

    return pow(a, 1.0 / p);
}

int main(int argc, char* argv[])
{
    double x[4] = {2, 3, 4, 5}; //  The variable x is already a pointer.
    int s = 4; 

    double norm_x = CalculateNorm(x, s);
    std::cout << "The norm of the vector x is : " << norm_x << "\n";

    return 0;
}