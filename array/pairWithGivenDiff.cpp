#include <bits/stdc++.h> 
using namespace std;

int findpair(int arr[],int n,int k){
    int i=0;
    int j=1;
    while(i<n && j<n){
        if(arr[j]-arr[i]<k){
            j++;
        }
        else if(arr[j]-arr[i]>k){
            i++;
        }
        else
        {
            return 1;
        }
    }
    return -1;
}


int main() {
    
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    int k;
	    cin>>k;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    cout<<findpair(arr,n,k)<<endl;
}
}