class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        while(i<n){
            if(matrix[i][0]<=target && target<=matrix[i][m-1]){
                break;
            }
            i++;
        }
        if(i==n){
            return false;
        }
        for(int j=0; j<matrix[i].size(); j++){
            if(target==matrix[i][j]){
                return true;
            }
        }
        return false;
    }
};