class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const char *str1 = word1.c_str();
        const char *str2 = word2.c_str();
        int turn = 0;
        string os = "";
        while(*str1 && *str2){
            bool isWordOneTurn = turn % 2 == 0 ? true : false;
            cout << isWordOneTurn;
            if(isWordOneTurn){
                os += *str1;
                str1++;
            }
            else{
                os += *str2;
                str2++;
            }
            turn++;
        }
        if(!*str1) return os + str2;
        return os + str1;
    }
};