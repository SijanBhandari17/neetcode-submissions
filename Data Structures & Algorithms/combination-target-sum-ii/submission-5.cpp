
class Solution {
   private:
    vector<vector<int>> res;

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        int index = 0;
        sort(candidates.begin(),candidates.end());
        combinations(candidates, target, res, index, arr);
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
        combinations(nums, target, res, index + 1, arr);
        arr.pop_back();

        while(index + 1 < nums.size() && nums[index] == nums[index + 1]){
            index++;
        }
        combinations(nums, target, res, index + 1, arr);
    }
};