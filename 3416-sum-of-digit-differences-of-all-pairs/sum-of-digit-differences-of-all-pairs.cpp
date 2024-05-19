class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        map<pair<int, int>, long long> mp;
        int digits = 0;

        for (auto &it: nums) {
            int index = 0;
            while (it > 0) {
                mp[{it % 10, index}]++;
                index++;
                it /= 10;
            }
            digits = index;
        }

        long long res = 1LL * n * (n - 1) / 2 * digits;
        for (auto &[i, j] : mp) {
            res -= j * (j - 1) / 2;
        }

        return res;
    }
};