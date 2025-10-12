class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum = 0;
        map<int, int> mp;
        for (auto i: nums) {
            mp[i]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] % k == 0) {
                sum += nums[i];
            }
        }
        return sum;
    }
};