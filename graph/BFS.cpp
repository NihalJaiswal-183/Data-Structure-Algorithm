#include<bits/stdc++.h> 
using namespace std; 

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

// hint : remove mark* work add*
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
  bool visited[7]={false}; 
  queue<pair<int,string> > bfs;
  int src=0;
  bfs.push({src,to_string(src)});
  while(bfs.size()>0){
      pair<int,string> rem=bfs.front();
      bfs.pop();
      if(visited[rem.first]==true){
          continue;
      }
      visited[rem.first]=true;
      cout<<rem.first<<"@"<<rem.second<<endl;
      for(auto e:adj[rem.first]){
          if(visited[e.nbr]==false){
              bfs.push({e.nbr,rem.second+to_string(e.nbr)});
          }
      }
  }
 } 
