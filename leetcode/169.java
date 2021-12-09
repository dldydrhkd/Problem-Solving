class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int num = nums[0];
        int cnt = 1;
        int max_cnt = 1;
        int max_num = nums[0];
        for(int i=1; i<nums.length; i++){
            if(num==nums[i]){
                cnt++;
            }
            else{
                if(max_cnt<cnt){
                    max_cnt = cnt;
                    max_num = num;
                }
                num = nums[i];
                cnt = 1;
            }
        }
        if(max_cnt<cnt){
            max_cnt = cnt;
            max_num = num;
        }
        return max_num;
    }
}