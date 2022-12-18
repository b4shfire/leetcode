// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        const int N = temperatures.size();

        vector<int> answer(N);
        stack<int> st;

        for (int i=N-1; i>=0; --i) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            answer[i] = (st.empty() ? 0 : st.top() - i);
            st.push(i);
        }

        return answer;
    }
};
