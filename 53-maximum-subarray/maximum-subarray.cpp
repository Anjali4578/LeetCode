class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum += nums[j];
        //         ans = max(ans, sum);
        //     }
        // }
        // return ans;

        // T.C. = O(N^2)  S.C. = O(1)

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
        return ans;
        // T.C. = O(N)  S.C. = (1)
    }
};