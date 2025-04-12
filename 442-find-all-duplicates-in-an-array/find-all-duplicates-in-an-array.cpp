class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto it: mp) {
            if (it.second == 2) {
                ans.push_back(it.first);
            }
        }
        return ans;

        // T.C. = O(N)  S.C. = O(N) -> map
    }
};