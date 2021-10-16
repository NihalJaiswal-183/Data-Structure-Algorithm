// class Solution{
// public:
// #define R 100
// #define C 100

// int maxcost(int i,int n,int j, vector<vector<int>> &matrix,bool path[R][C]){
//     if(j>=n||j<0||i<0||i>=n||path[i][j]==true){
//         return INT_MIN;
//     }
//     if(i==n-1){
//         return matrix[i][j];
//     }
//     path[i][j]=true;
//     int a=matrix[i][j]+maxcost(i+1,n,j,matrix,path);
//     int b=matrix[i][j]+maxcost(i+1,n,j+1,matrix,path);
//     int c=matrix[i][j]+maxcost(i+1,n,j-1,matrix,path);
//     path[i][j]=false;
//     return max(a,max(b,c));
// }

//     int maximumPath(int N, vector<vector<int>> matrix)
//     {

//   bool path[R][C];
//         int maxans=INT_MIN;
//         for(int j=0;j<N;j++){
//       memset(path,false,sizeof(path));
//        int ans=maxcost(0,N,j,matrix,path);
//        maxans=max(maxans,ans);
//         }
//         return maxans;

//     }
// };

//************************************************************************************************************************************************

// class Solution{
// public:

//     int maximumPath(int N, vector<vector<int>> Matrix)
//     {
//     int dp[N][N];
//     for(int i=N-1;i>=0;i--){
//         for(int j=0;j<N;j++){
//            if(i==N-1){
//                dp[i][j]=Matrix[i][j];
//            }
//            else if(j==0){
//                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+Matrix[i][j];
//            }
//            else if(j==N-1){
//                dp[i][j]=max(dp[i+1][j],dp[i+1][j-1])+Matrix[i][j];
//            }
//            else{
//            dp[i][j]=max(dp[i+1][j],max(dp[i+1][j+1],dp[i+1][j-1]))+Matrix[i][j];
//            }

//         }

//     }
//     int ans=INT_MIN;
//  for(int i=0;i<N;i++){
//       ans=max(ans,dp[0][i]);
//  }
//     return ans;
//     }