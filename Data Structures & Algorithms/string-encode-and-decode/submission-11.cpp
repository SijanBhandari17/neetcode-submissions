class Solution {
public:

    string encode(vector<string>& strs) {    
        string es = "";
        if(!strs.size()) return "";
        for(const string &s : strs){
            int length = s.length();
            es += to_string(length) + '#' + s ;
        }
        cout << es << '\n';
        return es;
    }

    vector<string> decode(string s) {
        cout << "string " << s<<'\n';
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
            cout << "i ko value: " << i << '\n'; 
            cout << "length " << length << '\n';
            while(length != 0){
                cout<<"inner loop running"<<'\n';
                    str += s[i];
                    length--;
                
                i++;
            }
            cout << "Pushing " << str << '\n';
            ds.push_back(str);
            str = "";
        }
        return ds;
    }
};
