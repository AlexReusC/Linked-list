#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node* next;
};

void inserta_al_inicio(Node **h, int a){
  Node* tmp = new Node;
  tmp->data = a;
  tmp->next = (*h);
  (*h) = tmp;
}

void inserta_al_final(Node **h, int a){
  Node* tmp = new Node;
  tmp->data = a;
  tmp->next = NULL;
  if(*h == NULL){
    *h = tmp;
    return;
  }

  Node* pos = *h;

  while(pos->next != NULL){
    pos = pos->next;
  }
  pos->next = tmp;
}

void elimina_al_inicio(Node **h){
  if(*h == NULL){
    return;
  }
  Node *tmp = *h;
  *h = tmp->next;
  delete(tmp);
}

void elimina_al_final(Node **h){
  if(*h == NULL){
    return;
  }
  if((*h)->next == NULL){
    delete(*h);
    return;
  }
  Node *pos = *h;
  while(pos->next->next != NULL){
    pos = pos->next;
  }
  delete(pos->next);
  pos->next = NULL;
}

void imprime(Node *h){
  Node *temp = h;
  while(temp != NULL){
    cout<<temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main(){
  int go, num;
  Node* head = NULL;
  while(true){
    cin >> go;
    switch(go){
      case 1:
        cin >> num;
        inserta_al_inicio(&head, num);
        break;
      case 2:
        cin >> num;
        inserta_al_final(&head, num);
        break;
      case 3:
        elimina_al_inicio(&head);
        break;
      case 4:
        elimina_al_final(&head);
        break;
      case 5:
        imprime(head);
        break;
      case 0:
        return 0;
        break;
    }
  }

  return 0;
}
