#include <bits/stdc++.h> 
using namespace std;

int findsum(long long int arr[],long long int n,int k){
    long long int currsum=arr[0];
    long long int j=0;
     for(long long int i=1;i<=n;i++){
      
     while(currsum>k && j<i-1){
         currsum=currsum-arr[j];
         j++;
     }
     if(currsum==k){
         cout<<j+1<<" "<<i<<endl;
         return 0;
     }
     
     if(i<n){
         currsum+=arr[i];
     }
     }
     return 1;
}

int main() {
    
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int arr[n];
	    int k;
	    cin>>k;
	    for(long long int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int ans=findsum(arr,n,k);
	    if(ans){
	        cout<<"-1"<<endl;
	    }
}
}