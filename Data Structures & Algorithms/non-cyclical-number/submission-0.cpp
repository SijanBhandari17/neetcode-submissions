class Solution {
   public:
    bool isHappy(int n) {
        vector<int> digits;
        unordered_set<int> s;
        int temp = n;
        int prev_sum, sum = 0;

        while (true) {
            while (temp != 0) {
                digits.push_back(temp % 10);
                temp = temp / 10;
            }
            for (int i = 0; i < digits.size(); i++) {
                sum += pow(digits[i], 2);
            }
            if (prev_sum == sum) {
                return true;
            }
            prev_sum = sum;
            sum = 0;
            if (s.contains(prev_sum)) {
                return false;
            }
            s.insert(prev_sum);
            digits = {};
            temp = prev_sum;
        }
    }
};
