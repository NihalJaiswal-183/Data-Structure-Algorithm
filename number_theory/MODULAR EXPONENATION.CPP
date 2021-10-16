#include <bits/stdc++.h>
using namespace std;

int exp(int a,int b,int c){
    if(b==0){
        return 1;

    }
    if(b%2==0){
    int temp=exp(a,b/2,c);
    return (temp%c*temp%c)%c;

    }
    else{
     int temp=exp(a,b/2,c);
     return (a%c*temp%c)%c;
    }
   
}
*******
int main(){
    int a,b,c;
    cin>>a>>b>>c;
cout<<exp(a,b,c)<<endl;
}
// time complexity  O(log(b))
// space complexity O(log(b))