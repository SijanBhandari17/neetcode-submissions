class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            int size = nums.size();
            int i =0, j = 0;
            while(j < size){
                nums[i] = nums[j];
                while(nums[i] == nums[j] && j < size){
                    j++;
                }
                i++;
            }
            return i;
        }
};