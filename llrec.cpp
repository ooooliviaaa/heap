#include "llrec.h"
#include <iostream> 

using namespace std; 
//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //when the input singly linked list is empty 
  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return; 
  }
  //recursive call so that everything after head is recursively done 
  llpivot(head->next, smaller, larger, pivot);
  //assign head next to smaller and then make smaller as the new head 
  if(head->val <= pivot){
    head->next = smaller;
    smaller = head;
    head = nullptr;
  }
  else{
    head->next = larger;
    larger = head;
    head = nullptr;
  }
}


