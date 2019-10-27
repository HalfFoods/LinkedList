#include "LinkedList.h"

void print_list(struct node * n){
  printf("[ ");
  while(n){
    printf("%d ", n->i);
    n = n->next;
  }
  printf("]\n");
}

struct node * insert_front(struct node * n, int val){
  struct node * front = malloc(sizeof(struct node));
  front->i = val;
  front->next = n;
  return front;
}

struct node * free_list(struct node * n){
  struct node * p = n;
  while(n){
    p = p->next;
    printf("freeing node: %d\n", n->i);
    free(n);
    n = p;
  }
  return n;
}

struct node * remove_node(struct node *front, int data){
  if (!front){
    return front;
  }
  if (front->i == data){
    struct node * ans = front->next;
    free(front);
    return ans;
  }
  front->next = remove_node(front->next, data);
  return front;
}
