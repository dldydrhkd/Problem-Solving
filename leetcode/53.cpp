class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = nums[0];
        int cur = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(cur < 0 && cur < nums[i]){
                cur = nums[i];
            }
            else if(cur+nums[i]>0){
                cur += nums[i];
            }
            else{
                cur = nums[i];
            }
            answer = max(answer, cur);
        }
        return answer;
    }
};