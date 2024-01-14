class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26, 0), freq2(26, 0);
        vector<bool> isPresent1(26, false), isPresent2(26, false);

        for (char ch: word1) {
            freq1[ch - 'a']++;
            isPresent1[ch - 'a'] = true;
        }

        for (char ch: word2) {
            freq2[ch - 'a']++;
            isPresent2[ch - 'a'] = true;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2 && isPresent1 == isPresent2;

    }
};