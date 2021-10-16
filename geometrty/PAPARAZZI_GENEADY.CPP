#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

struct point{
	lli x = 0;
	lli y = 0;
};

point P[500001];
point st[4*500001];

int orientation(point p1, point p2, point p3) 
{
    lli val = (p2.y - p1.y) * (p3.x - p2.x) - 
               (p2.x - p1.x) * (p3.y - p2.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1 : 2; // clock or counterclock wise 
} 




int getAns(int n)
{
	stack<point> st;
	st.push(P[1]) , st.push(P[2]);
	
	for(int i=3;i<=n;i++)
	if(st.size() >= 2)
	{
		while(st.size() >= 2)
		{
			point p2 = st.top();
			st.pop();
			
			point p1 = st.top();
			
			int orient = orientation(p1 , p2 , P[i]);
			if(orient == 1)
			{
				st.push(p2);
				break;
			}
		}
		
		st.push(P[i]);
	}
	
	lli res = 1;
	while(st.size() >= 2)
	{
		point p2 = st.top();
		st.pop();
		
		point p1 = st.top();
		res = max(res , p2.x - p1.x);
	}
	
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t , n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		REP(i , n) cin>>P[i].y , P[i].x = i;
		
		cout<<getAns(n)<<endl;
		
	}
}

