class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] == target) {
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;
        // T.C. = O(N ^ 2)  S.C.-> for ans

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];
            if (mp.find(rem) != mp.end()) {
                ans.push_back(i);
                ans.push_back(mp[rem]);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};

        // T.C. = O(N)   S.C. = O(N) -> map
    }
};