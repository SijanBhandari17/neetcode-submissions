class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> str;
        backtrack(s, str, 0 , 0);
        return res;
    }
    void backtrack(string &s, vector<string> &str, int i, int j){

        if(j >= s.size()){
            if(i == j) res.push_back(str);
            return;
        }
        if(isPalindrome(s,i,j)){
            str.push_back(s.substr(i, j - i + 1));
            backtrack(s,str,j + 1 ,j + 1);
            str.pop_back();
        }

        backtrack(s,str,i, j + 1);
    }
    bool isPalindrome(string &s, int l , int r){
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

