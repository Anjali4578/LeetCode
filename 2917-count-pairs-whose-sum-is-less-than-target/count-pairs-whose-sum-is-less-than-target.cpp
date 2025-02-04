class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // int n = nums.size(), cnt = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] < target) {
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;

        // // T.C. = O(N^2)

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, h = n - 1;
        int ans = 0;
        while (l < h) {
            if (nums[l] + nums[h] < target) {
                ans += h - l;
                l++;
            }
            else {
                h--;
            }
        }
        return ans;

        // T.C. = O(N log N)
    }
};