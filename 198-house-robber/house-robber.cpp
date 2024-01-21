class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int i, int n) {
        if (i >= n) return 0;
        if (dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(helper(nums, dp, i + 1, n), nums[i] + helper(nums, dp, i + 2, n));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return helper(nums, dp, 0, n);
    }
};