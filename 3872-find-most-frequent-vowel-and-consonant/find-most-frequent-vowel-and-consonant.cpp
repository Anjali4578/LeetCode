class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        int vowelmax = 0, consmax = 0;
        for (char c: s) {
            freq[c - 'a']++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelmax = max(vowelmax, freq[c - 'a']);
            }
            else {
                consmax = max(consmax, freq[c - 'a']);
            }
        }
        return vowelmax + consmax;
        // T.C. = O(n) S.C. = O(26)
    }
};