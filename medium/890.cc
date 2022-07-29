// https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> matches;
        
        for (const string& word : words) {
            
            unordered_map<char, char> forward_mapping;
            unordered_map<char, char> reverse_mapping;
            
            bool match = true;
            
            for (int i=0; i<word.size(); ++i) {
                
                // using value_type to insert {key => value}, or look up the value if key already exists
                auto fw_prev = forward_mapping.insert(unordered_map<char, char>::value_type(word[i], pattern[i]));
                auto rv_prev = reverse_mapping.insert(unordered_map<char, char>::value_type(pattern[i], word[i]));
                
                // if we have previously mapped either word[i] or pattern[i] to a different character
                if ((!fw_prev.second && fw_prev.first->second != pattern[i]) ||
                   (!rv_prev.second && rv_prev.first->second != word[i])) {
                    match = false;
                    break;
                }
            }
            
            if (match) matches.push_back(word);
        }
        
        return matches;
    }
};
