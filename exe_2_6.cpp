#include <iostream>
#include <cmath>

int main(int argv, char *argc[])
{
    double x_prev, x_next;

    // Initial guess.
    x_prev = 0;

    for (int i = 1; i < 100; i++)
    {
        x_next = x_prev - (exp(x_prev) + pow(x_prev, 3) - 5) /
                        (exp(x_prev) + 3 * pow(x_prev, 2));
        
        printf("x_[%i] is %.10f\n", i, x_prev);
    }

    return 0;
}