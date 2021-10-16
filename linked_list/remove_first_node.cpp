#include <bits/stdc++.h>
using namespace std;


  class node {
    public:
    int data;
    node *next;
  };

 class LinkedList {
     public:
    node *head;
    node *tail;
 
  };
int size=0;

void printlinkedlist(LinkedList *Node){

node *p=Node->head;
int k=size;
while(k--){
    cout<<p->data<<endl;
    p=p->next;
}
}
void removefirst(LinkedList *Node){
    int data=Node->head->data;
   Node->head=Node->head->next;
   size--;
   cout<<"remove data is"<<" "<<data<<endl;
}
void addnode(LinkedList *Node,int data){

node *p=new node;
p->data=data;
p->next=NULL;
if(size==0){
    Node->head=p;
    Node->tail=p;
    size++;
}
else{
    Node->tail->next=p;
    Node->tail=p;
    size++;
}

}  
int main(){
    int data;
    int n;
    cin>>n;
    LinkedList *root;
    root->head=NULL;
    root->tail=NULL;
    while(n--){
        cin>>data;
        addnode(root,data);
    }
    printlinkedlist(root);
    removefirst(root);
    printlinkedlist(root);
}