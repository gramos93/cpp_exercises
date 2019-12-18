#include <iostream>
#include <cmath>

int main(int argv, char *argc[])
{
    double x_prev, x_next, ep = 1e-5;

    // Initial guess.
    x_prev = 0;

    do
    {
        x_prev = x_next;
        x_next = x_prev - (exp(x_prev) + pow(x_prev, 3) - 5) /
                        (exp(x_prev) + 3 * pow(x_prev, 2));
        
        printf("x_next is %.10f\n", x_next);
        
    } while (fabs(x_next - x_prev) > ep);

    return 0;
}