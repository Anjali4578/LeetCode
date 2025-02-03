class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int ans = 0;
        int left = 0, right;
        map<char, int> freq;
        for (right = 0; right < n; right++) {
            // if (s[right] == ' ') {
            //     break;
            // }
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] > 1) {
                freq[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};