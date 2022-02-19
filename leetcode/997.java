class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] arr = new int[1001];
        int[][] arr2 = new int[1001][1001];
        for(int i=0; i<trust.length; i++){
            arr[trust[i][1]]++;
            arr2[trust[i][0]][trust[i][1]]=1;
        }
        for(int i=1; i<=n; i++){
            if(arr[i]==n-1){
                boolean is_judge = true;
                for(int j=1; j<=n; j++){
                    if(j==i) continue;
                    if(arr2[i][j]==1){
                        is_judge = false;
                        break;
                    }
                }
                if(is_judge==true){
                    return i;
                }
            }
        }

        return -1;
    }
}