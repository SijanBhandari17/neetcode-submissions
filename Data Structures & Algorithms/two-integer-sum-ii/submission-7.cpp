#include<optional>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        vector<int> out;
        for(int i = 0; i < len; i++){
            cout << i << endl;
            auto x = binary_search(numbers, target, i);
            if(x.has_value()){
                out.push_back(i + 1);
                out.push_back(x.value() + 1);
                return out;
            }
        }
        return out;
    }
    optional<int> binary_search(vector<int> &numbers, int target, int num){
        int r = numbers.size() - 1;
        int l = num;
        while(l <= r){
            int mid = l + (r - l)/ 2;
            cout << mid ;
            int sub = target - numbers[num];

            if(numbers[mid] == sub )return mid;
            if(numbers[mid] < sub) l = mid + 1;
            if(numbers[mid] > sub) r= mid - 1;
        }
        return nullopt;
    }
};
