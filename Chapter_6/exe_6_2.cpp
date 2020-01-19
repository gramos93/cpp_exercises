#include <iostream>
#include "DoubleSquareMatrix.cpp"

void TestMatrixInvertion(DoubleSquareMatrix z);
void TestOperators(DoubleSquareMatrix z);

int main()
{
    // Main function for testing the DoubleSquareMatrix class.
    
    DoubleSquareMatrix z;
    double matrixContent[4] = {1.0, 2.0, 3.0, 4.0};
    DoubleSquareMatrix x(matrixContent);

    std::cout << "Matrix z :\n" << z << std::endl;
    std::cout << "Matrix x :\n" << x << std::endl;
    std::cout << "Setting matrix z equal to x..." << std::endl;
    z = x;
    std::cout << z << std::endl;

    std::cout << "The determinant of the z matrix is : "
              << z.Determinant() << std::endl;

    DoubleSquareMatrix w(x);
    std::cout << "Matrix w created from matrix x\n" << std::flush;
    (w[1])[1] = 0;
    (w[0])[0] = 5;
    std::cout << "Modified matrix w is :\n" << w << std::endl;
    std::cout << "w + x = \n" << (w + x) << std::endl;
    std::cout << "w - x = \n" << (w - x) << std::endl;
    std::cout << "z * 3.0 = \n" << (z * 3.0) << std::endl;

    std::cout << "The inverse of z is : \n" << z.Invert() << std::endl;
}
