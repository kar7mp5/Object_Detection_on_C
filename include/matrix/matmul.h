// matmul.h

#ifndef MATH_MATMUL_H
#define MATH_MATMUL_H

#include <stdio.h>

// Define a struct to represent a block
typedef struct {
    size_t size;
    double *data;
} matrix_block;

// Define a struct to represent a matrix
typedef struct {
    size_t rows;  // Number of rows
    size_t cols;  // Number of columns
    double *data; // Pointer to the matrix data
    matrix_block *block;
    int owner;
} matrix;

/**
 * @brief Allocate the memory for a matrix with garbage values.
 *
 * @param n1 Number of rows
 * @param n2 Number of columns
 * @return Pointer to the newly allocated matrix with uninitialized values.
 */
matrix *matrix_alloc(size_t n1, size_t n2);

/**
 * @brief Allocate the memory for a matrix and initialize all elements to 0.
 *
 * @param n1 Number of rows
 * @param n2 Number of columns
 * @return Pointer to the newly allocated matrix with all elements set to 0.
 */
matrix *matrix_calloc(size_t n1, size_t n2);

/**
 * @brief Frees the memory allocated for a matrix.
 *
 * @param m Pointer to the matrix whose memory will be freed.
 */
void matrix_free(matrix *m);

/**
 * @brief Reallocate array data to fit the memory of a matrix.
 *
 * @param matrix Pointer to the matrix whose memory will be reallocated.
 * @param data Pointer to the array containing the data to be copied into the matrix.
 */
void matrix_cpy(matrix *matrix, const size_t *data);

/**
 * @brief Retrieves an element from the specified position in the matrix.
 *
 * @param m Pointer to the matrix from which the element will be retrieved.
 * @param i The row index of the element to retrieve.
 * @param j The column index of the element to retrieve.
 * @return The value of the element at the specified row and column.
 */
double matrix_get(const matrix *m, const size_t i, const size_t j);

/**
 * @brief Sets the value of an element at the specified position in the matrix.
 *
 * @param m Pointer to the matrix where the element will be set.
 * @param i The row index of the element to set.
 * @param j The column index of the element to set.
 * @param x The value to assign to the specified element.
 */
void matrix_set(matrix *m, const size_t i, const size_t j, double x);

/**
 * @brief Sets the same value for all elements in the matrix.
 *
 * @param m Pointer to the matrix where all elements will be set.
 * @param x The value to assign to all elements in the matrix.
 */
void matrix_set_all(matrix *m, double x);

/**
 * @brief Sets all elements of the matrix to 0.
 *
 * @param m Pointer to the matrix whose elements will be set to 0.
 */
void matrix_set_zero(matrix *m);

/**
 * @brief Performs matrix multiplication.
 * Multiplies a matrix of size r1 x r2 with another matrix of size r2 x c2.
 *
 * @param m1 The first matrix to be multiplied.
 * @param m2 The second matrix to be multiplied.
 * @param output The output matrix to store the result.
 */
void matmul(matrix *m1, matrix *m2, matrix *output);

/**
 * @brief Function to create a matrix with given rows and columns.
 * Allocates memory for the matrix.
 *
 * @param rows Number of rows
 * @param cols Number of cols
 * @return A matrix struct with allocated memory
 */
matrix create_matrix(int rows, int cols);

/**
 * @brief Initializes a dynamically allocated matrix by copying data from a 1D
 * array.
 *
 * @param matrix The matrix to be initialized (dynamically allocated).
 * @param data The 1D array whose elements will be copied into the matrix.
 */
void initialize_matrix(matrix *matrix, const double *data);

/**
 * @brief Transposes a given matrix.
 *
 * This function creates a new matrix that is the transpose of the input matrix.
 * In the transposed matrix, rows become columns and columns become rows.
 *
 * @param matrix The input matrix to be transposed.
 * @return A new matrix that is the transpose of the input matrix.
 */
matrix transpose_matrix(matrix *matrix);

/**
 * @brief Print a matrix.
 *
 * @param matrix The matrix to be printed.
 */
void print_matrix(matrix *matrix);

#endif // MATH_MATMUL_H