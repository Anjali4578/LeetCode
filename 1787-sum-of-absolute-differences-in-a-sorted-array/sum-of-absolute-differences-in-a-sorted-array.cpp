class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix_sum(n), suffix_sum(n);
        prefix_sum[0] = nums[0];
        suffix_sum[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
            suffix_sum[n - i - 1] = suffix_sum[n - i] + nums[n - i - 1];
        } 
        for (int i = 0; i < n; i++) {
            int diff = ((nums[i] * i) - prefix_sum[i]) + (suffix_sum[i] - (nums[i] * (n - i - 1)));
            ans[i] = diff;
        }
        return ans;
    }
};