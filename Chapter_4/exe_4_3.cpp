#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    const int len = 3;

    for(int j = 0; j < 1000; j++)
    {   
        double* p_x = new double [len];
        double* p_y = new double [len];

        for (int i = 0; i < len; i++)
        {
            p_x[i] = 1.0;
            p_y[i] = 2.0 * ((double) i);
        }
        double dot;
        dot = p_x[0] * p_y[0] + p_x[1] * p_y[1] + p_x[2] * p_y[2];
        printf("Dot product is : %f\n", dot);

        delete[] p_x;
        delete[] p_y;
        // std::cout << p_x[2] << "\n";

        // if ((p_x != NULL) && (p_y != NULL)) {return 1;}
    }
    
    return 0;
}