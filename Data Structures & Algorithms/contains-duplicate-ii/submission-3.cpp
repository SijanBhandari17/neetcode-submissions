class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> occur;
        int n = nums.size();

        for(int i = 0; i < n ; i++){
            if(occur.count(nums[i]))
            return true;

            occur.insert(nums[i]);

            if(occur.size() > k){
                occur.erase(nums[i - k]);
            }
        }
        return false;
      
    }
};