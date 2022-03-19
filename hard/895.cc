// https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
    
    // needed for selecting the element nearest to the top of the stack
    long _num_pushes = 0;
    
    // maps val => number of occurences
    unordered_map<int, int> _counts;
    
    // maps {number of occurences, insertion number} => val
    map<pair<int, long>, int> _stack;
    
public:
    FreqStack() {}
    
    void push(int val) {
        _stack[{_counts[val], _num_pushes}] = val;
        _counts[val]++;
        _num_pushes++;
    }
    
    int pop() {
        int val = _stack.rbegin()->second;
        _stack.erase(prev(_stack.end()));
        _counts[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
