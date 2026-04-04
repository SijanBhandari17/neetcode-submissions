class Solution {
public:
    bool isPalindrome(string s) {
        string cleanStr = "";
        for(const char &c: s){
            if(isalnum(c)) cleanStr += tolower(c);
        }
        int i = 0, j = cleanStr.length() - 1;

        while( i < j){
            if(tolower(cleanStr[i]) != tolower(cleanStr[j])) return false;   
            i++;
            j--;     
        }
        return true;
    }
};
