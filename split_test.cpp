#include <iostream>
#include "split.h"
using namespace std;

int main (int argc, char *argv[]){
  
  Node* node5 = new Node(5, nullptr);
  Node* node4 = new Node(4, node5);
  Node* node3 = new Node(3, node4);
  Node* node2 = new Node(2, node3);
  Node* node1 = new Node(1, node2);

  Node *odds = nullptr;
  Node *evens = nullptr;

  split(node1, odds, evens);

  while (odds != nullptr){
    cout << odds->value << endl;
    odds = odds->next; 
  }

  while (evens != nullptr){
    cout << evens->value << endl;
    evens = evens->next; 
  }

  delete node5;
  delete node4;
  delete node3;
  delete node2;
  delete node1;
 

}