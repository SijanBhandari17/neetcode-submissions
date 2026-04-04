class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int ub = min(strs.front().length(),strs.back().length());
        int i = 0;
        while(i <= ub && strs.front()[i] == strs.back()[i]){
            i++;
        }
        return strs.front().substr(0,i);
    }
};