#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

class AbstractOdeSolver
{
    protected:
        double stepSize;
        double initialTime;
        double finalTime;
        double initialValue;

    public:
        void SetStepSize(double h);
        void SetTimeInterval(double t0, double t1);
        void SetInitialValue(double y0);
        virtual double RightHandSide(double y, double t) = 0;
        virtual double SolveEquation() = 0;
};

class ForwardEulerSolver : public AbstractOdeSolver
{
    public:
        void setFunc(double (func) (double _, double __));
        virtual double RightHandSide(double y, double t);
        virtual double SolveEquation();
    
    private:
        double (*p_f) (double a, double b);
};

class RungeKuttaSolver : public AbstractOdeSolver 
{
    public:
        void setFunc(double (func) (double _, double __));
        double RightHandSide(double y, double t);
        double SolveEquation();

    private:
        double (*p_f) (double a, double b);

};

#endif
