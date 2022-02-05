// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // contains {node->value, node} for the next node in each list
        set<pair<int, ListNode*>> available;
        
        // add the first node in each list to the set
        for (const auto& l : lists){
            if (l != nullptr) available.insert({l->val, l});
        }
        
        ListNode ans_head;
        ListNode* ans_curr = &ans_head;
        
        while (!available.empty()){
            
            // get the smallest available node and add it to our list
            ans_curr->next = available.begin()->second;
            ans_curr = ans_curr->next;
            
            // remove smallest from the set
            available.erase(available.begin());
            
            // add smallest->next to the set
            if (ans_curr->next != nullptr){
                available.insert({ans_curr->next->val, ans_curr->next});
            }
        }
        
        return ans_head.next;
    }
};
