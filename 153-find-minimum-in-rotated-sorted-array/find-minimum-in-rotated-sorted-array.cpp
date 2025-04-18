class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        
        while (l < h) {
            // array already sorted
            if (nums[l] < nums[h]) return nums[l];

            int mid = (l + h) / 2;
            if (nums[mid] > nums[h]) {
                l = mid + 1;
            }
            else {
                h = mid;
            }
        }
        return nums[l];

        // T.C. = O(log n) 
        // S.C. = (1)
    }
};