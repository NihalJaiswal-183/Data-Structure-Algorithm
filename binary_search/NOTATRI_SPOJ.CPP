#include <bits/stdc++.h>
using namespace std;

long long int bsearch(vector<long long int>&s1,int c)
{

int start=0;
int end=s1.size()-1;
   long long int res = 0;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (s1[mid]<c)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return res+1;
}

int main(){
    bool flag=true;
    while(flag==true){
    int n;
    cin>>n;
    if(n==0){
        flag=false;
    }
    else{
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<long long int>s1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              s1.push_back(arr[i]+arr[j]);
            }
        }
        sort(s1.begin(),s1.end());
       long long int count=0;
        for(int i=0;i<n;i++){
            count+=bsearch(s1,arr[i]);
        }
    }
    
    }
  
}