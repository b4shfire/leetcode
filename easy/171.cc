// https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int col = 0;
        
        for (char c : columnTitle){
            col *= 26;
            col += c - 'A' + 1;
        }
        
        return col;
    }
};
