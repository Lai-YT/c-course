#include <stdbool.h>

/**
 * A doubly linked node.
 */
typedef struct ListNode {
  int data;
  struct ListNode *next;
  struct ListNode *prev;
} ListNode;

/**
 * A double-sided linked list for doubly linked nodes.
 */
typedef struct {
  ListNode *head;
  ListNode *tail;
  size_t size;
} DoublyLinkedList;

/**
 * Returns true if the size of the list is 0.
 */
bool IsEmpty(DoublyLinkedList *list);

/**
 * Returns a newly allocated empty list.
 */
DoublyLinkedList *NewList(void);

/**
 * Returns a newly allocated node with data 0.
 */
ListNode *NewNode(void);

/**
 * This function assumes that the numbers inside list is already sorted
 * so only inserts the new node to its corresponding position.
 */
void InsertNode(DoublyLinkedList *list, ListNode *new_node);

/**
 * Deletes the frees the last node from the list.
 * Safe when the list is empty.
 */
void DeleteLast(DoublyLinkedList *list);

/**
 * Deallocates the list itself and every of its nodes.
 */
void FreeList(DoublyLinkedList *list);

/**
 * Prints the whole list.
 */
void PrintList(DoublyLinkedList *list);
