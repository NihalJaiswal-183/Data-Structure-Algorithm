class Solution {
public:
    pair<int,int>parent[505][505];
    int rank[505][505];
    pair<int,int> get(  pair<int,int> b)
{
    return parent[b.first][b.second] = (parent[b.first][b.second] == b ? b : get( parent[b.first][b.second] ));
} 

void dis_joint_union( pair<int,int> a, pair<int,int> b)
{
    a = get(a);
    b = get(b);
    if (rank[a.first][a.second] == rank[b.first][b.second])
    {
        parent[b.first][b.second]=a;
        rank[a.first][a.second]++;
    }
     if (rank[a.first][a.second]  > rank[b.first][b.second])
    {
        parent[b.first][b.second] = a;
    }
    else
    {
        parent[a.first][a.second]= b;
    }
}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1)
                {
                    parent[i][j]={i,j};
                    rank[i][j]=0;
                }
            }
        }
         for(int i=0;i<grid.size()-1;i++){
            for(int j=0;j<grid.size()-1;j++){
                if(grid[i][j]==1 && grid[i+1][j]==1)
                {
                 dis_joint_union({i,j},{i+1,j});
                }
                 if(grid[i][j]==1 && grid[i][j+1]==1)
                {
                 dis_joint_union({i,j},{i,j+1});
                }
            }
        }
        for(int i=0;i<grid.size()-1;i++){
              if(grid[n-1][i]==1 && grid[n-1][i+1]==1)
                {
                 dis_joint_union({n-1,i},{n-1,i+1});
                }
        }
           for(int i=0;i<grid.size()-1;i++){
              if(grid[i][n-1]==1 && grid[i+1][n-1]==1)
                {
                 dis_joint_union({i,n-1},{i+1,n-1});
                }
        }
        map<pair<int,int>,int>cnt;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
               cnt[get({i,j})]++;
                
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==0)
                {
                   int left=0,right=0,top=0,bottom=0;
                    pair<int,int> lp={-1,-1},rp={-1,-1},tp={-1,-1},bp={-1,-1};
                    if(j-1>=0 and grid[i][j-1]==1){
                        lp=get({i,j-1});
                        left=cnt[lp];
                    }
                     if(j+1<n and grid[i][j+1]==1){
                        rp=get({i,j+1});
                        right=cnt[rp];
                    }
                     if(i-1>=0 and grid[i-1][j]==1){
                        tp=get({i-1,j});
                        top=cnt[tp];
                    }
                     if(i+1<n and grid[i+1][j]==1){
                        bp=get({i+1,j});
                        bottom=cnt[bp];
                    }
                    set<pair<int,int>> s = { tp,bp,lp,rp};
                    int temp=0;
                    for(auto x:s){
                        if(x.first!=-1){
                            temp+=cnt[x];
                        }
                        
                    }
                ans=max(ans,temp+1);
                }
            }
        }
        for(auto x:cnt){
            if(cnt[x.first]<n*n)
                ans=max(ans,cnt[x.first]+1);
            else if(cnt[x.first]==n*n){
                ans=n*n;
                break;
            }
         }
        if(ans==INT_MIN)
            return 1; 
            return ans;
    }
};