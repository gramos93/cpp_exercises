#include <iostream>

void printInt(int* i)
{
    // De-referencing the pointer argument as so to pring the integer stored in
    // memory at that specific location.
    printf("The integer is %i.\n", *i);
}


int main (int argc, char* argv[])
{
    int x = 1;
    // Passing the address of x to the pointer argument of the function.
    printInt(&x);
    
    return 0;  
}
