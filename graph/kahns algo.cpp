// 	public:
// 	vector<int> topoSort(int V, vector<int> adj[]) {
// 	    // code here
	    
// 	    int indeg[V];
// 	    for(int i=0;i<V;i++)
// 	    indeg[i]=0;
// 	    for(int i=0;i<V;i++){
// 	        for(auto x:adj[i]){
// 	            indeg[x]++;
// 	        }
// 	    }
	    
// 	    queue<int >topo;
// 	    for(int i=0;i<V;i++){
// 	        if(indeg[i]==0){
// 	            topo.push(i);
// 	        }
// 	    }
// 	    vector<int>ans;
// 	    while(topo.size()>0){
// 	        int rem=topo.front();
// 	        topo.pop();
// 	        ans.push_back(rem);
// 	        for(auto x:adj[rem]){
// 	            indeg[x]--;
// 	            if(indeg[x]==0){
// 	                topo.push(x);
// 	            }
// 	        }
// 	    // }
// 	    return ans;
// 	}
// };