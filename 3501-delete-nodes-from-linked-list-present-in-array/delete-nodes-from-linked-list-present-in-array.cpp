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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;

        set<int> s(nums.begin(), nums.end());
        while (head != NULL) {
            if (s.find(head -> val) == s.end()) {
                temp -> next = head;
                temp = temp -> next;
            }
            head = head -> next;
        }
        temp -> next = NULL;

        return dummy -> next;

        /*  k -> nums, n -> linked list
        T.C. = O(k log k + n log k)  -> set, unordered_set -> O(n + k)
        S.C. = O(k) - > to store in set
        */
    }
};