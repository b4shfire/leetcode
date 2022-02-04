// https://leetcode.com/problems/stone-game-iv/

class Solution {
    
    // -1=losing, 0=unset, 1=winning
    unordered_map<int, int> _winnable;
    
public:
    bool winnerSquareGame(int n) {

        if (_winnable[n] != 0) return (_winnable[n] == 1);
        
        for (int t=sqrt(n); t>0; t--){
            if (!winnerSquareGame(n-t*t)) {
                _winnable[n] = 1;
                return true;
            }
        }
        
        _winnable[n] = -1;
        return false;
    }
};
