#include <stdlib.h>
#include <stdio.h>

#include "node.h"

struct node* newNode(int value) {
  struct node *myNode;
  myNode = (struct node*)malloc(sizeof(struct node));
  myNode->i = value;
  myNode->next = NULL;
  return myNode;
}

void print_list(struct node * myNode) {
  //make new node copy, so as not to modify original pointer.
  struct node * newNode = myNode;
  //if current node is null, print nothing!
  if (newNode == NULL) {
    printf("[ ]\n");
    return;
  }
  //if it's not null:
  printf("[ ");
  //loop which stops once there is no next node.
  while (newNode->next != NULL) {
    printf("%d ",newNode->i);
    newNode = newNode->next;
  }
  //there is no next node, but still need to print current (last) node:
   printf("%d ]\n",newNode->i);
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

struct node * free_list(struct node * myNode) {
  //create helper so that freeing nodes doesnt create problems (w pointer)
  struct node * helper = myNode;
  struct node * helper2 = helper;

  while (helper->next != NULL) {
    helper2 = helper2->next;
    //printf("freeing: %d",helper->i);
    free(helper);
    //helper is now bleh so helper2 still points to valid pointer
    helper = helper2;
  }
  //at the end, you get to a node that doesnt have a next but still needs to be freed.
  //printf("freeing: %d",helper->i);
  free(helper);

  //make sure orig starting is now null
  myNode = NULL;

  return myNode;
}

struct node * remove_node(struct node *myNode, int data) {
  struct node * helper = myNode;
      //printf("\tfirst: %d\tpointer: %p",helper->i, helper);

  //first check to see that myNode isn't null:
  if (myNode==NULL) {
    return myNode;
  }

  //condition 1: first node contains data.
  if (helper->i == data) {
    //printf("first element!\n");
    //condition 1.5: first node is a lonely node- doesn't have a next
    if (helper->next == NULL) {
      free(helper);
      return NULL;
    }
    myNode = myNode->next;
    free(helper);
    // printf("\tnew first: %d\tpointer: %p",myNode->i, myNode);
    return myNode;
  }

  //not first node; iterate through list.
  struct node * prev;
  while (helper->next != NULL) {
    //condition 2: in middle of list
    if (helper->i == data) {
        //helper is current node (the one that has data)
        //prev is the one before helper
        //ik we didn't define prev necessarily, but this is guaranteed not to be the
        //first run of the loop, so prev will be defined by now.
        prev->next = helper->next;
        free(helper);
        return myNode; //still return the first node
    }
    //you did not find data on this run unfortunately
    prev = helper;
    helper = helper->next;
  }

  //you got to the end of the list (the last node! - next = nothing)
  //condition 3: at very end of list
  if (helper->i == data) {
    //printf("last element!\n");
    //prev still exists! - and is still 1 behind helper
    prev->next = NULL;
    //printf("setprev\n");
    //printf("freeing: %d\n", helper->i);
    free(helper);
    return myNode;
  }
  //printf("not found");
  //printf("\tfirst: %d\t",myNode->i);
  //condition 4: data not found at all.
  return myNode;
}
