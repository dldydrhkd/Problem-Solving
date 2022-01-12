class Solution {
    public int[] productExceptSelf(int[] nums) {
        int zero_cnt = 0;
        int total = 1;
        int[] answer = new int[nums.length];
        for(int num : nums){
            if(num==0){
                zero_cnt++;
            }
            else{
                total*=num;
            }
        }
        if(zero_cnt>1){
            for(int i=0; i<answer.length; i++){
                answer[i] = 0;
            }
        }
        else if(zero_cnt==0){
            for(int i=0; i<answer.length; i++){
                answer[i] = total/nums[i];
            }
        }
        else{
            for(int i=0; i<answer.length; i++){
                if(nums[i]==0){
                    answer[i] = total;
                }
                else{
                    answer[i] = 0;
                }
            }
        }
        return answer;
    }
}