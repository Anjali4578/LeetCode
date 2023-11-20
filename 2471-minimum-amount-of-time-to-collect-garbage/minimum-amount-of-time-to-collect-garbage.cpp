class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for (int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i - 1];
        }

        unordered_map<char, int> mp;
        int ans = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (char ch: garbage[i]) {
                mp[ch] = i;
            }
            ans += garbage[i].size();  // for picking up 
        }

        string s = "MPG";    // for travelling for each type of garbage
        for (char ch: s) {
            ans += (mp[ch] == 0 ? 0 : travel[mp[ch] - 1]);
        }
        return ans;

        // T.C. = O(n * k)  -- k max length of a garbage 
        // S.C. = O(1)
    }
};