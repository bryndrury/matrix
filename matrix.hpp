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

    // destructor
    ~Matrix();

    // operator overloading
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(const std::vector<double>& values);
    Matrix& operator=(const std::vector<std::vector<double> >& values);
    Matrix& operator=(const double scalar);

    Matrix operator+(const Matrix& other);
    Matrix& operator+=(const Matrix& other);

    Matrix operator-(const Matrix& other);
    Matrix& operator-=(const Matrix& other);

    Matrix operator*(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    Matrix operator*(const double scalar);
    Matrix& operator*=(const double scalar);


    // set values
    void setValues(const std::vector<std::vector<double> >& values);
    void setValues(const std::vector<double>& values);

    // return or output values
    void out() const;
    std::vector<size_t> shape() const;
    int size() const;
    std::vector<double> toVec() const;
    std::vector< std::vector<double> > toNestedVec() const;
    std::vector<double> getRow(size_t i) const;
    std::vector<double> getCol(size_t j) const;

    // matrix operations (will include more later)
    Matrix transpose() const;

private:
    size_t mRows;
    size_t mCols;
    std::vector<double> mData;
};

#endif // MATRIX_HPP