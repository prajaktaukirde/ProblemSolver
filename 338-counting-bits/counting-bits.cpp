class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            // Clear lowest set bit and add 1 for the bit we removed
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};
//DP with Lowest Set Bit