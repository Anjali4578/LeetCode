class Solution {
public:
    int numSub(string s) {
        int ans = 0;
        int cnt = 0, mod = 1e9 + 7;
        for (char c: s) {
            if (c == '1') cnt++;
            else {
                cnt = 0;
            }
            ans =  (ans + cnt) % mod;
        }
        return ans;

        // T.C. = O(N)   S.C. = O(1)
    }
};