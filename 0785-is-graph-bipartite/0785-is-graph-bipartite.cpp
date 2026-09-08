class Solution {
public:
    bool dfs(int i, int col, vector<int>& color, vector<vector<int>>& graph){
        color[i]=col;
        for(auto it: graph[i]){
            if(color[it]==-1){
                if(!dfs(it,!col,color,graph)) return false;
            }else if(color[it]==color[i]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph)) return false;
            }
        }
        return true;
    }
};