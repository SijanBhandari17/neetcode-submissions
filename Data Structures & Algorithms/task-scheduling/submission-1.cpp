class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;
        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        int countMax = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                countMax++;
            }
        }
        int intervals = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), intervals);
    }
};
