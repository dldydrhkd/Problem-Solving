/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        TreeNode answer = add(nums, 0, nums.length-1);
        return answer;
    }
    public TreeNode add(int[] nums, int start, int end){
        if(start>end){
            return null;
        }
        int mid = (start+end)/2;
        TreeNode temp = new TreeNode(nums[mid]);
        temp.left = add(nums, start, mid-1);
        temp.right = add(nums, mid+1, end);
        return temp;
    }
}