class Solution {
public:
    int characterReplacement(string s, int k) {
       unordered_map<char,int> table;
       int n = s.size();
       int l = 0,r = 0;
       int windowSize = 0;
       int maxElement = 0;
       int maxR = 0;
       for(; r < n ; r++){

            if(table.find(s[r]) == table.end()){
                table.insert({s[r],0});
            }
            table[s[r]]++;
            windowSize = r - l + 1;
            maxElement = table[s[r]] > maxElement ? table[s[r]] : maxElement;
            if((windowSize - maxElement) <= k){
                maxR = windowSize; 
            }
            else{
                table[s[l]]--;
                l++;
            }
       }
       return maxR;
           }
};
