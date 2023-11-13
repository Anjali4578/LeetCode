class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string sortVowels(string s) {
        vector<char> vowels;
        int n = s.size();
        for (char c: s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end());
        string ans;
        int index = 0;
        for (char c: s) {
            if (isVowel(c)) {
                ans += vowels[index++];
            }
            else {
                ans += c;
            }
        }

        return ans;
    }
};