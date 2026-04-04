class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0;
        int r = rows * cols - 1;

        while(l <= r){
            int mid = (l + r) / 2;
            // mapping 
            int row = mid / cols;
            int col = mid % cols;

            if(matrix[row][col] < target){
                l = mid + 1;
            }
            else if(matrix[row][col] > target){
                r = mid -1 ;
            }
            else{
                return matrix[row][col];
            }
        }
        return false;
    }
};
