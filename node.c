#include <stdlib.h>
#include <stdio.h>

#include "node.h"

void print_list(struct node * myNode) {
  //make new node copy, so as not to modify original pointer.
  struct node * newNode = myNode;
  //if current node is null, print nothing!
  if (newNode == NULL) {
    printf("[ ]");
    return;
  }
  //if it's not null:
  printf("[ ");
  //loop which stops once there is no next node.
  while (newNode->next != 0) {
    printf("%d ",newNode->i);
    newNode = newNode->next;
  }
  //there is no next node, but still need to print current (last) node:
   printf("%d]\n",newNode->i);
  //nvm if there is no next
  //printf("]");
  return;
}

struct node * insert_front(struct node * myNode, int val){
  struct node * out = malloc(sizeof(struct node));
  out->next = myNode;
  out->i = val;
  return out;
}
