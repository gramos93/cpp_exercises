#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    int i = 5;
    int* p_j = &i; // Adress of `i`.
    printf("The value at location p_j is: %i\n", *p_j);

    *p_j *= 5; // `i` becomes 5 * 5 = 25.
    printf("The NEW value at location p_j is: %i\n", *p_j);
    
    int* p_k = new int;
    *p_k = i; // The value `i` is stores in a NEW location in memory.
    printf("The NEW value at location p_k is: %i\n", *p_k);

    *p_j = 0; // The value `i` is changed to 0.
    printf("The NEW value at location p_j is: %i\n", *p_j);
    printf("The NEW value at location p_k is: %i\n", *p_k);

    // delete p_j does not work because it was not initiated with `new`.
    delete p_k;

    return 0;
}