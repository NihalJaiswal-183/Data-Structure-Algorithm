// this question was solved by me without any help

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int i=0;
	    int j=n-1;
	    while(i<j){
	        if(a[i]==1){
	            {
	                while(a[j]!=0){
	                    j--;
	                }
	                if(i<j){
	                int temp;
	                temp=a[i];
	                a[i]=a[j];
	                a[j]=temp;
	                j--;
	                }
	            
	            }
	        }
	        
	   i++;
	    }
	    for(int i=0;i<n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
}
}