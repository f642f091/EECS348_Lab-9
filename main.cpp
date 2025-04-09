#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char *argv[]) {
    // check that exactly one input file is given
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]); // open input file
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::size_t N;   // matrix size
    int type_flag;   // 0 for int, 1 for double (not used in logic)
    file >> N >> type_flag;

    Matrix A(N), B(N); // allocate two NxN matrices

    file >> A; // read matrix A
    file >> B; // read matrix B
    file.close();

    Matrix A_orig = A; // save original A for reset

    std::cout << "Matrix A:\n" << A;
    std::cout << "Matrix B:\n" << B;

    Matrix sum = A + B; // matrix addition
    std::cout << "A + B:\n" << sum;

    Matrix prod = A * B; // matrix multiplication
    std::cout << "A * B:\n" << prod;

    // print diagonals of A
    std::cout << "Main diagonal of A: " << A.sum_diagonal_major() << std::endl;
    std::cout << "Secondary diagonal of A: " << A.sum_diagonal_minor() << std::endl;

    A = A_orig;
    A.swap_rows(0, 1); // swap rows 0 and 1
    std::cout << "Matrix A after swapping rows 0 and 1:\n" << A;

    A = A_orig;
    A.swap_cols(0, 1); // swap columns 0 and 1
    std::cout << "Matrix A after swapping columns 0 and 1:\n" << A;

    A = A_orig;
    A.set_value(0, 0, 999); // modify A[0][0]
    std::cout << "Matrix A after setting A[0][0] = 999:\n" << A;

    return 0;
}
