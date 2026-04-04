class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const char *str1 = word1.c_str();
        const char *str2 = word2.c_str();
        string os = "";
        while(*str1 && *str2){
                os += *str1++;
                os += *str2++;
        }
        if(!*str1) return os + str2;
        return os + str1;
    }
};