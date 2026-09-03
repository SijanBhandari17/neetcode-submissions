class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        long long num = digits[0];
        for(int i = 1; i < digits.size() ;i++){
            num = num * 10 + digits[i];
            cout << num<<endl ;
        }
            // cout << num ;
        num++;
        while(num != 0){
            res.push_back(num % 10);
            num = num /10;
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
