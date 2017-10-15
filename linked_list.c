/* 
Queenie Xiang
Systems pd5
HW06: Enlist your C skillz
2017-10-15
*/


#include<stdio.h>
#include<stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node * insert_front(struct node * old_node, int cargo) {
  struct node * new_node;

  new_node = (struct node *) malloc(sizeof(struct node)); 
  new_node->value = cargo;
  new_node->next = old_node;

  return new_node;
}
    
struct node * free_list(struct node * ptr) {  
  while (ptr) {
    struct node * node_removed = ptr;
    ptr = ptr->next;
    
    free(node_removed);
    node_removed = NULL;
    
  }

  return ptr; 
}

void print_list(struct node * ptr) {
  printf("Data in list: \n"); 
  while (ptr) {  
    printf(" %d", ptr->value);
    ptr = ptr->next;
  }
  printf("\n"); 
}

int main() {
  int counter = 1;

  struct node * list = 0;

  list = insert_front(list, 5);

  list = insert_front(list, 100);

  while (counter < 10) {
    list = insert_front(list, counter);
    counter++;
  } 

  printf("All data in list: \n");
  print_list(list);

  list = free_list(list);

  printf("\nFreed list \n"); 
  print_list(list);
    
}
  

    
  






  
  
