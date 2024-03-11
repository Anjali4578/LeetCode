class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        int idx = 0;
        for (auto x: order) {
            mp[x] = idx++;
        }

        sort(s.begin(), s.end(), [&](const char &a, const char &b) {
            return mp[a] < mp[b];
        });

        return s;
    }
};