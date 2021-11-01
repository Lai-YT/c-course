/* gcc matrix.c -o bin/main -lm */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Prints the side * side square matrix.
 *
 * e.g., matrix = {1, 2, 3, 4}, side = 2.
 *       print: 1 2
 *              3 4
 */
void PrintSquareMatrix(int *matrix, size_t side);

/**
 * Swaps the value of a and b.
 */
void Swap(int *a, int *b);

/**
 * Returns the pointer to matrix_row,col.
 * Notice that col and row starts from 0.
 *
 * e.g., matrix = {1, 2, 3, 4} = (1 2)
 *                               (3 4)
 * GetMatrixElement(matrix, 2, 0, 0) returns the pointer to 1,
 * which is the element of the first row and the first column.
 */
int *GetMatrixElement(int *matrix, size_t row_size, size_t row, size_t col);

/*
 * GOAL: Avoid using square brackets ([]).
 */
int main(int argc, char const *argv[]) {
  /* Read in the matrix size. */
  int num_of_elements = 0;
  scanf("%d", &num_of_elements);
  int side = sqrt(num_of_elements);  /* impicit cast */

  /* Have the matrix be a pure pointer to avoid using []. */
  int *matrix = calloc(num_of_elements, sizeof(int));

  /* Read in the matrix as a flat pointer form. */
  for (size_t i = 0; i < num_of_elements; ++i) {
    scanf("%d", matrix + i);
  }
  PrintSquareMatrix(matrix, side);

  /* Swap the first row and the third row. */
  for (size_t i = 0; i < side; ++i) {
    Swap(GetMatrixElement(matrix, side, 0, i),
         GetMatrixElement(matrix, side, 2, i));
  }
  PrintSquareMatrix(matrix, side);

  /* Swap the first column and the third column. */
  for (size_t i = 0; i < side; ++i) {
    Swap(GetMatrixElement(matrix, side, i, 0),
         GetMatrixElement(matrix, side, i, 2));
  }
  PrintSquareMatrix(matrix, side);

  free(matrix);

  return 0;
}


void PrintSquareMatrix(int *matrix, size_t side) {
  putchar('\n');
  for (size_t i = 0; i < side; ++i) {
    for (size_t j = 0; j < side; ++j) {
      printf("%d ", *GetMatrixElement(matrix, side, i, j));
    }
    putchar('\n');
  }
}


void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


int *GetMatrixElement(int *matrix, size_t row_size, size_t row, size_t col) {
  return (matrix + row_size * row + col);
}
