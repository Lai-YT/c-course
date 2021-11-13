#include <stdbool.h>


#ifndef LINKED_LIST
#define LINKED_LIST

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

#endif /* end of include guard: LINKED_LIST */


/**
 * Returns true if the size of the list is 0.
 */
bool IsEmpty(DoublyLinkedList *list);

/**
 * Returns a newly allocated empty list.
 */
DoublyLinkedList *NewList(void);

/**
 * Returns a newly allocated node with data.
 */
ListNode *NewNode(int data);

/**
 * Inserts the new_node into the insert_pos. insert_pos starts from 1.
 *
 * If insert_pos is the size of list + 1, the new_node is inserted to the tail.
 * Safe to have insert_pos non-positive or greater than the size of list.
 */
void InsertNode(DoublyLinkedList *list, ListNode *new_node, int insert_pos);

/**
 * Deletes the node on delete_pos. delete_pos starts from 1.
 *
 * Safe to have delete_pos non-positive or greater than the size of list.
 */
void DeleteNode(DoublyLinkedList *list, int delete_pos);

/**
 * Deallocates the list itself and every of its nodes.
 */
void FreeList(DoublyLinkedList *list);

/**
 * Prints the whole list in 2 ways:
 * from head to tail and from tail to head.
 */
void PrintList(DoublyLinkedList *list);
