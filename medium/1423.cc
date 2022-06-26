// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int score = 0;
        
        for (int i=0; i<k; ++i)
            score += cardPoints[i];
        
        int max_score = score;
        
        for (int i=0; i<k; ++i) {
            score -= cardPoints[k-i-1];
            score += cardPoints[cardPoints.size()-i-1];
            max_score = max(max_score, score);
        }
        
        return max_score;
    }
};
