#include <iostream>
#include <fstream>
#include <cassert>

#include "AbstractOdeSolver.hpp"

void AbstractOdeSolver::SetStepSize(double h)
{
    stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1)
{
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(double y0)
{
    initialValue = y0;
}

void ForwardEulerSolver::setFunc(double (func) (double _, double __))
{
    p_f = func;     
}

double ForwardEulerSolver::RightHandSide(double y, double t)
{
    return y + stepSize * p_f(y, t);
}

double ForwardEulerSolver::SolveEquation()
{
    double y = initialValue;
    double t = initialTime;
    std::ofstream result("/home/gramos/cpp_tuts/Chapter_7/output_Euler.csv");
    assert(result.is_open());

    for(int i = 1; i <= (finalTime - initialTime) / stepSize; i++)
    {
        y = RightHandSide(y, t);
        t = initialTime + (i * stepSize);
        printf("Iteration %i | Y = %0.2f | time = %0.2f\n", i, y, t);
        result << t << "," << y << std::endl;   
    }

    result.flush();
    result.close();
    return y;
}

void RungeKuttaSolver::setFunc(double (func) (double _, double __))
{
    p_f = func;     
}

double RungeKuttaSolver::RightHandSide(double y, double t)
{
    return stepSize * p_f(y, t);
}

double RungeKuttaSolver::SolveEquation()
{
    double y = initialValue;
    double t = initialTime;
    double k1, k2, k3, k4;

    std::ofstream result("/home/gramos/cpp_tuts/Chapter_7/output_Runge.csv");
    assert(result.is_open());

    for(int i = 1; i <= (finalTime - initialTime) / stepSize; i++)
    {
        k1 = RightHandSide(y, t);
        k2 = RightHandSide(y + .5 * k1, t + .5 * stepSize);
        k3 = RightHandSide(y + .5 * k2, t + .5 * stepSize);
        k4 = RightHandSide(y + k3, t + stepSize);

        y += ((1.0/6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4));
        t = (initialTime + (i * stepSize));
        printf("k1 : %0.2f | k2 : %0.2f | k3 : %0.2f | k4 : %0.2f\n", k1, k2, k3, k4);
        printf("Iteration %i | Y = %0.2f | time = %0.2f\n", i, y, t);
        result << t << "," << y << std::endl;   
    }

    return y;
}

