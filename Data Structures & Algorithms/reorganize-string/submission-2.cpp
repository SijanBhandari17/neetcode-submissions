class Solution {
   public:
    string reorganizeString(string s) {
        vector<int> freq_count(26, 0);
        for (const char& a : s) {
            freq_count[a - 'a']++;
        }

        int maxIdx = max_element(freq_count.begin(), freq_count.end()) - freq_count.begin();
        int maxElem = freq_count[maxIdx];

        int n = s.size();
        cout << maxElem << endl;
        if(maxElem > (n + 1)/2) return "";

        int idx = 0;
        string output(n,' ');

        while(freq_count[maxIdx] > 0){
            output[idx] = maxIdx + 'a';
            idx+= 2;
            freq_count[maxIdx]--;
        }

        for(int i = 0; i < 26; i++){
            while(freq_count[i] > 0){
                if(idx >= n){
                    idx = 1;
                }
                output[idx] = i + 'a';
                freq_count[i]--;
                idx += 2;
            }
        }
        return output;
        
        

    }
};