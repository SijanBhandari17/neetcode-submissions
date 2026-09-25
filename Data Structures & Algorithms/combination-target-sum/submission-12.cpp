class Solution {
   private:
    vector<vector<int>> res;

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> arr;
        int index = 0;
        combinations(nums, target, res, index, arr);
        return res;
    }

    void combinations(vector<int>& nums, int target, vector<vector<int>>& res, int index,
                      vector<int>& arr) {

        if (accumulate(arr.begin(), arr.end(), 0) == target) {
            res.push_back(arr);
            return;
        }

        if (index == nums.size() || accumulate(arr.begin(), arr.end(), 0) > target) {
            return;
        }
        arr.push_back(nums[index]);
        combinations(nums, target, res, index, arr);
        arr.pop_back();

        //dont take same 
        combinations(nums, target, res, index + 1, arr);
    }
};
