class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // if(nums.size() == 0 || nums.size() == 1){
        //     return false;
        // }
        // for(int  i = 0; i <= nums.size() - 2; i++){
        //     if(nums[i] == nums[i+1]){
        //         return true;
        //     }
        // }
        // return false;

        unordered_set<int> us;
        for(const int item : nums){
            if(us.find(item) != us.end()){
                return true;
            }
            us.insert(item);
        }
        return false;
    }
};
