#ifndef __SET_H_INC
#define __SET_H_INC

/*
  Define the set type.

  Make sure your implementations have a struct set_struct defined.
*/
typedef struct set_struct *set;

/*
  Create a new set. Needs to be freed using set_free
 */
set set_new(void);

/*
  Free a set. Consumes a set created by set_new.
 */
void set_free(set s);

/*
  Add elem to the set s. If elem is already in the set,
  do not mutate s.
 */
void set_add(set s, void *elem);

/*
  Remove elem from the set s. If elem is not in the set,
  print a message to stderr and do not mutate s.
 */
void set_remove(set s, void *elem);

/*
  Test if elem is in the set. If it's not, return 0. If it
  is, return something else.
 */
int set_contains(set s, void *elem);

#endif
