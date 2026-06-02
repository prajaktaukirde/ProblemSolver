class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        f[0] = 1;
        int n = nums.size();
        int sum = 0;
        int res = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            int ques = sum - k;
            res += f[ques];
            f[sum]++;
        }

        return res;

    }
};