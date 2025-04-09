#include "matrix.hpp"
#include <iostream>
#include <iomanip>

// constructor: allocate NxN matrix with all 0s
Matrix::Matrix(std::size_t N) {
    size = N;
    data = new int*[size];
    for (std::size_t i = 0; i < size; ++i)
        data[i] = new int[size](); // zero-initialize
}

// copy constructor: deep copy from another matrix
Matrix::Matrix(const Matrix& other) {
    size = other.size;
    data = new int*[size];
    for (std::size_t i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (std::size_t j = 0; j < size; ++j)
            data[i][j] = other.data[i][j];
    }
}

// assignment operator: free old memory, deep copy new
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (std::size_t i = 0; i < size; ++i)
            delete[] data[i];
        delete[] data;

        size = other.size;
        data = new int*[size];
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = new int[size];
            for (std::size_t j = 0; j < size; ++j)
                data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

// destructor: free dynamically allocated memory
Matrix::~Matrix() {
    for (std::size_t i = 0; i < size; ++i)
        delete[] data[i];
    delete[] data;
}

// matrix addition
Matrix Matrix::operator+(const Matrix& rhs) const {
    Matrix result(size);
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + rhs.data[i][j];
    return result;
}

// matrix multiplication
Matrix Matrix::operator*(const Matrix& rhs) const {
    Matrix result(size);
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            for (std::size_t k = 0; k < size; ++k)
                result.data[i][j] += data[i][k] * rhs.data[k][j];
    return result;
}

// update value at (i, j)
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    data[i][j] = n;
}

// get value at (i, j)
int Matrix::get_value(std::size_t i, std::size_t j) const {
    return data[i][j];
}

// return matrix dimension
int Matrix::get_size() const {
    return static_cast<int>(size);
}

// sum of main diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i)
        sum += data[i][i];
    return sum;
}

// sum of secondary diagonal
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i)
        sum += data[i][size - 1 - i];
    return sum;
}

// swap row r1 with r2
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    std::swap(data[r1], data[r2]);
}

// swap column c1 with c2
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    for (std::size_t i = 0; i < size; ++i)
        std::swap(data[i][c1], data[i][c2]);
}

// output matrix using << overloading
std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (std::size_t i = 0; i < matrix.size; ++i) {
        for (std::size_t j = 0; j < matrix.size; ++j)
            out << std::setw(5) << matrix.data[i][j];
        out << std::endl;
    }
    return out;
}

// input matrix using >> overloading
std::istream& operator>>(std::istream& in, Matrix& matrix) {
    for (std::size_t i = 0; i < matrix.size; ++i)
        for (std::size_t j = 0; j < matrix.size; ++j)
            in >> matrix.data[i][j];
    return in;
}
