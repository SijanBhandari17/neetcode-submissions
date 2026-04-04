class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int length = nums.size();
       vector<int> outputArr = {};
        unordered_map <int,int> freqMap;
        vector<vector<int>> freqArr(length + 1);
        for(const int &num : nums){
            freqMap[num]++;
        }
        for (auto &pair : freqMap) {
            cout << pair.first << " -> " << pair.second << endl;
            freqArr[pair.second].push_back(pair.first);

        }      
        for(const vector<int> &v : freqArr){
            for(const int &num : v){
                cout << num << '\n';
            }
        }
        for(int i = length; i > 0;i--){
            for(int j = 0; j < freqArr[i].size() ; j++){
                if(k ==0) return outputArr;
                outputArr.push_back(freqArr[i][j]);
                k--;
            }
        }
        return outputArr;
        
    }
};
