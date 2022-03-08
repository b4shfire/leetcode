// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // If there is a cycle, the two pointers will eventually meet
        while (fast != nullptr && fast->next != nullptr) {
            
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) return true;
        }
        
        return false;
    }
};
