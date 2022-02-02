class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        const int NS = s.size();
        const int NP = p.size();
        
        unordered_map<char, int> correct_counts;
        unordered_map<char, int> current_counts;

        for (const auto& c : p) correct_counts[c] ++;
        
        vector<int> start_positions;
        int remaining = NP;
        
        for (int i=0; i<NS; ++i){
            
            // add s[i] to the window
            if (++current_counts[s[i]] <= correct_counts[s[i]]) {
                remaining --;
            }
            
            // remove s[i-NP] from the window
            if (i >= NP && --current_counts[s[i-NP]] < correct_counts[s[i-NP]]) {
                remaining ++;
            }
            
            // check if our window contains all needed characters
            if (remaining == 0) {
                start_positions.push_back(i-NP+1);
            }
        }
        
        return start_positions;
    }
};
