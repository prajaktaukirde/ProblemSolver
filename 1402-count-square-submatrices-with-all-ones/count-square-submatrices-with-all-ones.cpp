class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> prev(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {

            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 0) {
                    curr[j] = 0;
                }
                else if (i == 0 || j == 0) {
                    curr[j] = 1;
                }
                else {
                    curr[j] = 1 + min(prev[j],
                                 min(curr[j-1], prev[j-1]));
                }

                ans += curr[j];
            }

            prev = curr;
        }

        return ans;
    }
};