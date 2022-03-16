// https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        // stores the simulation state
        stack<int> s;
        
        // stores the current index in 'popped'
        int i = 0;
        
        for (int val : pushed) {
            
            s.push(val);
            
            // pop as many values as possible from the stack
            while (!s.empty() && s.top() == popped[i]) {
                s.pop();
                i++;
            }
        }
        
        // if we successfully pushed and popped all values, return true
        return s.empty();
    }
};
