class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n), ans = "";
        for (char c: s) {
            if (c == '0') continue;
            else {
                ans += c;
            }
        }
        return stol(ans);
    }
};