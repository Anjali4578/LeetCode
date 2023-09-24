class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int n = s.size();
        int cnt1 = 0, cnt0 = 0;
        for (auto c: s) {
            if (c == '1') cnt1++;
            else cnt0++;
        }

        for (int i = 0; i < cnt1 - 1; i++) {
            ans += "1";
        }
        for (int i = 0; i < cnt0; i++) {
            ans += "0";
        }

        if (cnt1 > 0) ans += "1";

        return ans;
    }
};