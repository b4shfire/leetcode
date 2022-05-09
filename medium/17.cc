// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    
    unordered_map<char, string> _digit_to_chars = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    void _find_combinations(vector<string>& ans, string digits, const string& prefix) {
        
        if (digits.empty()) {
            ans.push_back(prefix);
            return;
        }

        char d = digits.back(); digits.pop_back();
                
        for (char c : _digit_to_chars[d]) {
            _find_combinations(ans, digits, prefix + c);
        }
            
        digits.push_back(d);
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty()) return {};
        
        vector<string> ans;
        _find_combinations(ans, string(digits.rbegin(), digits.rend()), "");
        return ans;
    }
};
