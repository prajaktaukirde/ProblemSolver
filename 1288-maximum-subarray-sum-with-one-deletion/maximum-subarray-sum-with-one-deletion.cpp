class Solution {
public:
    int maximumSum(vector<int>& a) {
        
        int n = a.size();

        int noDelete = a[0];
        int oneDelete = INT_MIN;
        int res = a[0];

        for(int i = 1; i < n; i++) {

            int prevNoDelete = noDelete;
            int prevOneDelete = oneDelete;

            noDelete = max(noDelete + a[i], a[i]);

            int v2;

            if(prevOneDelete == INT_MIN)
                v2 = a[i];
            else
                v2 = prevOneDelete + a[i];

            oneDelete = max(v2, prevNoDelete);

            res = max(res, max(noDelete, oneDelete));
        }

        return res;
    }
};