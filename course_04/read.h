
#ifndef ENUM_ACTION
#define ENUM_ACTION

/* the actions for the user to choose */
enum Action {
  ACT_EXIT = 0,
  /* acts on the linked-list */
  ACT_ADD,
  ACT_DEL,
};

#endif /* end of include guard: ENUM_ACTION */


#ifndef ENUM_POSITION
#define ENUM_POSITION

/* the position of the node to perform action */
enum Position {
  POS_BEFORE = 1,
  POS_AFTER,
};

#endif /* end of include guard: ENUM_POSITION */

/**
 * Returns the action read from the console.
 *
 * May not be any of the enum Action, make sure you double checked.
 */
int ReadAction(void);

/**
 * Returns the number read from the console.
 */
int ReadNumber(void);

/**
 * Returns the position from the console, which is simply a number.
 */
int ReadTargetPosition(void);

/**
* Returns the position read from the console.
*
* May not be any of the enum Position, make sure you double checked.
*/
int ReadPositionAdjustment(int position);
