class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> counts(2, 0);
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                counts[0]++;
            }

            else if (bills[i] == 10 && counts[0] >= 1) {
                counts[0]--;
                counts[1]++;
            }

            else if (bills[i] == 20) {
                if ((counts[1] >= 1 && counts[0] >= 1)) {
                    counts[0] -= 1;
                    counts[1] -= 1;
                } else if (counts[0] >= 3) {
                    counts[0] -= 3;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};