class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string s = words[i];
            string t = s;
            reverse(t.begin(), t.end());
            if (s == t) {
                return words[i];
            }
        }
        return "";
    }
};