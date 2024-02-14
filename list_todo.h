#include "container.h"
class List: public Container{
  public:
    Node* head;
    int size;
    List(){
      head=NULL;
      size=0;
    }
    List(int v){
      head = new Node(v);
      size = 1;
    }
    List(List& l){
      Node * w = l.head;
      Node * nW = new Node(w->value); 
      w = w-> next;
      while(w != NULL)
      {
        nW -> next = new Node(w->value);
        
      }

    }
    ~List(){
      while(head != NULL)
      {
        pop();
        size -= 1;
      }
      
    }
    void add(int v)
    {
      Node * w = head;
      if(head ==  NULL)
      {
        head = new Node(v);
        size = 1; 
        return;
      }
      while(w -> next != NULL)
      {
        w = w -> next;
      }
      w -> next = new Node(v);
    }
    int pop(){
      Node * w = head;
      Node * f = NULL;
      int p;
      if(w == NULL)
        return 0;
      if(w -> next == NULL)
      {
        head =  NULL;
        p = w-> value;
        free(w);
        size = 0;
        return p;
      }
      while(w->next!= NULL)
      {
        f = w;
        w = w -> next;
      }
      f ->next = NULL;
      p = w->value;
      free(w);
      size -= 1;
      return p;

    }
    bool operator==(const List& rhs){
      Node * r = head;
      Node * l = rhs.head;

      while(r != NULL && l != NULL)
      {
        if(r->value != l->value)
          return false;
        r = r -> next;
        l = l -> next;
      }
      if(r == NULL && l == NULL)
        return true;
      else
        return false;
    }
    bool operator!=(const List& rhs){
      Node * r = head;
      Node * l = rhs.head;

      while(r != NULL && l != NULL)
      {
        if(r->value != l->value)
          return true;
        r = r -> next;
        l = l -> next;
      }
      if(r == NULL && l == NULL)
        return false;
      else
        return true;
    }
    friend ostream& operator<<(ostream& os, List& l);
};
ostream& operator<<(ostream& os, List& l){
    Node * w = l.head;
    while(w != NULL)
    {
      os<<w->value<<",";
      w = w->next;
    }
    os << "Null";
    return os;
}
