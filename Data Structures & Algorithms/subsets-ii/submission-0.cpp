class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> out = {};
        sort(nums.begin(),nums.end());
        backtrack(0, nums, result, out);
        return result;
    }

    void backtrack(int index, vector<int>& nums, vector<vector<int>>& result, vector<int>& out) {
        if (index == nums.size()) {
            result.push_back(out);
            return;
        }

        out.push_back(nums[index]);
        backtrack(index + 1, nums, result, out);

        out.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]){
            index++;
        }
        backtrack(index + 1, nums, result, out);
    }
};
