#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e5+7;
int a[maxN];
class node
{
    public:
	int mx_sum;
	int mx1;
	int mx2;
	
	void merge(node left , node right)
	{
		int p[4];
		p[0] = left.mx1;
		p[1] = left.mx2;
		p[2] = right.mx1;
		p[3] = right.mx2;
		sort(p,p+4);
		mx1 = p[3];
		mx2 = p[2];
		mx_sum = mx1+mx2;
	}
}tree[4*maxN];


void build(int id, int left ,int right)
{
	if(left == right)
	{
		tree[id].mx1=a[left]; 
        tree[id].mx2=INT_MIN;
        tree[id].mx_sum=a[left]+INT_MIN; 
		return;
	}
	int mid = (left +right)/2;
	build(2*id , left , mid);
	build(2*id+1,mid+1,right);
	tree[id].merge(tree[2*id],tree[2*id+1]);
}
void update(int id , int left ,int right , int index , int val)
{
	if(left == right)
	{
		tree[id].mx1=val; 
        tree[id].mx2=INT_MIN;
        tree[id].mx_sum=a[left]+INT_MIN; 
		return;
	}
	int mid = (left+right)/2;
	if(index <= mid)
		update(2*id,left,mid,index,val);
	else
		update(2*id+1,mid+1,right,index,val);
	tree[id].merge(tree[2*id],tree[2*id+1]);
}

node query(int id , int left , int right ,int lq ,int rq)
{
	if(right < lq || left > rq){
        node temp;
		return temp;
    }
	if(left >= lq && right <= rq)
	{
		return tree[id];
	}
	int mid = (left+right)/2;
	node n_l = query(2*id,left,mid,lq,rq);
	node n_r = query(2*id+1,mid+1,right,lq,rq);
	node temp;
	temp.merge(n_l,n_r);
	return temp;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n; 
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int m; 
	build(1,0,n-1);
	scanf("%d",&m);
	while(m--)
	{
		char ch; 
		scanf(" %c",&ch);
		if(ch == 'U')
		{
			int i , x; 
			scanf("%d%d",&i,&x);
			i--;
			update(1,0,n-1,i,x);
			//update  
		}
		if(ch == 'Q')
		{
			int l , r; 
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,0,n-1,l-1,r-1).mx_sum);
			//query  
		}
	}
    return 0;
}