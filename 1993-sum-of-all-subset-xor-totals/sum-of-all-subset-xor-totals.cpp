class Solution {
private:
    int helper(vector<int>& nums, int level, int cur) {
        if (level == nums.size()) 
            return cur;
        
        int in = helper(nums, level + 1, cur ^ nums[level]);
        int ex = helper(nums, level + 1, cur);

        return in + ex;
    }

public: 
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};