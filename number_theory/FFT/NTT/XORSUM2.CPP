#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mod = 998244353;
typedef long long ll;
ll fact[N], a[N];
ll power(ll x, ll y, ll p)
{
	ll res = 1;
	x = x % p;
	while (y > 0)
    {
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res%p;
}
ll nCr(int n,int r)
{
    if(n < r)
        return 0;
    return ((ll)fact[n]*power((fact[r]*fact[n - r])%mod, mod - 2, mod))%mod;
}
void ntt(vector<ll> &a, bool invert) {
    int n = a.size();
    int i, j, k;
    for (i = n>>1,j = 1; j < n-1; j++) {
        if(i >j)
            swap(a[i],a[j]);
        for(k = n >>1;k <= i;k >>= 1)
            i ^= k;i ^= k;
    }
    for (int len = 2; len <= n; len <<= 1){
        ll wlen = 1;
        if(invert)
            wlen = power(3, (mod-1)/len, mod); // 3 is primitive root of mod = 998244353
        else
            wlen = power(3, (mod-1)/len*(len - 1), mod);
        for (i = 0; i < n; i += len) {
            ll w = 1;
            for (j = i; j < i + (len >> 1); j++) {
                ll u = a[j], v = a[j + (len >> 1)] * w % mod;
                a[j] = (u + v); a[j] = (a[j] >= mod) ? a[j] - mod : a[j];
                a[j + (len>>1)] = (u - v); a[j + (len>>1)] = (a[j + (len>>1)] < 0) ? a[j + (len>>1)] + mod : a[j + (len>>1)];
                w = w * wlen % mod;
            }
        }
    }
    if (invert) {
        const int x = power(n, mod - 2, mod);
        for (int i = 0; i < n; i++) {
            a[i] = a[i] * x % mod;
        }
    }
}
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n <= a.size() + b.size() - 2)
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; i++)
    {
        fa[i] *= fb[i];
        fa[i] %= mod;
    }
    ntt(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = round(fa[i]);
        //result[i] = round(fa[i].real());
        //result[i] %= mod;
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("xorsum2.txt","r",stdin);
    int i, j, k;
    fact[0] = fact[1] = 1;
    for(i = 2; i < N;i++)
    {
        fact[i] = fact[i - 1]*i;
        fact[i] %= mod;
    }
    int n, q;
    scanf("%d",&n);
    for(i = 0;i< n;i++)
        scanf("%lld", &a[i]);
    ll ans[n + 1];
    int freq[30];
    for(i = 0; i <= n;i++)
        ans[i] = 0;
    for(i = 0;i < 30;i++) freq[i] = 0;
    for(i = 0; i < n;i++)
    {
        for(j = 0;j < 30;j++)
        {
            if(a[i]&(1 << j))
                freq[j] += 1;
        }
    }
    for(j = 0;j < 30;j++)
    {
        vector<ll> ones(freq[j]+1), zeroes(n - freq[j] + 1);
        ones[0] = 0;
        for(i = 1;i <= freq[j];i += 2)
            ones[i] = nCr(freq[j], i);
        for(i = 0;i <= n - freq[j];i++)
            zeroes[i] = nCr(n - freq[j], i);
        vector<ll> coeff = multiply(ones, zeroes);
        /*for(i = 0;i <= freq[j]; i++)
            cout<<ones[i]<<" ";
        cout<<endl;
        for(i = 0; i <= n - freq[j];i++)
            cout<<zeroes[i]<<" ";
        cout<<endl;
        for(auto &e: coeff)
            cout<<e<<" ";
        cout<<endl;*/
        for(i = 0;i <= n;i++)
            ans[i] = (ans[i] + (coeff[i]*(1 << j))%mod)%mod;
        //for(i = 0; i <= n;i++)
          //  cout<<ans[i]<<" ";
        //cout<<"\n"<<endl;
    }
    for(i = 1;i <= n;i++)
        ans[i] = (ans[i] + ans[i - 1])%mod;
    //for(int i = 0; i <= n;i++)
      //  cout<<ans[i]<<'\n';
    //return 0;
    scanf("%d",&q);
    while(q--)
    {
        int m;
        scanf("%d",&m);
        printf("%lld\n",ans[m]);
    }
    return 0;
}
