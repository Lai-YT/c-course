#include <stdio.h>

#include "read.h"


int ReadAction(void) {
  int action = 0;
  printf("------\n");
  printf("(%d) Add or (%d) Delete a number, (%d) Exit: ",
         ACT_ADD, ACT_DEL, ACT_EXIT);
  scanf("%d", &action);
  return action;
}


int ReadNumber(void) {
  int number = 0;
  printf("  Add a number: ");
  scanf("%d", &number);
  return number;
}


int ReadTargetPosition(void) {
  int pos = 0;
  printf("    Specify a target position: ");
  scanf("%d", &pos);
  return pos;
}


int ReadPositionAdjustment(int position) {
  int adjustment = 0;
  printf("    (%d) Before or (%d) After position %d: ",
         POS_BEFORE, POS_AFTER, position);
  scanf("%d", &adjustment);
  return adjustment;
}
