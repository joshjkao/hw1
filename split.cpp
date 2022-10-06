/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == NULL) {  //base case: no more nodes to process
    if (odds != NULL) odds->next = NULL;
    if (evens != NULL) evens->next = NULL;
    return;
  }
  else {
    Node* temp = in->next;
    if (in->value % 2 == 0) {  //recurvise case: even node
      if (evens == NULL) {
        evens = in;
        in = NULL;
        split(temp, odds, evens);
      }
      else {
        evens->next = in;
        in = NULL;
        split(temp, odds, evens->next);
      }
    }
    else {  //recursive case 2: odd node
      if (odds == NULL) {
        odds = in;
        in = NULL;
        split(temp, odds, evens);
      }
      else {
        odds->next = in;
        in = NULL;
        split(temp, odds->next, evens);
      }
    }
    
  }

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE