// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
public:
    int numberOfSteps(int num) {
        
        /*
            Dividing by 2 shifts all bits to the right
            Subtracting 1 clears the 0th bit
            The number of divisions is the index of the highest set bit
            The number of subtractions is the number of bits set
            We add them together to get the answer
        */
        
        int highest_1 = 0;
        int num_1s = 0;
        
        for (int i=0; i<32; ++i){
            if (num & 1<<i){
                highest_1 = i;
                num_1s++;
            }
        }

        return highest_1 + num_1s;
    }
};
