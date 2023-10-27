#include <iostream>
#include <ctime>
#include "matrix.hpp"

int main() 
{
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);

    mat1(0,0) = 1;
    std:: cout << "\nMatrix one first value set to 1: " << std::endl;
    mat1.out();

    std::vector<double> values = {1,2,3,4};
    std::vector< std::vector<double> > values2 = {{4,3},{2,1}};
    
    std::cout << "\nMatrix one:" << std::endl;
    mat1.setValues(values);
    mat1.out();

    std::cout << "\nMatrix two:" << std::endl;
    mat2.setValues(values2);
    mat2.out();

    std::cout << "\nMatrix two equals matrix one: (?)" << std::endl;
    mat2 = mat1;
    mat2.out();

    std::cout << "\nMatrix one + matrix two as a result:" << std::endl;
    Matrix result(2,2);
    result = mat1 + mat2;
    std::cout << "Result: " << std::endl;
    result.out();
    std::cout << "Matrix one: " << std::endl;
    mat1.out();
    std::cout << "Matrix two: " << std::endl;
    mat2.out();

    std::cout << "\nMatrix two += matrix one: (?)" << std::endl;
    mat2 += mat1;
    mat2.out();


    std::cout << "\nMatrix one - matrix two as a result:" << std::endl;
    result = mat1 - mat2;
    std::cout << "Result: " << std::endl;
    result.out();
    std::cout << "Matrix one: " << std::endl;
    mat1.out();
    std::cout << "Matrix two: " << std::endl;
    mat2.out();

    std::cout << "\nMatrix two -= matrix one: (?)" << std::endl;
    mat2 -= mat1;
    mat2.out();

    std::cout << "\nMatrix one * 2 as a result:" << std::endl;
    result = mat1 * 2;
    std::cout << "Result: " << std::endl;
    result.out();

    std::cout << "\nMatrix one *= 2: (?)" << std::endl;
    mat1 *= 2;
    mat1.out();

    std::cout << "\nMatrix one transposed:" << std::endl;
    result = mat1.transpose();
    result.out();

    return 0;
}
