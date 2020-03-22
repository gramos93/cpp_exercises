#include <iostream>
#include <string>

#include "Students.cpp"

int main()
{
    std::cout << "Students class test starting...\n" <<
                 "Defining students...\n";
    
    // Empty student
    Student sEmpty;
    std::cout << "Empty Student exemple: " 
              << sEmpty.name << std::endl 
              << sEmpty.tuitionFees 
              << std::endl << sEmpty.getLibFines() << std::endl;

    Student Gerald = Student("Gerald", 100000., 50.);
    std::cout << "Normal Student exemple: " 
              << Gerald.name << std::endl 
              << "Student total fees: " << Gerald.tuitionFees 
              << std::endl << "Library fees: " << Gerald.getLibFines() << std::endl;

    GradStudent Yennifer(Gerald);
    Yennifer.name = "Yennifer";
    Yennifer.fullTime = true;

    std::cout << "Graduate Student exemple: " 
              << Yennifer.name << std::endl 
              << "Student total fees: " << Yennifer.CalculateFees() 
              << std::endl << "Library fees: " << Yennifer.getLibFines() << std::endl;
       
    return 0;
}
