class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int officer = 0;  
        int cm = 1;        
        int uni = 1;      

        while(cm < n) {
            if(nums[cm] == nums[cm - 1]) {
                cm++;   
            }
            else {
                officer++;
                nums[officer] = nums[cm]; 
                cm++;
                uni++;
            }
        }
        return uni;
    }
};