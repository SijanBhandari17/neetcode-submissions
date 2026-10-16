class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curr_max = 0;
        int global_max = nums[0];

        int curr_min = 0;
        int global_min = nums[0];
        for (const int& num : nums) {
            curr_max = max(curr_max+ num , num);
            global_max = max(curr_max, global_max);
            total += num;

            curr_min = min(curr_min + num , num);
            global_min = min(curr_min, global_min);
        }
        return global_max > 0 ? max(total - global_min, global_max) : global_max;
    }
};