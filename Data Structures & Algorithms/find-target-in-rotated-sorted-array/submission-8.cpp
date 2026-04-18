class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            if (l == r && nums[l] != target) return -1;
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[r] > nums[m]) {
                if (nums[r] >= target && nums[m] <= target) {
                    l = m + 1;
                } else {
                    r = m;
                }
            } else {
                if (nums[m] >= target && nums[l] <= target) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
