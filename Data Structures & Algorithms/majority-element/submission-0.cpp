class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> nc;
        int length = nums.size();
        int maxOccurence = floor(length /2);
        for(int i =0;i < length; i++){
            nc[nums[i]]++;
            if(nc[nums[i]] > maxOccurence )
            return nums[i];
        }
        return 0;
    }
};
