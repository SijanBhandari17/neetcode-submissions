class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        combinations(arr,n,k,1);
        return res;
    }

    void combinations(vector<int> arr,int n,int k,int si){
        if(arr.size() == k){
            res.push_back(arr);
            return;
        }
          if (si > n) {
    return;
  }
    arr.push_back(si);
    combinations(arr,n,k,si + 1);

    arr.pop_back();
    combinations(arr,n,k,si + 1);
    }


};