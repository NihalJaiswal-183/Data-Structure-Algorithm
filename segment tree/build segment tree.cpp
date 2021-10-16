#include <bits/stdc++.h>
using namespace std;
int tree[4*n+1];

void segmenttree(int tree[],int arr[],int index,int s,int e){

if(s>e){
    return;
}
if(s==e){
    tree[index] =arr[s];
    return;
}
int mid=(s+e)/2;
segmenttree(tree,arr,2*index,s,mid);
segmenttree(tree,arr,2*index+1,mid+1,e);
int left=tree[2*index];
int right=tree[2*index+1];
tree[index]=min(left,right);
}

int query(int tree[],int index,int s,int e,int qs,int qe){
if(qs>e||qe<s){
    return INT_MAX;
}
if(qs==s&&qe==e){
    return tree[index];
}
int mid=(s+e)/2;
int left=query(tree,2*index,s,mid,qs,qe);
int right=query(tree,2*index+1,mid+1,e,qs,qe);
return min(left,right);
}


int main()
{
    int n=6;
    int arr[n]={1,7,9,3,4,-7};


    int index=1;
    int s=0;
    int e=n-1;
    int qs=2;
    int qe=5;
    segmenttree(tree,arr,index,s,e);
    query(tree,index,s,e,qs,qe);
}
    