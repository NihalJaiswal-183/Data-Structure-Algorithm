#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<long long int>&s2, long long int l,long long int r,long long int x) 
{ 
    if (r >= l) { 
       long long int mid = l + (r - l) / 2; 
  
        if (s2[mid]== x) 
            return true; 
  

        if (s2[mid] > x) 
            return binarySearch(s2, l, mid - 1, x); 
  

        return binarySearch(s2, mid + 1, r, x); 
    } 
  
 
    return false; 
} 

int main(){
   long long int n,a,b;
    cin>>n>>a>>b;
   long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<long long int> s1;
    s1.push_back(0);

    vector<long long int> s2;
    s2.push_back(0);
    for(long long int i=0;i<n/2;i++){
       long long int temp=0;
        for(long long int j=i;j<n/2;j++){
          temp+=arr[j];
          s1.push_back(temp);
        }
    }
    for(long long int i=n/2;i<n;i++){
      long long  int temp=0;
        for(long long int j=i;j<n;j++){
          temp+=arr[j];
          s2.push_back(temp);
        }
    }
   long long int n1=s1.size();
    //sort(s1.begin(), s1.end()); 
   long long int n2=s2.size();
   sort(s2.begin(), s2.end()); 
   unsigned long long int count=0;
    for(long long int i=a;i<=b;i++){
     for(long long int j=0;j<n1;j++){
         if(binarySearch(s2,0,n2,i-s1[j])){
             count++;
         }
     }
    }
    cout<<count<<endl;
}