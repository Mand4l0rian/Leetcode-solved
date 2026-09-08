class Solution {
public:
    void dfs(int i, int j, vector<int>& dx, vector<int>& dy, vector<vector<int>>& visited, vector<vector<char>>& grid){
        visited[i][j]=1;
        for(int z=0;z<4;z++){
            int x=i+dx[z];
            int y=j+dy[z];
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1' && !visited[x][y]){
                dfs(x,y,dx,dy,visited,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    ans++;
                    dfs(i,j,dx,dy,visited,grid);
                }
            }
        }
        return ans;
    }
};