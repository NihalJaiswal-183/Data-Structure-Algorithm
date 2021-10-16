#include<bits/stdc++.h>
using namespace std;


#define pb push_back

class edge{
public:
int src,nbr,wt;
public:
 edge(int x,int y,int z)
{
    this->src=x;
    this->nbr= y;
    this->wt=z;
}
};
class prims{
public:
int v,av,wt;
prims(int x,int y,int z){
    this->v=x;
    this->av=y;
    this->wt=z;
}
};

class myComparator
{
public:
    int operator() (const prims& p1, const prims& p2)
    {
        return p1.wt > p2.wt;
    }
};

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
      vector<edge> adj[n];
 
  while(e--){
      int s,nb,w;
      cin>>s>>nb>>w;
  adj[s].push_back(edge(s,nb,w));
  adj[nb].push_back(edge(nb,s,w));
  }
  int ans=0;
priority_queue<prims, vector<prims>, myComparator> pq;
pq.push(prims(0,-1,0));
bool visited[n+1]={false};
while(pq.size()!=0){
    prims rem=pq.top();
    pq.pop();
    if(visited[rem.v]==true){
        continue;
    }
    visited[rem.v]=true;
    if(rem.av!=-1){
    cout<<"["<<rem.v<<"-"<<rem.av<<"@"<<rem.wt<<"]"<<endl;
    ans+=rem.wt;
    }
    for(auto e:adj[rem.v]){
        if(visited[e.nbr]==false){
            pq.push(prims(e.nbr,rem.v,e.wt));
        }
    }
}
}

// prims algo is used when there is a sparse garph i.e when vertices are greater then edges
// kruskal is used when edges is greater then vertices
// both kruskal and prims are greedy algorithm