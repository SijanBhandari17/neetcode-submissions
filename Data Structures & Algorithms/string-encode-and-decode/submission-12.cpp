class Solution {
public:

    string encode(vector<string>& strs) {    
        string es = "";
        if(!strs.size()) return "";
        for(const string &s : strs){
            int length = s.length();
            es += to_string(length) + '#' + s ;
        }
        return es;
    }

    vector<string> decode(string s) {
        vector<string> ds={};
        int i = 0;
        string str = "";
        while(i < s.length()){
            string lenString = "";
            while(s[i] != '#'){
                lenString += s[i];
                i++;
            }
            i++;

            int length = stoi(lenString);
            while(length != 0){
                    str += s[i];
                    length--;
                
                i++;
            }
            ds.push_back(str);
            str = "";
        }
        return ds;
    }
};
