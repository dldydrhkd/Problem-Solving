class Solution {
    public List<Integer> getRow(int rowIndex) {
        int[][] arr = new int[40][40];
        arr[0][0]=1;
        for(int i=1; i<=rowIndex; i++){
            arr[i][0]=1;
            for(int j=1; j<rowIndex; j++){
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
            }
            arr[i][rowIndex]=1;
        }
        List li = new ArrayList();
        for(int i=0; i<=rowIndex; i++){
            li.add(arr[rowIndex][i]);
        }
        return li;
    }
}