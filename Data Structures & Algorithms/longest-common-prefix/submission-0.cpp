class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string outputString = "";

        for(int i = 0; i < strs[0].size();i++){
            cout<<strs[strs.size() - 1][i]<<'\n';
            cout<<strs[0][i]<<'\n';
            if(strs[0][i] == strs[strs.size() - 1][i]) {
                outputString += strs[0][i];
            }
            else {
                break;
            }
        }
        return outputString;
    }
};