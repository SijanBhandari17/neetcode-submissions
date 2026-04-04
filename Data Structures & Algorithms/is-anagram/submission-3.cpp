class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }

    unordered_map<char,int> sm;
    unordered_map<char,int> tm;
    
    for(int i = 0; i < s.length();i++){

            auto it1 = sm.find(s[i]);
            auto it2 = tm.find(t[i]);

            if(it1 != sm.end()){
                int val = sm.at(s[i]);
                sm.at(s[i]) = ++val; 
            }
            else{
                        sm.insert({s[i],1});

            }
            if(it2 != tm.end()){
                int val = tm.at(t[i]);
                tm.at(t[i]) = ++val; 
            }
            else{
                        tm.insert({t[i],1});

            }
    
    }
    return sm == tm;
        
    }
};
