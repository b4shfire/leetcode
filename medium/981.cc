// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
    unordered_map<string, map<int, string, greater<>>> _store;
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        
        _store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        
        auto timestamps = _store.find(key);
        if (timestamps == _store.end()) return "";
        
        auto res = timestamps->second.lower_bound(timestamp);
        if (res == timestamps->second.end()) return "";
        
        return res->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
