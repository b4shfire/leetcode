// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
    
    priority_queue<int, vector<int>, greater<>> _k_largest;
    int _k;
    
    void _push(int val) {
        if (_k_largest.size() < _k) {
            _k_largest.push(val);
        } else if (val > _k_largest.top()) {
            _k_largest.pop();
            _k_largest.push(val);
        }
    }
    
public:
    KthLargest(int k, vector<int>& nums) : _k(k) {
        
        for (int n : nums) _push(n);
    }
    
    int add(int val) {
        
        _push(val);
        return _k_largest.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
