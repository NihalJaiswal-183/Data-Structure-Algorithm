#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1e9+7;
vector<bool> isprime(500005,true);
vector<ll> primes;

void gen_primes(ll max_limit){
    isprime[0]=isprime[1]=false;
    for(ll i=2;i*i<=max_limit;i++){
        if(isprime[i]){
            for(int j=i*i;j<=max_limit;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(int i=0;i<=max_limit;i++){
        if(isprime[i]){
            primes.push_back(i);
        }
    }
}

void segmented_sieve(ll a,ll b){
    vector<bool> segmented(b-a+1,true);
    if(a==1){
        a++;
    }
    for(int i=0;primes[i]*primes[i]<=b;i++){
        ll p=primes[i];
        ll j=(a/p)*p;
        if(j<a){
            j+=p;
        }
        // j is the first multiple
        for(;j<=b;j+=p){
            if(j!=p)
            segmented[j-a]=false;
        }
    }
    for(ll i=a;i<=b;i++){
        if(i==1) continue;
        if(segmented[i-a]==true){
            cout<<i<<endl;
        }

    }
}

ll divisoroffact(ll n){
    ll result =1;
    for(int i=0; primes[i]<=n;i++){
        ll k=primes[i];
        ll count =0;
        while((n/k)!=0){
            count=(count+(n/k)%mod)%mod;
            k=k*primes[i];
        }
        result=((result%mod)*(count+1)%mod)%mod;
    }
    return result;
}
int main(){
gen_primes(500001);
int t;
cin>>t;
while(t--){
    ll n,m;
    cin>>n>>m;
    segmented_sieve(n,m);
    cout<<endl;

}
}