// https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(), tokens.end());
        
        int i=0, j=tokens.size()-1, score=0;
        
        while (i <= j) {
            if (tokens[i] <= power) {
                power -= tokens[i++];
                ++score;
            } else if (score > 0) {
                power += tokens[j--] - tokens[i++];
            } else return 0;
        }
        
        return score;
    }
};
