class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int count = 0, product = 1;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            product *= nums[j];
            while (i <= j && product >= k) {
                product /= nums[i++];
            }

            count += (j - i + 1);
        }
        return count;
    }
};