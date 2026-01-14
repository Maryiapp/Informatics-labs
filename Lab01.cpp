#include <iostream>   
#include <iomanip>   
#include <cmath>     
#include <string>

int main()
{
    //task 1
    std::string name;
    int age;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Hello, " << name << "! You are " << age << " years old.\n";

    std::cout << "Size of name: " << sizeof(name) << " bytes\n";
    std::cout << "Size of age: " << sizeof(age) << " bytes\n\n";



    // task 2
    double a, b;

    std::cout << "Enter two numbers (a and b): ";
    std::cin >> a >> b;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Sum = " << a + b << "\n";
    std::cout << "Difference = " << a - b << "\n";
    std::cout << "Product = " << a * b << "\n";

    if (b != 0)
        std::cout << "Quotient = " << a / b << "\n\n";
    else
        std::cout << "Quotient = undefined (division by zero)\n\n";



    // task 3
    double A, B;

    std::cout << "Enter coefficients a and b for a*x + b = 0: ";
    std::cin >> A >> B;

    if (A == 0)
    {
        if (B == 0)
            std::cout << "Equation always true\n\n";
        else
            std::cout << "No solution\n\n";
    }
    else
    {
        double x = -B / A;
        std::cout << "Solution: x = " << x << "\n\n";
    }



    // task 4
    bool lightOn;
    int input;
    std::cout << "Enter 1 for light ON, 0 for light OFF: ";
    std::cin >> input;

    lightOn = input;   

    if (lightOn)
        std::cout << "The room is bright!\n";
    else
        std::cout << "It's dark in here.\n";

    return 0;
}
