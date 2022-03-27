// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        const int N = mat.size();
        const int M = mat[0].size();
        
        // stores {strength(mat[i]), i}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> strengths;
        
        for (int i=0; i<N; ++i) {
            
            // binary search to find strength of this row
            int l=0, m=0, r=M;
            
            while (l < r) {
                m = (l+r)/2;
                if (mat[i][m] == 1) l = m+1;
                else r = m;
            }

            // add this row to the queue
            strengths.push({l, i});
        }
        
        vector<int> ans(k);
        
        // get the k weakest rows
        for (int i=0; i<k; ++i) {
            ans[i] = strengths.top().second;
            strengths.pop();
        }
        
        return ans;
    }
};
