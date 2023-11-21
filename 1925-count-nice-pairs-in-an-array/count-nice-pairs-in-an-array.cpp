class Solution {
public:
    int rev(int num) 
    { 
        int rev_num = 0; 
        while (num > 0) { 
            rev_num = rev_num * 10 + num % 10; 
            num = num / 10; 
        } 
        return rev_num; 
    } 

    int countNicePairs(vector<int>& nums) {
        int MOD = 1e9 + 7;

        int n = nums.size();
        int cnt = 0; 
        unordered_map<int, int> mp;

        for (int i: nums) {
            int val = i - rev(i);
            cnt = (cnt + mp[val]) % MOD;
            mp[val]++;
        }

        return cnt % MOD;
    }
};