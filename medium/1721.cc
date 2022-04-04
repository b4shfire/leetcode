// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* curr = head;
        
        while (--k) curr = curr->next;
        
        ListNode* a = curr;
        ListNode* b = head;
        
        curr = curr->next;
        
        while (curr != nullptr) {
            curr = curr->next;
            b = b->next;
        }
        
        swap(a->val, b->val);

        return head;
    }
};
