// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* new_head = head->next;            // save head->next so we don't lose it
        head->next = swapPairs(head->next->next);   // swap the rest of the list
        new_head->next = head;                      // swap these two nodes
        return new_head;                            // return the new head
    }
};
