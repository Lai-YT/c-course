#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


bool IsEmpty(DoublyLinkedList *list) {
  return list->size == 0;
}


DoublyLinkedList *NewList(void) {
  DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}


ListNode *NewNode(int data) {
  ListNode *node = malloc(sizeof(ListNode));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}


void DeleteNode(DoublyLinkedList *list, int delete_pos) {
  if (IsEmpty(list)) {
    printf("the list is empty\n");
    return;
  }

  if (delete_pos == 1) {
    /* delete head */
    ListNode *node_to_delete = list->head;
    if (list->size == 1) {
      /* it's the last one */
      free(node_to_delete);
      list->head = NULL;
      list->tail = NULL;
    } else {
      list->head = node_to_delete->next;
      list->head->prev = NULL;
      free(node_to_delete);
    }
  } else if (delete_pos == list->size) {
    /* Delete tail. Can't be also the head since it's handled. */
    ListNode *node_to_delete = list->tail;
    list->tail = node_to_delete->prev;
    list->tail->next = NULL;
    free(node_to_delete);
  } else {
    /* delete from the middle */
    int curr_pos = 2;
    ListNode *curr = list->head->next;
    /* find the pos */
    while (curr_pos != delete_pos) {
      curr = curr->next;
      ++curr_pos;
    }
    /* delete the curr node */
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    printf("break\n");
    free(curr);
  }
  --(list->size);
}


void InsertNode(DoublyLinkedList *list, ListNode *new_node, int insert_pos) {
  if (insert_pos < 1 || insert_pos > (list->size + 1)) {
    printf("insert_pos out of range\n");
    return;
  }

  if (insert_pos == 1) {
    /* add to the head */
    if (IsEmpty(list)) {
      list->head = new_node;
      list->tail = new_node;
    } else {
      new_node->next = list->head;
      new_node->next->prev = new_node;
      list->head = new_node;
    }
  } else if (insert_pos == (list->size + 1)) {
    /* Add to the tail. Can't be also the head since it's handled. */
    new_node->prev = list->tail;
    new_node->prev->next = new_node;
    list->tail = new_node;
  } else {
    /* insert in the middle */
    int curr_pos = 2;
    ListNode *curr = list->head->next;
    /* find the pos */
    while (curr_pos != insert_pos) {
      curr = curr->next;
      ++curr_pos;
    }
    /* insert as the previous node of curr */
    curr->prev->next = new_node;
    new_node->prev = curr->prev;
    curr->prev = new_node;
    new_node->next = curr;
  }
  ++(list->size);
}


void FreeList(DoublyLinkedList *list) {
  ListNode *curr = list->head;
  /* free all nodes */
  while (curr) {
    ListNode *temp = curr;
    curr = curr->next;
    free(temp);
  }
  /* free list itself */
  free(list);
  list = NULL;
}


void PrintList(DoublyLinkedList *list) {
  printf("  size: %ld\n", list->size);
  /* from head to tail */
  printf("  from head: ");
  ListNode *curr = list->head;
  while (curr) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  putchar('\n');
  /* from tail to head */
  printf("  from tail: ");
  curr = list->tail;
  while (curr) {
    printf("%d ", curr->data);
    curr = curr->prev;
  }
  putchar('\n');
}
