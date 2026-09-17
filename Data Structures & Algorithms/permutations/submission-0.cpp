class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> result;
       vector<int> perm;
       vector<bool> boolArr(nums.size(),false) ;
       backtrack(result,perm,boolArr,nums );
       return result;
    }
    void backtrack(vector<vector<int>> &result,vector<int> &perm,vector<bool> &boolArr,vector<int> &nums){
        if(perm.size() == nums.size()){
            result.push_back(perm);
            return;
        }

        for(int i = 0; i < nums.size();i++){
            if(!boolArr[i]){
                boolArr[i] = true;
                perm.push_back(nums[i]);

                backtrack(result,perm,boolArr,nums);

                boolArr[i] = false;
                perm.pop_back();

            }

        }

    }
};
