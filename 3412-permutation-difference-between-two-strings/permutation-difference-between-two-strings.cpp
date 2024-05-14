class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> mp1, mp2;
        for (int i = 0; i < s.size(); i++) {
            mp1[s[i]] = i;
            mp2[t[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < mp1.size(); i++) {
            ans += abs(mp1[i] - mp2[i]);
        }
        return ans;
    }
};