#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>

int main(int argc, char* argv[])
{
    assert(argc == 2);

    int grid = atoi(argv[1]);
    assert(grid > 1);

    double step = 1 / (double) grid;
    double x = 0, y, y_prev = 1;

    std::ofstream res("xy.dat");

    printf("Using grid size : %i\n", grid);
    printf("Using step size : %f\n", step);

    if (res.is_open())
    {
        res.precision(5);
        res << x << " " << y_prev << "\n";

        for (int i = 1; i < grid + 1; i++)
        {
            x = i * step;
            y = (-y_prev / step) / (-1 - 1/step);
            res << x << " " << y << "\n";
            res.flush();
            y_prev = y;
        }
        res.close();
    }
    return 0;
}