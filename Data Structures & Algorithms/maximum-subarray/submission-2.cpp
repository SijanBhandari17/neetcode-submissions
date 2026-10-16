class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int best_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current_sum = max(nums[i], current_sum + nums[i]);
            if (current_sum >= best_sum) {
                best_sum = current_sum;
            }
        }
        return best_sum;
    }
};
