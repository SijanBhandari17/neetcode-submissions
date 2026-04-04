class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> on(2*n);
        int i = 0;
        while(i < n){
            on[i] = nums[i];
            on[i + n] = nums[i];
            i++;
        }
        return on;

    }
};