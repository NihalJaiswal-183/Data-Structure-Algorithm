#include <bits/stdc++.h> 
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int count=1;
	    int mje=a[0];
	    for(int i=1;i<n;i++){
	       if(a[i]==mje){
	           count++;
	       }
	       else if(a[i]!=mje && count==1)
	    {
	        mje=a[i];
	        count =1;
	    }
	    
	    else{
	        count--;
	    }
	    }
	   
	    count=0;
	    for(int i=0;i<n;i++){
	        if(a[i]==mje){
	        count++;
	        }
	    }
	  
	    if(count>(n/2)){
	        cout<<mje<<endl;
	    }
	    else{
	        cout<<"-1"<<endl;
	    }
	    }
}
	    
	    