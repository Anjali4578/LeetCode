class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if (left == 0 || right == 0) {   // if anyone zero then 0
            return 0;
        }

        if ((int)log2(left) != (int)log2(right)) return 0;
        // if number of digits is different then 0

        int ans = left;
        for (long i = left; i <= right; i++) {
            ans &= i;
        }

        return ans;
    }
};