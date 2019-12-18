#include <iostream>
#include <fstream>
 
int main(int argc, char* argv[])
{
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};

    std::ifstream read_file("x_and_y.dat");
    std::ofstream write_file;

    if (read_file.is_open())
    {
        char del;
        std::cout << "Should the file be overwritten or not (y/n): ";
        std::cin >> del;
        if (del == 'y')
        {
            read_file.close();
            std::cout << "Deleting current file\n";
            write_file.open("x_and_y.dat");
        }
        else
        {
            write_file.open("x_and_y.dat", std::ios::app);
        }
        
    }

    write_file.setf(std::ios::showpos);
    write_file.precision(10);

    if (write_file.is_open())
    {
        for (int i = 0; i < 4; i++) 
        {
            write_file << x[i] << " ";
            write_file.flush();
        }
        write_file << "\n";

        for (int i = 0; i < 4; i++) 
        {
            write_file << y[i] << " ";
            write_file.flush();
        }
        write_file << "\n";
        // Checks and closing
        write_file.good();
        write_file.close();
    }
    else
    {
        printf("File is not opened");
    }

    return 0;
}