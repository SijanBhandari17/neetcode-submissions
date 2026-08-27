class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() + 1;
        int n = text2.size() + 1; 
        vector<vector<int>> matrix (m,vector<int>(n,0));

        for(int i = 1; i < m;i++){
            for(int j = 1; j < n;j++){
                if(text1[i - 1] == text2[j -1]){
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                }
                else{
                    matrix[i][j] = max(matrix[i - 1] [j], matrix[i][j -1]);
                }
            }
        }
        return matrix[m - 1][n -1];
    }
};
