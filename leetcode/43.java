class Solution {
    public List<Integer> partitionLabels(String s) {
        int arr[] = new int[26];
        List<Integer> li = new ArrayList<Integer>();
        for(int i=0; i<s.length(); i++){
            int temp = (int)(s.charAt(i)-'a');
            arr[temp]=i;
        }
        int cnt = 0;
        int idx = -1;
        for(int i=0; i<s.length(); i++){
            int temp = (int)(s.charAt(i)-'a');
            idx = Math.max(idx,arr[temp]);
            cnt++;
            if(idx==i){
                li.add(cnt);
                cnt = 0;
                idx = -1;
            }
        }
        if(idx!=-1){
            li.add(cnt);
        }
        return li;
    }
}