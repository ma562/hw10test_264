// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL) // the linked list must end with NULL
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
// the linked list must end with NULL
ListNode * createList(int valn)
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* new_head = head; 

  for(int k=0; k< valn -1; k++){
    new_head->value = k;
    new_head->next = malloc(sizeof(ListNode));
    new_head = new_head->next;
  }
  new_head->value = valn -1;
  new_head->next = NULL;
  return head;
}

#endif


#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  ListNode* ptr = head;
  int counter;

  while((head->next) != NULL){
    counter = 0;
    while(counter < valk){
      if(ptr != NULL){
        counter++;
      }
      ListNode* new_ptr = ptr->next;
      if(counter == valk){

      

#ifdef DEBUG
  // this #ifdef ... #endif should be inside the condition *BEFORE* a
  // node' value is printed and it is deleted
        ListNode * todelete = p;
        printListNode (todelete); 
#endif
        printf("%d\n", ptr->value);
        head = deleteNode(head,ptr);
      }
      if(new_ptr != NULL){
        ptr = new_ptr;
      }
      else{
        ptr = head;
      }
    }
  }
  printf("%d\n", head->value);
  free(head);
}
#endif



#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  if(head == NULL){
    return NULL;
  }

  if(todelete == NULL){
    return head;
  }

  if(head == todelete){
    ListNode* ptr = head->next;
    free(head);
    return ptr;
  }
  ListNode* ptr = head; 
  while((ptr != NULL) && ((ptr->next) != todelete)){
    ptr = ptr->next;

  }
  if(ptr != NULL){
    ptr->next = todelete->next;
    free(todelete);
  }
  return head;
}
#endif


