class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int r = k - 1, l = 0;
       int n = arr.size();
       if(k >= n) return arr;

       for(int i = k; i < n;i++){
            bool flag = (abs(arr[l] - x) < abs(arr[i] - x)) || (
                (abs(arr[l] - x) == abs(arr[i] - x)) && (arr[l] < arr[i])
            );
            if(!flag){
                l++;
                r++;
            }
       } 
        return vector<int>(arr.begin() + l,arr.begin() + l + k);
    }
};