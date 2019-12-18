#include<iostream>
/*
    Guide to Scientific Computing with C++ 

    Problem :2.3 In this exercise you are asked to write and test a program which sums a list of
                 numbers which are provided by a user via std::cin (see Sect. 1.5.2).
                 1. Write a program that calculates the sum of a collection of positive integers that
                 are entered by the user from the keyboard. Your program should prompt the user
                 to enter each integer followed by the return key, and to enter “−1” at the end
                 of the list of integers to be added. Note that there is no need to store the list of
                 integers: you can keep track of the sum as the user is entering the values.

                 2. Modify your code so that the code terminates if the sum of integers entered up to
                 that point exceeds 100.

                 3. Modify your code so that, if the user has entered an incorrect integer, they may
                 enter “−2” to reset the sum to zero and begin entering integers again.
*/

int main(int argc, char *argv[])
{
    int count = 0, uInput = 0;
    
    while ((uInput != -1) && (count < 100))
    {
        std::cout << "Enter an integer: ";   
        std::cin >> uInput;
        std::cout << "\n"; 

        if (uInput == -2)
        {
            count = 0;
        }
        else
        {
            count += uInput;
        }
        if (count >= 100)
        {
            std:: cout << "The count is > 100 " << "\nSum is finished.\n";
        }
        else {std:: cout << "The count is : " << count << "\n";} 
    }  

    return 0;
}