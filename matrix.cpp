#include "matrix.hpp"

Matrix::Matrix(size_t rows, size_t cols)
: mRows(rows),
  mCols(cols),
  mData(rows * cols)
{
}

double& Matrix::operator()(size_t i, size_t j)
{
    return mData[i * mCols + j];
}

double Matrix::operator()(size_t i, size_t j) const
{
    return mData[i * mCols + j];
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        mRows = other.mRows;
        mCols = other.mCols;
        mData = other.mData;
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other)
{
    Matrix result(mRows, mCols);
    if (mRows == other.mRows || mCols == other.mCols)
    {
        for (int i = 0; i < mRows; i++)
        {
            for (int j = 0; j < mCols; j++)
            {
                result.mData[i*mCols + j] = mData[i*mCols + j] + other.mData[i*mCols + j];
            }
        }
    }
    else
    {
        std::cout << "Matrix dimensions do not match!" << std::endl;
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    if (mRows == other.mRows || mCols == other.mCols)
    {
        for (int i = 0; i < mRows; i++)
        {
            for (int j = 0; j < mCols; j++)
            {
                mData[i*mCols + j] += other.mData[i*mCols + j];
            }
        }
    }
    else
    {
        std::cout << "Matrix dimensions do not match!" << std::endl;
    }
    return *this;
}

void Matrix::out() const
{
    int c = 0;
    for (auto& e : mData)
    {
        if (c == mCols)
        {
            std::cout << std::endl;
            c = 0;
        }
        std::cout << e << " ";
        c++;
    }
    std::cout << std::endl;
}

void Matrix::setValues(const std::vector<std::vector<double> >& values) {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            mData[i*mCols + j] = values[i][j];
        }
    }
}

void Matrix::setValues(const std::vector<double>& values) {
    mData = values;
}