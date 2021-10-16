#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;

    }
    int temp=min(b,a);
    int temp1=max(a,b);
    return gcd(temp,temp1%temp);
}
int lcm(int a,int b){
    int temp=gcd(a,b);
    int ans=(a*b)/temp;
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
cout<<gcd(a,b)<<endl;
cout<<lcm(a,b);

}

// time complexity log(min(a,b)), where base is phi which is golden ratio;