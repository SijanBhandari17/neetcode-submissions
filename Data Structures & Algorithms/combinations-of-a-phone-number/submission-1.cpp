class Solution {
   private:
    vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

   public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        vector<int> digit;
        for (const char c : digits) {
            digit.push_back(c - '0');
        }
        string str;
        backtrack(digit, str, 0);
        return res;
    }

    void backtrack(vector<int> digit, string str, int index) {
        if (index > digit.size()) return;
        if (str.size() == digit.size()) {
            res.push_back(str);
            return;
        }
        for (int i = 0; i < phone[digit[index]].size(); i++) {
            str.push_back(phone[digit[index]][i]);
            backtrack(digit, str, index + 1);
            str.pop_back();
        }
    }
};
