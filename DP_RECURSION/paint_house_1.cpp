#include<bits/stdc++.h>
using namespace std;
#define len 3
int minprice(int a[][len],int pre,int n)
{ 
    if(n<0){
        return 0;
    }
    
    int c=INT_MAX;
     for(int i=0;i<3;i++){
         if(pre!=i)
     c=min(c,a[n][i]+minprice(a,i,n-1));
     }

    return c;
}


int main(){
   
    int n;
    cin>>n;
    int a[n][len];
    for(int i=0;i<n;i++){
            for(int j=0;j<3;j++)
               cin>>a[i][j];
    }
    int ans=minprice(a,-1,n-1);
    cout<<ans<<endl;
    }
//*******************************************************************************//
#include<bits/stdc++.h>
using namespace std;
#define len 3
int minprice(int a[][len],int n)
{ 
    int dp[n][len];
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];

    
     for(int i=1;i<n;i++){
    dp[i][0]=min(dp[i-1][1],dp[i-1][2])+a[i][0];
    dp[i][1]=min(dp[i-1][0],dp[i-1][2])+a[i][1];
    dp[i][2]=min(dp[i-1][1],dp[i-1][0])+a[i][2];    
     }
     int c=INT_MAX; 
    for(int k=0;k<3;k++){
     c=min(c,dp[n-1][k]);
     }
    return c;
}


int main(){
   
    int n;
    cin>>n;
    int a[n][len];
    for(int i=0;i<n;i++){
            for(int j=0;j<3;j++)
               cin>>a[i][j];
    }
    int ans=minprice(a,n);
    cout<<ans<<endl;
    }
