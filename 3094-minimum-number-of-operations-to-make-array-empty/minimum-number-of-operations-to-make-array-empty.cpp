class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i: nums) {
            mp[i]++;
        }
        
        int ans = 0;
        for (auto it: mp) {
            int cnt = it.second;
            if (cnt == 1) return -1;

            ans += cnt / 3;
            if (cnt % 3) ans++; 
        }
        
        return ans;
    }
};