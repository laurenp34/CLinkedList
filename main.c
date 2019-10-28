#include <stdlib.h>
#include <stdio.h>

#include "node.h"

int main() {
  //blank node (no next pointer) - for creating nodes w insert_front

  // struct node * n;
  // struct node * o;
  // struct node * p;
  //struct node * q;

  // n.i = 0;
  // o.i = 1;
  // p.i = 2;
  // q.i = 3;

  // // q = insert_front(&blank,3);
  // // printf("created defs\n");
  // q.next = 0;
  // // printf("set next\n");
  // q.i = 3;

  printf("\nTESTING INSERT_FRONT\n");

  printf("New node w/ value %d: ", 4);
  struct node * head = newNode(4);
  print_list(head);

  printf("Insert %d to front", 3);
  struct node *q = insert_front(head,3);
  print_list(q);

  printf("Insert %d to front", 2);
  struct node *p = insert_front(q,2);
  print_list(p);

  printf("Insert %d to front", 1);
  struct node *o = insert_front(p,1);
  print_list(o);

  printf("Insert %d to front,",0);
  struct node *n = insert_front(o,0);
  print_list(n);

  // printf("p->next->i: %d", p->next->i);
  // printf("%d\n",(q.next)->i);

  printf("\nTESTING FREE LIST\n");
  printf("new list: ");
  struct node * headd = newNode(4);
  struct node *qq = insert_front(headd,3);
  struct node *pp = insert_front(qq,2);
  struct node *oo = insert_front(pp,1);
  struct node *nn = insert_front(oo,0);
  print_list(nn);

  nn = free_list(nn);
  print_list(nn);

  printf("\nTESTING REMOVE\n");

  print_list(n);

  // free_list(n);

  //TEST REMOVE LAST ELEMENT
  struct node * new = remove_node(n,4);
  printf("Removing %d: ",4);
  print_list(new);

  //TEST REMOVE MIDDLE ELEMENT
  new = remove_node(new,1);
  printf("Removing %d: ",1);
  print_list(new);

  new = remove_node(new,2);
  printf("Removing %d: ",2);
  print_list(new);

  //TEST REMOVE FIRST ELEMENT
  new = remove_node(new,0);
  // printf("points to: %p\n",new);
  printf("Removing %d: ",0);
  print_list(new);

  //TEST REMOVE ELEMENT NOT IN LIST
  new = remove_node(new,6);
  printf("Removing %d: ",6);
  print_list(new);

  //TEST REMOVE FIRST ELEMENT AND ONLY ELEMENT
  new = remove_node(new,3);
  printf("Removing %d: ",3);
  print_list(new);

  //TEST REMOVE FIRST ELEMENT
  new = remove_node(new,0);
  printf("Removing %d: ",0);
  print_list(new);


  // print_list(n);

  return 0;
}
