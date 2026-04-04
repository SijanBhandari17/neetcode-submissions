class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
unordered_set<int> occur;
        int curr = 1;
        int n = nums.size();
        for(int i = 0; i <= k;i++){
            if(occur.find(nums[i]) != occur.end()){
                return true;
            }
            occur.insert(nums[i]);
        }
        for(const int num: occur)
        cout << num << '\n';
        while(curr + k  < n){
                occur.erase(nums[curr - 1]);
                if(occur.find(nums[curr + k]) != occur.end()){
                    return true;
                }
                occur.insert(nums[curr + k]);
                curr++;
        }
        return false;
    }
};