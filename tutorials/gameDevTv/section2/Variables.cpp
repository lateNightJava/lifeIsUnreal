#include <iostream>

int main() 
{
    int a = 2;
    std::cout << a << std::endl;

    int numA = 2, numB = 2, numC = 3;
    int sum = numA + numB + numC;
    int product = numA * numB * numC;

    std::cout << numA << " + ";
    std::cout << numB << " + ";
    std::cout << numC;
    std::cout << " = " << sum << std::endl;

    std::cout << numA << " * ";
    std::cout << numB << " * ";
    std::cout << numC;
    std::cout << " = " << product << std::endl;


    
    return 0;
}