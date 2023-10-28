#include "matrix.hpp"
// For how to use this class, see matrix/main.hpp

// To do: (- not done, + done, ~ in progress) 

// - Matrix inverse():

// ~ Matrix operator*(const Matrix& other);
// ~ Matrix& operator*=(const Matrix& other);

// + Matrix(size_t rows, size_t cols);
// + std::vector<double> toVec() const;
// + std::vector< std::vector<double> > toNestedVec() const;
// + std::vector<double> getRow(size_t i) const;
// + std::vector<double> getCol(size_t j) const;
// + Matrix '=' operator (all forms I can think would be useful)
// + Matrix operator-(const Matrix& other);
// + Matrix& operator-=(const Matrix& other);
// + Matrix operator*(const double scalar);
// + Matrix& operator*=(const double scalar);
// + Matrix& operatorT(); (Transpose the matrix)

// Constructor and Destructor
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

Matrix::~Matrix() 
{
}


// Operator overloading
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

Matrix& Matrix::operator=(const std::vector<std::vector<double> >& values)
{
    for (int i = 0; i < mRows; i++) 
    {
        for (int j = 0; j < mCols; j++) 
        {
            mData[i*mCols + j] = values[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator=(const std::vector<double>& values)
{
    mData = values;
    return *this;
}

Matrix& Matrix::operator=(const double scalar)
{
    for (auto& e : mData)
    {
        e = scalar;
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

Matrix Matrix::operator-(const Matrix& other)
{
    Matrix result(mRows, mCols);
    if (mRows == other.mRows || mCols == other.mCols)
    {
        for (int i = 0; i < mRows; i++)
        {
            for (int j = 0; j < mCols; j++)
            {
                result.mData[i*mCols + j] = mData[i*mCols + j] - other.mData[i*mCols + j];
            }
        }
    }
    else
    {
        std::cout << "Matrix dimensions do not match!" << std::endl;
    }
    return result;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    if (mRows == other.mRows || mCols == other.mCols)
    {
        for (int i = 0; i < mRows; i++)
        {
            for (int j = 0; j < mCols; j++)
            {
                mData[i*mCols + j] -= other.mData[i*mCols + j];
            }
        }
    }
    else
    {
        std::cout << "Matrix dimensions do not match!" << std::endl;
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& other)
{
    if (mCols == other.mRows)
    {
        Matrix result(mRows, other.mCols);
        for (int i = 0; i < mRows; i++)
        {
            for (int j = 0 ; j < other.mCols; j++)
            {
                for (int k = 0; k < mCols; k++)
                {
                    result.mData[i*other.mCols + j] += mData[i*mCols + k] * other.mData[k*other.mCols + j];
                }
            }
        }
        return result;
    }
    else
    {
        std::cout << "Matrix dimensions do not match!" << std::endl;
    }
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    if (mCols == other.mRows)
    {
        Matrix result(mRows, other.mCols);
        for (int i = 0; i < mRows; i++)
        {
            for (int j = 0 ; j < other.mCols; j++)
            {
                for (int k = 0; k < mCols; k++)
                {
                    result.mData[i*other.mCols + j] += mData[i*mCols + k] * other.mData[k*other.mCols + j];
                }
            }
        }
        *this = result;
        return *this;
    }
    else
    {
        std::cout << "Matrix dimensions do not match!" << std::endl;
    }
}

Matrix Matrix::operator*(const double scalar)
{
    Matrix result(mRows, mCols);
    for (int i = 0; i < mRows; i++)
    {
        for (int j = 0 ; j < mCols; j++)
        {
            result.mData[i*mCols + j] = mData[i*mCols + j] * scalar;
        }
    }
    return result;
}

Matrix& Matrix::operator*=(const double scalar)
{
    for (auto& e : mData)
    {
        e *= scalar;
    }
    return *this;
}


// Set values
void Matrix::setValues(const std::vector<std::vector<double> >& values) 
{
    for (int i = 0; i < mRows; i++) 
    {
        for (int j = 0; j < mCols; j++) 
        {
            mData[i*mCols + j] = values[i][j];
        }
    }
}

void Matrix::setValues(const std::vector<double>& values) 
{
    mData = values;
}


// Return or output values
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

std::vector<size_t> Matrix::shape() const
{
    std::vector<size_t> result = {mRows, mCols};
    return result;
}

std::vector<double> Matrix::toVec() const
{
    return mData;
}

std::vector< std::vector<double> > Matrix::toNestedVec() const
{
    std::vector< std::vector<double> > result;
    for (int i = 0; i < mRows; i++)
    {
        std::vector<double> row;
        row = getRow(i);
        if (i != (mRows))
        {
            result.push_back(row);
        }
    }
    return result;
}

std::vector<double> Matrix::getRow(size_t i) const
{
    std::vector<double> result;
    for (int j = 0; j < mCols; j++)
    {
        result.push_back(mData[i*mCols + j]);
    }
    return result;
}

std::vector<double> Matrix::getCol(size_t j) const
{
    std::vector<double> result;
    for (int i = 0; i < mRows; i++)
    {
        result.push_back(mData[i*mCols + j]);
    }
    return result;
}


// Matrix transpose and inverse (inverse not yet implemented)
Matrix Matrix::transpose() const
{
    Matrix result(mCols, mRows);
    for (int i = 0; i < mRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            if (i != j)
            {
                result.mData[j*mRows + i] = mData[i*mCols + j];
            }
            else
            {
                result.mData[i*mCols + j] = mData[i*mCols + j];
            }
        }
    }
    return result;
}

