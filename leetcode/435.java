class Solution {
    public static int num = 1;
    public static int x = 0;
    public static int y = 0;
    Solution(){
        num = 1;
        x = 0;
        y = 0;
    }
    public void fill(int[][] arr, int n, int len){
        if(num==n*n){
            arr[x][y] = num;
            return;
        }
        else if(num>n*n){
            return;
        }
        int[] dir_x = {0,1,0,-1};
        int[] dir_y = {1,0,-1,0};
        for(int i=0; i<4; i++){
            for(int j=0; j<len-1; j++){
                int temp_x = x + dir_x[i]*j;
                int temp_y = y + dir_y[i]*j;
                if(j==0){
                    arr[x][y] = num;
                }
                else{
                    arr[temp_x][temp_y] = num;
                }
                num+=1;
            }
            x+=dir_x[i]*(len-1);
            y+=dir_y[i]*(len-1);
        }
        x+=1;
        y+=1;
        fill(arr,n,len-2);
    }
    public int[][] generateMatrix(int n) {
        int[][] arr = new int[n][n];
        fill(arr, n, n);
        return arr;
    }
}