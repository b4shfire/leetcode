// https://leetcode.com/problems/short-encoding-of-words/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

        // sort in descending lexicographical order of the reversed strings
        // this ensures that words are immediately followed by suffixes
        sort(words.begin(), words.end(),
             [](const string& a, const string& b) {
                 return lexicographical_compare(b.rbegin(), b.rend(), a.rbegin(), a.rend());
             });
        
        int len = words[0].size() + 1;
        
        for (int i=1; i<words.size(); ++i) {
            // only increase the length if this word is not a suffix of the previous word
            if (mismatch(words[i].rbegin(), words[i].rend(), 
                         words[i-1].rbegin()).first != words[i].rend()) {
                len += words[i].size() + 1;
            }
        }
        
        return len;
    }
};
