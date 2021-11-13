#include <stdio.h>

#include "linked_list.h"
#include "read.h"


int main(int argc, char const *argv[]) {
  DoublyLinkedList *list = NewList();
  while (1) {
    int input_act = ReadAction();

    /* exit the while loop and go free list */
    if (input_act == ACT_EXIT) {
      break;
    }
    switch (input_act) {
      case ACT_ADD:
        ;  /* to fix error: a label can only be part of a statement and a
              declaration is not a statement */
        /* read in the new node */
        int number = ReadNumber();
        ListNode *new_node = NewNode(number);
        /* read in the position */
        int insert_pos = 0;
        if (IsEmpty(list)) {
          insert_pos = 1;
        } else {
          /* read in position to insert */
          insert_pos = ReadTargetPosition();
          /* error handle */
          if (insert_pos < 1 || insert_pos > list->size) {
            printf("error: position out of range\n");
            break;
          }
          /* adjust pos */
          int pos_adjust = ReadPositionAdjustment(insert_pos);
          if (pos_adjust == POS_BEFORE) {
            ;  /* don't need adjustment */
          } else if (pos_adjust == POS_AFTER) {
            ++insert_pos;
          } else {
            printf("error: no such choice\n");
            break;
          }
        }
        /* do the insertion */
        InsertNode(list, new_node, insert_pos);
        break;
      case ACT_DEL:
        ;  /* to fix error: a label can only be part of a statement and a
              declaration is not a statement */
        int delete_pos = ReadTargetPosition();
        /* error handle */
        if (delete_pos < 1 || delete_pos > list->size) {
          printf("error: position out of range\n");
          break;
        }
        DeleteNode(list, delete_pos);
        break;
      default:
        printf("error: no such choice\n");
        break;
    }
    putchar('\n');
    PrintList(list);
  }
  FreeList(list);

  return 0;
}
