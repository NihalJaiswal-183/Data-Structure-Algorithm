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
      vector<edge> adj[7];
  adj[0].push_back(edge(0,1,10));
  adj[0].push_back(edge(0,3,10));
  adj[1].push_back(edge(1,0,10));
  adj[1].push_back(edge(1,2,10));
  adj[2].push_back(edge(2,1,10));
  adj[2].push_back(edge(2,3,10));
  adj[3].push_back(edge(3,2,10));
  adj[3].push_back(edge(3,0,10));
  adj[3].push_back(edge(3,4,10));
  adj[4].push_back(edge(4,3,10));
  adj[4].push_back(edge(4,5,3));
  adj[4].push_back(edge(4,6,8));

  adj[5].push_back(edge(5,4,3));
  adj[5].push_back(edge(5,6,3));

  adj[6].push_back(edge(6,5,3));
  adj[6].push_back(edge(6,4,4));
priority_queue<prims, vector<prims>, myComparator> pq;
pq.push(prims(0,-1,0));
bool visited[10]={false};
while(pq.size()!=0){
    prims rem=pq.top();
    pq.pop();
    if(visited[rem.v]==true){
        continue;
    }
    visited[rem.v]=true;
    cout<<rem.v<<" "<<rem.av<<" "<<rem.wt<<endl;
    for(auto e:adj[rem.v]){
        if(visited[e.nbr]==false){
            pq.push(prims(e.nbr,rem.v,e.wt));
        }
    }
}
}