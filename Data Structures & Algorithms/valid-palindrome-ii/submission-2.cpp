class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0,r = s.length() - 1;
        while( l < r){
            if(s[r] != s[l]){
                if(validPalindromeAfterDeletion(s,l + 1,r)) return true;
                if(validPalindromeAfterDeletion(s,l,r - 1)) return true;
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindromeAfterDeletion(string s,int l,int r){
        cout << s[l] << " " << s[r] << endl;
        cout << l << " " << r << endl;
        // if(l >= r) return false;
        while(l < r){
            cout << "running" << endl;
            if(s[r] != s[l]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};