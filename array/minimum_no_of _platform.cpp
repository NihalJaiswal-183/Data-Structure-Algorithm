// brute force approach


#include <iostream>
using namespace std;

int main() {
    
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n],dep[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>dep[i];
	    }
	    int res=0;
	    int curr=1;
	    int l,u;
	    for(int i=0;i<n;i++){
	     l=arr[i];
	     u=dep[i];
	     curr=1;
	     for(int j=i+1;j<n;j++){
	       if(arr[j]>l&&dep[j]<u)
	       curr++;
	         
	     }
	     res=max(res,curr);
	    }
	    
	    cout<<res<<endl;
	    
	}
}


// ****************************************************************
#include <bits/stdc++.h> 
using namespace std;

int main() {
    
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n],dep[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>dep[i];
	    }
	    sort(arr,arr+n);
	    sort(dep,dep+n);
	    int j=0;
	    int res=1;
	    for(int  i=0;i<n;i++){
	        if(arr[i]<dep[j])
	        res++;
	        else{
	            while(dep[j]<arr[i]&&j<n){
	                j++;
	                if(res>1){
	                    res--;
	                }
	            }
	        }
	    }
	    
	    cout<<res<<endl;
	    
	}
}