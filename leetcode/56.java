class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override public int compare(int[] o1, int[] o2) {
                if(o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                }else {
                    return o1[0] - o2[0];
                }
            }
        });
        int idx = 0;
        ArrayList<Integer[]> answer = new ArrayList<Integer[]>();
        answer.add(new Integer[]{intervals[0][0],intervals[0][1]});
        for(int i=1; i<intervals.length; i++){
            if(answer.get(idx)[1]>=intervals[i][1]){
                continue;
            }
            else if(answer.get(idx)[1]>=intervals[i][0]){
                answer.get(idx)[1] = intervals[i][1];
            }
            else{
                idx++;
                answer.add(new Integer[]{intervals[i][0],intervals[i][1]});
            }
        }
        int[][] temp = new int[answer.size()][2];
        for(int i=0; i<answer.size(); i++){
            temp[i][0] = answer.get(i)[0];
            temp[i][1] = answer.get(i)[1];
        }
        return temp;
    }
}