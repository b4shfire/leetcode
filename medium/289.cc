// https://leetcode.com/problems/game-of-life/

class Solution {
    
    // checks whether a cell is alive, with bounds checking
    bool _alive(const vector<vector<int>>& board, int i, int j) {
        if (i < 0 || i >= board.size()) return false;
        if (j < 0 || j >= board[0].size()) return false;
        return (board[i][j] == 1 || board[i][j] == 3);
    }
    
    // returns the number of living neighbours
    int _neighbours(const vector<vector<int>>& board, int i, int j) {
        
        int neighbours = 0;
        
        for (int di=-1; di<=1; ++di) {
            for (int dj=-1; dj<=1; ++dj) {
                if (di == 0 && dj == 0) continue;
                neighbours += _alive(board, i+di, j+dj);
            }
        }
        
        return neighbours;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        const int M = board.size();
        const int N = board[0].size();
        
        // 0 = dead -> dead
        // 1 = alive -> alive
        // 2 = dead -> alive
        // 3 = alive -> dead
        
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                
                int neighbours = _neighbours(board, i, j);
                
                if (board[i][j] == 1) {
                    if (neighbours < 2 || neighbours > 3) board[i][j] = 3;
                } else {
                    if (neighbours == 3) board[i][j] = 2;
                }
            }
        }
        
        // resolve 2s and 3s
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (board[i][j] > 1) board[i][j] = (board[i][j] == 2);
            }
        }
    }
};
