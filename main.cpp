#include <iostream>
#include <ctime>
#include "matrix.h"

int main() 
{
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);
    Matrix bigMat(1, 5);
    bigMat = 12;

    mat1(0,0) = 1;
    std:: cout << "\nMatrix one first value set to 1: " << std::endl;
    mat1.out();

    std::vector<double> values = {1,2,3,4};
    std::vector< std::vector<double> > values2 = {{4,3},{2,1}};

    mat1 = values2;
    mat1.out();

    mat1 = values;
    mat1.out();
    
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

    // std::cout << "\nBig Matrix: " << std::endl;
    // bigMat.out();

    // std::cout << "\nBig Matrix transposed: " << std::endl;
    // bigMat.transpose().out();

    std::cout << "\nMatrix one: " << std::endl;
    mat1.out();
    std::cout << "\nMatrix one (0,1): " << std::endl;
    std::cout << mat1(0,1) << std::endl;


    std::cout << "\nMatrix one row 0: " << std::endl;
    std::vector<double> row;
    row = mat1.getRow(0);
    for (int i = 0; i < row.size(); i++)
    {
        std::cout << row[i] << " ";
    }

    std::cout << "\nMatrix one col 0: " << std::endl;
    std::vector<double> col;
    col = mat1.getCol(0);
    for (int i = 0; i < col.size(); i++)
    {
        std::cout << col[i] << " ";
    }

    std::cout << "\nMatrix one as a vector: " << std::endl;
    std::vector<double> vec;
    vec = mat1.toVec();
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    
    std::cout << "\nmat1: " << std::endl; 
    mat1.out();

    std::cout << "\nMatrix one as a nested vector: " << std::endl;
    std::vector< std::vector<double> > nestedVec;
    nestedVec = mat1.toNestedVec();
    for (int i = 0; i < nestedVec.size(); i++)
    {
        for (int j = 0; j < nestedVec[i].size(); j++)
        {
            std::cout << nestedVec[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Matrix multiplication
    std::cout << "\nMultiplication: " << std::endl;
    std::cout << "\nMatrix one: " << std::endl;
    mat1.out();
    std::cout << "\nMatrix two: " << std::endl;
    mat2.out();
    std::cout << "\nMatrix one * matrix two as a result:" << std::endl;
    result = mat1 * mat2;
    std::cout << "Result: " << std::endl;
    result.out();

    std::vector< std::vector<double> > values3 = {{1},{2},{3},{4}};
    std::vector< std::vector<double> > values4 = {{1,2,3,4}};

    Matrix mat3(4,1);
    Matrix mat4(1,4);

    mat3 = values3;
    mat4 = values4;

    std::cout << "\nMatrix three: " << std::endl;
    mat3.out();
    std::cout << "\nMatrix four: " << std::endl;
    mat4.out();

    std::cout << "\nMatrix three * matrix four as a result:" << std::endl;
    result = mat3 * mat4;
    std::cout << "Result: " << std::endl;
    result.out();

    std::cout << "\nMatrix four * matrix three:" << std::endl; 
    mat4 *= mat3;
    std::cout << "Result: " << std::endl;
    mat4.out();

    return 0;
}
