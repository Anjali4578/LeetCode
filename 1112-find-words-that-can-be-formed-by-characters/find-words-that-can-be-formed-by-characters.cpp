class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for (auto ch: chars) {
                mp[ch]++;
        }

        int sum = 0;
        for (auto str: words) {
            bool flag = true;
            unordered_map<char, int> mpp;
            for (auto ch: str) {
                if (++mpp[ch] > mp[ch]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                sum += str.size();
            }
        }
        return sum;
    }
};