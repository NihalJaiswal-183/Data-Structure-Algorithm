// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int v=graph.size();
//         int color[v];
//         for(int i=0;i<v;i++)
//             color[i]=0;
//         for(int i=0;i<v;i++){
//             if(color[i]==1||color[i]==-1)
//                 continue;
//             color[i]=1;
//             queue<int>bfs;
//             bfs.push(i);
//             while(bfs.size()>0){
//                 int rem=bfs.front();
//                 bfs.pop();
//                 for(auto x:graph[rem])
//                 if(color[x]==0){
//                     color[x]=-color[rem];
//                     bfs.push(x);
//                 }
//                 else if(color[rem]==color[x]){
//                     return false;
//                 }
//             }
            
//         }
//         return true;
//     }
// };