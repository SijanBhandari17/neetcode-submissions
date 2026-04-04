class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int out_len = INT_MAX;
        int l= 0,r =0;
        for(; r < nums.size();r++){
            sum += nums[r];
            while(sum >=target){
                out_len = min(out_len,r - l + 1);
                sum -= nums[l++];
            }
        }
        return out_len == INT_MAX ? 0 : out_len;
    }
};