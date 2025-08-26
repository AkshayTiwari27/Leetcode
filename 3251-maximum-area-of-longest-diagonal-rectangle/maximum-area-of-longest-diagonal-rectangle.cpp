class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiag = 0; 
        int maxArea = 0;

        for (auto &v : dimensions) {
            int l = v[0];
            int w = v[1];

            double diag = sqrt(1.0 * l * l + 1.0 * w * w);
            int area = l * w;

            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (abs(diag - maxDiag) < 1e-9) { 
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
