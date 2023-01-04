// https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int deletions = 0;

        for (int i=0; i<strs[0].size(); ++i)
            for (int j=1; j<strs.size(); ++j)
                if (strs[j-1][i] > strs[j][i]) {
                    ++deletions; break;
                }

        return deletions;
    }
};
