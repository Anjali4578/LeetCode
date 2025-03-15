class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1, h = *max_element(nums.begin(), nums.end());
        while(l < h) {
            int mid = (l + h) / 2;
            int cnt = 0;
            for (int i = 0; i < n && cnt < k; i++) {
                cnt += nums[i] <= mid;
                i += nums[i] <= mid;
            }

            if (cnt < k) {
                l = mid + 1;
            }
            else {
                h = mid;
            }
        }
        return l;

        // T.C. = O(N log max(nums))
        // S.C. = O(1)
    }
};