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

node* insert_node_at_nth_pos(node *head, int data, int position)
{   
    /* current node */
    node* cur = head;

    /* initialize new node to be inserted at given position */
    node* nth = new node(data);

    if(position == 0){
        /* insert new node at head */
        head = nth;
        head->next = cur;
        return head;
    }else{
        /* traverse list */
        int count = 0;            
        node* pre = new node(0);

        while(count != position){
            if(count == (position - 1)){
                pre = cur;
            }
            cur = cur->next;            
            count++;
        }

        /* insert new node here */
        pre->next = nth;
        nth->next = cur;

        return head;
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
  insertAtHead(head,26);
  //deleteAtHead(head);

  head = insert_node_at_nth_pos(head,69,1);
  display(head);
  insertAtTail(head,1);
  deleteAtHead(head);
  deleteAtHead(head);
  display(head);

  return 0;
}

