class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt_even = 0;
        for (auto i: nums) {
            if (i % 2 == 0) cnt_even++;
        }
        return cnt_even >= 2;
    }
};