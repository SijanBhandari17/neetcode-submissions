class Solution {
public:
    void sortColors(vector<int>& nums) {
    int i = 0;
        int fp = 0;
        int lp = nums.size() - 1;
        while( i <= lp ){
            if(nums[i] == 0){
                swap(nums[i],nums[fp]);
                fp++;
            }
            else if(nums[i]== 2){
                swap(nums[i],nums[lp]);
                lp--;
                i--;
            }
            i++;
        }
    }
};