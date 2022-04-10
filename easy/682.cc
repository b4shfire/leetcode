// https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int> scores;
        
        for (const string& o : ops) {
            switch (o[0]) {
                case '+':
                    scores.push_back(scores.end()[-1] + scores.end()[-2]);
                    break;
                case 'D':
                    scores.push_back(scores.back() * 2);
                    break;
                case 'C':
                    scores.pop_back();
                    break;
                default:
                    scores.push_back(stoi(o));
            }
        }

        return accumulate(scores.begin(), scores.end(), 0);
    }
};
