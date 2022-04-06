// https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {

        unordered_map<int, int> singles, doubles;
        
        int count = 0;
        
        for (int n : arr) {
            if (n > target) continue; // small optimisation because all elements are positive
            count = (count + doubles[target-n]) % 1000000007;
            for (const pair<int, int>& s : singles) {
                if (n + s.first > target) continue; // same optimisation again
                doubles[n+s.first] += s.second;
            }
            ++singles[n];
        }
        
        return count;
    }
};
