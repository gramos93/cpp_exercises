#include <iostream>

//#include "matplotlib-cpp/matplotlibcpp.h"
#include "AbstractOdeSolver.cpp"

double f(double a, double b) {return 1.0 + b;}

int main()
{
    std::cout << "Tesing ODE solver Foward Euler...\n";
    
    double y0 = 2.0;
    double t0 = 0.0, tN = 1.0;
    double h = 0.1;
    
    ForwardEulerSolver func;

    func.SetTimeInterval(t0, tN);
    func.SetStepSize(h);
    func.SetInitialValue(y0);
    func.setFunc(f);

    std::cout << "\nParameters : \n" 
              << "Time interval -> " << t0 << " to " << tN << std::endl
              << "Initial value -> " << y0 << std::endl
              << "Step Size -> " << h << std::endl
              << "Function -> dy/DT = 1 + t" << std::endl;

    std::cout << "\nSolving ODE problem ...\n"; 
    func.SolveEquation();


    std::cout << "\nTesing ODE solver Runge Kutta...\n";
    
    RungeKuttaSolver func2;
    func2.SetTimeInterval(t0, tN);
    func2.SetStepSize(h);
    func2.SetInitialValue(y0);
    func2.setFunc(f);
    
    std::cout << "\nSolving ODE problem ...\n"; 
    func2.SolveEquation();

    return 0;
}
