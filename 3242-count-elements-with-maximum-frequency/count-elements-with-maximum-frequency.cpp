class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0, maxFreq = 0;
        unordered_map<int, int> mp;
        for (int i: nums) {
            mp[i]++;
        }

        for (auto it: mp) {
            maxFreq = max(maxFreq, it.second);
        }
        
        for (auto it: mp) {
            if (it.second == maxFreq) {
                ans += it.second;
            }
        }
        return ans;
    }
};