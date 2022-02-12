// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        const int N = wordList.size();

        // -1=visited, 0=dne, 1=unvisited
        unordered_map<string, int> states;
        states.reserve(N);
        
        // add all words to the map
        for (const auto& w : wordList) states[w] = 1;

        // make sure endWord is in the map
        if (states.find(endWord) == states.end()) return 0;
        
        // {word, depth}
        deque<pair<string, int>> queue = {{beginWord, 1}};
        
        while (!queue.empty()){
            
            // get the first item in the queue
            auto [word, depth] = queue.front();
            queue.pop_front();
            
            // search for adjacent words by modifying each character in turn
            for (int i=0, n=word.size(); i<n; ++i){
                
                char saved_letter = word[i];
                
                for (word[i]='a'; word[i]<='z'; ++word[i]){
                    
                    // make sure we have actually modified the word
                    if (word[i] == saved_letter) continue;
                    
                    auto adj = states.find(word);

                    if (adj != states.end() && adj->second == 1){
                        
                        // check if the adjacent word is the target
                        if (word == endWord) return depth + 1;
                        
                        // otherwise, add it to the back of the queue and mark it as visited
                        queue.push_back({word, depth+1});
                        adj->second = -1;
                    }
                }
                
                word[i] = saved_letter;
            }
        }
        
        // we didn't find the target word
        return 0;
    }
};
