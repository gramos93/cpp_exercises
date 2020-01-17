#include <iostream>
#include "DoubleSquareMatrix.cpp"

void TestMatrixInvertion(DoubleSquareMatrix z);
void TestOperators(DoubleSquareMatrix z);

int main(int argc, char* argv[])
{
    // Main function for testing the DoubleSquareMatrix class.
    
    DoubleSquareMatrix z;
    DoubleSquareMatrix x(1, 2, 3, 4);
    
    std::cout << "Matrix z :\n" << z << std::endl;
    std::cout << "Setting matrix z equal to x..." << std::endl;
    z = x;
    std::cout << z << std::endl;
    std::cout << "The determinant of the z matrix is :" 
              << z.Determinant() << std::endl; 

    DoubleSquareMatrix w(x);
    w[1][1] = 0;
    w[0][0] = 5;

    std::cout << "w + x = \n" << w + x << std::endl;
    std::cout << "w - x = \n" << w - x << std::endl;
    std::cout << "z * 3.0 = \n" << z * 3.0 << std::endl;
    
    std::cout << "The inverse of z is : \n" << Invert(z) << std::endl;
}
