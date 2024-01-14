class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26, 0), b(26, 0); 
        for (char c: s) {
            a[c - 'a']++;
        }
        for (char c: t) {
            b[c - 'a']++;
        }
        int min_Step = 0;
        for (int i = 0; i < 26; i++) {
                min_Step += abs(a[i] - b[i]);
        }
        return min_Step;
    }
};