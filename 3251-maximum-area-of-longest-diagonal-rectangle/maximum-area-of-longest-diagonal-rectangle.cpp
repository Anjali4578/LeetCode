class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxArea = 0, maxD = 0;
        for (int i = 0; i < n; i++) {
                int l = dimensions[i][0], b = dimensions[i][1];
                int curD = l * l + b * b;
                if (curD > maxD || curD == maxD && l * b > maxArea) {
                    maxD = curD;
                    maxArea = l * b;
                }
        }
        return maxArea;
    }
};