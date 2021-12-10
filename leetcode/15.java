class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> li = new HashSet<>();
        Arrays.sort(nums);
        for(int i=0; i<nums.length; i++){
            int j=i+1;
            int k=nums.length-1;
            int r = -nums[i];
            while(j<k){
                if(nums[j]+nums[k]==-nums[i]){
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(nums[k]);
                    li.add(temp);
                    j++;
                }
                else if(nums[j]+nums[k]<r){
                    j++;
                }
                else if(nums[j]+nums[k]>r){
                    k--;
                }
            }
        }
        return new ArrayList<>(li);
    }
}