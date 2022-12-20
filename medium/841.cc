// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> to_visit({0});
        unordered_set<int> visited({0});

        while (!to_visit.empty()) {
            int curr = to_visit.front(); to_visit.pop();

            for (int n : rooms[curr])
                if (visited.insert(n).second)
                    to_visit.push(n);
        }

        return visited.size() == rooms.size();
    }
};
