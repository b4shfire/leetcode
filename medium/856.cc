// https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int depth = 0, score = 0;

        for (int i=0; i<s.size(); ++i) {
            
            // '(' means we are going deeper, ')' means we are ascending
            depth += (s[i] == '(' ? 1 : -1);
            
            // check if we are at a '()'
            if (s[i] == ')' && s[i-1] == '(') {
                
                // its score (initially 1) will be doubled 'depth' times
                score += 1 << depth;
            }
        }
        
        return score;
    }
};
