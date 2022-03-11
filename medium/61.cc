// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (!head) return nullptr;

        ListNode* curr = head;
        int node_count = 1;
                
        // count the number of nodes
        while (curr->next != nullptr) {
            
            curr = curr->next;
            node_count++;
        }
        
        // rotation by node_count has no effect
        if (k % node_count == 0) return head;
        else k %= node_count;
        
        // loop the end of the list back to the beginning
        curr->next = head;
        
        // advance to the split point
        for (int i=0; i<node_count-k; ++i) curr = curr->next;
        
        // split the list
        ListNode* new_head = curr->next;
        curr->next = nullptr;
        
        return new_head;
    }
};
