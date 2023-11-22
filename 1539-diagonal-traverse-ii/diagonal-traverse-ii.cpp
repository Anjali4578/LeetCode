class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxVal = 0, n = nums.size();
        vector<int> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < nums[i].size(); j++) {
                maxVal = max(maxVal, i + j);
                mp[i + j].push_back(nums[i][j]);
            }
        }

        for (int i = 0; i <= maxVal; i++) {
            for (auto it: mp[i]) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};