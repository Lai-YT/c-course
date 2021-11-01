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


ListNode *NewNode(void) {
  ListNode *node = malloc(sizeof(ListNode));
  node->data = 0;
  node->next = NULL;
  node->prev = NULL;
  return node;
}


void DeleteLast(DoublyLinkedList *list) {
  if (IsEmpty(list)) {
    printf("The list is empty\n");
    return;
  }

  ListNode *node_to_delete = list->tail;
  if (list->size == 1) {
    free(node_to_delete);
    list->head = NULL;
    list->tail = NULL;
  } else {
    list->tail = node_to_delete->prev;
    list->tail->next = NULL;
    free(node_to_delete);
  }
  --(list->size);
}


void InsertNode(DoublyLinkedList *list, ListNode *new_node) {
  if (IsEmpty(list)) {
    /* simply set the new node as the first node */
    list->head = new_node;
    list->tail = new_node;
  } else {
    ListNode *curr_node = list->tail;
    while (curr_node && new_node->data < curr_node->data) {
      /* haven't find the position yet */
      curr_node = curr_node->prev;
    }
    if (!curr_node) {
      /* add to the head */
      new_node->next = list->head;
      new_node->next->prev = new_node;
      list->head = new_node;
    } else if (curr_node == list->tail) {
      /* add to the tail */
      new_node->prev = list->tail;
      list->tail->next = new_node;
      list->tail = new_node;
    } else {
      /* normal insertion: insert to the next of the curr node */
      new_node->next = curr_node->next;
      curr_node->next = new_node;
      new_node->prev = curr_node;
      new_node->next->prev = new_node;
    }
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
  printf("  list->size: %ld\n", list->size);
  printf("  numbers: ");
  ListNode *curr = list->head;
  while (curr) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  putchar('\n');
}
