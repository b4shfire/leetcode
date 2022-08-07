// https://leetcode.com/problems/count-vowels-permutation/

class Solution {
    
    enum vowel {
        VOWEL_A,
        VOWEL_E,
        VOWEL_I,
        VOWEL_O,
        VOWEL_U
    };
    
    inline uint32_t _mod(uint32_t x) {

        while (x >= 1000000007)
            x -= 1000000007;
        
        return x;
    }
    
public:
    int countVowelPermutation(int n) {

        vector<uint32_t> dp(5, 1), tmp(5);
        
        for (int i=0; i<n-1; ++i) {
            tmp[VOWEL_A] = dp[VOWEL_E];
            tmp[VOWEL_E] = _mod(dp[VOWEL_A] + dp[VOWEL_I]);
            tmp[VOWEL_I] = _mod(dp[VOWEL_A] + dp[VOWEL_E] + dp[VOWEL_O] + dp[VOWEL_U]);
            tmp[VOWEL_O] = _mod(dp[VOWEL_I] + dp[VOWEL_U]);
            tmp[VOWEL_U] = dp[VOWEL_A];
            swap(dp, tmp);
        }
        
        return _mod( _mod(dp[VOWEL_A] + dp[VOWEL_E]) + 
                    dp[VOWEL_I] + dp[VOWEL_O] + dp[VOWEL_U]
                   );
    }
};
