#include <bits/stdc++.h>
using namespace std;

vector<int> s1;
int generate_subsets(long long int arr[],long long int n){
     
     for(int i=0;i<(1<<n);i++){
         int sum=0;
          for (int j = 0; j <(1<<n) ; j ++) {
                if (i & (1 << j)) 
                sum += arr[j];
            }
         s1.push_back(sum);
     }
}


int main(){
   long long int n,a,b;
    cin>>n>>a>>b;
   long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    generate_subsets(arr,n/2);
    sort(s1.begin(), s1.end()); 
    n=n-n/2;
   unsigned long long int count=0;
    for(long long int s=a;s<=b;s++){
     for(int i=0;i<(1<<n);i++){
         int sum=0;
          for (int j = 0; j <(1<<n) ; j ++) {
                if (i & (1 << j)) 
                sum += arr[j+n/2];
            }
         int low=lower_bound(s1.begin(), s1.end(), s-sum)  - s1.begin(); 
         int high=upper_bound(s1.begin(), s1.end(), s-sum)  - s1.begin(); 
         count+=high-low;

     }
    }
    cout<<count<<endl;
}