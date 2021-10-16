 #include <bits/stdc++.h>
using namespace std;
// a%b=a-b[a/b]
class extEuclidTriplet{
    public:
    int ans;
    int x;
    int y;

};
extEuclidTriplet gcd(int a,int b){
    if(b==0){
        extEuclidTriplet base;
        base.ans=a;
        base.x=1;
        base.y=0;
        return base;

    }
    extEuclidTriplet temp=gcd(b,a%b);
    extEuclidTriplet myans;
    myans.ans=temp.ans;
    myans.x=temp.y;
    myans.y=(temp.x-((a/b)*temp.y));
    return myans;
}

int main(){
    int a,b;
    cin>>a>>b;
extEuclidTriplet fans= gcd(a,b);
cout<<fans.ans<<endl;
cout<<(fans.x%b+b)%b<<endl;
cout<<fans.y<<endl;
}
/*
application of  extended euclid algorithm
1. multiplicative modular inverse
2. modular congruency
*/