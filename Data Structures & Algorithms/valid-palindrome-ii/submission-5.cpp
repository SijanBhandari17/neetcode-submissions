class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0,r = s.length() - 1;
        while( l < r){
            if(s[r] != s[l]){
                return validPalindromeAfterDeletion(s,l + 1,r) || 
                         validPalindromeAfterDeletion(s,l,r - 1);
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindromeAfterDeletion(string s,int l,int r){
        while(l < r){
            if(s[r] != s[l]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};