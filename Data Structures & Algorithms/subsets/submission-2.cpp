class Solution {
   public:
    void backtrack(int index, vector<int>& nums, vector<vector<int>>& result, vector<int>& out) {
        if (index == nums.size()) {
            result.push_back(out);
            return;
        }

        out.push_back(nums[index]);
        backtrack(index + 1, nums, result, out);

        out.pop_back();
        backtrack(index + 1, nums, result, out);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> out = {};
        backtrack(0, nums, result, out);
        return result;
    }
};
