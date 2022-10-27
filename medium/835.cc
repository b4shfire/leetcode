// https://leetcode.com/problems/image-overlap/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        const int N = img1.size();
        
        int largest = 0;
        
        for (int x=1-N; x<=N-1; ++x) {
            for (int y=1-N; y<=N-1; ++y) {
                
                int overlap = 0;
                
                for (int i=0; i<N-abs(x); ++i)
                    for (int j=0; j<N-abs(y); ++j) 
                        overlap += (img1[i+max(x,0)][j+max(y,0)] && img2[i+max(-x,0)][j+max(-y,0)]);

                largest = max(largest, overlap);
            }
        }
        
        return largest;
    }
};
