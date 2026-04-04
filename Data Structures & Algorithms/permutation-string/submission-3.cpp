class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    int window_size = s1.size();

    unordered_map<char,int> window(window_size);
    unordered_map<char,int> string_char(window_size);

    for(const char s : s1)
        string_char[s]++;

    int l =0 ,r = 0;

    for(;r < s2.size();r++){
        window[s2[r]]++;
        if(r - l + 1 ==  window_size   ) {
            if(window == string_char) {
                return true;
            }

            if(window[s2[l]] == 1){
                window.erase(s2[l]);
            }
            else{
                window[s2[l]]--;
            }
            l++;
        }
    }
    return false;
    }
};
