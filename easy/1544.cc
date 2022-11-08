// https://leetcode.com/problems/make-the-string-great/

class Solution {
public:
    string makeGood(string s) {
        
        string good;
        
        for (char c : s) {
            if (!good.empty() && good.back() == (isupper(c) ? tolower(c) : toupper(c)))
                good.pop_back();
            else
                good.push_back(c);
        }
        
        return good;
    }
};
