#include<bits/stdc++.h> 
using namespace std;
int ma=INT_MIN;


void LIS(int arr[], int n, int prev,int l,int i)
{
  if(n<i|| arr[i]<prev){
   if(ma<l){
       ma=l;
   }
  return;
  }
 
  LIS(arr,n,arr[i],l+1,i+1);
  LIS(arr,n,prev,l,i+1);
 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
  
	LIS(arr, n,INT_MIN,0,0);
     cout<<ma;
    }
}