#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <cmath>

class Matrix
{
public:
    // constructor
    Matrix(size_t rows, size_t cols);
    double& operator()(size_t i, size_t j);
    double operator()(size_t i, size_t j) const;

    // operator overloading
    Matrix& operator=(const Matrix& other);

    Matrix operator+(const Matrix& other);
    Matrix& operator+=(const Matrix& other);

    Matrix operator-(const Matrix& other);
    Matrix& operator-=(const Matrix& other);

    Matrix operator*(const double scalar);
    Matrix& operator*=(const double scalar);


    // set values
    void setValues(const std::vector<std::vector<double> >& values);
    void setValues(const std::vector<double>& values);

    // return or output values
    void out() const;
    Matrix transpose() const;

private:
    size_t mRows;
    size_t mCols;
    std::vector<double> mData;
};

#endif // MATRIX_HPP