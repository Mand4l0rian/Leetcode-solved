class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int i) {
        
        // All characters matched
        if (i == word.size())
            return true;

        // Invalid cell / mismatch
        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != word[i])
            return false;

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions
        bool found =
            dfs(board, word, r + 1, c, i + 1) ||
            dfs(board, word, r - 1, c, i + 1) ||
            dfs(board, word, r, c + 1, i + 1) ||
            dfs(board, word, r, c - 1, i + 1);

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        // Impossible if word has more characters than cells
        if (word.size() > m * n)
            return false;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == word[0] &&
                    dfs(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};