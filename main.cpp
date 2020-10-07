/*
Alejandro Castro Reus-A01731065
Fecha de entrega: 07/10/2020

Programa que crea una lista enlazada lineal y permite aniadir nuevos nodos
al principio y al final, eliminar los nodos ya existentes al inicio al final.
Tambien permite imprimirlos y borra la lista al terminar el programa
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node* next;
};

//Inserta un nodo al inicio, recibe un pointer de pointer nodo y un entero
//no regresa nada
//O(1)
void inserta_al_inicio(Node **h, int a){
  Node* tmp = new Node;
  tmp->data = a;
  tmp->next = (*h);
  (*h) = tmp;
}

//Inserta un nodo al final, recibe un pointer de pointer nodo y un entero
//no regresa nada
//O(n)
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

//Elimina un nodo al inicio, recibe un pointer de pointer nodo
//no regresa nada
//O(1)
void elimina_al_inicio(Node **h){
  if(*h == NULL){
    cout << "ERROR" << endl;
    return;
  }
  if((*h)->next == NULL){
    delete(*h);
    *h = NULL;
    return;
  }
  Node *tmp = *h;
  *h = tmp->next;
  delete(tmp);

}

//Elimina un nodo al final, recibe un pointer de pointer nodo
//no regresa nada
//O(n)
void elimina_al_final(Node **h){
  if(*h == NULL){
    cout << "ERROR" << endl;
    return;
  }
  if((*h)->next == NULL){
    delete(*h);
    *h = NULL;
    return;
  }
  Node *pos = *h;
  while(pos->next->next != NULL){
    pos = pos->next;
  }
  delete(pos->next);
  pos->next = NULL;
}

//Imprime los nodos, recibe un pointer de Node y no regresa nada
//O(n)
void imprime(Node *h){
  Node *temp = h;
  while(temp != NULL){
    cout<<temp->data << endl;
    temp = temp->next;
  }
}

void deleteStuff(Node *h){
  Node *curr = h;
  Node *prev = h;
  while(curr != NULL){
    curr = curr->next;
    delete(prev);
    prev = curr;
  }
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
        deleteStuff(head);
        return 0;
        break;
    }
  }
  return 0;
}
