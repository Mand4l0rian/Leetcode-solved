class Solution {
public:
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    bool solve(vector<vector<char>>& board) {
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] != '.') continue;
                for(int x = 1; x <= 9; x++) {
                    int b = (r / 3) * 3 + (c / 3);
                    if(!row[r][x] && !col[c][x] && !box[b][x]) {
                        board[r][c] = '0' + x;
                        row[r][x] = true;
                        col[c][x] = true;
                        box[b][x] = true;
                        if(solve(board))
                            return true;
                        // Backtrack
                        board[r][c] = '.';
                        row[r][x] = false;
                        col[c][x] = false;
                        box[b][x] = false;
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize the tracking arrays
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] != '.') {
                    int x = board[r][c] - '0';
                    int b = (r / 3) * 3 + (c / 3);
                    row[r][x] = true;
                    col[c][x] = true;
                    box[b][x] = true;
                }
            }
        }
        solve(board);
    }
};