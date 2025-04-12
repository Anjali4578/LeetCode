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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *temp = head;

        while(head != NULL) {
            if (temp != NULL) {
                temp = temp -> next;
            }
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;

        // T.C. = O(N)  S.C. = O(1)
    }
};