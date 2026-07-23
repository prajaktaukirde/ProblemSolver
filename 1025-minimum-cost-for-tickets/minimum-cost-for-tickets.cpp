class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366,0);
        unordered_set<int>travel(days.begin(),days.end());
        for (int i =1; i<=365;i++){
            if (travel.find(i)==travel.end()){
                dp[i]=dp[i-1];
            }
            else{
                int oneday = dp[i-1]+costs[0];
                int sevenday = dp[max(0,i-7)]+costs[1];
                int thirtyday = dp[max(0,i-30)]+costs[2];
                dp[i]=min(oneday , min(sevenday , thirtyday));
            }
        }
        return dp[365];

    }
};