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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* node = new ListNode(0, head);
        unordered_map<int, ListNode*> mp;
        int pre = 0;
        mp[0] = node;

        while (head != NULL) {
            pre += head -> val;
            mp[pre] = head;
            head = head -> next;
        }

        head = node;
        pre = 0;

        while (head != NULL) {
            pre += head -> val;
            head -> next = mp[pre] -> next;
            head = head -> next;
        }

        return node -> next;
    }
};