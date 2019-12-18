#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    std::ifstream read_file("x_and_y.dat");
    if (!read_file.is_open())
    {
        return 1;
    }

    int number_of_rows = 0;
    int some_var;

    /* Using EOF in the while loop will be wrong. Here we are reading numbers
       so with this while loop our code expresses this logic.
       At the end of the while loop the failbit or badbit will be set. That's because
       at the last attemp to read nothing was extrated. */

    while(read_file >> some_var)
    {
        // Assuming we know the file contains 4 columns, we read 3 more times before indexing
        // num_of_columns.
        read_file >> some_var;
        read_file >> some_var >> some_var;
        number_of_rows++;
    }

    std::cout << "Number of rows = " << number_of_rows << "\n";
    read_file.close();
    return 0;
}