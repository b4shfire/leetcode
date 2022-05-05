// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
    
    queue<int> _store;
    
public:
    MyStack() {}
    
    void push(int x) {
        _store.push(x);
        for (int i=1; i<_store.size(); ++i) {
            _store.push(_store.front()); _store.pop();
        }
    }
    
    int pop() {
        int temp = _store.front(); _store.pop();
        return temp;
    }
    
    int top() {
        return _store.front();
    }
    
    bool empty() {
        return _store.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
