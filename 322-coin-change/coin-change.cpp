class Solution {
public:

    vector<int> dp;

    int solve(vector<int>& coins, int amount) {

        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }


        int ans = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {

            if (coins[i] <= amount) {

                int result = solve(coins, amount - coins[i]);

                if (result != INT_MAX) {
                    ans = min(ans, result + 1);
                }
            }
        }


        dp[amount] = ans;

        return dp[amount];
    }


    int coinChange(vector<int>& coins, int amount) {

        dp.resize(amount + 1, -1);

        int answer = solve(coins, amount);


        if (answer == INT_MAX) {
            return -1;
        }

        return answer;
    }
};