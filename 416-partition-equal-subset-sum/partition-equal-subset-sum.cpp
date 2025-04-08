class Solution {
public:
    bool rec(int ind, vector<int> &nums, int target, vector<vector<int>> &dp) {
        if (target == 0) return true;
        if (ind == 0) return nums[ind] == target;

        if (dp[ind][target] != -1) return dp[ind][target];

        bool not_take = rec(ind - 1, nums, target, dp);
        bool take = false;

        if (nums[ind] <= target) {
            take = rec(ind - 1, nums, target - nums[ind], dp);
        }

        return dp[ind][target] = not_take || take;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) total += nums[i];
        if (total % 2 != 0) return false;
        else {
            int target = total / 2;
            vector<vector<int>> dp(n, vector<int> (target + 1, -1));
            return rec(n - 1, nums, target, dp);
        }
    }

    // T.C. = O(n * target) + O(N)  ~ O(N * target)
                             // for getting total  
    // S.C. = O(N * target) dp array + O(N) recursive stack space
};