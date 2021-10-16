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
while(size--){
    cout<<p->data;
    p=p->next;
}
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
}