class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, maxFreq = 0;

        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++) {
            maxFreq = max(maxFreq, ++mp[nums[j]]);

            if (j - i + 1 - maxFreq > k) {
                --mp[nums[i++]];
            }
        }

        return maxFreq;
    }
};