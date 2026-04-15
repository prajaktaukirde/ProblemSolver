class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int maxDiff=INT_MAX;
        int res=INT_MIN;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                int diff=abs(target-sum);
                if(maxDiff>diff){
                    maxDiff=diff;
                    res=sum;
                }
                if(sum==target){
                    return sum;
                }
                if(sum<target){
                    left++;
                }
                if(sum>target){
                    right--;
                }


            }
        }
        return res;

    }
};