class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,pair<int,int>>> q;
       for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==2) q.push({0,{i,j}});
        }
       }
       vector<int> dx={1,0,-1,0};
       vector<int> dy={0,1,0,-1};
       int ans=0;
       while(!q.empty()){
        int min=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        ans=max(ans,min);
        q.pop();
        for(int i=0;i<4;i++){
            int nr=row+dy[i];
            int nc=col+dx[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                grid[nr][nc]=2;
                q.push({min+1,{nr,nc}});
            }
        }
       }
       for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1) return -1;
        }
       }
       return ans;
    }
};