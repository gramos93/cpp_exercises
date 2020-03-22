#include <cassert>
#include <string>

#include "Students.hpp"

Student::Student()
{
    name = "unadentified";
    tuitionFees = .0;
    setLibFines(.0);
}

Student::Student(std::string sName, double fees, double fines)
{
    name = sName;
    tuitionFees = fees;
    setLibFines(fines);
}

Student::Student(const Student& s)
{
    name = s.name;
    tuitionFees = s.tuitionFees;
    setLibFines(s.libFines);
}

void Student::setLibFines(double fines)
{
    assert(libFines >= 0);
    libFines = fines;
}

double Student::getLibFines()
{
    return libFines;
}

double Student::CalculateFees()
{
    return getLibFines();
}

GradStudent::GradStudent(Student& s)
{
    name = s.name;
    tuitionFees = 0.;
    setLibFines(s.getLibFines());
}

double GradStudent::CalculateFees()
{
    return getLibFines();
}

double PhDStudent::CalculateFees()
{
    return tuitionFees;
}
