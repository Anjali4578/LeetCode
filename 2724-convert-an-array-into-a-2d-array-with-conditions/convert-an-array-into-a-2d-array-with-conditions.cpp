class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxRow = 0;
        for (auto i: nums) {
            mp[i]++;
            maxRow = max(maxRow, mp[i]);
        }

        vector<vector<int>> ans(maxRow);
        for (auto i: mp) {
            for (int j = 0; j < i.second; j++) {
                ans[j].push_back(i.first);
            }
        }
        return ans;
    }
};