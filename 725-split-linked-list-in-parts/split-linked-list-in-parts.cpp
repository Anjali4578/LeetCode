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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        if (!head) 
            return vector<ListNode*>(k, nullptr);

        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp -> next;
        }

        int parts = cnt / k;
        int extra = cnt % k;

        vector<ListNode*> ans;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        int start = parts + (extra > 0 ? 1 : 0);
        if (extra > 0) extra--;

        for (int i = 0; i < cnt; i++) {
            if (i == start) {
                prev -> next = nullptr;
                ans.push_back(curr);
                start += parts + (extra > 0 ? 1 : 0);
                if (extra > 0) extra--;
            }

            prev = curr;
            curr = curr -> next;
            if (i == 0) {
                ans.push_back(head);
            }
        }

        while (ans.size() < k) {
            ans.push_back(nullptr);
        }

        return ans;
    }
};