class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> window;
        int n = s.size();
        int l = 0;
        int r = 0;
        int max = 0;
        int count = 0;
        while(r < n){
            while(window.find(s[r]) != window.end()){
                window.erase(s[l++]);
            }
            count = r - l + 1;
            max = count > max ? count : max;
            window.insert(s[r++]);
        }
        return max;
    }
};
