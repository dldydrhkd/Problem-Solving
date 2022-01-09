class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int x = 0;
        int m = matrix.length;
        int n = matrix[0].length;
        int y = n-1;
        while(x<m && y>=0){
            if(matrix[x][y]>target){
                y--;
            }
            else if(matrix[x][y]<target){
                x++;
            }
            else{
                return true;
            }
        }
        return false;
    }
}