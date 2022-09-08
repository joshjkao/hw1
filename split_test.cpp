#include <iostream> 
#include "split.h"
using namespace std;

int main() {
  Node* f = new Node(6, NULL);
  Node* e = new Node(5, f);
  Node* d = new Node(4, e);
  Node* c = new Node(3, d);
  Node* b = new Node(2, c);
  Node* a = new Node(1, b);

  Node* curr = a;
  Node* odds = NULL;
  Node* evens = NULL;

  while (curr != NULL) {
    cout << curr->value << " ";
    curr = curr->next;
  }
  cout << endl;

  curr = a;

  split(curr, odds, evens);

  cout << "odds: ";
  while (odds != NULL) {
    cout << odds->value << " ";
    odds = odds->next;
  }
  cout << endl;

  cout << "evens: ";
  while (evens != NULL) {
    cout << evens->value << " ";
    evens = evens->next;
  }
  cout << endl;

  return 0;
}