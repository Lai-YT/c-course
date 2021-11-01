#include <stdio.h>
#include <stdlib.h>


typedef struct {
  int *data;
  size_t size;
} NumList;

/**
 * This is a ascending bubble sort.
 */
void BubbleSort(NumList *list);

/**
 * Merges list1 and list2, then put the result in list1.
 * Which means list2 is unchanged, list1 is modified.
 */
void Merge(NumList *list1, NumList *list2);

/**
 * Allocates a NumList with data in size, or NULL if the allocation fails.
 *
 * This function guarantees that there's no partially allocated list,
 * which has the structure allocated successfully but data is NULL.
 */
NumList *NewNumList(size_t size);

/**
 * Frees the NumList allocated by NewNumList(),
 * which means the list can't be partially allocated.
 */
void FreeNumList(NumList *list);

/**
 * Reads a list from the console.
 */
NumList *ReadList(int list_id);

/**
 * Prints the list; blank line if the list is NULL.
 */
void PrintList(NumList *list);

/**
 * Swaps the value of a and b.
 */
void Swap(int *a, int *b);


/**
 * Requirements:
 *  Only use dynamic allocations on Numlist and pass then through pointers
 *  to avoid any overhead on copying.
 */
int main(int argc, char const *argv[]) {
  /* read */
  NumList *list1 = ReadList(1);
  NumList *list2 = ReadList(2);

  printf("Original list1: ");
  PrintList(list1);
  printf("Original list2: ");
  PrintList(list2);

  /* sort */
  BubbleSort(list1);
  printf("Sorted list1: ");
  PrintList(list1);

  BubbleSort(list2);
  printf("Sorted list2: ");
  PrintList(list2);

  /* merge */
  Merge(list1, list2);
  PrintList(list1);

  /* free */
  FreeNumList(list1);
  FreeNumList(list2);

  return 0;
}


NumList *NewNumList(size_t size) {
  /* Allocates the outer structure first. */
  NumList *new_num_list = malloc(sizeof(NumList));
  /* fail */
  if (!new_num_list) {
    return NULL;
  }

  /* Then allocate the inner list. */
  new_num_list->data = calloc(size, sizeof(int));
  /* fail */
  if (!new_num_list->data) {
    free(new_num_list);
    return NULL;
  }

  /* success */
  new_num_list->size = size;
  return new_num_list;
}


void FreeNumList(NumList *num_list) {
  if (num_list) {
    free(num_list->data);
    free(num_list);
    /* avoid garbage value */
    num_list = NULL;
  }
}


void BubbleSort(NumList *list) {
  for (size_t i = 0; i < list->size - 1; ++i) {
    for (size_t j = 0; j < list->size - i - 1; ++j) {
      if (list->data[j] > list->data[j + 1]) {
        Swap(list->data + j, list->data + j + 1);
      }
    }
  }
}


/*
 * Simply merge the two lists into the third list,
 * then replace the first list with the third one.
 */
void Merge(NumList *list1, NumList *list2) {
  int *res_data = calloc(list1->size + list2->size, sizeof(int));

  /*
   * Fail to get space to place the new list:
   * no merge performed.
   */
  if (!res_data) {
    return;
  }

  /* normal merge */
  size_t i = 0, j = 0;
  while (i < list1->size && j < list2->size) {
    if (list1->data[i] <= list2->data[j]) {
      res_data[i + j] = list1->data[i];
      ++i;
    } else {
      res_data[i + j] = list2->data[j];
      ++j;
    }
  }

  while (i != list1->size) {
    res_data[i + j] = list1->data[i];
    ++i;
  }
  while (j != list2->size) {
    res_data[i + j] = list2->data[j];
    ++j;
  }

  /* replace */
  free(list1->data);
  list1->size = list1->size + list2->size;
  list1->data = res_data;
  res_data = NULL;
}


NumList *ReadList(int list_id) {
  size_t size_of_list = 0;
  printf("Please enter how many numbers in list%d: ", list_id);
  scanf("%ld", &size_of_list);

  NumList *new_num_list = NewNumList(size_of_list);
  /* fail */
  if (!new_num_list) {
    printf("Allocation of a size %ld list failed.\n", size_of_list);
    return NULL;
  }
  printf("  Please input %ld numbers: ", new_num_list->size);
  for (size_t i = 0; i < new_num_list->size; ++i) {
    scanf("%d", new_num_list->data + i);
  }

  return new_num_list;
}


void PrintList(NumList *list) {
  if (!list) {
    putchar('\n');
    return;
  }

  for (size_t i = 0; i < list->size; ++i) {
    printf("%d ", list->data[i]);
  }
  putchar('\n');
}


void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
