class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> b(nums.size(), -1);  
        int i=0;
        int j=nums.size()-1;
        int k=nums.size()-1;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                b[k]=nums[i]*nums[i];
                i++;
            }
            else{
                b[k]=nums[j]*nums[j];
                j--;
            }
            k=k-1;
        }
return b;
    }
};