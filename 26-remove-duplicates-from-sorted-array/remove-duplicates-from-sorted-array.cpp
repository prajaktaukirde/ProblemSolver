class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i=1 ;
        int j=0;
        int uni=1;
        while(i<nums.size()){
            if (nums[i]!=nums[j]){
                j++;
               (nums[j]=nums[i]);
                uni++;
            }
            i++;
        }
        return uni;
    }
};
