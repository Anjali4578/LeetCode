class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], sum = nums[0];

        for (int i = 1; i < n; i++) {
            sum += nums[i];

            if (nums[i - 1] >= nums[i]) {
                sum = nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};