class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> sm;
        vector<int> indexes;

        for(int i = 0; i < nums.size();i++){
            auto it = sm.find(target - nums[i]);
            if(it != sm.end()){
                cout << it->first << ": " << it->second;
                int index = it->second;
                cout << index;
                indexes.push_back(index);
                indexes.push_back(i);
                return indexes;
            }
                sm[nums[i]] = i;
        }
    }
};
