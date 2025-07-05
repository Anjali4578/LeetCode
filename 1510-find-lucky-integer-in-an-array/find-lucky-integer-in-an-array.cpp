class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int, int> mp;
        for (int i: arr) mp[i]++;

        for (auto it: mp){
            if (it.second == it.first) {
                ans = max(ans, it.first);
            }
        }
        return ans;
        // T.C. = O(N)
        // S.C. = O(N) - map
    }
};