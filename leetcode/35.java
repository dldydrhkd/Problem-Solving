class Solution {
    public int searchInsert(int[] nums, int target) {
        boolean find = false;
        int j = 0;
        for(int i=0; i<nums.length; i++){
            if(target==nums[i]){
                return i;
            }
            if(nums[i]<target){
                j = i+1;
            }
        }
        return j;
    }
}