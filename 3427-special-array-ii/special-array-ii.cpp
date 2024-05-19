class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<bool> answer(q, 1);
        vector<int> pre(n);

        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                pre[i] += 1;
            }
            pre[i + 1] += pre[i];
        }

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int cnt = (r > 0 ? pre[r - 1] : 0) - (l > 0 ? pre[l - 1] : 0);

            if (cnt > 0) {
                answer[i] = 0;
            }
        }

        return answer;
    }
};