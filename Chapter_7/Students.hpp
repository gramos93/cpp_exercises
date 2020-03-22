#ifndef STUDENTSHEADERDEF
#define STUDENTSHEADERDEF

#include <string>
#include <cassert>

class Student
{
    public:
        // CONSTRUCTORS
        Student();
        Student(std::string sName, double fees, double fines);
        // Copy Constructor
        Student(const Student& s);
        std::string name;
        double tuitionFees;
        
        void setLibFines(double fines);
        virtual double getLibFines();
        virtual double CalculateFees();
        
    private:
        double libFines;
};

class GradStudent : public Student
{
    public:
        GradStudent();
        GradStudent(std::string name,bool fullTime);
        GradStudent(Student& s);
        bool fullTime;
        double CalculateFees();
};

class PhDStudent : public GradStudent
{
    public:
        double CalculateFees();
};

#endif
