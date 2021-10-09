
#include<bits/stdc++.h>
using namespace std;


class node{
  public:
    int data;
    node* next;
    node(int data){
      this->data=data; 
      next=NULL;
    }
};

void insertAtHead(node* &head, int val){
  node* nw=new node(val);
  nw->next=head;
  head=nw;
}

void insertAtTail(node* &head, int val){
  node* nw=new node(val);
  if(head==NULL){
    head=nw;
    return;
  }
  node* temp=head;
  while(temp->next!=NULL)
    temp=temp->next;
  temp->next=nw;
}

void deleteAtHead(node* &head){
  if(head==NULL)
    return;
  node* todelete=head;
  head=head->next;
  delete todelete; 
  todelete=NULL; 
}

void deleteVal(node* &head, int val){
  if(head==NULL)
    return;
  if(head->data==val){
    deleteAtHead(head);
    return;
  }
  node*temp=head;
  bool found=false;
  while((temp!=NULL) && (temp->next!=NULL)){
    if(temp->next->data==val){
      found=true;
      break;
    }
    temp=temp->next;
  }
  if(found){
    node* todelete=temp->next;
    temp->next=todelete->next;
    delete todelete;
    todelete=NULL;
  }
}


bool search(node* head, int key){
  while(head!=NULL){
    if(head->data==key)
      return true;
    head=head->next;
  }
  return false;
}


void display(node* head){
  while(head!=NULL){
    cout<<head->data<<" --> ";
    head=head->next;
  }
  cout<<endl;
}


int main(){
  node* head=NULL;
  deleteAtHead(head);
  display(head);
  insertAtTail(head,1);
  deleteAtHead(head);
  deleteAtHead(head);
  display(head);

  return 0;
}