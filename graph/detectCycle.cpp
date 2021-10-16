// for undirected graph using DFS
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

bool detectCycle(vector<edge> adj[],int src,bool visited[],int parent){

    visited[src]=true; 
     for(auto x:adj[src]){
        if(visited[x.nbr]==false){
        bool path=detectCycle(adj,x.nbr,visited,src);
        if(path==true)
        return true;
        }
        else if(x.nbr!=parent){
        return true;
        }
        }
    return false;
    }
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
cout<<adj[3].size();

  bool ans=detectCycle(adj,0,visited,-1);
  if(ans){
      cout<<"cycle is present";
  }
  else{
      cout<<"cycle is not present";
  }
 } 
//  /////////////////////////////////////////////////////////////////////////////////////////////////////////
// for directed graph using DFS
/*#include<bits/stdc++.h> 
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

int detectCycle(vector<edge> adj[],int src,bool visited[],bool helper[]){
    helper[src]=true;
    visited[src]=true; 
     for(auto x:adj[src]){
         if(helper[x.nbr]==true){
             return true;
         }
        if(visited[x.nbr]==false){
        bool path=detectCycle(adj,x.nbr,visited,helper);
        if(path==true)
        return true;
        }
        }
        helper[src]=false;
    return false;
    }
  int main(){
  vector<edge> adj[7];
  adj[0].push_back(edge(0,1,10));
  //adj[0].push_back(edge(0,3,10));
  //adj[1].push_back(edge(1,0,10));
  adj[1].push_back(edge(1,2,10));
  //adj[2].push_back(edge(2,1,10));
  //adj[2].push_back(edge(2,3,10));
  adj[3].push_back(edge(3,2,10));
  adj[3].push_back(edge(3,0,10));
  adj[3].push_back(edge(3,4,10));
  adj[4].push_back(edge(4,3,10));
  adj[4].push_back(edge(4,5,3));
  adj[4].push_back(edge(4,6,8));

  adj[5].push_back(edge(5,4,3));
  adj[5].push_back(edge(5,6,3));

  //adj[6].push_back(edge(6,5,3));
 // adj[6].push_back(edge(6,4,4));
  bool visited[7]={false}; 
  bool helper[7]={false};

  int ans=detectCycle(adj,0,visited,helper);
  if(ans){
      cout<<"cycle is present";
  }
  else{
      cout<<"cycle is not present";
  }
 } 
 */
