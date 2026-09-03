class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int temp = n;
        int prev_sum, sum = 0;

        while (true) {
            while (temp != 0) {
                int digit = temp % 10;
                sum += digit * digit;
                temp = temp / 10;
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
            temp = prev_sum;
        }
    }
};
