#include <bits/stdc++.h>
using namespace std;

long double pi=3.14159265358979323846264338327950;

bool valid(long double num,long double arr[],int n,int f)
{
    int fr=0;
    if (num==0)
        return 0;
    for (int i=0; i<n; i++)
        fr+=(int)(arr[i]/num);
    if (fr>=f)
        return true;
    else
        return false;
}

long double bs(long double arr[],int n,int f)
{
    long double ini=0,last=arr[n-1],max=0.0;
    while (last - ini >= 1e-6)
    {
        long double mid=(ini+last)/2;
        if (valid(mid,arr,n,f))
        {
            
            ini=mid;
        }
        else
            last=mid;
    }
    return ini;
}

int main(){
int t;
cin>>t;
while(t--){
    int n,f;
    cin>>n>>f;
long double arr[n];
int arr1[n];
for(int i=0;i<n;i++){
    cin>>arr1[i];
}
   for (int i=0; i<n; i++)
   arr[i]=arr1[i]*arr1[i]*pi;
   sort(arr,arr+n);
   
   long double k=bs(arr,n,f+1);
        printf("%.4Lf\n",k);
}
}