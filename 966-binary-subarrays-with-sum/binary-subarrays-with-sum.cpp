class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        int prefixSum = 0;
        map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            ans += mp[prefixSum - goal];
            mp[prefixSum]++;
        }
        return ans;
    }
};