class Solution {
   private:
    vector<vector<int>> res;

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> boolArr(nums.size(), false);
        vector<int> arr;
        sort(nums.begin(), nums.end());
        permute(nums, boolArr, arr);
        return res;
    }
    void permute(vector<int>& nums, vector<bool>& boolArr, vector<int> arr) {
        if (arr.size() == nums.size()) {
            res.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!boolArr[i]) {
                arr.push_back(nums[i]);
                boolArr[i] = true;

                permute(nums, boolArr, arr);

                boolArr[i] = false;
                arr.pop_back();

                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
    }
}
;