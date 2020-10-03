#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node* next;
};

int main(){
  Node* head = new Node;
  Node* temp = new Node;

  temp->data = 3;
  temp->next = NULL;

  head = temp;

  cout << head->data;

  return 0;
}
