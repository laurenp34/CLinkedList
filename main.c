#include <stdlib.h>
#include <stdio.h>

#include "node.h"

int main() {
  //blank node (no next pointer) - for creating nodes w insert_front
  struct node blank;
  blank.next = 0;
  blank.i = 5;

  struct node * n;
  struct node * o;
  struct node * p;
  struct node * q;

  // n.i = 0;
  // o.i = 1;
  // p.i = 2;
  // q.i = 3;

  q = insert_front(&blank,3);
  p = insert_front(q,2);
  o = insert_front(p,1);
  n = insert_front(o,0);

  // printf("%d\n",(q.next)->i);
  print_list(n);

  return 0;
}
