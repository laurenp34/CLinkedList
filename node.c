#include <stdlib.h>
#include <stdio.h>

// #include <node.h>

struct node {
  int i;
  struct node * next;
};

void print_list(struct node * ) {
  printf("[ ");
  if (node->next != 0) {
    printf("%d ",next->i);
  }
  printf("]\n");
}

int main() {
  struct node n;
  struct node o;
  struct node p;
  struct node q;

  n.i = 0;
  o.i = 1;
  p.i = 2;
  q.i = 3;

  n.next = *o;
  o.next = *p;
  p.next = *q;

  print_list(*n);

  return 0;
}
