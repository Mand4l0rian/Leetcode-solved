// DFS: MAINTAIN A COLOR ARRAY INITIALIZED WITH VALUE -1 REPRESENTING NO COLOR
// GIVE A STARTING COLOR 0, SEE ADJACENT NODES, IF UNCOLOURED THEN COLOR WITH OPPOSITE COLOR
// ELSE CHECK IF THE ADJACENT NODE HAS SAME COLOR AS CURRENT NODE, IF YES THEN THERE IS A CYCLE AND
// RETURN FALSE.

// class Solution {
// public:
//     bool dfs(int i, int col, vector<int>& color, vector<vector<int>>& graph){
//         color[i]=col;
//         for(auto it: graph[i]){
//             if(color[it]==-1){
//                 if(!dfs(it,!col,color,graph)) return false;
//             }else if(color[it]==color[i]) return false;
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         vector<int> color(graph.size(),-1);
//         for(int i=0;i<graph.size();i++){
//             if(color[i]==-1){
//                 if(!dfs(i,0,color,graph)) return false;
//             }
//         }
//         return true;
//     }
// };

// BFS:
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {

            // New connected component
            if (color[i] != -1)
                continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {

                    // Not colored yet
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }

                    // Same color on both ends
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};