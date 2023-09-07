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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp = new ListNode(0);
        ListNode* prev = tmp, *cur;

        tmp -> next = head;
        for (int i = 0; i < left - 1; i++) {
            prev = prev -> next;
        }

        cur = prev -> next;
        for (int i = 0; i < right - left; i++) {
            ListNode *forward = cur -> next;
            cur -> next = forward -> next;
            forward -> next = prev -> next;
            prev -> next = forward;

        }
        return tmp -> next;
    }
};