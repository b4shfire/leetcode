// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr)
            return nullptr;
        
        ListNode* odd = head, *even = head->next, *saved_second = head->next;

        while (even != nullptr && even->next != nullptr) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }

        odd->next = saved_second;

        return head;
    }
};
