class Solution {
    vector<string> res;

   public:
    void backtrack(int n, int oc, int cc, string& paren) {
        if (oc < cc || oc > n) return;

        if (oc == n && cc == n) {
            res.push_back(paren);
            return;
        }

        paren += '(';
        backtrack(n, oc + 1, cc, paren);

        paren.pop_back();

        paren += ')';
        backtrack(n, oc, cc + 1, paren);
        paren.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string paren = "";
        paren += '(';
        int oc = 1;
        int cc = 0;
        backtrack(n, oc, cc, paren);
        return res;
    }
};
