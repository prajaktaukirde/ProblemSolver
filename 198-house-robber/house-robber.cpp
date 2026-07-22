class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
         int a=0;
         int b=0;
         for (int i =0;i<n;i++){
            int c = max (nums[i]+a,b);
            a=b;
            b=c;
         }
         return b;

    }
};