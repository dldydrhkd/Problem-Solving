class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] o1, int[] o2){
                if(o1[1]==o2[1]){
                    return o2[0]-o1[0];
                }
                else{
                    return o1[1]-o2[1];
                }
            }
        });
        int cnt = 0;
        int idx = 1;
        int right = intervals[0][1];
        while(idx<intervals.length){
            if(right<=intervals[idx][0]){
                right=intervals[idx][1];
            }
            else{
                cnt++;
            }
            idx++;
        }
        return cnt;
    }
}