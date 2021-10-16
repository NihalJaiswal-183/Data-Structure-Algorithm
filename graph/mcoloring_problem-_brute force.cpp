// void printSolution(int color[],int V)
// {
//     cout << "Solution Exists:" " Following are the assigned colors \n";
//     for (int i = 0; i < V; i++)
//         cout << "  " << color[i];
//     cout << "\n";
// }
// bool issafe(bool graph[101][101],int color[],int v ){
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             if(graph[i][j]&&color[i]==color[j]){
              
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// bool colorg(bool graph[101][101], int m, int V,int j,int color[]){
//     if(j==V){
//         bool a=issafe(graph,color,V);
//         if(a==true){
//               printSolution(color,V);
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     for(int i=1;i<=m;i++)
//     {
//         color[j]=i;
//         bool ans=colorg(graph,m,V,j+1,color);
//         if(ans==true){
//             return true;
//         }
//         color[j]=0;
//     }
//     return false;
// }
// bool graphColoring(bool graph[101][101], int m, int V)
// {
//     // your code here
    
//     int color[V];
//     for(int i=0;i<V;i++)
//     color[i]=0;
//     return colorg(graph,m,V,0,color);
    
// }