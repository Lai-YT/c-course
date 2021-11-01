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

/**
 * Returns the newly allocated memory.
 * This is a wrapper function of realloc. It works the same as it when the
 * reallocation is successful; otherwise it still frees the ptr (which may be
 * forgotten and causes leak) and returns NULL.
 */
void *ReallocAlwaysFree(void *ptr, size_t new_size);

/*
 * GOAL: Allocate the matrix dynamically since we don't know how big it is at
 *      the beginning.
 */
int main(int argc, char const *argv[]) {
  int num_of_elements = 0;
  int e = 0;
  int *matrix = NULL;

  while (scanf("%d", &e) != EOF) {
    matrix = ReallocAlwaysFree(matrix, (++num_of_elements) * sizeof(int));
    if (!matrix /* allocation failed */) {
      return EXIT_FAILURE;
    }
    /* Add in the new element. */
    *(matrix + num_of_elements - 1) = e;
  }
  int side = sqrt(num_of_elements);  /* impicit cast */

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


void *ReallocAlwaysFree(void *ptr, size_t new_size) {
  void *temp = realloc(ptr, new_size);
  /* The always free part. */
  if (!temp) {
    free(ptr);
  }
  return temp;
}
