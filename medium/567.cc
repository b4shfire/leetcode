// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        const int N1 = s1.size();
        const int N2 = s2.size();
        
        unordered_map<char, int> correct_counts;
        unordered_map<char, int> current_counts;

        for (const auto& c : s1) correct_counts[c] ++;
        
        int remaining = N1;
        
        for (int i=0; i<N2; ++i){
            
            // add s2[i] to the window
            if (++current_counts[s2[i]] <= correct_counts[s2[i]]) {
                remaining --;
            }
            
            // remove s2[i-N1] from the window
            if (i >= N1 && --current_counts[s2[i-N1]] < correct_counts[s2[i-N1]]) {
                remaining ++;
            }
            
            // check if our window contains all needed characters
            if (remaining == 0) return true;
        }
        
        return false;
    }
};
