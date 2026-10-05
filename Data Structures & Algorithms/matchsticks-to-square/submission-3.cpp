class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {

      int sum = accumulate(matchsticks.begin(), matchsticks.end(),0); 
      if(sum % 4 != 0) return false; 
      sort(matchsticks.begin(),matchsticks.end(),greater<int>());
      int len = sum / 4;
      vector<int> sides(4,0);
      return dfs(matchsticks, 0, len, sides);
    }

    bool dfs(vector<int> matchsticks, int idx, int len, vector<int> sides){
      if(idx == matchsticks.size()) return true;

      for(int i = 0; i < sides.size();i++){
        if(matchsticks[idx] + sides[i] <= len){
          sides[i] += matchsticks[idx];
          if(dfs(matchsticks, idx + 1, len, sides)) {
            return true;
          }
          sides[i] -= matchsticks[idx];
        }
        if(sides[i] == 0) break;
      }
      return false;

    }
};