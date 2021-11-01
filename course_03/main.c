#include <stdio.h>

#include "linked_list.h"


/**
 * Infinite loop reads numbers, creates and inserts nodes into a list.
 *
 * The list is kept sorted.
 * Key in -2 to delete the last node of the list,
 * -1 to end the infinite loop.
 */
int main(int argc, char const *argv[]) {
  const int EXIT_CODE = -1;
  const int DEL_CODE  = -2;

  DoublyLinkedList *list = NewList();
  int input_num = 0;
  while (1) {
    printf("Input a number (%d to exit, %d to delete last): ",
           EXIT_CODE, DEL_CODE);
    scanf("%d", &input_num);

    if (input_num == EXIT_CODE) {
      break;
    }

    if (input_num == DEL_CODE) {
      DeleteLast(list);
    } else {
      /* read in a new node and insert into list */
      ListNode *new_node = NewNode();
      new_node->data = input_num;
      InsertNode(list, new_node);
    }
    PrintList(list);
    /* extra new line for separation */
    putchar('\n');
  }
  FreeList(list);

  return 0;
}
