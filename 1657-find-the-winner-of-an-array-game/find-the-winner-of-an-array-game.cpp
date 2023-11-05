class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int curMax = arr[0];
        for (int i = 1; i < n; i++) {
            curMax = max(curMax, arr[i]);
            mp[curMax]++;
            if (mp[curMax] == k) 
                return curMax;
        }
        return curMax;

        // T.C. = O(n)
        // S.C. = O(1)
    }
};