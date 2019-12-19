#include <iostream>

void modInt(int* i)
{
    // De-referencing the pointer argument as to modify the integer stored in
    // memory at that specific location.
    *i += *i; 
    printf("The new integer is %i.\n", *i);
}
// Using reference value `int&` so no need to de-reference in the function scope. 
void modInt(int& i)
{
    // De-referencing the pointer argument as to modify the integer stored in
    // memory at that specific location.
    i += i; 
    printf("The new integer is %i.\n", i);
}

int main (int argc, char* argv[])
{
    int x = 10;
    // Passing the address of x to the pointer argument of the function.
    modInt(&x);
    modInt(x);
    
    return 0;  
}
