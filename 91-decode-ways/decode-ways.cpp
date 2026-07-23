class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();

        int a = 1;  // dp[i-2]
        int b = 1;  // dp[i-1]

        if (s[0] == '0')
            return 0;


        for (int i = 1; i < n; i++) {

            int c = 0;  // dp[i]


            // Single digit
            if (s[i] != '0') {
                c += b;
            }


            // Two digits
            int num = (s[i-1]-'0') * 10 + (s[i]-'0');

            if (num >= 10 && num <= 26) {
                c += a;
            }


            // Move forward
            a = b;
            b = c;
        }


        return b;
    }
};