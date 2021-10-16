#include<bits/stdc++.h>
using namespace std;
int maxsum(int a[],int adj,int n)
{ 
    if(n<0){
        return 0;
    }
    
    int c=0;
    if(adj!=n+1){
     c=a[n]+maxsum(a,n,n-1);
    }
    int b=maxsum(a,adj,n-1);
    return max(c,b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int ans=maxsum(a,-1,n-1);
    cout<<ans<<endl;
    }
}


//*************************************************************//
#include<bits/stdc++.h>
using namespace std;
long long int maxsum(int a[],int n)
{ 
    long long int dp_inc[n];
    long long int dp_exc[n];
    
    
    dp_inc[0]=a[0];
    dp_exc[0]=0;
    
    for(int i=1;i<n;i++){
        
        int ans=max(dp_inc[i-1],dp_exc[i-1]);
        dp_exc[i]=ans;
        dp_inc[i]=dp_exc[i-1]+a[i];
        
    }
    
    return max(dp_inc[n-1],dp_exc[n-1]);
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
   long long int ans=maxsum(a,n);
    cout<<ans<<endl;
    }
}